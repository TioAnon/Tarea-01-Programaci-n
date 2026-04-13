#include "GestorGimnasio.h"
#include <iostream>
#include <limits> // Necesario para limpiar el buffer con seguridad

// 1. DESTRUCTOR: Limpieza de memoria dinámica
GestorGimnasio::~GestorGimnasio() {
    for (Ejercicio* e : catalogo) {
        delete e; // Borramos cada objeto creado con 'new' [cite: 71]
    }
    catalogo.clear();
}

// 2. CREAR: Instanciación polimórfica [cite: 22]
void GestorGimnasio::crearEjercicio() {
    std::string cod, nom, niv, desc, espec;
    int t, s, tipo;

    std::cout << "Tipo de Ejercicio (1. Cardio / 2. Fuerza): ";
    std::cin >> tipo;
    std::cout << "Codigo: "; std::cin >> cod;
    std::cout << "Nombre: "; std::cin.ignore(); std::getline(std::cin, nom);
    std::cout << "Intensidad (Basico/Intermedio/Avanzado/Alto rendimiento): "; std::getline(std::cin, niv);
    std::cout << "Tiempo (min): "; std::cin >> t;
    std::cout << "Descripcion: "; std::cin.ignore(); std::getline(std::cin, desc);
    std::cout << "Semana de ultimo uso: "; std::cin >> s;

    if (tipo == 1) {
        std::cout << "Maquina utilizada: "; std::getline(std::cin, espec);
        catalogo.push_back(new Cardio(cod, nom, niv, t, desc, s, espec)); // [cite: 15]
    } else {
        std::cout << "Grupo Muscular: "; std::getline(std::cin, espec);
        catalogo.push_back(new Fuerza(cod, nom, niv, t, desc, s, espec)); // [cite: 16]
    }
    std::cout << "Ejercicio guardado con exito.\n";
}

// 3. GENERAR RUTINA: Filtro de semana y cálculo de tiempo [cite: 27, 30]
void GestorGimnasio::generarRutina(int cantidad, std::string nivel, int semanaActual) {
    int tiempoTotal = 0;
    int encontrados = 0;

    std::cout << "\n--- RUTINA GENERADA PARA NIVEL: " << nivel << " ---\n";

    for (Ejercicio* e : catalogo) {
        if (encontrados >= cantidad) break;

        // Regla: Misma intensidad Y que no se haya usado la semana anterior [cite: 18, 29]
        if (e->getIntensidad() == nivel && e->getSemana() != (semanaActual - 1)) {
            e->mostrarInfo();
            tiempoTotal += e->getTiempo(); // Sumamos tiempo para el requisito final 
            encontrados++;
        }
    }
    std::cout << "TIEMPO TOTAL ESTIMADO: " << tiempoTotal << " minutos.\n";
}

// 4. CONSULTAR: Buscar un ejercicio por su código [cite: 25]
void GestorGimnasio::consultarEjercicio(std::string id) const {
    for (Ejercicio* e : catalogo) {
        if (e->getCodigo() == id) {
            e->mostrarInfo();
            return;
        }
    }
    std::cout << "Ejercicio no encontrado.\n";
}

// 5. ELIMINAR: Borrado físico y lógico [cite: 24]
void GestorGimnasio::eliminarEjercicio(std::string id) {
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if ((*it)->getCodigo() == id) {
            delete *it; // Liberamos memoria [cite: 71]
            catalogo.erase(it); // Sacamos del vector
            std::cout << "Ejercicio eliminado.\n";
            return;
        }
    }
    std::cout << "No se pudo eliminar: ID inexistente.\n";
}

// 6. BUSCAR POR INTENSIDAD [cite: 26]
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
