#ifndef BASEDATOSCANCION_H
#define BASEDATOSCANCION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class BaseDatosCancion {
private:
    string* canciones128;   // arreglo dinámico cancion 128
    string* canciones320;   // arreglo dinámico cancion 320
    int numCanciones;      // cantidad de canciones
    int capacidad;         // capacidad arreglo
    const char* filename;  // nombre archivo CSV

public:
    BaseDatosCancion();
    BaseDatosCancion(const char* file);
    ~BaseDatosCancion();

    bool cargarCSV();
    int getCantidad() const { return numCanciones; }
    void aumentarCapacidad();  //funcion expandir arreglo
    string extraerCampos128(const string& linea); //procesa concatena los 5 campos
    string extraerCampos320(const string& linea);
    string getCancion128(int i) const;
    string getCancion320(int i) const;
    int getNumCanciones() const;


};



#endif // BASEDATOSCANCION_H
