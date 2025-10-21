#ifndef ALBUM_H
#define ALBUM_H

#include <string>
using namespace std;

class Album {
private:
    string codigo;
    string codigoArtista;
    string nombre;
    string generos;
    string fechaLanzamiento;
    int duracionTotalSegundos;
    string sello;
    float puntuacion;
    string portada;

public:
    Album(string c="", string ca="", string n="", string g="", string f="", int d=0, string s="", float p=0, string pt="");

    // Getters
    string getCodigo() const;
    string getNombre() const;
    string getGeneros() const;
    string getPortada() const;
    float getPuntuacion() const;

    // Métodos
    void mostrarInfo() const;
};

#endif
