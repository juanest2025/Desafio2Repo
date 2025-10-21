#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>
using namespace std;


class usuario {
private:
    string nombreUsuario;
    string menbresia;
    string ciudad;
    string pais;
    string fecha;

public:
    usuario(const string& archivo);
    void registroUsuario(const string& archivo);
    void serPrimiun (const string& archivo);

};


#endif // USUARIOS_H
