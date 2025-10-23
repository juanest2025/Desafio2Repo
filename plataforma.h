#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <string>
#include "Usuario.h"
#include "Artista.h"
#include "Album.h"
#include "Cancion.h"
#include "ListaFavoritos.h"
#include "Publicidad.h"
using namespace std;

class Plataforma {
private:
    Usuario* usuarios[100];
    int numUsuarios;

    Artista* artistas[100];
    int numArtistas;

    Album* albumes[200];
    int numAlbumes;

    Cancion* canciones[500];
    int numCanciones;

    Publicidad* anuncios[50];
    int numAnuncios;

    Usuario* usuarioActual;  //usuario logueado
    ListaFavoritos* listaFavoritosActual; //lista de favoritos del usuario actual

public:
    Plataforma();

    //---carga de datos---
    void cargarUsuarios(const string& nombreArchivo);
    void cargarArtistas(const string& nombreArchivo);
    void cargarAlbumes(const string& nombreArchivo);
    void cargarCanciones(const string& nombreArchivo);
    void cargarPublicidad(const string& nombreArchivo);

    //---sistema de usuario---
    void iniciarSesion();
    void mostrarMenu();

    // ---funciones de control---
    void reproducirCancionAleatoria();
    void mostrarAnuncio();
    void gestionarFavoritos();

    //---utilidades---
    Usuario* buscarUsuarioPorId(const string& id);
    Cancion* buscarCancionPorId(int id);

    //---destructor---
    ~Plataforma();
};

#endif
