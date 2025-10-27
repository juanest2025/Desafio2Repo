#ifndef REPRODUCCIONPREMIUM_H
#define REPRODUCCIONPREMIUM_H
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "BaseDatosCancion.h"
#include "GestorDatos.h"
using namespace std;

class ReproduccionPremium {
private:
    BaseDatosCancion* base;
    GestorDatos* gestor;
    int historial[4]; // últimas 4 canciones reproducidas
    int indiceHistorial;
    int actual;
    bool repetir;

    void esperarSegundos(int segundos);
    void mostrarCancion(int indice, bool formato320);

public:
    ReproduccionPremium();
    void enlazarDatos(BaseDatosCancion* b, GestorDatos* g);
    void reproducirAleatoria320();
    void siguiente();
    void anterior();
    void activarRepetir(bool estado);
};

#endif
