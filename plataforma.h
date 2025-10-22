#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Usuario.h"
#include "Album.h"
#include "Publicidad.h"
#include <string>
using namespace std;

class Plataforma {
private:
    Usuario* usuarios[100];       // Lista de usuarios
    Album* albumes[100];          // Lista de álbumes
    Publicidad* anuncios[50];     // Lista de publicidades
    int totalUsuarios;
    int totalAlbumes;
    int totalAnuncios;

public:
    Plataforma();

    // Métodos principales
    void cargarUsuarios(const string& ruta);
    void cargarAlbumes(const string& ruta);
    void cargarPublicidad(const string& ruta);

    void mostrarUsuarios() const;
    void mostrarAlbumes() const;
    void mostrarPublicidad() const;

    void iniciarSesion();
};

#endif
