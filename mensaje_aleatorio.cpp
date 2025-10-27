
/*
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getNumAle(int limite) {
    return rand() % limite; // devuelve número entre 0 y limite-1
}


int main()
{

    srand(time(0)); // inicializar la semilla.
    int maxiEntrada = 50;
    char* mensaje[maxiEntrada] = {nullptr};
    int contador = 0;

    ifstream archivo("Publicidad_mensaje.csv");
    if (!archivo.is_open()){
        cerr <<"No se puedo abrir el archivo.\n";
        return 1;
    }

    string linea;
    while (getline(archivo,linea) && contador < maxiEntrada) {

        mensaje[contador] = new char[linea.length() + 1];
        //reservo memoria.

        for (size_t i = 0; i < linea.length(); i++){
            mensaje[contador][i] = linea[i];
        }

        mensaje[contador][linea.length()] = '\0';

        contador ++;
    }

    archivo.close();

    int indice = getNumAle(contador+1); // Generar numero aleatorio entre 0 y valor contador.
    string prioridad;
    string mensajePros;
    string mensaje2 = mensaje[indice];
    stringstream ss(mensaje2);
    getline(ss, prioridad, ';');
    getline(ss, mensajePros, ';');

    cout << "Mensaje: " << indice << endl;
    cout << "prioridad: " << prioridad << endl;
    cout << mensajePros;

//    cout << "Mensaje: " <<indice << endl;
//  cout << mensaje[indice] <<endl;



    // Liberar memoria
    for (int i = 0; i < contador; ++i) {
        delete[] mensaje[i];
    }

    return 0;
}
*/
/*

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    const char* filename = "canciones2.csv";
    int numLineas = 0;
    char** lineas = nullptr;

    // 1️⃣ Contar líneas
    ifstream entradaCount(filename);
    if (!entradaCount) {
        cout << "Error al abrir el archivo.\n";
        return 1;
    }

    char c;
    while (entradaCount.get(c)) {
        if (c == '\n') numLineas++;
    }
    entradaCount.close();

    if (numLineas == 0) {
        cout << "Archivo vacío.\n";
        return 1;
    }

    // 2️⃣ Reservar arreglo de punteros dinámico
    lineas = new char*[numLineas];

    // 3️⃣ Leer línea por línea y reservar memoria exacta
    ifstream entrada(filename);
    if (!entrada) {
        cout << "Error al abrir el archivo.\n";
        delete[] lineas;
        return 1;
    }

    int index = 0;
    while (!entrada.eof() && index < numLineas) {
        string temp;  // usar string temporal solo para medir longitud
        getline(entrada, temp);
        if (temp.empty()) continue;

        // Reservar memoria exacta
        lineas[index] = new char[temp.length() + 1];
        strcpy(lineas[index], temp.c_str());
        index++;
    }
    entrada.close();

    // 4️⃣ Ejemplo: modificar campo "veces_reproducida" del ID ingresado
    const int indexId = 10;
    char idBuscado[indexId];
    cout << "Ingrese ID de canción: ";
    cin >> idBuscado;

    int incremento;
    cout << "Ingrese incremento de reproducciones: ";
    cin >> incremento;

    bool encontrado = false;
    for (int i = 1; i < numLineas; i++) { // i=1 para saltar encabezado
        // Extraer ID hasta ';'
        char idLinea[indexId];
        int j = 0;
        while (lineas[i][j] != ';' && lineas[i][j] != '\0') {
            idLinea[j] = lineas[i][j];
            j++;
        }
        idLinea[j] = '\0';

        if (strcmp(idLinea, idBuscado) == 0) {
            encontrado = true;

            // Buscar campo 7 y actualizar (igual que tu código anterior)
            int campo = 0, inicio = -1, fin = -1;
            for (int k = 0; lineas[i][k] != '\0'; k++) {
                if (lineas[i][k] == ';') {
                    campo++;
                    if (campo == 6) inicio = k+1;
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

            // Reconstruir línea
            int nuevaLen = strlen(lineas[i]) + 1; // suficiente para nuevo número
            char* nuevaLinea = new char[nuevaLen];
            strncpy(nuevaLinea, lineas[i], inicio);
            nuevaLinea[inicio] = '\0';
            char nuevoValor[15];
            sprintf(nuevoValor, "%d", valor);
            strcat(nuevaLinea, nuevoValor);
            strcat(nuevaLinea, lineas[i] + fin);

            delete[] lineas[i];          // liberar memoria vieja
            lineas[i] = nuevaLinea;      // asignar nueva línea
            break;
        }
    }

    if (!encontrado) cout << "ID no encontrado.\n";

    // 5️⃣ Reescribir archivo
    ofstream salida(filename);
    for (int i = 0; i < numLineas; i++) {
        salida << lineas[i] << "\n";
        delete[] lineas[i];  // liberar memoria línea por línea
    }
    salida.close();
    delete[] lineas;  // liberar arreglo de punteros

    return true;
}
*/
