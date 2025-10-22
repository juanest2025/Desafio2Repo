#include "Album.h"
#include <iostream>
using namespace std;

Album::Album(string id, string artistaId, string nombre,
             string fecha, float duracion,
             string generos, string sello,
             string portada, float puntuacion)
    : id(id), artistaId(artistaId), nombre(nombre),
      fechaLanzamiento(fecha), duracionTotal(duracion),
      generos(generos), sello(sello),
      portada(portada), puntuacion(puntuacion) {}

string Album::getId() const { return id; }
string Album::getArtistaId() const { return artistaId; }
string Album::getNombre() const { return nombre; }
string Album::getGeneros() const { return generos; }
string Album::getPortada() const { return portada; }
float Album::getDuracion() const { return duracionTotal; }
float Album::getPuntuacion() const { return puntuacion; }

void Album::mostrarInfo() const {
    cout << "Álbum: " << nombre
         << "\nID: " << id
         << "\nArtista ID: " << artistaId
         << "\nFecha de lanzamiento: " << fechaLanzamiento
         << "\nDuración: " << duracionTotal << " min"
         << "\nGéneros: " << generos
         << "\nSello: " << sello
         << "\nPuntuación: " << puntuacion
         << "\nPortada: " << portada << endl;
}
