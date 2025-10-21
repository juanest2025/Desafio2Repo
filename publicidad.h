#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H

#include <string>
using namespace std;

class Publicidad {
private:
    int id;
    string idArtista;
    string nombreArtista;
    string idAlbum;
    string mensaje;
    char categoria; // C, B o A

public:
    Publicidad(int id=0, string art="", string nom="", string alb="", string msg="", char cat='C');

    // Getters
    int getId() const;
    char getCategoria() const;
    string getMensaje() const;

    // Métodos
    int obtenerPrioridad() const;
    void mostrarInfo() const;
};

#endif
