#include "Plataforma.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>  // para sleep()
using namespace std;

Plataforma::Plataforma() {
    totalUsuarios = totalAlbumes = totalAnuncios = 0;
    srand(time(NULL));
}

//------------------- carga de archivos 

void Plataforma::cargarUsuarios(const char* ruta) {
    ifstream file(ruta);
    if (!file.is_open()) {
        cout << "Error al abrir " << ruta << endl;
        return;
    }

    char linea[256];
    file.getline(linea, 256); // Encabezado

    while (file.getline(linea, 256)) {
        char id[10], nombre[50], tipo[15], ciudad[30], pais[30], fecha[20];
        sscanf(linea, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;\n]",
               id, nombre, tipo, ciudad, pais, fecha);

        usuarios[totalUsuarios++] = new Usuario(id, nombre, tipo, ciudad, pais, fecha);
    }

    file.close();
}

void Plataforma::cargarAlbumes(const char* ruta) {
    ifstream file(ruta);
    if (!file.is_open()) {
        cout << "Error al abrir " << ruta << endl;
        return;
    }

    char linea[512];
    file.getline(linea, 512);

    while (file.getline(linea, 512)) {
        char id[20], artista[50], nombre[50], generos[60], sello[50], fecha[20], portada[60];
        float duracion, puntuacion;

        sscanf(linea, "%[^;];%[^;];%[^;];%[^;];%f;%[^;];%[^;];%[^;];%f",
               id, artista, nombre, fecha, &duracion, generos, sello, portada, &puntuacion);

        albumes[totalAlbumes++] = new Album(id, artista, nombre, fecha, duracion, generos, sello, portada, puntuacion);
    }

    file.close();
}

void Plataforma::cargarPublicidad(const char* ruta) {
    ifstream file(ruta);
    if (!file.is_open()) {
        cout << "Error al abrir " << ruta << endl;
        return;
    }

    char linea[512];
    file.getline(linea, 512);

    while (file.getline(linea, 512)) {
        char codigo[20], mensaje[500], prioridad;
        sscanf(linea, "%[^;];%c;%[^;\n]", codigo, &prioridad, mensaje);
        anuncios[totalAnuncios++] = new Publicidad(codigo, prioridad, mensaje);
    }

    file.close();
}

// ------------------- mostrar datos 

void Plataforma::mostrarUsuarios() const {
    for (int i = 0; i < totalUsuarios; i++) {
        cout << "------------------------------\n";
        usuarios[i]->mostrarInfo();
    }
}

void Plataforma::mostrarAlbumes() const {
    for (int i = 0; i < totalAlbumes; i++) {
        cout << "------------------------------\n";
        albumes[i]->mostrarInfo();
    }
}

void Plataforma::mostrarPublicidad() const {
    for (int i = 0; i < totalAnuncios; i++) {
        cout << "------------------------------\n";
        anuncios[i]->mostrarInfo();
    }
}

//------------------- sesión 

void Plataforma::iniciarSesion() {
    char nombre[50];
    cout << "\nIngrese su nombre de usuario: ";
    cin >> nombre;

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i]->getNombre(), nombre) == 0) {
            cout << "\n Bienvenido, " << nombre << "!" << endl;
            usuarios[i]->mostrarInfo();
            menuPrincipal(usuarios[i]);
            return;
        }
    }
    cout << "Usuario no encontrado." << endl;
}

//------------------- menú principal 

void Plataforma::menuPrincipal(Usuario* u) {
    int opcion = 0;
    do {
        cout << "\n======= MENU PRINCIPAL =======" << endl;
        cout << "1. Reproducir aleatoriamente" << endl;
        if (u->esPremium())
            cout << "2. Administrar lista de favoritos" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                reproducirAleatorio(u);
                break;
            case 2:
                if (u->esPremium())
                    cout << "\n(Opción de lista de favoritos aún no implementada)\n";
                else
                    cout << "\nSolo disponible para usuarios Premium.\n";
                break;
            case 3:
                cout << "\nSaliendo del sistema..." << endl;
                break;
            default:
                cout << "\nOpción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}

// ------------------- reproducción aleatoria 

void Plataforma::reproducirAleatorio(Usuario* u) {
    cout << "\nReproducción aleatoria iniciada...\n";

    for (int i = 0; i < 5; i++) {
        int idx = rand() % totalAlbumes;
        Album* a = albumes[idx];

        cout << "\Reproduciendo álbum: " << a->getNombre() << endl;
        cout << "Portada: " << a->getPortada() << endl;
        cout << "Duración total: " << a->getDuracion() << " minutos" << endl;

        if (!u->esPremium() && (i % 2 == 1) && totalAnuncios > 0) {
            int ad = rand() % totalAnuncios;
            cout << "\nPUBLICIDAD: " << anuncios[ad]->getMensaje() << endl;
        }

        sleep(3);  // espera 3 segundos entre canciones
    }

    cout << "\Reproducción finalizada después de 5 canciones.\n";
}
