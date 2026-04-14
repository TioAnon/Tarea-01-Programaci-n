#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <string>
#include <iostream>

class Ejercicio {
protected: 
    std::string codigo, nombre, intensidad, descripcion;
    int tiempoMinutos, ultimaSemanaUsado;

public:
    // He añadido la implementación del constructor aquí mismo para asegurar que funcione
    Ejercicio(std::string c, std::string n, std::string i, int t, std::string d, int s)
        : codigo(c), nombre(n), intensidad(i), tiempoMinutos(t), descripcion(d), ultimaSemanaUsado(s) {}
    
    virtual ~Ejercicio() {}

    virtual void mostrarInfo() const = 0; 

    // Getters y Setters que ya tenías (están perfectos)
    std::string getCodigo() const { return codigo; }
    std::string getIntensidad() const { return intensidad; }
    int getTiempo() const { return tiempoMinutos; }
    int getSemana() const { return ultimaSemanaUsado; }
    void setNombre(std::string n) { nombre = n; }
    void setTiempo(int t) { tiempoMinutos = t; }
    void setSemana(int s) { ultimaSemanaUsado = s; }
};

#endif
