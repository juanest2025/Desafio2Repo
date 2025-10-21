#include "Publicidad.h"
#include <iostream>
using namespace std;

Publicidad::Publicidad(int id, string art, string nom, string alb, string msg, char cat)
    : id(id), idArtista(art), nombreArtista(nom), idAlbum(alb), mensaje(msg), categoria(cat) {}

int Publicidad::getId() const { return id; }
char Publicidad::getCategoria() const { return categoria; }
string Publicidad::getMensaje() const { return mensaje; }

int Publicidad::obtenerPrioridad() const {
    switch (categoria) {
    case 'C': return 1;
    case 'B': return 2;
    case 'A': return 3;
    default: return 1;
    }
}

void Publicidad::mostrarInfo() const {
    cout << "Publicidad ID: " << id
         << "\nArtista: " << nombreArtista
         << "\nÁlbum: " << idAlbum
         << "\nCategoría: " << categoria
         << "\nMensaje: " << mensaje << endl;
}
