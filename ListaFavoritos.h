#ifndef LISTAFAVORITOS_H
#define LISTAFAVORITOS_H
#include <iostream>
#include <string>
#include "Cancion.h"
using namespace std;

class ListaFavoritos {
private:
    string usuario_id;           
    string nombre_lista;         
    int ids_canciones[10000];    
    int cantidad_canciones;      
    bool esPremium;             

public:

    ListaFavoritos(string usuario_id, string nombre_lista, bool esPremium);

    
    void agregarCancion(int id_cancion);
    void eliminarCancion(int id_cancion);
    void mostrarLista();
    void reproducirLista(Cancion* canciones, int totalCanciones);  // Reproduce todas las canciones de la lista


    int buscarCancion(int id_cancion);
    int getCantidadCanciones() const { return cantidad_canciones; }
    string getNombreLista() const { return nombre_lista; }
};

#endif //LISTAFAVORITOS

