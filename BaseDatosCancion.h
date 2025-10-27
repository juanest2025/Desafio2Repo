#ifndef BASEDATOSCANCION_H
#define BASEDATOSCANCION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class BaseDatosCancion {
private:
    string* canciones128;   // arreglo dinámico para formato 128
    string* canciones320;   // arreglo dinámico para formato 320
    int numCanciones;      // cantidad de canciones cargadas
    int capacidad;         // capacidad actual del arreglo
    const char* filename;  // nombre del archivo CSV

public:
    BaseDatosCancion();
    BaseDatosCancion(const char* file);
    ~BaseDatosCancion();

    bool cargarCSV();
    int getCantidad() const { return numCanciones; }
    void aumentarCapacidad();  // función interna para expandir arreglo
    string extraerCampos128(const string& linea); // procesa y concatena los 5 campos
    string extraerCampos320(const string& linea);
    string getCancion128(int i) const;
    string getCancion320(int i) const;
    int getNumCanciones() const;


};



#endif // BASEDATOSCANCION_H
