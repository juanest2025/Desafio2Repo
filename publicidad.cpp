#include "Publicidad.h"

Publicidad::Publicidad() {
    contador = 0;
    srand(time(0)); //inicializa semilla aleatoria
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
    return rand() % limite; //número entre 0 y limite-1
}

bool Publicidad::cargarMensajes(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return false;
    }

    string linea;
    bool primeraLinea = true; //para saltar encabezado
    while (getline(archivo, linea) && contador < 50) {
        if (primeraLinea) { //omitir encabezado
            primeraLinea = false;
            continue;
        }

        //ignorar líneas vacías
        if (linea.size() < 3) continue;

        //guardar línea completa
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

    int indice = getNumAle(contador);
    string mensaje2 = mensajes[indice];

    //separar prioridad y mensaje
    string prioridad = "", mensajePros = "";
    bool antesDelPuntoYComa = true;
    for (int i = 0; mensaje2[i] != '\0'; i++) {
        if (mensaje2[i] == ';') {
            antesDelPuntoYComa = false;
            continue;
        }
        if (antesDelPuntoYComa)
            prioridad += mensaje2[i];
        else
            mensajePros += mensaje2[i];
    }

    cout << "\n [PUBLICIDAD - Prioridad " << prioridad << "]\n";
    cout << mensajePros << endl;
}
