#include "Publicidad.h"
#include <iostream>
using namespace std;

Publicidad::Publicidad(string codigo, char prioridad, string mensaje)
    : codigo(codigo), prioridad(prioridad), mensaje(mensaje) {}

string Publicidad::getCodigo() const { return codigo; }
char Publicidad::getPrioridad() const { return prioridad; }
string Publicidad::getMensaje() const { return mensaje; }

int Publicidad::obtenerProbabilidad() const {
    switch (prioridad) {
        case 'C': return 1;
        case 'B': return 2;
        case 'AAA': return 3;
        default: return 1;
    }
}

void Publicidad::mostrarInfo() const {
    cout << "Código: " << codigo
         << "\nPrioridad: " << prioridad
         << "\nMensaje: " << mensaje
         << "\nProbabilidad: " << obtenerProbabilidad() << endl;
}
