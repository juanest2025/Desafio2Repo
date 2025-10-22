#include <fstream>
#include <sstream>
#include <vector>
#include "Usuario.h"
#include "Album.h"
#include "Publicidad.h"
using namespace std;

void cargarUsuarios() {
    ifstream archivo("usuarios.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nick, tipo, ciudad, fecha;
        getline(ss, nick, ',');
        getline(ss, tipo, ',');
        getline(ss, ciudad, ',');
        getline(ss, fecha, ',');
        Usuario u(nick, tipo, ciudad, fecha);
        u.mostrarInfo();
        cout << endl;
    }
    archivo.close();
}

int main() {
    cout << "=== Prueba de carga de usuarios ===\n";
    cargarUsuarios();
}
