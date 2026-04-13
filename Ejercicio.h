#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <string>
#include <iostream>

class Ejercicio {
protected: // Usamos protected para que las clases hijas Cardio y Fuerza accedan a los datos [cite: 46]
    std::string codigo;         // [cite: 34]
    std::string nombre;         // [cite: 35]
    std::string intensidad;     // [cite: 37] (Básico, Intermedio, Avanzado, Alto rendimiento) [cite: 8]
    int tiempoMinutos;          // [cite: 38]
    std::string descripcion;    // [cite: 39]
    int ultimaSemanaUsado;      // [cite: 40]

public:
    // Constructor: Inicializa los datos obligatorios
    Ejercicio(std::string c, std::string n, std::string i, int t, std::string d, int s);
    
    // Destructor Virtual: CRÍTICO para la nota de implementación (30%) 
    // Sin esto, al borrar un ejercicio de la lista, habrá fugas de memoria.
    virtual ~Ejercicio() {}

    // MÉTODO VIRTUAL PURO: Hace que la clase sea Abstracta [cite: 44, 47]
    // Obliga a que cada ejercicio se presente según su tipo (Cardio o Fuerza).
    virtual void mostrarInfo() const = 0; 

    // Getters: Necesarios para que el Gestor pueda buscar y calcular tiempos [cite: 30]
    std::string getCodigo() const { return codigo; }
    std::string getIntensidad() const { return intensidad; }
    int getTiempo() const { return tiempoMinutos; }
    int getSemana() const { return ultimaSemanaUsado; }
};

#endif
