#include "BaseDatosCancion.h"

BaseDatosCancion::BaseDatosCancion(const char* file) {
    filename = file;
    numCanciones = 0;
    capacidad = 10;
    canciones128 = new string[capacidad];
    canciones320 = new string[capacidad];
}

BaseDatosCancion::~BaseDatosCancion() {
    delete[] canciones128;
    delete[] canciones320;
}

void BaseDatosCancion::aumentarCapacidad() {
    capacidad *= 2;
    string* nuevo128 = new string[capacidad];
    string* nuevo320 = new string[capacidad];
    for (int i = 0; i < numCanciones; i++) {
        nuevo128[i] = canciones128[i];
        nuevo320[i] = canciones320[i];
    }
    delete[] canciones128;
    delete[] canciones320;

    canciones128 = nuevo128;
    canciones320 = nuevo320;
}

string BaseDatosCancion::extraerCampos128(const string& linea) {
    string campos[8];
    int campoIndex = 0;
    string temp = "";

    for (size_t i = 0; i < linea.length(); i++) {
        if (linea[i] == ';') {
            campos[campoIndex++] = temp;
            temp = "";
        } else {
            temp += linea[i];
        }
    }
    campos[campoIndex] = temp;

    //validación si faltan campos
    if (campoIndex < 5) return "";

    //campos 0=id, 1=nombre, 2=duración, 3=ruta128, 5=portada
    string resultado = campos[0] + ";" + campos[1] + ";" + campos[2] + ";" + campos[3] + ";" + campos[5];
    return resultado;
}

string BaseDatosCancion::extraerCampos320(const string& linea) {
    string campos[8];
    int campoIndex = 0;
    string temp = "";

    for (size_t i = 0; i < linea.length(); i++) {
        if (linea[i] == ';') {
            campos[campoIndex++] = temp;
            temp = "";
        } else {
            temp += linea[i];
        }
    }
    campos[campoIndex] = temp;

    //validación si faltan campos
    if (campoIndex < 5) return "";

    // Campos 0=id, 1=nombre, 2=duración, 4=ruta320, 5=portada
    string resultado = campos[0] + ";" + campos[1] + ";" + campos[2] + ";" + campos[4] + ";" + campos[5];
    return resultado;
}

string BaseDatosCancion::getCancion128(int i) const
{
    return canciones128[i];
}

string BaseDatosCancion::getCancion320(int i) const
{
    return canciones320[i];
}

int BaseDatosCancion::getNumCanciones() const
{
    return numCanciones;
}

bool BaseDatosCancion::cargarCSV() {
    ifstream archivo(filename);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return false;
    }

    string linea;
    getline(archivo, linea); //saltar encabezado

    while (getline(archivo, linea)) {
        if (linea.empty()){
            continue;
        }

        string datos128 = extraerCampos128(linea);
        string datos320 = extraerCampos320(linea);
        if (datos128.empty() || datos320.empty()){
            continue; //línea mal formada

        }
        if (numCanciones >= capacidad){
            aumentarCapacidad();
        }
        canciones128[numCanciones] = datos128;
        canciones320[numCanciones] = datos320;
        numCanciones++;
    }

    archivo.close();
    return true;
}


