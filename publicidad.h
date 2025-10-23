#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H

#include <string>
using namespace std;

class Publicidad {
private:
    string codigo;
    char prioridad;  //C,B,A
    string mensaje;

public:
    Publicidad(string codigo = "", char prioridad = 'C', string mensaje = "");

    //getters
    string getCodigo() const;
    char getPrioridad() const;
    string getMensaje() const;

    //metodos
    int obtenerProbabilidad() const; //C=1,B=2,AAA=3
    void mostrarInfo() const;
};

#endif
