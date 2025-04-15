// DEFINICIÓN DE LA CLASE ALUMNO
// Representa a un alumno que puede responder pruebas

#ifndef ALUMNO_H
#define ALUMNO_H

#include "GestorPreguntas.h"
#include "GestorPruebas.h"
#include <string>

using namespace std;

class Alumno {
private:
    string nombre;    // Nombre del alumno
    
    // Método privado para responder pruebas
    void responderPrueba(GestorPreguntas* gestorPreguntas, GestorPruebas* gestorPruebas);

public:
    // Constructor y destructor
    Alumno(string nombre);
    ~Alumno();

    // Método principal de interacción con el menú
    void menu(GestorPreguntas* gestorPreguntas, GestorPruebas* gestorPruebas);
};

#endif
