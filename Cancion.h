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

    //créditos
    string productores;
    string musicos;
    string compositores;

public:
    //constructores
    Canciones();
    Canciones(long long id, string nom, float dur, string r128, string r320,string port, int rep, string prod, string mus, string comp);

    //getters
    long long getIdCancion() const;
    string getNombre() const;
    float getDuracion() const;
    string getRuta128() const;
    string getRuta320() const;
    string getPortada() const;
    int getVecesReproducida() const;

    //setters
    void setVecesReproducida(int n);

    //mostrar información
    void mostrarDatos() const;

    //reproducción
    void reproducir(const string& tipoUsuario);
};

#endif // CANCIONES_H
