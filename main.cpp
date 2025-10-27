
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
/*
int main() {
    const int MAX_LONG = 2048;  // mayor longitud por línea
    int numLineas = 0;
    char **lineas = nullptr;    // arreglo dinámico de líneas
    const char *filename = "canciones2.csv";

    // 1️⃣ Contar líneas en el archivo
    ifstream entradaCont(filename);
    if (!entradaCont) {
        cout << "Error al abrir el archivo para conteo: " << filename << "\n";
        return 1;
    }

    char buffer[MAX_LONG];
    while (entradaCont.getline(buffer, MAX_LONG)) {
        numLineas++;
    }
    entradaCont.close();

    if (numLineas == 0) {
        cout << "El archivo está vacío o no se leyó ninguna línea.\n";
        return 1;
    }

    cout << "Líneas encontradas: " << numLineas << "\n";

    // 2️⃣ Reservar memoria dinámica
    lineas = new char*[numLineas];
    for (int i = 0; i < numLineas; i++) {
        lineas[i] = new char[MAX_LONG];
        lineas[i][0] = '\0'; // inicializar
    }

    // 3️⃣ Volver a leer las líneas (usar otro ifstream para claridad)
    ifstream entrada(filename);

    int indice = 0;
    while (indice < numLineas && entrada.getline(lineas[indice], MAX_LONG)) {
        indice++;
    }
    entrada.close();

    // 4️⃣ Pedir ID y nuevo valor
    char idBuscado[9];
    cout << "Ingrese el ID de la canción a modificar: ";
    cin >> idBuscado;

    int incremento;
    cout << "Ingrese en cuánto aumentar las reproducciones: ";
    cin >> incremento;

    bool encontrado = false;

    // 5️⃣ Buscar y modificar el campo "veces_reproducida"
    for (int i = 0; i < numLineas; i++) {
        // Saltar encabezado
        if (i == 0 && strstr(lineas[i], "id_cancion") != nullptr)
            continue;

        // Obtener el ID hasta el primer ';'
        char idLinea[32];
        int j = 0;
        while (lineas[i][j] != ';' && lineas[i][j] != '\0' && j < (int)sizeof(idLinea)-1) {
            idLinea[j] = lineas[i][j];
            j++;
        }
        idLinea[j] = '\0';

        // Comparar con el ID buscado
        if (strcmp(idLinea, idBuscado) == 0) {
            encontrado = true;

            // Buscar el campo 7 (veces_reproducida): contamos separadores ';'
            int campo = 0, inicio = -1, fin = -1;
            for (int k = 0; lineas[i][k] != '\0'; k++) {
                if (lineas[i][k] == ';') {
                    campo++;
                    if (campo == 6) inicio = k + 1; // empieza el campo (después del separador)
                    else if (campo == 7) { fin = k; break; } // termina el campo
                }
            }
            // Si fin == -1 significa que el campo 7 es hasta el final de línea
            if (inicio != -1 && fin == -1) fin = (int)strlen(lineas[i]);

            if (inicio == -1 || fin <= inicio) {
                cout << "No se pudo localizar correctamente el campo 'veces_reproducida' en la línea.\n";
                break;
            }

            // Extraer el número actual
            char numeroStr[32];
            int pos = 0;
            for (int k = inicio; k < fin && lineas[i][k] != '\0' && pos < (int)sizeof(numeroStr)-1; k++)
                numeroStr[pos++] = lineas[i][k];
            numeroStr[pos] = '\0';

            int valor = atoi(numeroStr);
            valor += incremento;

            // Construir nueva línea: parte antes de inicio + nuevo valor + resto desde fin
            char nuevaLinea[MAX_LONG];
            // copia la parte antes del campo
            if (inicio > 0) {
                strncpy(nuevaLinea, lineas[i], inicio);
                nuevaLinea[inicio] = '\0';
            } else {
                nuevaLinea[0] = '\0';
            }

            // nuevo valor y resto
            char nuevoValor[32];
            sprintf(nuevoValor, "%d", valor);
            strcat(nuevaLinea, nuevoValor);

            // añadir el resto (desde fin hasta final)
            strcat(nuevaLinea, lineas[i] + fin);

            // Reemplazar línea modificada
            strncpy(lineas[i], nuevaLinea, MAX_LONG-1);
            lineas[i][MAX_LONG-1] = '\0';

            cout << "Canción con ID " << idBuscado << " actualizada a " << valor << " reproducciones.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró el ID indicado.\n";
    } else {
        // 6️⃣ Reescribir el archivo completo
        ofstream salida(filename);
        if (!salida) {
            cout << "Error al abrir el archivo para escribir: " << filename << "\n";
        } else {
            for (int i = 0; i < numLineas; i++) {
                salida << lineas[i] << "\n";
            }
            salida.close();
            cout << "Archivo sobrescrito correctamente.\n";
        }
    }

    // 7️⃣ Liberar memoria
    for (int i = 0; i < numLineas; i++)
        delete[] lineas[i];
    delete[] lineas;

    return 0;
}
*/

/*
#include "Publicidad.h"

int main() {
    Publicidad pub;

    if (pub.cargarMensajes("Publicidad_mensaje.csv")) {
        pub.mostrarMensajeAleatorio();
    }

    return 0;
}*/

//actualizaciones

/*
#include <iostream>
#include "ActualizacionDatos.h"
using namespace std;

int main() {
    ActualizacionDatos datos("canciones2.csv");

    if (!datos.cargarArchivo()) {
        cout << "No se pudo cargar el archivo.\n";
        return 1;
    }

    char idBuscado[10];
    cout << "Ingrese ID de canción: ";
    cin >> idBuscado;

    int incremento;
    cout << "Ingrese incremento de reproducciones: ";
    cin >> incremento;

    if (datos.actualizarReproducciones(idBuscado, incremento)) {
        if (datos.guardarArchivo())
            cout << "Archivo actualizado correctamente.\n";
        else
            cout << "Error al guardar archivo.\n";
    } else {
        cout << "ID no encontrado.\n";
    }

    return 0;
}
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "BaseDatosCancion.h"
#include "GestorDatos.h"
#include "ReproduccionEstandar.h"
#include "ReproduccionPremium.h"
using namespace std;

// --- Función para mostrar un anuncio aleatorio ---
void mostrarAnuncio() {
    const char* anuncios[5] = {
        "¡Suscríbete a UdeATunes Premium y escucha sin anuncios!",
        "Mejora tu experiencia musical con UdeATunes Premium.",
        "Escucha tus canciones favoritas en 320 kbps.",
        "Sin interrupciones, solo buena música. UdeATunes Premium.",
        "Miles de artistas te esperan en UdeATunes Premium."
    };
    int indice = rand() % 5;
    cout << "\n [ANUNCIO]: " << anuncios[indice] << endl;
}

int main() {
    srand(time(NULL));
    ifstream archivo("Usuarios.csv");
    if (!archivo.is_open()) {
        cout << " No se pudo abrir Usuarios.csv\n";
        return 1;
    }

    string linea, idIngresado, nombre;
    bool encontrado = false, esPremium = false;

    cout << "---------------------------------------\n";
    cout << "          LOGIN UdeATunes \n";
    cout << "---------------------------------------\n";
    cout << "Ingrese su ID de usuario: ";
    cin >> idIngresado;

    //-------buscar usuario
    while (getline(archivo, linea)) {
        if (linea.find(idIngresado) == 0) {
            encontrado = true;
            string usuario_id, tipo, ciudad, pais, fecha;
            int campo = 0; string temp = "";

            for (int i = 0; i < linea.size(); i++) {
                char c = linea[i];
                if (c == ';' || i == linea.size() - 1) {
                    if (i == linea.size() - 1) temp += c;
                    switch (campo) {
                    case 0: usuario_id = temp; break;
                    case 1: nombre = temp; break;
                    case 2: tipo = temp; break;
                    case 3: ciudad = temp; break;
                    case 4: pais = temp; break;
                    case 5: fecha = temp; break;
                    }
                    campo++;
                    temp = "";
                } else temp += c;
            }

            cout << "\n Usuario encontrado:\n";
            cout << "ID: " << usuario_id << "\nNombre: " << nombre;
            cout << "\nCiudad: " << ciudad << "\nPaís: " << pais;
            cout << "\nFecha inscripción: " << fecha << endl;

            if (tipo == "true") {
                esPremium = true;
                cout << "\n Tipo de usuario: PREMIUM\n";
            } else {
                esPremium = false;
                cout << "\n Tipo de usuario: ESTÁNDAR\n";
            }
            break;
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "\n El ID ingresado no existe en la base de datos.\n";
        return 0;
    }

    //-----cargar datos base
    BaseDatosCancion base("Canciones.csv");
    if (!base.cargarCSV()) {
        cout << " Error al cargar Canciones.csv\n";
        return 1;
    }
    GestorDatos gestor;
    gestor.cargarAlbumes("Albumes.csv");
    gestor.cargarArtistas("Artistas.csv");

    int opcion = -1;
    int contadorCanciones = 0;

    //----------menu usuario estandar
    if (!esPremium) {
        ReproduccionEstandar repEstandar;
        repEstandar.enlazarDatos(&base, &gestor);

        while (opcion != 0) {
            cout << "\n--------menu estándar -------\n";
            cout << "Hola, " << nombre << "!\n";
            cout << "1. Reproducción aleatoria (128 kbps)\n";
            cout << "0. Salir\n";
            cout << "--------------------------------\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;

            if (opcion == 1) {
                contadorCanciones++;
                repEstandar.reproducirAleatoria128();

                // Cada 2 canciones -> anuncio
                if (contadorCanciones % 2 == 0) {
                    mostrarAnuncio();
                }
            } else if (opcion != 0) {
                cout << "\nOpción no válida.\n";
            }
        }
    }

    //--------------menu usuario premium
    else {
        ReproduccionPremium repPremium;
        repPremium.enlazarDatos(&base, &gestor);

        while (opcion != 0) {
            cout << "\n---------menu premium ------------\n";
            cout << "Hola, " << nombre << "!\n";
            cout << "1. Reproducción aleatoria (320 kbps)\n";
            cout << "2. Siguiente canción\n";
            cout << "3. Canción anterior\n";
            cout << "4. Repetir canción\n";
            cout << "0. Salir\n";
            cout << "-----------------------------\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;

            if (opcion == 1)
                repPremium.reproducirAleatoria320();
            else if (opcion == 2)
                repPremium.siguiente();
            else if (opcion == 3)
                repPremium.anterior();
            else if (opcion == 4)
                repPremium.activarRepetir(true);
            else if (opcion != 0)
                cout << "\nOpción no válida.\n";
        }
    }

    cout << "\n Gracias por usar UdeATunes.\n";
    return 0;
}



