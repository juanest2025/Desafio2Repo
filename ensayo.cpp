
/*
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int contarTokens(const char* str) {
    int count = 1;
    for (int i = 0; str[i]; i++)
        if (str[i] == ',') count++;
    return count;
}

char** split(const char* str, int& numTokens) {
    numTokens = contarTokens(str);
    char** tokens = new char*[numTokens];
    char* copia = new char[strlen(str) + 1];
    strcpy(copia, str);

    char* token = strtok(copia, ",");
    int i = 0;
    while (token != NULL) {
        tokens[i] = new char[strlen(token) + 1];
        strcpy(tokens[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    delete[] copia;
    return tokens;
}

bool existe(char** arr, int n, const char* id) {
    for (int i = 0; i < n; i++)
        if (strcmp(arr[i], id) == 0) return true;
    return false;
}

char* join(char** arr, int n) {
    int len = 0;
    for (int i = 0; i < n; i++)
        len += strlen(arr[i]) + 1;

    char* resultado = new char[len];
    resultado[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(resultado, arr[i]);
        if (i != n - 1) strcat(resultado, ",");
    }
    return resultado;
}

int main() {
    const char* archivo = "ListaFavoritos.csv";
    const int MAX_LINEAS = 100;
    const int MAX_LONG = 1024;

    char* lineas[MAX_LINEAS];
    int numLineas = 0;

    ifstream entrada(archivo);
    if (!entrada) { cout << "No se puede abrir el archivo\n"; return 1; }
    while (entrada.getline((lineas[numLineas] = new char[MAX_LONG]), MAX_LONG)) {
        numLineas++;
    }
    entrada.close();

    char usuario_destino[5], usuario_origen[5];
    cout << "ID del usuario destino: "; cin >> usuario_destino;
    cout << "ID del usuario origen: "; cin >> usuario_origen;

    int idx_destino = -1;
    int idx_origen = -1;

    for (int i = 0; i < numLineas; i++) {
        char* copia = new char[strlen(lineas[i]) + 1];
        strcpy(copia, lineas[i]);
        char* id = strtok(copia, ";");
        if (strcmp(id, usuario_destino) == 0) idx_destino = i;
        if (strcmp(id, usuario_origen) == 0) idx_origen = i;
        delete[] copia;
    }

    if (idx_destino == -1 || idx_origen == -1) {
        cout << "Usuario no encontrado\n"; return 1;
    }

    // Extraer canciones origen
    char* copia_origen = new char[strlen(lineas[idx_origen]) + 1];
    strcpy(copia_origen, lineas[idx_origen]);
    strtok(copia_origen, ";"); // id
    strtok(NULL, ";"); // nombre lista
    char* canciones_origen_str = strtok(NULL, ";");
    int n_origen;
    char** canciones_origen = split(canciones_origen_str, n_origen);
    delete[] copia_origen;

    // Extraer canciones destino
    char* copia_destino = new char[strlen(lineas[idx_destino]) + 1];
    strcpy(copia_destino, lineas[idx_destino]);
    strtok(copia_destino, ";");
    strtok(NULL, ";");
    char* canciones_destino_str = strtok(NULL, ";");
    int n_destino;
    char** canciones_destino = split(canciones_destino_str, n_destino);
    delete[] copia_destino;

    // Agregar solo las canciones no repetidas
    for (int i = 0; i < n_origen; i++) {
        if (!existe(canciones_destino, n_destino, canciones_origen[i])) {
            char** tmp = new char*[n_destino + 1];
            for (int j = 0; j < n_destino; j++) tmp[j] = canciones_destino[j];
            tmp[n_destino] = canciones_origen[i];
            delete[] canciones_destino;
            canciones_destino = tmp;
            n_destino++;
        } else {
            delete[] canciones_origen[i]; // liberar duplicado
        }
    }
    delete[] canciones_origen;

    // Crear nueva cadena
    char* nuevas_canciones = join(canciones_destino, n_destino);

    // Reconstruir línea destino
    char nueva_linea[MAX_LONG];
    char* copia_linea = new char[strlen(lineas[idx_destino]) + 1];
    strcpy(copia_linea, lineas[idx_destino]);
    char* id = strtok(copia_linea, ";");
    char* nombre_lista = strtok(NULL, ";");
    strcpy(nueva_linea, id);
    strcat(nueva_linea, ";");
    strcat(nueva_linea, nombre_lista);
    strcat(nueva_linea, ";");
    strcat(nueva_linea, nuevas_canciones);

    delete[] lineas[idx_destino];
    lineas[idx_destino] = new char[strlen(nueva_linea) + 1];
    strcpy(lineas[idx_destino], nueva_linea);

    // Guardar cambios en el CSV
    ofstream salida(archivo);
    for (int i = 0; i < numLineas; i++) salida << lineas[i] << "\n";
    salida.close();

    cout << "Canciones agregadas correctamente!\n";

    // Liberar memoria
    delete[] nuevas_canciones;
    for (int i = 0; i < n_destino; i++) delete[] canciones_destino[i];
    delete[] canciones_destino;
    for (int i = 0; i < numLineas; i++) delete[] lineas[i];
    delete[] copia_linea;

    return 0;
}

*/

