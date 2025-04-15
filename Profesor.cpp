// IMPLEMENTACIÓN DE LA CLASE PROFESOR

#include "Profesor.h"
#include <iostream>
#include <chrono>

using namespace std;

time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());         // Obtener el año actual
tm* ltm = localtime(&now);
const int anioActual = 1900 + ltm->tm_year;

// Constructor con parámetros
Profesor::Profesor(string nombre) {
    this->nombre = nombre;
}

// Destructor de la clase
Profesor::~Profesor() {}

// Menú principal del profesor
void Profesor::menu(GestorPreguntas* gestorPreguntas, GestorPruebas* gestorPruebas) {
    int opcion, anio, nivelInput;
    string asignatura, nombreArchivo;
    float ponderacion;
    NivelTaxonomico nivel;
    
    cout<<"¡Bienvenido profesor "<<nombre<<"!";
    do {        
        cout << "\n=== Menu Profesor ===" << endl;
        cout << "1. Crear prueba" << endl;                       
        cout << "2. Ver pruebas" << endl;                         
        cout << "3. Cargar preguntas desde archivo" << endl;
        cout << "4. Crear pregunta manualmente" << endl;
        cout << "5. Actualizar pregunta" << endl;
        cout << "6. Eliminar pregunta" << endl;
        cout << "7. Ver todas las preguntas" << endl;
        cout << "8. Buscar pregunta por nivel taxonomico" << endl;
        cout << "9. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:                                     // Crear una nueva prueba
                cout << "Ingrese la asignatura: ";
                getline(cin, asignatura);
                cout << "Ingrese la ponderacion: ";
                cin >> ponderacion;
                cout << "Ingrese el anio: ";
                cin >> anio;
                gestorPruebas->crearPrueba(asignatura, ponderacion, anio, *gestorPreguntas, anioActual);
                break;
            case 2:                                     // Mostrar todas las pruebas creadas
                gestorPruebas->mostrarPruebas(*gestorPreguntas);
                break;
            case 3:                                     // Cargar preguntas desde un archivo
                cout << "Ingrese el nombre del archivo: ";
                getline(cin, nombreArchivo);
                gestorPreguntas->cargarDesdeArchivo(nombreArchivo.c_str());
                break;
            case 4:                                     // Crear una nueva pregunta manualmente
                gestorPreguntas->crearPregunta();
                break;
            case 5:                                     // Modificar una pregunta existente
                gestorPreguntas->modificarPregunta();
                break;
            case 6:                                     // Eliminar una pregunta existente
                gestorPreguntas->eliminarPregunta();
                break;
            case 7:                                     // Mostrar todas las preguntas válidas para el año actual
                gestorPreguntas->mostrarPreguntas(anioActual);
                break;
            case 8:                                     // Buscar preguntas por nivel taxonómico
                cout << "Seleccione el nivel de la pregunta que desea buscar (0 - Recordar, 1 - Entender, 2 - Aplicar, 3 - Analizar, 4 - Evaluar, 5 - Crear): ";
                while (true) {
                    cin >> nivelInput;
                    if (nivelInput >= 0 && nivelInput <= 5) {
                        nivel = static_cast<NivelTaxonomico>(nivelInput);
                        gestorPreguntas->buscarPorNivel(nivel, anioActual);
                        break;
                    } else {
                        cout << "Entrada inválida. Por favor, ingrese un número entre 0 y 5.\n";
                        cout << "Seleccione el nivel de la pregunta que desea buscar (0 - Recordar, 1 - Entender, 2 - Aplicar, 3 - Analizar, 4 - Evaluar, 5 - Crear): ";
                    }
                }
                break;
            case 9:                                     // Volver al menú principal
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 9);
}