// DEFINICIÓN DE LA CLASE PROFESOR
// Representa a un profesor en el sistema que puede gestionar preguntas y pruebas

#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
#include "GestorPreguntas.h"
#include "GestorPruebas.h"

using namespace std;

class Profesor {
private:
    string nombre;    // Nombre del profesor

public:
    // Constructores y destructor
    Profesor(string nombre);
    ~Profesor();

    // Método principal de interacción
    void menu(GestorPreguntas* gestorPreguntas, GestorPruebas* gestorPruebas);
};

#endif
