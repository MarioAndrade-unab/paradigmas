// DEFINICIÓN DE LA CLASE PREGUNTA
// Representa una pregunta en el sistema

#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <string>

using namespace std;

// Enumeraciones para los niveles taxonómicos
enum NivelTaxonomico {
    RECORDAR,           // Nivel básico de memorización
    ENTENDER,          // Comprensión de conceptos
    APLICAR,           // Uso práctico del conocimiento
    ANALIZAR,          // Descomposición y relación de conceptos
    EVALUAR,           // Juicio crítico
    CREAR              // Generación de nuevo conocimiento
};

// Enumeraciones para los tipos de preguntas
enum TipoPregunta {
    VERDADERO_FALSO,    // Preguntas de verdadero o falso
    RESPUESTA_CORTA,    // Preguntas que requieren respuesta breve
    SELECCION_MULTIPLE  // Preguntas con opciones múltiples
};

class Pregunta {
private:
    static int contadorId;    // Contador global para generar IDs únicos
    int id;                   // ID único de la pregunta
    string enunciado;         // Texto de la pregunta
    NivelTaxonomico nivel;    // Nivel taxonómico de la pregunta
    TipoPregunta tipo;        // Tipo de pregunta
    int tiempoEstimado;       // Tiempo estimado para responder (en minutos)
    string solucionEsperada;  // Respuesta correcta
    int anioCreacion;         // Año en que se creó la pregunta
    string asignatura;        // Asignatura a la que pertenece

public:
    // Constructores
    Pregunta();
    Pregunta(string enun, NivelTaxonomico niv, TipoPregunta tip, int tiempo, string solucion, int anio, string asig);

    // Métodos principales
    bool esValida(int anioActual) const;  // Verifica si la pregunta está vigente (creada en el año actual o el anterior)
    void mostrar() const;                 // Muestra la información de la pregunta

    // Getters
    int getId() const;
    int getTiempo() const;
    string getEnunciado() const;
    NivelTaxonomico getNivel() const;
    string getAsignatura() const;
    string getSolucion() const;

    // Setters
    void setEnunciado(const string& enunciado);
    void setNivel(NivelTaxonomico nivel);
    void setTipo(TipoPregunta tipo);
    void setTiempoEstimado(int tiempoEstimado);
    void setSolucion(const string& solucion);
    void setAnioCreacion(int anioCreacion);
    void setAsignatura(const string& asignatura);
};

#endif
