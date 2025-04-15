// IMPLEMENTACIÓN DE LA CLASE GESTORPRUEBAS

#include "GestorPruebas.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor por defecto
GestorPruebas::GestorPruebas() {
    capacidad = 10;
    pruebas = new Prueba[capacidad];
    cantidad = 0;
}

// Destructor de la clase
GestorPruebas::~GestorPruebas() {
    delete[] pruebas;
}

// Constructor de copia
GestorPruebas::GestorPruebas(const GestorPruebas& otro) {
    capacidad = otro.capacidad;
    cantidad = otro.cantidad;
    pruebas = new Prueba[capacidad];
    for(int i = 0; i < cantidad; i++) {
        pruebas[i] = otro.pruebas[i];
    }
}

// Operador de asignación
GestorPruebas& GestorPruebas::operator=(const GestorPruebas& otro) {
    if(this != &otro) {
        delete[] pruebas;
        capacidad = otro.capacidad;
        cantidad = otro.cantidad;
        pruebas = new Prueba[capacidad];
        for(int i = 0; i < cantidad; i++) {
            pruebas[i] = otro.pruebas[i];
        }
    }
    return *this;
}

// Agrega una prueba al gestor
void GestorPruebas::crearPrueba(string asignatura, float ponderacion, int anio, GestorPreguntas& preguntasCargadas, int anioActual) {
    Prueba nuevaPrueba(asignatura, ponderacion, anio);

    char usarFiltro;
    cout << "\n¿Desea cargar preguntas de una asignatura específica? (s/n): ";        // Preguntar si se desea usar un filtro de asignatura para cargar preguntas
    cin >> usarFiltro;
    cin.ignore();

    if (usarFiltro == 's' || usarFiltro == 'S') {
        string asignaturaFiltro;
        cout << "\nAsignatura a filtrar: ";
        getline(cin, asignaturaFiltro);

        cout << "\n=== CARGANDO PREGUNTAS DE LA ASIGNATURA '" << asignaturaFiltro << "' ===\n";
        for (int i = 0; i < preguntasCargadas.getCantidad(); i++) {
            Pregunta p = preguntasCargadas.obtenerPregunta(i);
            if (p.esValida(anioActual) && p.getAsignatura() == asignaturaFiltro) {
                nuevaPrueba.agregarPregunta(p.getId());
            }
        }
    } else {                                                        // Si no se usa filtro, se cargan todas las preguntas válidas para seleccionar manualmente
        cout << "\n=== SELECCIÓN MANUAL DE PREGUNTAS ===\n";
        for (int i = 0; i < preguntasCargadas.getCantidad(); i++) {
            Pregunta p = preguntasCargadas.obtenerPregunta(i);
            if (p.esValida(anioActual)) {
                p.mostrar();
                char incluir;
                cout << "¿Desea incluir esta pregunta en la prueba? (s/n): ";
                cin >> incluir;
                cin.ignore();
                if (incluir == 's' || incluir == 'S') {
                    nuevaPrueba.agregarPregunta(p.getId());
                }
            }
        }
    }

    if (nuevaPrueba.getCantidadPreguntas() == 0) {
        cout << "\nNo se creó ninguna prueba ya que no se seleccionaron preguntas.\n";
    } else {
        pruebas[cantidad++] = nuevaPrueba;
        cout << "\nPrueba creada exitosamente con " << nuevaPrueba.getCantidadPreguntas() << " preguntas.\n";
    }
}

// Muestra todas las pruebas creadas
void GestorPruebas::mostrarPruebas(GestorPreguntas& gestorPreguntas) const {
    if (cantidad == 0) {
        cout << "No hay pruebas registradas.\n";
        return;
    }

    cout << "=== LISTA DE PRUEBAS ===\n";
    for (int i = 0; i < cantidad; i++) {
        pruebas[i].mostrar(gestorPreguntas);
    }
}

// Obtiene una prueba por su índice
Prueba* GestorPruebas::obtenerPrueba(int indice) {
    if (indice >= 0 && indice < cantidad) {
        return &pruebas[indice];
    }
    return nullptr;
}

// Obtiene la cantidad de pruebas en el gestor
int GestorPruebas::getCantidad() const {
    return cantidad;
}

// Busca una prueba por su ID
Prueba* GestorPruebas::buscarPorId(int id) {
    for(int i = 0; i < cantidad; i++) {
        if(pruebas[i].getId() == id) {
            return &pruebas[i];
        }
    }
    return nullptr;
}
