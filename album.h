#ifndef ALBUM_H
#define ALBUM_H

#include <string>
using namespace std;

class Album {
private:
    string id;
    string artistaId;
    string nombre;
    string fechaLanzamiento;
    float duracionTotal;
    string generos;
    string sello;
    string portada;
    float puntuacion;

public:
    Album(string id = "", string artistaId = "", string nombre = "",
          string fecha = "", float duracion = 0.0,
          string generos = "", string sello = "",
          string portada = "", float puntuacion = 0.0);

    //getters
    string getId() const;
    string getArtistaId() const;
    string getNombre() const;
    string getGeneros() const;
    string getPortada() const;
    float getDuracion() const;
    float getPuntuacion() const;

    void mostrarInfo() const;
};

#endif
