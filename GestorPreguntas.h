// DEFINICIÓN DE LA CLASE GESTORPREGUNTAS
// Gestiona la colección de preguntas y sus operaciones

#ifndef GESTORPREGUNTAS_H
#define GESTORPREGUNTAS_H

#include "Pregunta.h"


class GestorPreguntas {
private:
    Pregunta* preguntas;   // Arreglo dinámico de preguntas
    int cantidad;          // Cantidad actual de preguntas
    int capacidad;         // Capacidad máxima del arreglo

public:
    // Constructores y destructor
    GestorPreguntas();
    GestorPreguntas(const GestorPreguntas& otro);
    ~GestorPreguntas();

    // Operador de asignación
    GestorPreguntas& operator=(const GestorPreguntas& otro);

    // Métodos de gestión de preguntas
    void agregarPregunta(const Pregunta& p);      // Agrega una nueva pregunta
    void crearPregunta();                         // Crea una pregunta de manera manual
    void modificarPregunta();                     // Modifica una pregunta existente
    void eliminarPregunta();                      // Elimina una pregunta
    void mostrarPreguntas(int anioActual) const;  // Muestra todas las preguntas válidas
    void buscarPorNivel(NivelTaxonomico nivel, int anioActual) const;  // Busca preguntas por nivel
    void cargarDesdeArchivo(const char* nombreArchivo);  // Carga preguntas desde archivo
    Pregunta obtenerPregunta(int indice) const;      // Obtiene una pregunta por índice
    int getCantidad() const;                        // Obtiene la cantidad de preguntas
    string trim(const string& str);                  // Elimina espacios en blanco al inicio y al final de una cadena
    Pregunta buscarPorId(int id) const;              // Busca una pregunta por su ID
};

#endif
