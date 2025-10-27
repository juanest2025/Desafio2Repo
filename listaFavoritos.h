#ifndef LISTAFAVORITOS_H
#define LISTAFAVORITOS_H

#include <string>
using std::string;

class ListaFavoritos {
private:
    static const int MAX_LINEAS = 100;
    static const int MAX_LONG = 1024;

    char* lineas[MAX_LINEAS];
    int numLineas;
    string archivo;

public:
    //constructor
    ListaFavoritos(const string& nombreArchivo = "ListaFavoritos.csv");

    //destructor
    ~ListaFavoritos();

    //métodos públicos
    bool copiarCanciones(const string& usuario_destino, const string& usuario_origen);
    void mostrarLista(const string& usuario_id);
    //métodos auxiliares privados
    int contarTokens(const string& str, char delim);
    char** split(const string& str, int& numTokens, char delim);
    bool existe(char** arr, int n, const string& id);
    string join(char** arr, int n, char delim);
    int buscarUsuario(const string& usuario_id);
    char** obtenerCanciones(int idx, int& n);
    void actualizarLinea(int idx, char** canciones, int n);
    bool cargarArchivo();
    bool guardarArchivo();

};

#endif // LISTAFAVORITOS_H
