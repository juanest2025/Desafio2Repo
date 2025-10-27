#ifndef REPRODUCCIONESTANDAR_H
#define REPRODUCCIONESTANDAR_H

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "BaseDatosCancion.h"
#include "GestorDatos.h"
using namespace std;

class ReproduccionEstandar {
private:
    BaseDatosCancion* base;
    GestorDatos* gestor;

    void esperarSegundos(int segundos); //simulador reproducción

public:
    ReproduccionEstandar();
    void enlazarDatos(BaseDatosCancion* b, GestorDatos* g);
    void reproducirAleatoria128(); // solo formato 128
};

#endif
