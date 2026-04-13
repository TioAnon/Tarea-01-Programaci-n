#include "GestorGimnasio.h"
#include <iostream>

GestorGimnasio::~GestorGimnasio() {
    for (Ejercicio* e : catalogo) {
        delete e; // Borra cada objeto creado con 'new' [cite: 71]
    }
    catalogo.clear();
}
