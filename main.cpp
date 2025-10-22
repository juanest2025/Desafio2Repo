#include "Plataforma.h"

int main() {
    Plataforma app;
    app.cargarUsuarios("usuarios.txt");
    app.cargarAlbumes("Albumes.txt");
    app.cargarPublicidad("Mensaje_publicidad.txt");
    app.iniciarSesion();
    return 0;
}
