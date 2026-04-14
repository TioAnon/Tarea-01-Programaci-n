#include "GestorGimnasio.h"
#include <iostream>

// 1. DESTRUCTOR:
GestorGimnasio::~GestorGimnasio() {
    for (Ejercicio* e : catalogo) {
        delete e; 
    }
    catalogo.clear();
}

// 2. CREAR:
void GestorGimnasio::crearEjercicio() {
    std::string cod, nom, niv, desc, espec;
    int t, s, tipo;

    std::cout << "Tipo (1. Cardio / 2. Fuerza): "; std::cin >> tipo;
    std::cout << "Codigo: "; std::cin >> cod;
    std::cout << "Nombre: "; std::cin.ignore(); std::getline(std::cin, nom);
    std::cout << "Intensidad: "; std::getline(std::cin, niv);
    std::cout << "Tiempo (min): "; std::cin >> t;
    std::cout << "Descripcion: "; std::cin.ignore(); std::getline(std::cin, desc);
    std::cout << "Semana ultimo uso: "; std::cin >> s;

    if (tipo == 1) {
        std::cout << "Maquina: "; std::getline(std::cin, espec);
        catalogo.push_back(new Cardio(cod, nom, niv, t, desc, s, espec)); 
    } else {
        std::cout << "Grupo Muscular: "; std::getline(std::cin, espec);
        catalogo.push_back(new Fuerza(cod, nom, niv, t, desc, s, espec)); 
    }
    std::cout << "Ejercicio guardado.\n";
}

// 3. ACTUALIZAR:
void GestorGimnasio::actualizarEjercicio(std::string id) {
    for (Ejercicio* e : catalogo) {
        if (e->getCodigo() == id) {
            std::string nuevoNom;
            int nuevoT;
            std::cout << "Nuevo Nombre: "; std::cin.ignore(); std::getline(std::cin, nuevoNom);
            std::cout << "Nuevo Tiempo (min): "; std::cin >> nuevoT;
            
            e->setNombre(nuevoNom); // Usamos setters
            e->setTiempo(nuevoT);
            std::cout << "Ejercicio " << id << " actualizado con exito.\n";
            return;
        }
    }
    std::cout << "No se encontro el ejercicio para actualizar.\n";
}

// 4. GENERAR RUTINA: 
void GestorGimnasio::generarRutina(int cantidad, std::string nivel, int semanaActual) {
    int tiempoTotal = 0;
    int encontrados = 0;

    std::cout << "\n--- RUTINA GENERADA PARA NIVEL: " << nivel << " ---\n";

    for (Ejercicio* e : catalogo) {
        if (encontrados >= cantidad) break;

        if (e->getIntensidad() == nivel && e->getSemana() != (semanaActual - 1)) {
            e->mostrarInfo();
            tiempoTotal += e->getTiempo();
            e->setSemana(semanaActual); // Marca el ejercicio como usado esta semana
            encontrados++;
        }
    }
    std::cout << "TIEMPO TOTAL ESTIMADO: " << tiempoTotal << " minutos.\n";
}

// 5. CONSULTAR y ELIMINAR: 
void GestorGimnasio::consultarEjercicio(std::string id) const {
    for (Ejercicio* e : catalogo) {
        if (e->getCodigo() == id) {
            e->mostrarInfo();
            return;
        }
    }
    std::cout << "Ejercicio no encontrado.\n";
}

void GestorGimnasio::eliminarEjercicio(std::string id) {
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if ((*it)->getCodigo() == id) {
            delete *it; 
            catalogo.erase(it); 
            std::cout << "Ejercicio eliminado.\n";
            return;
        }
    }
    std::cout << "No se pudo eliminar.\n";
}

void GestorGimnasio::buscarPorIntensidad(std::string niv) const {
    bool hay = false;
    for (Ejercicio* e : catalogo) {
        if (e->getIntensidad() == niv) {
            e->mostrarInfo();
            hay = true;
        }
    }
    if (!hay) std::cout << "No hay ejercicios con intensidad " << niv << "\n";
}
