#ifndef ACTUALIZACIONDATOS_H
#define ACTUALIZACIONDATOS_H
class ActualizacionDatos {
private:
    char** lineas;
    int numLineas;
    const char* filename;

    void liberarMemoria();

public:
    //constructor y destructor
    ActualizacionDatos(const char* file);
    ~ActualizacionDatos();

    //metodos publicos
    bool cargarArchivo();
    bool actualizarReproducciones(const char* idBuscado, int incremento);
    bool guardarArchivo();
};

#endif // ACTUALIZACIONDATOS_H

