#ifndef SISTEMAMUSICAL_H
#define SISTEMAMUSICAL_H


#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "GestorDatos.h"
#include "BaseDatosCancion.h"
using namespace std;

class SistemaMusical {
private:
    GestorDatos* gestor;
    BaseDatosCancion* base;

    void extraerDatosCancion(const string& registro, string& id, string& nombre, string& ruta, string& duracion);
    void buscarAlbumYArtista(const string& id_cancion, string& nombreArtista, string& nombreAlbum, string& rutaAlbum);

public:
    SistemaMusical(GestorDatos* g, BaseDatosCancion* b);
    void mostrarCancion128();
    void mostrarCancion320();
    void reproducirFavoritos();
};

#endif // SISTEMAMUSICAL_H
