#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <iostream>
#include <fstream>
#include <string>
#include "BaseDatosCancion.h"
using namespace std;

class GestorDatos {
private:
    string* albumes;
    string* artistas;
    string* listas;

    int numAlbumes;
    int numArtistas;
    int numListas;

    int capAlbumes;
    int capArtistas;
    int capListas;

    void aumentarCapacidad(string*& arreglo, int& capacidad);

public:
    GestorDatos();
    ~GestorDatos();

    bool cargarAlbum(const char* archivo);
    bool cargarArtista(const char* archivo);
    bool cargarLista(const char* archivo);

    int getNumAlbum() const;
    int getNumArtista() const;
    int getNumLista() const;

    string getAlbum(int i) const;
    string getArtista(int i) const;
    string getLista(int i) const;


};

#endif // GESTORDATOS_H
