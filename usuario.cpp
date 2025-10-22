#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(string id, string nombre, string tipo, string ciudad, string pais, string fecha)
    : id(id), nombre(nombre), tipo(tipo), ciudad(ciudad), pais(pais), fechaInscripcion(fecha) {}

string Usuario::getId() const { return id; }
string Usuario::getNombre() const { return nombre; }
string Usuario::getTipo() const { return tipo; }
string Usuario::getCiudad() const { return ciudad; }
string Usuario::getPais() const { return pais; }
string Usuario::getFecha() const { return fechaInscripcion; }

bool Usuario::esPremium() const { return tipo == "premium"; }

void Usuario::mostrarInfo() const {
    cout << "ID Usuario: " << id
         << "\nNombre: " << nombre
         << "\nTipo: " << tipo
         << "\nCiudad: " << ciudad
         << "\nPaís: " << pais
         << "\nFecha de inscripción: " << fechaInscripcion << endl;
}
