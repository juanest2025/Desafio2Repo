#include "ListaReproduccion.h"
#include <fstream>
#include <cstring>
#include <string> // <--- Se incluye std::string
#include <iostream>

using namespace std;

// Se mantiene el constructor original
ListaReproduccion::ListaReproduccion(const char* file) {
    // Almacenamiento del nombre del archivo (se asume que 'filename' es un const char* o se copia)
    filename = file;
    lineas = nullptr;
    numLineas = 0;
    cargarCSV();
}

ListaReproduccion::~ListaReproduccion() {
    for (int i = 0; i < numLineas; i++)
        delete[] lineas[i];
    delete[] lineas;
}

// *** FUNCIÓN REDUCIDA Y SIMPLIFICADA CON std::string ***
bool ListaReproduccion::cargarCSV() {
    // La doble pasada para el conteo de líneas aún es necesaria para dimensionar char**
    ifstream entradaCount(filename);
    if (!entradaCount) return false;

    char c;
    numLineas = 0;
    // Se cuenta un salto de línea por cada línea completa
    while (entradaCount.get(c)) {
        if (c == '\n') numLineas++;
    }
    entradaCount.close();

    // Reabrir para verificar si la última línea no tiene salto de línea
    // y no está vacía, para contarla
    ifstream checkLast(filename);
    checkLast.seekg(0, ios::end);
    long size = checkLast.tellg();
    if (size > 0) {
        checkLast.seekg(-1, ios::end);
        char lastChar;
        checkLast.get(lastChar);
        if (lastChar != '\n') numLineas++; // Cuenta la línea final si no tiene \n
    }
    checkLast.close();

    if (numLineas == 0) return false;

    lineas = new char*[numLineas];

    // Lectura de datos: Ahora con std::string
    ifstream entrada(filename);
    if (!entrada) {
        delete[] lineas; // Liberar memoria si falla la apertura
        lineas = nullptr;
        numLineas = 0;
        return false;
    }

    int index = 0;
    string temp;
    while (getline(entrada, temp) && index < numLineas) {
        // La comprobación de línea vacía aún es útil
        if (temp.empty()) continue;

        // Almacenar la línea. std::string hace esto muy seguro.
        // Se copia a char* para mantener la interfaz de clase (char** lineas)
        lineas[index] = new char[temp.length() + 1];
        strcpy(lineas[index], temp.c_str());
        index++;
    }
    entrada.close();

    // Ajustar numLineas al número de líneas leídas realmente
    if (index < numLineas) numLineas = index;

    return true;
}

bool ListaReproduccion::guardarCSV() {
    // ... sin cambios, es eficiente ...
    ofstream salida(filename);
    if (!salida) return false;
    for (int i = 0; i < numLineas; i++) {
        salida << lineas[i] << "\n";
    }
    salida.close();
    return true;
}

bool ListaReproduccion::idExisteEnCampo(const char* campo, const char* id) {
    // ... se mantiene, ya que trabaja a bajo nivel de C ...
    const char* ptr = campo;
    char temp[32];
    while (*ptr != '\0') {
        int j = 0;
        while (*ptr != ',' && *ptr != '\0' && j < 31) temp[j++] = *ptr++;
        temp[j] = '\0';
        if (strcmp(temp, id) == 0) return true;
        if (*ptr == ',') ptr++;
    }
    return false;
}

char* ListaReproduccion::obtenerCampoIds(int lineaIndex) {
    // ... sin cambios, es eficiente a bajo nivel ...
    int campo = 0;
    int inicio = -1;
    for (int i = 0; lineas[lineaIndex][i] != '\0'; i++) {
        if (lineas[lineaIndex][i] == ';') campo++;
        if (campo == 2) { inicio = i + 1; break; }
    }
    if (inicio == -1) return nullptr;
    return lineas[lineaIndex] + inicio;
}

// *** FUNCIÓN SIMPLIFICADA CON std::string (internamente) ***
bool ListaReproduccion::copiarCancionesEntreUsuarios(const char* origen_id, const char* destino_id) {
    char* origenCampo = nullptr;
    char* destinoCampo = nullptr;
    int indexOrigen = -1, indexDestino = -1;

    // Búsqueda de índices (se mantiene por la interfaz de char**)
    const int ID_SIZE = 5;
    for (int i = 1; i < numLineas; i++) {
        char idLinea[ID_SIZE + 1];
        int j = 0;
        while (lineas[i][j] != ';' && lineas[i][j] != '\0' && j < ID_SIZE)
            idLinea[j++] = lineas[i][j];
        idLinea[j] = '\0';

        if (strcmp(idLinea, origen_id) == 0) indexOrigen = i;
        if (strcmp(idLinea, destino_id) == 0) indexDestino = i;
    }

    if (indexOrigen == -1 || indexDestino == -1) return false;

    origenCampo = obtenerCampoIds(indexOrigen);
    destinoCampo = obtenerCampoIds(indexDestino);
    if (!origenCampo || !destinoCampo) return false;

    // --- Reducción y Simplificación con std::string ---
    std::string nuevaLinea;
    std::string origenStr(origenCampo);
    std::string destinoStr(destinoCampo);

    // 1. Copiar la base de la línea de destino (hasta el campo de IDs)
    int inicio = destinoCampo - lineas[indexDestino];
    nuevaLinea.append(lineas[indexDestino], inicio);

    // 2. Inicializar el campo de IDs con los IDs existentes del destino
    std::string idsDestino = destinoStr;

    // 3. Procesar IDs del origen: usando un simple bucle y str.find() para evitar strtok
    size_t pos = 0;
    std::string token;

    // Convertir el campo de origen en un stringstream para tokenizar (opcional, pero limpio)
    // Sin embargo, para mantener una reducción visible del código, seguiremos la lógica de tokenización manual
    // pero usando strings para la construcción final, evitando el cálculo manual de memoria.

    // Reutilizamos la lógica de tokenización de C (strtok) con una copia de string
    // para procesar el origen de forma limpia, ya que no podemos usar std::stringstream por la restricción.
    char* origenCopia = new char[origenStr.length() + 1];
    strcpy(origenCopia, origenStr.c_str());

    char* tokenPtr = strtok(origenCopia, ",");
    while (tokenPtr != nullptr) {
        // El idExisteEnCampo ya funciona bien con char*
        if (!idExisteEnCampo(destinoCampo, tokenPtr)) {
            // Se usa el string de destino para la lógica de añadir coma
            if (!idsDestino.empty()) {
                idsDestino += ",";
            }
            idsDestino += tokenPtr;
        }
        tokenPtr = strtok(nullptr, ",");
    }
    delete[] origenCopia;

    // 4. Concatenar los IDs actualizados a la nueva línea base
    nuevaLinea += idsDestino;

    // 5. Reemplazar la línea de destino
    delete[] lineas[indexDestino];
    // Asignar el nuevo char* desde el std::string
    lineas[indexDestino] = new char[nuevaLinea.length() + 1];
    strcpy(lineas[indexDestino], nuevaLinea.c_str());

    return true;
}
