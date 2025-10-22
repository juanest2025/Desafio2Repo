#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
private:
    string id;
    string nombre;
    string tipo;   //premium o estandar
    string ciudad;
    string pais;
    string fechaInscripcion;

public:
    Usuario(string id = "", string nombre = "", string tipo = "",
            string ciudad = "", string pais = "", string fecha = "");

    // Getters
    string getId() const;
    string getNombre() const;
    string getTipo() const;
    string getCiudad() const;
    string getPais() const;
    string getFecha() const;

    // Métodos
    bool esPremium() const;
    void mostrarInfo() const;
};

#endif
