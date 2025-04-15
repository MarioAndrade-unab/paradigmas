// IMPLEMENTACIÓN DE LA CLASE PREGUNTA

#include "Pregunta.h"
#include <iostream>

using namespace std;

int Pregunta::contadorId = 0;        // Inicialización del contador de ID

// Constructor por defecto
Pregunta::Pregunta() {
    id = -1;
    enunciado = "";
    nivel = RECORDAR;
    tipo = VERDADERO_FALSO;
    tiempoEstimado = 0;
    solucionEsperada = "";
    anioCreacion = 0;
}

// Constructor con parámetros
Pregunta::Pregunta(string e, NivelTaxonomico n, TipoPregunta t, int tiempo, string solucion, int anio, string asign)
: enunciado(e), nivel(n), tipo(t), tiempoEstimado(tiempo), solucionEsperada(solucion), anioCreacion(anio), asignatura(asign) {
    id = ++contadorId;
}

// Verifica si la pregunta es válida para el año actual
bool Pregunta::esValida(int anioActual) const {
    return (anioActual - anioCreacion) <= 2;
}

// Getters
int Pregunta::getId() const {
    return id;
}

int Pregunta::getTiempo() const {
    return tiempoEstimado;
}

string Pregunta::getEnunciado() const {
    return enunciado;
}

NivelTaxonomico Pregunta::getNivel() const {
    return nivel;
}

string Pregunta::getAsignatura() const {
    return asignatura;
}

string Pregunta::getSolucion() const{
    return solucionEsperada;
}

// Setters
void Pregunta::setEnunciado(const string& enunciado) {
    this->enunciado = enunciado;
}

void Pregunta::setNivel(NivelTaxonomico nivel) {
    this->nivel = nivel;
}

void Pregunta::setTipo(TipoPregunta tipo) {
    this->tipo = tipo;
}

void Pregunta::setTiempoEstimado(int tiempoEstimado) {
    this->tiempoEstimado = tiempoEstimado;
}

void Pregunta::setSolucion(const string& solucion) {
    this->solucionEsperada = solucion;
}

void Pregunta::setAnioCreacion(int anioCreacion) {
    this->anioCreacion = anioCreacion;
}

void Pregunta::setAsignatura(const string& asignatura) {
    this->asignatura = asignatura;
}

// Muestra los detalles de la pregunta
void Pregunta::mostrar() const {
    cout << "=== PREGUNTA #" << id << " ==="<<endl;
    
    cout << "Enunciado: " << enunciado << endl;

    cout << "Nivel: ";
    switch (nivel) {
        case RECORDAR: cout << "Recordar"; break;
        case ENTENDER: cout << "Entender"; break;
        case APLICAR: cout << "Aplicar"; break;
        case ANALIZAR: cout << "Analizar"; break;
        case EVALUAR: cout << "Evaluar"; break;
        case CREAR: cout << "Crear"; break;
        default: cout << "Desconocido"; break;
    }
    cout << endl;

    cout << "Tipo: ";
    switch (tipo) {
        case VERDADERO_FALSO: cout << "Verdadero/Falso"; break;
        case RESPUESTA_CORTA: cout << "Respuesta Corta"; break;
        case SELECCION_MULTIPLE: cout << "Selección Múltiple"; break;
        default: cout << "Desconocido"; break;
    }
    cout << endl;

    cout << "Tiempo estimado: " << tiempoEstimado << " minutos" << endl;
    cout << "Año de creación: " << anioCreacion << endl;
    cout << "Asignatura: " << asignatura << "\n";
    cout << "-----------------------------\n";
}