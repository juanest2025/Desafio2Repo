#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(string nickname, string tipo, string ciudad, string fechaInscripcion)
    : nickname(nickname), tipo(tipo), ciudad(ciudad), fechaInscripcion(fechaInscripcion) {}

string Usuario::getNickname() const { return nickname; }
string Usuario::getTipo() const { return tipo; }
string Usuario::getCiudad() const { return ciudad; }
string Usuario::getFechaInscripcion() const { return fechaInscripcion; }

void Usuario::setNickname(string n) { nickname = n; }
void Usuario::setTipo(string t) { tipo = t; }
void Usuario::setCiudad(string c) { ciudad = c; }
void Usuario::setFechaInscripcion(string f) { fechaInscripcion = f; }

bool Usuario::esPremium() const { return tipo == "premium"; }

void Usuario::mostrarInfo() const {
    cout << "Usuario: " << nickname
         << "\nTipo: " << tipo
         << "\nCiudad: " << ciudad
         << "\nFecha de inscripción: " << fechaInscripcion << endl;
}
