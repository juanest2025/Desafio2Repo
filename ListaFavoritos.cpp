#include "ListaFavoritos.h"

//constructor
ListaFavoritos::ListaFavoritos(string nombreLista, string usuarioID) {
    this->nombreLista = nombreLista;
    this->usuarioID = usuarioID;
    this->capacidad = 10;      // Capacidad inicial
    this->cantidad = 0;
    this->canciones = new Cancion*[capacidad];
}

//destructor
ListaFavoritos::~ListaFavoritos() {
    for (int i = 0; i < cantidad; i++) {
        delete canciones[i];   // Liberar cada canción creada dentro de la lista
    }
    delete[] canciones;
}

//redimensiona el arreglo cuando se llena
void ListaFavoritos::redimensionar() {
    if (capacidad >= LIMITE_MAX) return;
    capacidad *= 2;
    if (capacidad > LIMITE_MAX) capacidad = LIMITE_MAX;

    Cancion** nuevo = new Cancion*[capacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = canciones[i];
    }
    delete[] canciones;
    canciones = nuevo;
}

//agregar canción a la lista
void ListaFavoritos::agregarCancion(Cancion* nuevaCancion) {
    if (cantidad >= LIMITE_MAX) {
        cout << " No se pueden agregar más canciones. Límite alcanzado." << endl;
        return;
    }
    if (cantidad >= capacidad) {
        redimensionar();
    }
    // Evitar duplicados
    for (int i = 0; i < cantidad; i++) {
        if (canciones[i]->getIdCancion() == nuevaCancion->getIdCancion()) {
            cout << " La canción ya está en la lista." << endl;
            return;
        }
    }
    canciones[cantidad++] = nuevaCancion;
    cout << " Canción '" << nuevaCancion->getNombre() << "' agregada a la lista '" << nombreLista << "'.\n";
}

//eliminar canción
void ListaFavoritos::eliminarCancion(int id) {
    int pos = buscarCancion(id);
    if (pos == -1) {
        cout << " La canción con ID " << id << " no está en la lista.\n";
        return;
    }
    delete canciones[pos];
    for (int i = pos; i < cantidad - 1; i++) {
        canciones[i] = canciones[i + 1];
    }
    cantidad--;
    cout << " Canción eliminada correctamente.\n";
}

//buscar canción por ID
int ListaFavoritos::buscarCancion(int id) const {
    for (int i = 0; i < cantidad; i++) {
        if (canciones[i]->getIdCancion() == id)
            return i;
    }
    return -1;
}

//mostrar canciones en la lista
void ListaFavoritos::mostrarLista() const {
    cout << "\n Lista: " << nombreLista << " (Usuario: " << usuarioID << ")\n";
    if (cantidad == 0) {
        cout << " No hay canciones en la lista.\n";
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << canciones[i]->getNombre()
        << " - " << canciones[i]->getDuracion() << " min\n";
    }
}

//reproducir canciones con temporizador
void ListaFavoritos::reproducirLista(bool aleatoria) {
    if (cantidad == 0) {
        cout << " La lista está vacía.\n";
        return;
    }

    cout << "\n Reproduciendo lista '" << nombreLista << "'...\n";

    if (aleatoria) {
        srand(time(0));
    }

    for (int i = 0; i < cantidad; i++) {
        int index = aleatoria ? rand() % cantidad : i;
        canciones[index]->reproducir();

        //pausa de 3 segundos entre canciones
        this_thread::sleep_for(chrono::seconds(3));
    }

    cout << "\n Fin de la lista '" << nombreLista << "'.\n";
}

//fusionar con otra lista (premium)
void ListaFavoritos::fusionarListas(ListaFavoritos* otraLista) {
    cout << " Fusionando lista '" << nombreLista
         << "' con '" << otraLista->getNombreLista() << "'...\n";

    for (int i = 0; i < otraLista->getCantidad(); i++) {
        agregarCancion(otraLista->canciones[i]);
    }
    cout << " Fusión completada.\n";
}
