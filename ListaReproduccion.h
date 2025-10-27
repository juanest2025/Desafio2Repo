#ifndef LISTAREPRODUCCION_H
#define LISTAREPRODUCCION_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class ListaReproduccion {
private:
    char** lineas;        // Arreglo dinámico que almacena cada línea del CSV
    int numLineas;        // Número de líneas en el CSV
    const char* filename; // Nombre del archivo CSV

    // Métodos privados
    bool idExisteEnCampo(const char* campo, const char* id);
    // Verifica si un ID ya existe en un campo de IDs separados por coma

    char* obtenerCampoIds(int lineaIndex);
    // Retorna un puntero al campo "ids_canciones" de la línea especificada

public:
    // Constructor y destructor
    ListaReproduccion(const char* file);  // Carga automáticamente el CSV
    ~ListaReproduccion();                 // Libera memoria dinámica

    // Métodos públicos
    bool cargarCSV();  // Carga todas las líneas del archivo en memoria
    bool guardarCSV(); // Guarda todas las líneas en el archivo CSV

    // Copia todas las canciones de la lista de un usuario (origen_id)
    // al usuario destino (destino_id), evitando duplicados
    bool copiarCancionesEntreUsuarios(const char* origen_id, const char* destino_id);
};

#endif
