#ifndef ACTUALIZACIONDATOS_H
#define ACTUALIZACIONDATOS_H


class ActualizacionDatos {
private:
    char** lineas;
    int numLineas;
    const char* filename;

    void liberarMemoria();

public:
    // Constructor y destructor
    ActualizacionDatos(const char* file);
    ~ActualizacionDatos();

    // Métodos públicos
    bool cargarArchivo();
    bool actualizarReproducciones(const char* idBuscado, int incremento);
    bool guardarArchivo();
};

#endif // ACTUALIZACIONDATOS_H
