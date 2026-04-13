#include "Ejercicio.h"

// Usamos una lista de inicialización, que es la forma más eficiente en C++
Ejercicio::Ejercicio(std::string c, std::string n, std::string i, int t, std::string d, int s)
    : codigo(c), nombre(n), intensidad(i), tiempoMinutos(t), descripcion(d), ultimaSemanaUsado(s) {}
