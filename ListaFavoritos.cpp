#include "ListaFavoritos.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//constructor
ListaFavoritos::ListaFavoritos(const string& nombreArchivo) {
    archivo = nombreArchivo;
    numLineas = 0;
}

//destructor
ListaFavoritos::~ListaFavoritos() {
    for (int i = 0; i < numLineas; i++)
        delete[] lineas[i];
}

//métodos privados
int ListaFavoritos::contarTokens(const string& str, char delim) {
    int count = 1;
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == delim) count++;
    return count;
}

char** ListaFavoritos::split(const string& str, int& numTokens, char delim) {
    numTokens = contarTokens(str, delim);
    char** tokens = new char*[numTokens];

    size_t start = 0;
    int idx = 0;

    for (size_t i = 0; i <= str.length(); i++) {
        if (i == str.length() || str[i] == delim) {
            size_t len = i - start;
            tokens[idx] = new char[len + 1];
            str.copy(tokens[idx], len, start);
            tokens[idx][len] = '\0';
            start = i + 1;
            idx++;
        }
    }

    return tokens;
}

bool ListaFavoritos::existe(char** arr, int n, const string& id) {
    for (int i = 0; i < n; i++)
        if (string(arr[i]) == id) return true;
    return false;
}

string ListaFavoritos::join(char** arr, int n, char delim) {
    string resultado = "";
    for (int i = 0; i < n; i++) {
        resultado += arr[i];
        if (i != n - 1) resultado += delim;
    }
    return resultado;
}

int ListaFavoritos::buscarUsuario(const string& usuario_id) {
    for (int i = 0; i < numLineas; i++) {
        string linea(lineas[i]);
        size_t pos = linea.find(';');
        if (pos != string::npos) {
            string id = linea.substr(0, pos);
            if (id == usuario_id) {
                return i;
            }
        }
    }
    return -1;
}

char** ListaFavoritos::obtenerCanciones(int idx, int& n) {
    string linea(lineas[idx]);

    // Encontrar la tercera sección (ids_canciones)
    size_t pos1 = linea.find(';');
    size_t pos2 = linea.find(';', pos1 + 1);

    string canciones_str = linea.substr(pos2 + 1);
    char** canciones = split(canciones_str, n, ',');

    return canciones;
}

void ListaFavoritos::actualizarLinea(int idx, char** canciones, int n) {
    string linea(lineas[idx]);

    //extraer id y nombre_lista
    size_t pos1 = linea.find(';');
    size_t pos2 = linea.find(';', pos1 + 1);

    string id = linea.substr(0, pos1);
    string nombre_lista = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    string nuevas_canciones = join(canciones, n, ',');

    //reconstruir línea
    string nueva_linea = id + ";" + nombre_lista + ";" + nuevas_canciones;

    delete[] lineas[idx];
    lineas[idx] = new char[nueva_linea.length() + 1];
    strcpy(lineas[idx], nueva_linea.c_str());
}

bool ListaFavoritos::cargarArchivo() {
    ifstream entrada(archivo.c_str());
    if (!entrada) {
        cout << "No se puede abrir el archivo\n";
        return false;
    }

    numLineas = 0;
    while (entrada.getline((lineas[numLineas] = new char[MAX_LONG]), MAX_LONG)) {
        numLineas++;
    }
    entrada.close();
    return true;
}

bool ListaFavoritos::guardarArchivo() {
    ofstream salida(archivo.c_str());
    if (!salida) {
        cout << "No se puede escribir en el archivo\n";
        return false;
    }

    for (int i = 0; i < numLineas; i++)
        salida << lineas[i] << "\n";
    salida.close();
    return true;
}

//métodos públicos
bool ListaFavoritos::copiarCanciones(const string& usuario_destino, const string& usuario_origen) {
    if (!cargarArchivo())
        return false;

    int idx_destino = buscarUsuario(usuario_destino);
    int idx_origen = buscarUsuario(usuario_origen);

    if (idx_destino == -1 || idx_origen == -1) {
        cout << "Usuario no encontrado\n";
        return false;
    }

    //obtener canciones de ambos usuarios
    int n_origen, n_destino;
    char** canciones_origen = obtenerCanciones(idx_origen, n_origen);
    char** canciones_destino = obtenerCanciones(idx_destino, n_destino);

    //agregar solo las canciones no repetidas
    int cancionesAgregadas = 0;
    for (int i = 0; i < n_origen; i++) {
        if (!existe(canciones_destino, n_destino, string(canciones_origen[i]))) {
            char** tmp = new char*[n_destino + 1];
            for (int j = 0; j < n_destino; j++)
                tmp[j] = canciones_destino[j];
            tmp[n_destino] = canciones_origen[i];
            delete[] canciones_destino;
            canciones_destino = tmp;
            n_destino++;
            cancionesAgregadas++;
        } else {
            delete[] canciones_origen[i];
        }
    }
    delete[] canciones_origen;

    //actualizar la línea del usuario destino
    actualizarLinea(idx_destino, canciones_destino, n_destino);

    //liberar memoria
    for (int i = 0; i < n_destino; i++)
        delete[] canciones_destino[i];
    delete[] canciones_destino;

    // Guardar cambios
    bool exito = guardarArchivo();

    if (exito) {
        cout << "Se agregaron " << cancionesAgregadas
             << " canciones correctamente!\n";
    }

    return exito;
}

void ListaFavoritos::mostrarLista(const string& usuario_id) {
    if (!cargarArchivo())
        return;

    int idx = buscarUsuario(usuario_id);
    if (idx == -1) {
        cout << "Usuario no encontrado\n";
        return;
    }

    int n;
    char** canciones = obtenerCanciones(idx, n);

    cout << "Lista de canciones del usuario " << usuario_id << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "  - " << canciones[i] << "\n";
        delete[] canciones[i];
    }
    delete[] canciones;
}
