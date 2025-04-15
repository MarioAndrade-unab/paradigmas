// DEFINICIÓN DE LA CLASE PRUEBA
// Representa una prueba compuesta por múltiples preguntas

#ifndef PRUEBA_H
#define PRUEBA_H

#include "Pregunta.h"
#include "GestorPreguntas.h"

using namespace std;

// Declaración de la clase Prueba
class Prueba {
private:
    static int contadorId;     // Contador global para generar IDs únicos
    int id;                    // ID único de la prueba
    string asignatura;         // Asignatura de la prueba
    float ponderacion;         // Peso de la prueba en la evaluación
    int anio;                  // Año de la prueba
    int* preguntas;           // Arreglo dinámico de IDs de preguntas
    int cantidadPreguntas;    // Cantidad actual de preguntas
    int capacidadPreguntas;   // Capacidad máxima del arreglo

public:
    // Constructores y destructor
    Prueba();
    Prueba(string asig, float pond, int anio);
    Prueba(const Prueba& otra);  // Constructor de copia
    ~Prueba();

    // Operador de asignación
    Prueba& operator=(const Prueba& otra);

    // Métodos principales
    int getCantidadPreguntas() const;  // Obtiene la cantidad de preguntas en la prueba
    int getId() const { return id; }    // Obtiene el ID de la prueba
    void agregarPregunta(int idPregunta);    // Agrega una pregunta a la prueba
    int calcularTiempoTotal(GestorPreguntas& gestor) const;    // Calcula el tiempo total de la prueba
    void mostrar(GestorPreguntas& gestor) const;                 // Muestra la información de la prueba
    Pregunta* getPreguntas(GestorPreguntas& gestor) const;       // Obtiene las preguntas de la prueba
};

#endif
