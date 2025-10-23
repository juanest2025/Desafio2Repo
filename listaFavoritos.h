#ifndef LISTAFAVORITOS_H
#define LISTAFAVORITOS_H

#include <iostream>
#include <string>
#include "Cancion.h"
using namespace std;

class ListaFavoritos {
private:
    string usuario_id;           //ID del usuario propietario de la lista
    string nombre_lista;         //nombre de la lista (ej. "Favoritas")
    int ids_canciones[10000];    //IDs de canciones guardadas
    int cantidad_canciones;      //número actual de canciones en la lista
    bool esPremium;              //tipo de usuario: true = premium

public:
    //constructor
    ListaFavoritos(string usuario_id, string nombre_lista, bool esPremium);

    //métodos principales
    void agregarCancion(int id_cancion);
    void eliminarCancion(int id_cancion);
    void mostrarLista();
    void reproducirLista(Cancion* canciones, int totalCanciones);  //reproduce todas las canciones de la lista

    //métodos auxiliares
    int buscarCancion(int id_cancion);
    int getCantidadCanciones() const { return cantidad_canciones; }
    string getNombreLista() const { return nombre_lista; }
};

#endif
