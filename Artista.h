#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>
#include <string>
#include "Album.h"
using namespace std;

class Artista {
private:
    int artista_id;
    string nombre;
    int edad;
    string pais;
    long seguidores;
    int posicion_global;

    Album** albumes;     //arreglo dinámico de punteros a álbumes
    int cantidad_albumes;
    int capacidad;        //capacidad máxima actual del arreglo

    void redimensionar(); //método privado para aumentar capacidad

public:

    Artista(int id = 0, string nombre = "", int edad = 0, string pais = "", long seguidores = 0, int posicion_global = 0);
    ~Artista();

    //metodos de gestión
    void agregarAlbum(Album* nuevoAlbum);
    void mostrarInfo() const;
    void mostrarAlbumes() const;

    //getters
    int getId() const { return artista_id; }
    string getNombre() const { return nombre; }
    int getPosicionGlobal() const { return posicion_global; }
    int getCantidadAlbumes() const { return cantidad_albumes; }
    Album** getAlbumes() const { return albumes; }
};


#endif // ARTISTA_H
