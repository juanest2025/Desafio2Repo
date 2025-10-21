#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
private:
    string nickname;
    string tipo; // "estandar" o "premium"
    string ciudad;
    string fechaInscripcion;

public:
    // Constructor
    Usuario(string nickname="", string tipo="", string ciudad="", string fechaInscripcion="");

    // Getters
    string getNickname() const;
    string getTipo() const;
    string getCiudad() const;
    string getFechaInscripcion() const;

    // Setters
    void setNickname(string n);
    void setTipo(string t);
    void setCiudad(string c);
    void setFechaInscripcion(string f);

    // Métodos adicionales
    bool esPremium() const;
    void mostrarInfo() const;
};

#endif
