
/**
 * @file GestorPreguntas.cpp
 * @brief Implementación de la clase GestorPreguntas
 */

#include "GestorPreguntas.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor por defecto
GestorPreguntas::GestorPreguntas() {
    capacidad = 30;
    preguntas = new Pregunta[capacidad];
    cantidad = 0;
}

// Destructor de la clase
GestorPreguntas::~GestorPreguntas() {
    delete[] preguntas;
}

// Constructor de copia
GestorPreguntas::GestorPreguntas(const GestorPreguntas& otro) {
    capacidad = otro.capacidad;
    cantidad = otro.cantidad;
    preguntas = new Pregunta[capacidad];
    for(int i = 0; i < cantidad; i++) {
        preguntas[i] = otro.preguntas[i];
    }
}

// Operador de asignación
GestorPreguntas& GestorPreguntas::operator=(const GestorPreguntas& otro) {
    if(this != &otro) {
        delete[] preguntas;
        capacidad = otro.capacidad;
        cantidad = otro.cantidad;
        preguntas = new Pregunta[capacidad];
        for(int i = 0; i < cantidad; i++) {
            preguntas[i] = otro.preguntas[i];
        }
    }
    return *this;
}

// Agrega una pregunta al gestor
void GestorPreguntas::agregarPregunta(const Pregunta& p) {
    if (cantidad >= capacidad) {
        int nuevaCapacidad = capacidad * 2;
        Pregunta* nuevoArreglo = new Pregunta[nuevaCapacidad];        // Crear un nuevo arreglo con mayor capacidad en caso de ser necesario
        for (int i = 0; i < cantidad; i++) {
            nuevoArreglo[i] = preguntas[i];
        }
        delete[] preguntas;
        preguntas = nuevoArreglo;                                     // Asignar el nuevo arreglo al arreglo original
        capacidad = nuevaCapacidad;
    }
    preguntas[cantidad++] = p;
}

// Crea una nueva pregunta
void GestorPreguntas::crearPregunta() {
    string enunciado, solucion, asignatura;
    int tiempoEstimado, anioCreacion;
    int nivelInt, tipoInt;

    cout << "Ingrese el enunciado de la pregunta: ";
    getline(cin, enunciado);

    cout << "Ingrese el nivel taxonómico (0: Recordar, 1: Entender, 2: Aplicar, 3: Analizar, 4: Evaluar, 5: Crear): ";
    while (true) {
        cin >> nivelInt;
        if (nivelInt >= 0 && nivelInt <= 5) break;
        else {
            cout << "Nivel inválido. Ingrese un valor entre 0 y 5: ";
            cin.clear();
        }
    }

    cout << "Ingrese el tipo de pregunta (0: Verdadero/Falso, 1: Respuesta Corta, 2: Selección Múltiple): ";
    while (true) {
        cin >> tipoInt;
        if (tipoInt >= 0 && tipoInt <= 2) break;
        else {
            cout << "Tipo inválido. Ingrese un valor entre 0 y 2: ";
            cin.clear();
        }
    }

    cout << "Ingrese el tiempo estimado (en minutos): ";
    cin >> tiempoEstimado;

    cout << "Ingrese la solución esperada: ";
    cin.ignore(); 
    getline(cin, solucion);

    cout << "Ingrese el año de creación de la pregunta: ";
    cin >> anioCreacion;

    cout << "Ingrese la asignatura de la pregunta: ";
    cin.ignore();  
    getline(cin, asignatura);

    Pregunta nuevaPregunta(enunciado, static_cast<NivelTaxonomico>(nivelInt), static_cast<TipoPregunta>(tipoInt),
                           tiempoEstimado, solucion, anioCreacion, asignatura);

    agregarPregunta(nuevaPregunta);
}

// Modifica una pregunta existente
void GestorPreguntas::modificarPregunta() {
    int idBuscado;
    cout << "Ingrese el ID de la pregunta que desea actualizar: ";
    cin >> idBuscado;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (preguntas[i].getId() == idBuscado) {
            encontrado = true;

            cout << "Pregunta encontrada:\n";
            preguntas[i].mostrar(); 

            string enunciado;
            cout << "Ingrese el nuevo enunciado: ";
            cin.ignore();
            getline(cin, enunciado);
            
            int nivelInt;
            cout << "Ingrese el nuevo nivel taxonómico (0: Recordar, 1: Entender, 2: Aplicar, 3: Analizar, 4: Evaluar, 5: Crear): ";
            while (true) {
                cin >> nivelInt;
                if (nivelInt >= 0 && nivelInt <= 5) break;
                else {
                    cout << "Nivel inválido. Ingrese un valor entre 0 y 5: ";
                    cin.clear();
                    cin.ignore();
                }
            }

            int tipoInt;
            cout << "Ingrese el nuevo tipo de pregunta (0: Verdadero/Falso, 1: Respuesta Corta, 2: Selección Múltiple): ";
            while (true) {
                cin >> tipoInt;
                if (tipoInt >= 0 && tipoInt <= 2) break;
                else {
                    cout << "Tipo inválido. Ingrese un valor entre 0 y 2: ";
                    cin.clear();
                    cin.ignore();
                }
            }

            int tiempoEstimado;
            cout << "Ingrese el nuevo tiempo estimado (en minutos): ";
            cin >> tiempoEstimado;

            string solucion;
            cout << "Ingrese la nueva solución esperada: ";
            cin.ignore();
            getline(cin, solucion);

            int anioCreacion;
            cout << "Ingrese el nuevo año de creación: ";
            cin >> anioCreacion;

            string asignatura;
            cout << "Ingrese la nueva asignatura: ";
            cin.ignore();
            getline(cin, asignatura);

            preguntas[i].setEnunciado(enunciado);
            preguntas[i].setNivel(static_cast<NivelTaxonomico>(nivelInt));
            preguntas[i].setTipo(static_cast<TipoPregunta>(tipoInt));
            preguntas[i].setTiempoEstimado(tiempoEstimado);
            preguntas[i].setSolucion(solucion);
            preguntas[i].setAnioCreacion(anioCreacion);
            preguntas[i].setAsignatura(asignatura);

            cout << "Pregunta actualizada correctamente.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró la pregunta con ID: " << idBuscado << endl;
    }
}

// Elimina una pregunta existente
void GestorPreguntas::eliminarPregunta() {
    int idBuscado;
    cout << "Ingrese el ID de la pregunta que desea eliminar: ";
    cin >> idBuscado;

    bool encontrada = false;

    for (int i = 0; i < cantidad; i++) {
        if (preguntas[i].getId() == idBuscado) {
            for (int j = i; j < cantidad - 1; j++) {
                preguntas[j] = preguntas[j + 1];
            }
            cantidad--;
            encontrada = true;
            cout << "Pregunta eliminada correctamente.\n";
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró la pregunta con ID: " << idBuscado << endl;
    }
}

// Muestra todas las preguntas válidas para el año actual (que tenga menos de 2 años)
void GestorPreguntas::mostrarPreguntas(int anioActual) const {
    bool hayPreguntas = false;

    for (int i = 0; i < cantidad; i++) {
        if (preguntas[i].esValida(anioActual)) {
            if (!hayPreguntas) {
                cout << "=== PREGUNTAS DISPONIBLES ===\n";
            }
            hayPreguntas = true;
            preguntas[i].mostrar();
        }
    }

    if (!hayPreguntas) {
        cout << "No hay preguntas válidas para el año actual.\n";
    }
}

// Busca preguntas por nivel taxonómico y válidas para el año actual
void GestorPreguntas::buscarPorNivel(NivelTaxonomico nivel, int anioActual) const {
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (preguntas[i].getNivel() == nivel && preguntas[i].esValida(anioActual)) {
            preguntas[i].mostrar();
            cout << "-----------------------------\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron preguntas para el nivel seleccionado y el año proporcionado.\n";
    }
}

// Carga preguntas desde un archivo
void GestorPreguntas::cargarDesdeArchivo(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);        // Utilizar stringstream para dividir la línea por ';'
        string enunciado, nivelStr, tipoStr, tiempoStr, solucion, anioStr, asignatura;

        getline(ss, enunciado, ';');    
        enunciado = trim(enunciado);
        getline(ss, nivelStr, ';');
        nivelStr = trim(nivelStr);
        getline(ss, tipoStr, ';');
        tipoStr = trim(tipoStr);
        getline(ss, tiempoStr, ';');
        tiempoStr = trim(tiempoStr);
        getline(ss, solucion, ';');
        solucion = trim(solucion);
        getline(ss, anioStr, ';');
        anioStr = trim(anioStr);
        getline(ss, asignatura, ';');
        asignatura = trim(asignatura);

        int nivel = stoi(nivelStr);
        int tipo = stoi(tipoStr);
        int tiempo = stoi(tiempoStr);
        int anio = stoi(anioStr);

        Pregunta p(enunciado, static_cast<NivelTaxonomico>(nivel), static_cast<TipoPregunta>(tipo), tiempo, solucion, anio, asignatura);
        agregarPregunta(p);
    }

    archivo.close();
    cout << "Preguntas cargadas correctamente.\n";
}

// Elimina espacios en blanco al inicio y al final de una cadena
string GestorPreguntas::trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Obtiene una pregunta por su índice
Pregunta GestorPreguntas::obtenerPregunta(int indice) const {
    if (indice >= 0 && indice < cantidad) {
        return preguntas[indice];
    }
    return Pregunta();
}

// Obtiene la cantidad de preguntas en el gestor
int GestorPreguntas::getCantidad() const {
    return cantidad;
}

// Busca una pregunta por su ID
Pregunta GestorPreguntas::buscarPorId(int id) const {
    for (int i = 0; i < cantidad; i++) {
        if (preguntas[i].getId() == id) {
            return preguntas[i];
        }
    }
    cout << "No se encontró la pregunta con ID: " << id << endl;
    return Pregunta();
}
