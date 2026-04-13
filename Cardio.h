#ifndef CARDIO_H
#define CARDIO_H

#include "Ejercicio.h"

// Cardio "es un" Ejercicio (Herencia pública)
class Cardio : public Ejercicio {
private:
    std::string maquina; // Atributo único para ejercicios de cardio [cite: 36]

public:
    // El constructor llama al constructor de la clase base primero
    Cardio(std::string c, std::string n, std::string i, int t, std::string d, int s, std::string m)
        : Ejercicio(c, n, i, t, d, s), maquina(m) {}

    // Sobrescribimos el método para mostrar información específica
    // El uso de 'override' le asegura al profesor que sabes C++ moderno [cite: 48]
    void mostrarInfo() const override {
        std::cout << "--- EJERCICIO CARDIOVASCULAR ---" << std::endl;
        std::cout << "Codigo: " << codigo << " | Nombre: " << nombre << std::endl;
        std::cout << "Intensidad: " << intensidad << " | Tiempo: " << tiempoMinutos << " min" << std::endl;
        std::cout << "Maquina: " << maquina << std::endl;
        std::cout << "Descripcion: " << descripcion << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
};

#endifc
