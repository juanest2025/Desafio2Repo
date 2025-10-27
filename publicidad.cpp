#include "Publicidad.h"

Publicidad::Publicidad() {
    contador = 0;
    srand(time(0)); // inicializa semilla aleatoria
    for (int i = 0; i < 50; i++) {
        mensajes[i] = nullptr;
    }
}

Publicidad::~Publicidad() {
    for (int i = 0; i < contador; ++i) {
        delete[] mensajes[i];
    }
}

int Publicidad::getNumAle(int limite) const {
    return rand() % limite; // número entre 0 y limite-1
}

bool Publicidad::cargarMensajes(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea) && contador < 50) {
        mensajes[contador] = new char[linea.length() + 1];
        for (size_t i = 0; i < linea.length(); i++) {
            mensajes[contador][i] = linea[i];
        }
        mensajes[contador][linea.length()] = '\0';
        contador++;
    }

    archivo.close();
    return true;
}

void Publicidad::mostrarMensajeAleatorio() const {
    if (contador == 0) {
        cout << "No hay mensajes cargados.\n";
        return;
    }

    string mensaje2;
    string prioridad, mensajePros;
    int indice = getNumAle(contador);
    if (indice == 0){
        indice = 1;
        mensaje2 = mensajes[indice];
    }
    else {

         mensaje2 = mensajes[indice];
    }

    stringstream ss(mensaje2);
    getline(ss, prioridad, ';');
    getline(ss, mensajePros, ';');

    cout << "Mensaje #" << indice << endl;
    cout << "Prioridad: " << prioridad << endl;
    cout << "Contenido: " << mensajePros << endl;
}
