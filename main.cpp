#include "Usuario.h"
#include "Album.h"
#include "Publicidad.h"

int main() {
    Usuario u("juanest34", "estandar", "Medellín", "08-04-2023");
    u.mostrarInfo();

    Album a("AL001", "57526", "Midnights", "Pop/Synth-Pop", "2022-10-21", 2304, "Republic", 9.5, "midnights.png");
    a.mostrarInfo();

    Publicidad p(1, "57526", "Taylor Swift", "AL001", "¡La noche es tuya!", 'A');
    p.mostrarInfo();
}
