#include "Canciones.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

// Constructor por defecto
Cancion::Cancion() {
    id_cancion = 0;
    nombre = "";
    duracion = 0.0;
    ruta128 = "";
    ruta320 = "";
    portada = "";
    veces_reproducida = 0;
    productores = "";
    musicos = "";
    compositores = "";
}

// Constructor con parámetros
Cancion::Cancion(long long id, string nom, float dur, string r128, string r320,string port, int rep, string prod, string mus, string comp) {
    id_cancion = id;
    nombre = nom;
    duracion = dur;
    ruta128 = r128;
    ruta320 = r320;
    portada = port;
    veces_reproducida = rep;
    productores = prod;
    musicos = mus;
    compositores = comp;
}

// Getters
long long Cancion::getIdCancion() const { return id_cancion; }
string Cancion::getNombre() const { return nombre; }
float Cancion::getDuracion() const { return duracion; }
string Cancion::getRuta128() const { return ruta128; }
string Cancion::getRuta320() const { return ruta320; }
string Cancion::getPortada() const { return portada; }
int Cancion::getVecesReproducida() const { return veces_reproducida; }

// Setter
void Cancion::setVecesReproducida(int n) { veces_reproducida = n; }

// Mostrar datos
void Cancion::mostrarDatos() const {
    cout << "ID: " << id_cancion << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Duración: " << duracion << " min" << endl;
    cout << "Ruta 128 kbps: " << ruta128 << endl;
    cout << "Ruta 320 kbps: " << ruta320 << endl;
    cout << "Portada: " << portada << endl;
    cout << "Veces reproducida: " << veces_reproducida << endl;
    cout << "Productores: " << productores << endl;
    cout << "Músicos: " << musicos << endl;
    cout << "Compositores: " << compositores << endl;
}

// Reproducir canción
void Cancion::reproducir(const string& tipoUsuario) {
    cout << "\n Reproduciendo: " << nombre << endl;
    cout << "Portada: " << portada << endl;

    if (tipoUsuario == "premium") {
        cout << "Ruta de audio (alta calidad): " << ruta320 << endl;
    } else {
        cout << "Ruta de audio (calidad estándar): " << ruta128 << endl;
    }

    cout << " Reproduciendo... (3 segundos)" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    veces_reproducida++;
    cout << " Canción terminada: " << nombre << " | Total reproducciones: "<< veces_reproducida << endl;
}
