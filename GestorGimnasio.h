#ifndef GESTORGIMNASIO_H
#define GESTORGIMNASIO_H

#include <vector>
#include <string>
#include "Ejercicio.h"
#include "Cardio.h"
#include "Fuerza.h"

class GestorGimnasio {
private:
    std::vector<Ejercicio*> catalogo; // Agregación de punteros para polimorfismo [cite: 14, 47]

public:
    GestorGimnasio() {}
    ~GestorGimnasio(); // Destructor para liberar memoria dinámica [cite: 48, 71]

    // Métodos CRUD requeridos [cite: 22, 23, 24, 25]
    void crearEjercicio();
    void actualizarEjercicio(std::string id);
    void eliminarEjercicio(std::string id);
    void consultarEjercicio(std::string id) const;
    void buscarPorIntensidad(std::string niv) const; // [cite: 26]
    
    // Generación de rutina y cálculo de tiempo [cite: 27, 30]
    void generarRutina(int cantidad, std::string nivel, int semanaActual);
};

#endif
