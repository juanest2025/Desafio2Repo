#ifndef CANCIONES_H
#define CANCIONES_H
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Canciones{
private:
    long long id_cancion;
    string nombre;
    float duracion;
    string ruta128;
    string ruta320;
    string portada;
    int veces_reproducida;

    // Créditos
    string productores;
    string musicos;
    string compositores;

public:
    // Constructores
    Canciones();
    Canciones(long long id, string nom, float dur, string r128, string r320,string port, int rep, string prod, string mus, string comp);

    // Getters
    long long getIdCancion() const;
    string getNombre() const;
    float getDuracion() const;
    string getRuta128() const;
    string getRuta320() const;
    string getPortada() const;
    int getVecesReproducida() const;

    // Setters
    void setVecesReproducida(int n);

    // Mostrar información
    void mostrarDatos() const;

    // Reproducción
    void reproducir(const string& tipoUsuario);
};

#endif // CANCIONES_H

