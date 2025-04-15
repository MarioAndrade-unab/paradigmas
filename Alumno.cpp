// IMPLEMENTACIÓN DE LA CLASE ALUMNO

#include "Alumno.h"
#include "GestorPreguntas.h"
#include "GestorPruebas.h"
#include <iostream>

using namespace std;

// Constructor con parámetros
Alumno::Alumno(string nombre) {
    this->nombre = nombre;
}

// Destructor de la clase
Alumno::~Alumno() {}

// Menú principal del alumno
void Alumno::menu(GestorPreguntas* gestorPreguntas, GestorPruebas* gestorPruebas) {
    int opcion;
    cout<<"¡Bienvenido alumno "<<nombre<<"!";
    do {
        cout << "\n=== MENU ALUMNO ===" << endl;
        cout << "1. Ver pruebas disponibles" << endl;
        cout << "2. Responder prueba" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 
    
        switch (opcion) {
            case 1:
                gestorPruebas->mostrarPruebas(*gestorPreguntas);        // Mostrar pruebas creadas por el profesor
                break;
            case 2:
                responderPrueba(gestorPreguntas, gestorPruebas);        // Responder una prueba seleccionada
                break;
            case 3:                                 
                break;                                // Salir del menú
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 3);
}

// Método para responder una prueba
void Alumno::responderPrueba(GestorPreguntas* gestorPreguntas, GestorPruebas* gestorPruebas) {
    if (gestorPruebas->getCantidad() == 0) {
        cout << "No hay pruebas disponibles para responder.\n";        // Verificar si hay pruebas disponibles
        return;
    }
    
    int idPrueba;
    cout << "\nIngrese el ID de la prueba que desea responder: ";
    cin >> idPrueba;
    
    Prueba* prueba = gestorPruebas->buscarPorId(idPrueba);            // Buscar la prueba por su ID y verificar si existe
    if (prueba == nullptr) {
        cout << "No se encontró una prueba con ese ID.\n";
        return;
    }

    float puntajeTotal = 0;
    int cantidadPreguntas = prueba->getCantidadPreguntas();
    Pregunta* preguntas = prueba->getPreguntas(*gestorPreguntas);        // Obtener las preguntas de la prueba
    
    cout << "\n=== COMENZANDO PRUEBA ===\n";
    for (int i = 0; i < cantidadPreguntas; i++) {                         // Iterar sobre cada pregunta y obtener la respuesta del alumno
        string respuesta;
        
        cout << "\nPregunta " << (i + 1) << ":\n";
        preguntas[i].mostrar();
        
        cout << "Su respuesta: ";
        cin.ignore();
        getline(cin, respuesta);

        cout<<"respuesta correcta: "<<preguntas[i].getSolucion()<<endl;
        
        if (respuesta == preguntas[i].getSolucion()) {                    // Verificar si la respuesta es correcta y actualizar el puntaje
            cout << "Respuesta correcta!\n";
            puntajeTotal += 1;
        }

    }
    
    cout << "\nPrueba finalizada.\nPuntaje obtenido: " << puntajeTotal << "/" << cantidadPreguntas << endl;    // Mostrar el puntaje final obtenido por el alumno
}
