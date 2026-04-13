#ifndef FUERZA_H
#define FUERZA_H

#include "Ejercicio.h"

class Fuerza : public Ejercicio {
private:
    std::string grupoMuscular; // Atributo único para ejercicios de fuerza [cite: 36]

public:
    Fuerza(std::string c, std::string n, std::string i, int t, std::string d, int s, std::string gm)
        : Ejercicio(c, n, i, t, d, s), grupoMuscular(gm) {}

    void mostrarInfo() const override {
        std::cout << "--- EJERCICIO DE FUERZA ---" << std::endl;
        std::cout << "Codigo: " << codigo << " | Nombre: " << nombre << std::endl;
        std::cout << "Intensidad: " << intensidad << " | Tiempo: " << tiempoMinutos << " min" << std::endl;
        std::cout << "Grupo Muscular: " << grupoMuscular << std::endl;
        std::cout << "Descripcion: " << descripcion << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
};

#endif
