#include <iostream>
#include "Plataforma.h"
using namespace std;

int main() {
    Plataforma app;

    cout << "=============================================\n";
    cout << "        🎵 Bienvenido a UdeAtunes🎵         \n";
    cout << "=============================================\n";

    //---cargar los datos---
    cout << "\nCargando datos...\n";
    app.cargarUsuarios("usuarios.txt");
    app.cargarArtistas("artistas.txt");
    app.cargarAlbumes("albumes.txt");
    app.cargarCanciones("canciones.txt");
    app.cargarPublicidad("publicidad.txt");

    cout << "Datos cargados correctamente ✅\n";

    //---iniciar sesión---
    app.iniciarSesion();

    //---medir recursos(opcional)---
    cout << "\nFinalizando ejecución...\n";
    cout << "Liberando memoria y cerrando plataforma.\n";

    return 0;
}
