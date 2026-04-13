#include <iostream>
#include <string>
#include "GestorGimnasio.h"

int main() {
    // Instanciamos el controlador que maneja la lógica y los datos
    GestorGimnasio miGimnasio;
    int opcion;
    std::string auxCod;

    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "   SISTEMA DE RUTINAS - UNAB 2026   " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Crear nuevo ejercicio" << std::endl;
        std::cout << "2. Consultar informacion de un ejercicio" << std::endl;
        std::cout << "3. Buscar ejercicios por intensidad" << std::endl;
        std::cout << "4. GENERAR RUTINA PERSONALIZADA" << std::endl;
        std::cout << "5. Eliminar un ejercicio" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion: ";
        
        // Validación para evitar bucles infinitos si el usuario ingresa letras
        if (!(std::cin >> opcion)) {
            std::cout << "Error: Ingrese un numero valido." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                miGimnasio.crearEjercicio(); // Requerimiento: Crear 
                break;
            case 2:
                std::cout << "Ingrese el codigo a consultar: ";
                std::cin >> auxCod;
                miGimnasio.consultarEjercicio(auxCod); // Requerimiento: Consultar 
                break;
            case 3: {
                std::string nivel;
                std::cout << "Nivel a buscar (Basico/Intermedio/Avanzado/Alto rendimiento): ";
                std::cin.ignore();
                std::getline(std::cin, nivel);
                miGimnasio.buscarPorIntensidad(nivel); // Requerimiento: Buscar 
                break;
            }
            case 4: {
                int cant, sem;
                std::string niv;
                std::cout << "Cantidad de ejercicios deseados: "; std::cin >> cant; // [cite: 28]
                std::cout << "Nivel de intensidad: "; 
                std::cin.ignore();
                std::getline(std::cin, niv); // [cite: 29]
                std::cout << "Semana actual (para evitar repeticiones): "; std::cin >> sem;
                
                // Genera la rutina y calcula el tiempo total 
                miGimnasio.generarRutina(cant, niv, sem);
                break;
            }
            case 5:
                std::cout << "Ingrese el codigo del ejercicio a eliminar: ";
                std::cin >> auxCod;
                miGimnasio.eliminarEjercicio(auxCod); // Requerimiento: Eliminar 
                break;
            case 0:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }

    } while (opcion != 0);

    return 0;
}
