#include "ActualizacionDatos.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

// Liberar memoria dinámica
void ActualizacionDatos::liberarMemoria() {
    if (lineas) {
        for (int i = 0; i < numLineas; i++)
            delete[] lineas[i];
        delete[] lineas;
        lineas = nullptr;
    }
}

// Constructor
ActualizacionDatos::ActualizacionDatos(const char* file)
    : lineas(nullptr), numLineas(0), filename(file) {}

// Destructor
ActualizacionDatos::~ActualizacionDatos() {
    liberarMemoria();
}

// Cargar archivo CSV a memoria dinámica
bool ActualizacionDatos::cargarArchivo() {
    ifstream entradaCount(filename);
    if (!entradaCount) {
        cout << "Error al abrir el archivo.\n";
        return false;
    }

    char c;
    while (entradaCount.get(c)) {
        if (c == '\n') numLineas++;
    }
    entradaCount.close();

    if (numLineas == 0) {
        cout << "Archivo vacío.\n";
        return false;
    }

    lineas = new char*[numLineas];

    ifstream entrada(filename);
    if (!entrada) {
        cout << "Error al abrir el archivo.\n";
        delete[] lineas;
        lineas = nullptr;
        return false;
    }

    int index = 0;
    while (!entrada.eof() && index < numLineas) {
        string temp;
        getline(entrada, temp);
        if (temp.empty()) continue;
        lineas[index] = new char[temp.length() + 1];
        strcpy(lineas[index], temp.c_str());
        index++;
    }
    entrada.close();
    return true;
}

// Actualizar campo "veces_reproducida"
bool ActualizacionDatos::actualizarReproducciones(const char* idBuscado, int incremento) {
    if (!lineas) return false;

    bool encontrado = false;
    const int indexId = 10;

    for (int i = 1; i < numLineas; i++) {
        char idLinea[indexId];
        int j = 0;
        while (lineas[i][j] != ';' && lineas[i][j] != '\0') {
            idLinea[j] = lineas[i][j];
            j++;
        }
        idLinea[j] = '\0';

        if (strcmp(idLinea, idBuscado) == 0) {
            encontrado = true;

            int campo = 0, inicio = -1, fin = -1;
            for (int k = 0; lineas[i][k] != '\0'; k++) {
                if (lineas[i][k] == ';') {
                    campo++;
                    if (campo == 6) inicio = k + 1;
                    else if (campo == 7) { fin = k; break; }
                }
            }
            if (inicio != -1 && fin == -1) fin = strlen(lineas[i]);

            char numeroStr[15];
            int pos = 0;
            for (int k = inicio; k < fin && lineas[i][k] != '\0'; k++)
                numeroStr[pos++] = lineas[i][k];
            numeroStr[pos] = '\0';

            int valor = atoi(numeroStr);
            valor += incremento;

            int nuevaLen = strlen(lineas[i]) + 1;
            char* nuevaLinea = new char[nuevaLen];
            strncpy(nuevaLinea, lineas[i], inicio);
            nuevaLinea[inicio] = '\0';
            char nuevoValor[15];
            sprintf(nuevoValor, "%d", valor);
            strcat(nuevaLinea, nuevoValor);
            strcat(nuevaLinea, lineas[i] + fin);

            delete[] lineas[i];
            lineas[i] = nuevaLinea;
            break;
        }
    }

    return encontrado;
}

// Guardar los cambios en el archivo CSV
bool ActualizacionDatos::guardarArchivo() {
    if (!lineas) return false;

    ofstream salida(filename);
    if (!salida) {
        cout << "Error al abrir el archivo para escribir.\n";
        return false;
    }

    for (int i = 0; i < numLineas; i++) {
        salida << lineas[i] << "\n";
    }
    salida.close();
    return true;
}


#include <iostream>
#include "ActualizacionDatos.h"
using namespace std;
/*
int main() {
    ActualizacionDatos datos("canciones2.csv");

    if (!datos.cargarArchivo()) {
        cout << "No se pudo cargar el archivo.\n";
        return 1;
    }

    char idBuscado[10];
    cout << "Ingrese ID de canción: ";
    cin >> idBuscado;

    int incremento;
    cout << "Ingrese incremento de reproducciones: ";
    cin >> incremento;

    if (datos.actualizarReproducciones(idBuscado, incremento)) {
        if (datos.guardarArchivo())
            cout << "Archivo actualizado correctamente.\n";
        else
            cout << "Error al guardar archivo.\n";
    } else {
        cout << "ID no encontrado.\n";
    }

    return 0;
}
*/
