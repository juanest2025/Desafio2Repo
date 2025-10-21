#include "Album.h"
#include <iostream>
using namespace std;

Album::Album(string c, string ca, string n, string g, string f, int d, string s, float p, string pt)
    : codigo(c), codigoArtista(ca), nombre(n), generos(g), fechaLanzamiento(f),
    duracionTotalSegundos(d), sello(s), puntuacion(p), portada(pt) {}

string Album::getCodigo() const { return codigo; }
string Album::getNombre() const { return nombre; }
string Album::getGeneros() const { return generos; }
string Album::getPortada() const { return portada; }
float Album::getPuntuacion() const { return puntuacion; }

void Album::mostrarInfo() const {
    cout << "Álbum: " << nombre
         << "\nGéneros: " << generos
         << "\nSello: " << sello
         << "\nDuración total: " << duracionTotalSegundos << " s"
         << "\nPuntuación: " << puntuacion
         << "\nPortada: " << portada << endl;
}
