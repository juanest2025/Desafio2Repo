#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "BaseDatosCancion.h"
#include "GestorDatos.h"
#include "ReproduccionEstandar.h"
#include "ReproduccionPremium.h"
#include "Publicidad.h"
#include "ListaFavoritos.h"
using namespace std;

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
    gestor.cargarAlbum("Album.csv");
    gestor.cargarArtista("Artista.csv");

    int opcion = -1;
    int contadorCanciones = 0;

    //----------menu usuario estandar
    if (!esPremium) {
        ReproduccionEstandar repEstandar;
        repEstandar.enlazarDatos(&base, &gestor);

        while (opcion != 0) {
            cout << "\n--------menu estandar -------\n";
            cout << "Hola, " << nombre << "!\n";
            cout << "1. Reproducción aleatoria (128 kbps)\n";
            cout << "0. Salir\n";
            cout << "--------------------------------\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;

            if (opcion == 1) {
                contadorCanciones++;
                repEstandar.reproducirAleatoria128();

                //cada 2 canciones anuncio
                if (contadorCanciones % 2 == 0) {
                    cout << "\n--- publicidad ---\n";
                    Publicidad pup;
                    pup.cargarMensajes("Publicidad.csv");
                    pup.mostrarMensajeAleatorio();
                    cout << "------------------\n";
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
            cout << "5. Lista de favoritos\n";
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
            else if (opcion == 5) {
                //lista favoritos
                int subopcion = -1;
                while (subopcion != 0) {
                    cout << "\n-----lista de favoritos -----\n";
                    cout << "1. Actualizar/editar mi lista\n";
                    cout << "2. Seguir lista de otro usuario Premium\n";
                    cout << "3. Ejecutar mi lista\n";
                    cout << "0. Volver al menú anterior\n";
                    cout << "------------------------------\n";
                    cout << "Seleccione una opción: ";
                    cin >> subopcion;

                    switch (subopcion) {
                    case 1: {
                        cout << "\n---actualizar lista---\n";

                        ListaFavoritos listaFav("ListaFavoritos.csv");
                        if (!listaFav.cargarArchivo()) {
                            cout << "Error al abrir ListaFavoritos.csv\n";
                            break;
                        }

                        //mostrar la lista actual
                        cout << "\nTu lista actual:\n";
                        listaFav.mostrarLista(idIngresado);

                        //pedir canciones nuevas
                        cout << "\nIngrese los IDs de las canciones que desea agregar separados por coma (ej: C001,C002,C003)\n";
                        cout << "O presione ENTER para no agregar ninguna: ";

                        string nuevasCanciones;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar buffer seguro
                        getline(cin, nuevasCanciones);

                        if (nuevasCanciones.empty()) {
                            cout << "\nNo se agregó ninguna canción.\n";
                            break;
                        }

                        //buscar usuario
                        int idx = listaFav.buscarUsuario(idIngresado);
                        if (idx == -1) {
                            //no existe crear nueva
                            cout << "\nNo tienes una lista creada, se creará una nueva.\n";
                            string nuevaLinea = idIngresado + ";MiLista;" + nuevasCanciones;
                            ofstream salida("ListaFavoritos.csv", ios::app);
                            if (salida.is_open()) {
                                salida << nuevaLinea << "\n";
                                salida.close();
                                cout << "\nLista creada exitosamente.\n";
                            } else {
                                cout << "Error al guardar la nueva lista.\n";
                            }
                        } else {
                            //existe combinar canciones
                            int nExistentes = 0;
                            char** cancionesExistentes = listaFav.obtenerCanciones(idx, nExistentes);

                            //obtener string join()
                            string existentesStr = "";
                            if (nExistentes > 0) {
                                existentesStr = listaFav.join(cancionesExistentes, nExistentes, ',');
                            }

                            //liberar memoria cancionesExistentes
                            for (int i = 0; i < nExistentes; i++)
                                delete[] cancionesExistentes[i];
                            delete[] cancionesExistentes;

                            //si no hay usar nuevasCanciones
                            string combinado;
                            if (existentesStr.empty())
                                combinado = nuevasCanciones;
                            else
                                combinado = existentesStr + "," + nuevasCanciones;

                            int nTotalTmp = 0;
                            char** arrTotalTmp = listaFav.split(combinado, nTotalTmp, ',');

                            char** unicos = new char*[nTotalTmp];
                            int nUnicos = 0;
                            for (int i = 0; i < nTotalTmp; i++) {
                                bool ya = false;
                                for (int j = 0; j < nUnicos; j++) {
                                    if (string(unicos[j]) == string(arrTotalTmp[i])) { ya = true; break; }
                                }
                                if (!ya) {
                                    //duplicar cadena para unicos
                                    size_t len = strlen(arrTotalTmp[i]);
                                    unicos[nUnicos] = new char[len + 1];
                                    strcpy(unicos[nUnicos], arrTotalTmp[i]);
                                    nUnicos++;
                                }
                            }

                            //liberar arrTotalTmp
                            for (int i = 0; i < nTotalTmp; i++)
                                delete[] arrTotalTmp[i];
                            delete[] arrTotalTmp;

                            //actualizamos línea del usuario
                            listaFav.actualizarLinea(idx, unicos, nUnicos);
                            if (!listaFav.guardarArchivo()) {
                                cout << "Error al guardar los cambios en ListaFavoritos.csv\n";
                            } else {
                                cout << "\nLista actualizada correctamente.\n";
                            }

                            //liberar memoria unicos
                            for (int i = 0; i < nUnicos; i++)
                                delete[] unicos[i];
                            delete[] unicos;
                        }

                        break;
                    }
                    case 2:
                        cout << "\n no dio. \n";
                        break;
                    case 3:
                        cout << "\n no dio \n";
                        break;
                    case 0:
                        cout << "\nVolviendo al menú Premium...\n";
                        break;
                    default:
                        cout << "\nOpción no válida.\n";
                        break;
                    }
                }
            }
            else if (opcion != 0)
                cout << "\nOpción no válida.\n";
        }
    }
    cout << "\n Gracias por usar UdeATunes.\n";
    return 0;
}



