#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H

#include <string>
using namespace std;

class Publicidad {
private:
    string codigo;
    char prioridad;  // C, B, o A
    string mensaje;

public:
    Publicidad(string codigo = "", char prioridad = 'C', string mensaje = "");

    // Getters
    string getCodigo() const;
    char getPrioridad() const;
    string getMensaje() const;

    // Métodos
    int obtenerProbabilidad() const; // C=1, B=2, A=3
    void mostrarInfo() const;
};

#endif
