# Tarea-01-Programaci-n
# Sistema de Gestión de Rutinas de Entrenamiento - UNAB 2026

Este proyecto es una aplicación de consola robusta desarrollada en **C++** para la asignatura de **Paradigmas de Programación**. El software permite a los instructores gestionar un catálogo de ejercicios y generar rutinas automatizadas basadas en reglas de negocio específicas de intensidad y frecuencia.

## 📋 Información del Estudiante
* **Nombre:** Diego Ignacio Rubilar Gómez
* **RUT:** 20.829.066-5
* **NRC:** 8025
* **Docente:** Juan Calderón Maureira

## 🚀 Pilares de Programación Implementados
El sistema demuestra el dominio de los conceptos avanzados de POO exigidos en la Tarea 1:
- **Abstracción:** Uso de la clase base abstracta `Ejercicio` con métodos virtuales puros.
- **Herencia:** Especialización de comportamientos en las clases `Cardio` y `Fuerza`.
- **Polimorfismo:** Gestión dinámica de objetos mediante un `std::vector<Ejercicio*>` y enlace tardío (late binding).
- **Gestión de Memoria:** Implementación de destructores virtuales para garantizar la liberación de memoria en el Heap y prevenir fugas (Memory Leaks).

## 🛠️ Funcionalidades (CRUD Completo)
1. **Crear:** Registro polimórfico de ejercicios de Cardio o Fuerza.
2. **Consultar:** Búsqueda y despliegue detallado de información por código único.
3. **Actualizar:** Modificación dinámica de atributos en memoria.
4. **Eliminar:** Liberación de memoria dinámica y actualización del catálogo.
5. **Generar Rutina:** Algoritmo que filtra por intensidad y asegura que ningún ejercicio se repita en semanas consecutivas.

## 🧪 Guía de Pruebas (Demo para el Docente)
Para verificar el correcto funcionamiento, se sugieren las siguientes acciones en el menú:
1. **Verificar Polimorfismo:** Cree un ejercicio de cada tipo. Al "Consultar", notará que el sistema muestra atributos únicos (Máquina o Grupo Muscular) según el tipo de objeto.
2. **Verificar Regla de Negocio:** Registre un ejercicio con `semana = 1`. Intente generar rutina para la `semana = 2`. El ejercicio no aparecerá. Intente para la `semana = 3` y aparecerá nuevamente.
3. **Verificar Gestión de Memoria:** Al "Eliminar" un ejercicio, el sistema invoca el destructor específico, liberando los recursos de forma segura.

## ⚙️ Compilación y Ejecución
Utilice el siguiente comando en una terminal con `g++`:

```bash
g++ main.cpp GestorGimnasio.cpp Ejercicio.cpp Cardio.cpp Fuerza.cpp -o SistemaGimnasio
./SistemaGimnasio
```
