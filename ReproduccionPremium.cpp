#include "ReproduccionPremium.h"

ReproduccionPremium::ReproduccionPremium() {
    base = nullptr;
    gestor = nullptr;
    indiceHistorial = 0;
    actual = -1;
    repetir = false;
    srand(time(NULL));
}

void ReproduccionPremium::enlazarDatos(BaseDatosCancion* b, GestorDatos* g) {
    base = b;
    gestor = g;
}

void ReproduccionPremium::esperarSegundos(int segundos) {
    auto inicio = chrono::steady_clock::now();
    while (true) {
        auto ahora = chrono::steady_clock::now();
        auto tiempo = chrono::duration_cast<chrono::seconds>(ahora - inicio);
        if (tiempo.count() >= segundos)
            break;
    }
}

void ReproduccionPremium::mostrarCancion(int indice, bool formato320) {
    string datos = formato320 ? base->getCancion320(indice) : base->getCancion128(indice);

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

    cout << "\nReproduciendo: " << partes[1] << " (" << (formato320 ? "320 kbps" : "128 kbps") << ")\n";
    cout << "Ruta: " << partes[3] << endl;
    cout << "Portada: " << partes[4] << endl;
    esperarSegundos(3);
    cout << "Canción terminada.\n";
}

void ReproduccionPremium::reproducirAleatoria320() {
    if (!base) return;

    int total = base->getNumCanciones();
    if (total == 0) return;

    int indice = rand() % total;
    actual = indice;

    if (indiceHistorial < 4)
        historial[indiceHistorial++] = indice;
    else {
        for (int i = 1; i < 4; i++)
            historial[i - 1] = historial[i];
        historial[3] = indice;
    }

    mostrarCancion(indice, true);
}

void ReproduccionPremium::siguiente() {
    reproducirAleatoria320();
}

void ReproduccionPremium::anterior() {
    if (indiceHistorial <= 1) {
        cout << " No hay canciones anteriores.\n";
        return;
    }
    indiceHistorial--;
    actual = historial[indiceHistorial - 1];
    mostrarCancion(actual, true);
}

void ReproduccionPremium::activarRepetir(bool estado) {
    repetir = estado;
    if (repetir && actual != -1) {
        cout << "Repetición activada.\n";
        while (repetir) {
            mostrarCancion(actual, true);
            cout << "¿Seguir repitiendo? (1=Sí / 0=No): ";
            int opcion;
            cin >> opcion;
            if (opcion == 0) repetir = false;
        }
    } else {
        cout << " Repetición desactivada.\n";
    }
}


