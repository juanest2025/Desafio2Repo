#include "Plataforma.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

Plataforma::Plataforma() {
    numUsuarios = numArtistas = numAlbumes = numCanciones = numAnuncios = 0;
    usuarioActual = nullptr;
    listaFavoritosActual = nullptr;
    srand(time(0));
}

//--------------------carga de datos--------------------
void Plataforma::cargarUsuarios(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir " << nombreArchivo << endl;
        return;
    }

    string id, nombre, tipo, ciudad, pais, fecha;
    while (getline(archivo, id, ';')) {
        getline(archivo, nombre, ';');
        getline(archivo, tipo, ';');
        getline(archivo, ciudad, ';');
        getline(archivo, pais, ';');
        getline(archivo, fecha);
        usuarios[numUsuarios++] = new Usuario(id, nombre, tipo, ciudad, pais, fecha);
    }
    archivo.close();
}

void Plataforma::cargarArtistas(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id, edad, pos;
        string nombre, pais;
        long seguidores;

        ss >> id; ss.ignore();
        getline(ss, nombre, ';');
        ss >> edad; ss.ignore();
        getline(ss, pais, ';');
        ss >> seguidores; ss.ignore();
        ss >> pos;

        artistas[numArtistas++] = new Artista(id, nombre, edad, pais, seguidores, pos);
    }
    archivo.close();
}

void Plataforma::cargarAlbumes(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    string id, artistaId, nombre, fecha, generos, sello, portada;
    float duracion, puntuacion;

    while (getline(archivo, id, ';')) {
        getline(archivo, artistaId, ';');
        getline(archivo, nombre, ';');
        getline(archivo, fecha, ';');
        archivo >> duracion; archivo.ignore();
        getline(archivo, generos, ';');
        getline(archivo, sello, ';');
        getline(archivo, portada, ';');
        archivo >> puntuacion;
        archivo.ignore();

        albumes[numAlbumes++] = new Album(id, artistaId, nombre, fecha, duracion, generos, sello, portada, puntuacion);
    }
    archivo.close();
}

void Plataforma::cargarCanciones(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id, reproducciones;
        float duracion;
        string nombre, ruta128, ruta320, portada, productor, musico, compositor;

        ss >> id; ss.ignore();
        getline(ss, nombre, ';');
        ss >> duracion; ss.ignore();
        getline(ss, ruta128, ';');
        getline(ss, ruta320, ';');
        getline(ss, portada, ';');
        ss >> reproducciones; ss.ignore();
        getline(ss, productor, ';');
        getline(ss, musico, ';');
        getline(ss, compositor);

        canciones[numCanciones++] = new Cancion(id, nombre, duracion, ruta128, ruta320, portada, reproducciones, productor, musico, compositor);
    }
    archivo.close();
}

void Plataforma::cargarPublicidad(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    string codigo, mensaje; char prioridad;
    while (getline(archivo, codigo, ';')) {
        archivo >> prioridad; archivo.ignore();
        getline(archivo, mensaje);
        anuncios[numAnuncios++] = new Publicidad(codigo, prioridad, mensaje);
    }
    archivo.close();
}

//--------------------inicio de sesión--------------------
void Plataforma::iniciarSesion() {
    string id;
    cout << "\n--- INICIO DE SESIÓN ---\n";
    cout << "Ingrese su ID de usuario: ";
    cin >> id;

    usuarioActual = buscarUsuarioPorId(id);
    if (!usuarioActual) {
        cout << "Usuario no encontrado.\n";
        return;
    }

    cout << "Bienvenido, " << usuarioActual->getNombre() 
         << " (" << usuarioActual->getTipo() << ")\n";

    //crear lista de favoritos para el usuario actual
    listaFavoritosActual = new ListaFavoritos(
        usuarioActual->getId(),
        "Favoritos",
        usuarioActual->esPremium()
    );

    mostrarMenu();
}

// --------------------menú principal--------------------
void Plataforma::mostrarMenu() {
    if (!usuarioActual) return;

    int opcion;
    do {
        cout << "\n--- MENÚ PRINCIPAL ---\n";
        cout << "1. Reproducir canción aleatoria\n";
        cout << "2. Administrar lista de favoritos\n";
        cout << "3. Mostrar anuncio\n";
        cout << "4. Ver perfil\n";
        cout << "0. Cerrar sesión\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: reproducirCancionAleatoria(); break;
            case 2: gestionarFavoritos(); break;
            case 3: mostrarAnuncio(); break;
            case 4: usuarioActual->mostrarInfo(); break;
            case 0: cout << "Sesión finalizada.\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

// --------------------funciones de control--------------------
void Plataforma::reproducirCancionAleatoria() {
    if (numCanciones == 0) {
        cout << "No hay canciones disponibles.\n";
        return;
    }

    int indice = rand() % numCanciones;
    Cancion* c = canciones[indice];

    c->reproducir(usuarioActual->esPremium() ? "premium" : "gratis");

    if (!usuarioActual->esPremium()) {
        mostrarAnuncio();
    }
}

void Plataforma::mostrarAnuncio() {
    if (numAnuncios == 0) return;

    int idx = rand() % numAnuncios;
    cout << "\n--- PUBLICIDAD ---\n";
    anuncios[idx]->mostrarInfo();
    cout << "-------------------\n";
}

void Plataforma::gestionarFavoritos() {
    if (!listaFavoritosActual) return;

    int opcion;
    do {
        cout << "\n--- GESTIONAR FAVORITOS ---\n";
        cout << "1. Agregar canción\n";
        cout << "2. Eliminar canción\n";
        cout << "3. Ver lista\n";
        cout << "4. Reproducir lista\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                cout << "ID de canción: ";
                cin >> id;
                if (buscarCancionPorId(id))
                    listaFavoritosActual->agregarCancion(id);
                else
                    cout << "No se encontró la canción.\n";
                break;
            }
            case 2: {
                int id;
                cout << "ID de canción a eliminar: ";
                cin >> id;
                listaFavoritosActual->eliminarCancion(id);
                break;
            }
            case 3:
                listaFavoritosActual->mostrarLista();
                break;
            case 4:
                listaFavoritosActual->reproducirLista(
                    *canciones, numCanciones
                );
                break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

// --------------------utilidades--------------------
Usuario* Plataforma::buscarUsuarioPorId(const string& id) {
    for (int i = 0; i < numUsuarios; i++)
        if (usuarios[i]->getId() == id) return usuarios[i];
    return nullptr;
}

Cancion* Plataforma::buscarCancionPorId(int id) {
    for (int i = 0; i < numCanciones; i++)
        if (canciones[i]->getIdCancion() == id) return canciones[i];
    return nullptr;
}

// --------------------destructor--------------------
Plataforma::~Plataforma() {
    for (int i = 0; i < numUsuarios; i++) delete usuarios[i];
    for (int i = 0; i < numArtistas; i++) delete artistas[i];
    for (int i = 0; i < numAlbumes; i++) delete albumes[i];
    for (int i = 0; i < numCanciones; i++) delete canciones[i];
    for (int i = 0; i < numAnuncios; i++) delete anuncios[i];
    delete listaFavoritosActual;
}
