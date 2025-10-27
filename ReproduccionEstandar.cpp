#include "ReproduccionEstandar.h"

ReproduccionEstandar::ReproduccionEstandar() {
    base = nullptr;
    gestor = nullptr;
    srand(time(NULL));
}

void ReproduccionEstandar::enlazarDatos(BaseDatosCancion* b, GestorDatos* g) {
    base = b;
    gestor = g;
}

void ReproduccionEstandar::esperarSegundos(int segundos) {
    auto inicio = chrono::steady_clock::now();
    while (true) {
        auto ahora = chrono::steady_clock::now();
        auto tiempo = chrono::duration_cast<chrono::seconds>(ahora - inicio);
        if (tiempo.count() >= segundos)
            break;
    }
}

void ReproduccionEstandar::reproducirAleatoria128() {
    if (!base || !gestor) {
        cout << "⚠️ Bases de datos no enlazadas.\n";
        return;
    }

    int total = base->getNumCanciones();
    if (total == 0) {
        cout << "⚠️ No hay canciones disponibles.\n";
        return;
    }

    int indice = rand() % total;
    string datos = base->getCancion128(indice);

    // separar los campos manualmente
    string partes[5];
    string temp = "";
    int campo = 0;

    for (int i = 0; i < (int)datos.length(); i++) {
        if (datos[i] == ';') {
            partes[campo++] = temp;
            temp = "";
        } else temp += datos[i];
    }
    partes[campo] = temp;

    string idCancion = partes[0];
    string titulo = partes[1];
    string duracion = partes[2];
    string ruta = partes[3];
    string portada = partes[4];

    // Mostrar datos
    cout << "\n🎵 Reproduciendo canción aleatoria (128 kbps):\n";
    cout << "Título: " << titulo << endl;
    cout << "Duración: " << duracion << endl;
    cout << "Ruta audio: " << ruta << endl;
    cout << "Portada: " << portada << endl;

    cout << "\nReproduciendo...";
    esperarSegundos(3);
    cout << "\n✅ Canción terminada.\n";
}
