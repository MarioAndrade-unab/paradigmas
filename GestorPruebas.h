// DEFINICIÓN DE LA CLASE GESTORPRUEBAS
// Gestiona la colección de pruebas y sus operaciones

#ifndef GESTORPRUEBAS_H
#define GESTORPRUEBAS_H

#include "Prueba.h"
#include "GestorPreguntas.h"

using namespace std;

class GestorPruebas {
private:
    Prueba* pruebas;    // Arreglo dinámico de pruebas
    int cantidad;       // Cantidad actual de pruebas
    int capacidad;      // Capacidad máxima del array

public:
    // Constructores y destructor
    GestorPruebas();
    GestorPruebas(const GestorPruebas& otro);
    ~GestorPruebas();

    // Operador de asignación
    GestorPruebas& operator=(const GestorPruebas& otro);

    // Métodos principales
    void crearPrueba(string asignatura, float ponderacion, int anio,              // Crea una nueva prueba
                    GestorPreguntas& preguntasCargadas, int anioActual);
    void mostrarPruebas(GestorPreguntas& gestorPreguntas) const;                 // Muestra todas las pruebas
    
    // Métodos de acceso
    Prueba* obtenerPrueba(int indice);                                             // Obtiene una prueba por índice
    Prueba* buscarPorId(int id);                                                 // Busca una prueba por su ID
    int getCantidad() const;                                                    // Obtiene la cantidad de pruebas
};

#endif
