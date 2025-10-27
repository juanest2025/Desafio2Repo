#include "GestorDatos.h"

GestorDatos::GestorDatos() {
    capAlbumes = 10;
    capArtistas = 10;
    capListas = 10;

    numAlbumes = 0;
    numArtistas = 0;
    numListas = 0;

    albumes = new string[capAlbumes];
    artistas = new string[capArtistas];
    listas = new string[capListas];
}

GestorDatos::~GestorDatos() {
    delete[] albumes;
    delete[] artistas;
    delete[] listas;
}

void GestorDatos::aumentarCapacidad(string*& arreglo, int& capacidad) {
    int nuevaCap = capacidad * 2;
    string* nuevo = new string[nuevaCap];
    for (int i = 0; i < capacidad; i++)
        nuevo[i] = arreglo[i];
    delete[] arreglo;
    arreglo = nuevo;
    capacidad = nuevaCap;
}

bool GestorDatos::cargarAlbum(const char* archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir: " << archivo << endl;
        return false;
    }

    string linea;
    getline(file, linea); //saltar encabezado

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        string id, nombre, portada;
        int campo = 0;
        string temp = "";

        for (size_t i = 0; i < linea.length(); i++) {
            if (linea[i] == ';') {
                switch (campo) {
                case 0: id = temp; break;
                case 1: nombre = temp; break;
                case 6: portada = temp; break;
                }
                temp = "";
                campo++;
            } else temp += linea[i];
        }

        if (campo >= 6) portada = temp;

        string registro = id + ";" + nombre + ";" + portada;

        if (numAlbumes >= capAlbumes)
            aumentarCapacidad(albumes, capAlbumes);

        albumes[numAlbumes++] = registro;
    }

    file.close();
    return true;
}

bool GestorDatos::cargarArtista(const char* archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir: " << archivo << endl;
        return false;
    }

    string linea;
    getline(file, linea); //encabezado

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        string id, nombre;
        int campo = 0;
        string temp = "";

        for (size_t i = 0; i < linea.length(); i++) {
            if (linea[i] == ';') {
                if (campo == 0) id = temp;
                else if (campo == 2) nombre = temp;
                temp = "";
                campo++;
            } else temp += linea[i];
        }

        if (campo >= 2) nombre = temp;

        string registro = id + ";" + nombre;

        if (numArtistas >= capArtistas)
            aumentarCapacidad(artistas, capArtistas);

        artistas[numArtistas++] = registro;
    }

    file.close();
    return true;
}

bool GestorDatos::cargarLista(const char* archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir: " << archivo << endl;
        return false;
    }

    string linea;
    getline(file, linea); //encabezado

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        int separadores = 0;
        string ids = "";
        for (size_t i = 0; i < linea.length(); i++) {
            if (linea[i] == ';') separadores++;
            else if (separadores == 2) ids += linea[i];
        }

        if (numListas >= capListas)
            aumentarCapacidad(listas, capListas);

        listas[numListas++] = ids;
    }


    file.close();
    return true;
}

int GestorDatos::getNumAlbum() const
{
    return numAlbumes;
}
int GestorDatos::getNumArtista() const
{
    return numArtistas;
}
int GestorDatos::getNumLista() const
{
    return numListas;
}

string GestorDatos::getAlbum(int i) const
{
    return albumes[i];
}
string GestorDatos::getArtista(int i) const
{
    return artistas[i];
}
string GestorDatos::getLista(int i) const
{
    return listas[i];
}
