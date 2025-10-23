#ifndef LISTAFAVORITOS_H
#define LISTAFAVORITOS_H

#include <iostream>
#include <string>
#include "Cancion.h"
using namespace std;

class ListaFavoritos {
private:
    string usuario_id;           // ID del usuario propietario de la lista
    string nombre_lista;         // Nombre de la lista (ej. "Favoritas")
    int ids_canciones[10000];    // IDs de canciones guardadas
    int cantidad_canciones;      // Número actual de canciones en la lista
    bool esPremium;              // Tipo de usuario: true = premium

public:
    // Constructor
    ListaFavoritos(string usuario_id, string nombre_lista, bool esPremium);

    // Métodos principales
    void agregarCancion(int id_cancion);
    void eliminarCancion(int id_cancion);
    void mostrarLista();
    void reproducirLista(Cancion* canciones, int totalCanciones);  // Reproduce todas las canciones de la lista

    // Métodos auxiliares
    int buscarCancion(int id_cancion);
    int getCantidadCanciones() const { return cantidad_canciones; }
    string getNombreLista() const { return nombre_lista; }
};

#endif

