#include "Artista.h"

// Constructor
Artista::Artista(int id, string nombre, int edad, string pais, long seguidores, int posicion_global) {
    this->artista_id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->pais = pais;
    this->seguidores = seguidores;
    this->posicion_global = posicion_global;
    this->cantidad_albumes = 0;
    this->capacidad = 3; // capacidad inicial
    this->albumes = new Album*[capacidad];
}

// Destructor
Artista::~Artista() {
    for (int i = 0; i < cantidad_albumes; i++) {
        delete albumes[i];
    }
    delete[] albumes;
}

// Método para redimensionar dinámicamente
void Artista::redimensionar() {
    capacidad *= 2;
    Album** nuevoArreglo = new Album*[capacidad];
    for (int i = 0; i < cantidad_albumes; i++) {
        nuevoArreglo[i] = albumes[i];
    }
    delete[] albumes;
    albumes = nuevoArreglo;
}

// Agregar nuevo álbum
void Artista::agregarAlbum(Album* nuevoAlbum) {
    if (cantidad_albumes >= capacidad) {
        redimensionar();
    }
    albumes[cantidad_albumes++] = nuevoAlbum;
    cout << " Álbum '" << nuevoAlbum->getNombre()
         << "' agregado al artista " << nombre << "." << endl;
}

// Mostrar información general del artista
void Artista::mostrarInfo() const {
    cout << "\n Artista: " << nombre << endl;
    cout << " ID: " << artista_id << endl;
    cout << " Edad: " << edad << endl;
    cout << " País: " << pais << endl;
    cout << " Seguidores: " << seguidores << endl;
    cout << " Posición global: #" << posicion_global << endl;
    cout << " Álbumes registrados: " << cantidad_albumes << endl;
}

// Mostrar los álbumes del artista
void Artista::mostrarAlbumes() const {
    if (cantidad_albumes == 0) {
        cout << " El artista " << nombre << " no tiene álbumes registrados." << endl;
        return;
    }
    cout << "\n Álbumes de " << nombre << ":\n";
    for (int i = 0; i < cantidad_albumes; i++) {
        cout << "  - " << albumes[i]->getNombre()
        << " (" << albumes[i]->getFechaLanzamiento() << ")\n";
    }
}
