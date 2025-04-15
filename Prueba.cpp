// IMPLEMENTACIÓN DE LA CLASE PRUEBA

#include "Prueba.h"
#include <iostream>

using namespace std;

int Prueba::contadorId = 0;        // Inicialización del contador de ID

// Constructor por defecto
Prueba::Prueba() {
    id = -1;
    capacidadPreguntas = 0;
    preguntas = nullptr; 
    cantidadPreguntas = 0;
    asignatura = "";
    ponderacion = 0.0f;
    anio = 0;
}

// Constructor con parámetros
Prueba::Prueba(string asig, float pond, int anio) {
    id = ++contadorId;
    capacidadPreguntas = 30; 
    cantidadPreguntas = 0;
    asignatura = asig;
    ponderacion = pond;
    this->anio = anio;

    preguntas = new int[capacidadPreguntas];
}

// Destructor de la clase
Prueba::~Prueba() {
    delete[] preguntas;  
}

// Constructor de copia
Prueba::Prueba(const Prueba& otra) {
    id = otra.id;
    asignatura = otra.asignatura;
    ponderacion = otra.ponderacion;
    anio = otra.anio;
    cantidadPreguntas = otra.cantidadPreguntas;
    capacidadPreguntas = otra.capacidadPreguntas;
    
    preguntas = new int[capacidadPreguntas];
    for(int i = 0; i < cantidadPreguntas; i++) {
        preguntas[i] = otra.preguntas[i];
    }
}

// Operador de asignación
Prueba& Prueba::operator=(const Prueba& otra) {
    if(this != &otra) {
        delete[] preguntas;
        
        id = otra.id;
        asignatura = otra.asignatura;
        ponderacion = otra.ponderacion;
        anio = otra.anio;
        cantidadPreguntas = otra.cantidadPreguntas;
        capacidadPreguntas = otra.capacidadPreguntas;
        
        preguntas = new int[capacidadPreguntas];
        for(int i = 0; i < cantidadPreguntas; i++) {
            preguntas[i] = otra.preguntas[i];
        }
    }
    return *this;
}

// Obtiene la cantidad de preguntas en la prueba
int Prueba::getCantidadPreguntas() const{
    return cantidadPreguntas;
}

// Agrega una pregunta a la prueba
void Prueba::agregarPregunta(int idPregunta) {
    if (cantidadPreguntas >= capacidadPreguntas) {
        int nuevaCapacidad = capacidadPreguntas * 2;
        int* nuevo = new int[nuevaCapacidad];
        for (int i = 0; i < cantidadPreguntas; ++i)
            nuevo[i] = preguntas[i];
        delete[] preguntas;
        preguntas = nuevo;
        capacidadPreguntas = nuevaCapacidad;
    }
    preguntas[cantidadPreguntas++] = idPregunta;
}

// Calcula el tiempo total estimado para responder la prueba en base a el tiempo de cada pregunta
int Prueba::calcularTiempoTotal(GestorPreguntas& gestor) const {
    int total = 0;
    for (int i = 0; i < cantidadPreguntas; i++) {
        Pregunta p = gestor.buscarPorId(preguntas[i]);
        if (p.getId() != -1) { 
            total += p.getTiempo();
        }
    }
    return total;
}

// Muestra los detalles de la prueba
void Prueba::mostrar(GestorPreguntas& gestor) const {
    cout << "=== PRUEBA " << id << " ===" << endl;
    cout << "Asignatura: " << asignatura << endl;
    cout << "Ponderación: " << ponderacion << endl;
    cout << "Año: " << anio << endl;
    cout << "Preguntas: " << endl;
    for (int i = 0; i < cantidadPreguntas; ++i) {
        cout << "[" << (i + 1) << "]" << endl;
        Pregunta p = gestor.buscarPorId(preguntas[i]);
        if (p.getId() != -1) { 
            p.mostrar();
        } else {
            cout << "Pregunta no encontrada" << endl;
        }
        cout << endl;
    }
    cout << "Tiempo total estimado: " << calcularTiempoTotal(gestor) << " minutos" << endl;
    cout << "-----------------------------\n";
}

// Obtiene las preguntas de la prueba
Pregunta* Prueba::getPreguntas(GestorPreguntas& gestor) const {
    Pregunta* preguntasArray = new Pregunta[cantidadPreguntas];
    for (int i = 0; i < cantidadPreguntas; i++)
        preguntasArray[i] = gestor.buscarPorId(preguntas[i]);
    return preguntasArray;
}
