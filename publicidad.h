#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Publicidad {
private:
    char* mensajes[50];   // arreglo de punteros a char
    int contador;          // cantidad de mensajes cargados

public:
    Publicidad();          // constructor
    ~Publicidad();         // destructor

    bool cargarMensajes(const string& nombreArchivo);
    void mostrarMensajeAleatorio() const;
    int getNumAle(int limite) const;
};

#endif // PUBLICIDAD_H
