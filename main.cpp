// PUNTO DE ENTRADA DEL PROGRAMA
// Este archivo contiene el punto de entrada principal del programa, que maneja la interacción con el usuario y la ejecución del sistema.

#include <iostream>
#include <string>
#include "GestorPreguntas.h"
#include "GestorPruebas.h"
#include "Profesor.h"
#include "Alumno.h"

using namespace std;

int main() {
    int opcion;
    string nombre;
    GestorPreguntas gestorPreguntas;  // Gestor para administrar las preguntas
    GestorPruebas gestorPruebas;      // Gestor para administrar las pruebas
    
    do {
        // Menú principal del sistema
        cout << "=== Sistema de Gestion de Pruebas ===" << endl;
        cout << "1. Profesor" << endl;
        cout << "2. Alumno" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione su rol: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1 || opcion == 2) {
            cout<<"Ingrese su nombre: ";
            cin>>nombre;
            cin.ignore();
        }
    
        // Manejo de roles
        if (opcion == 1) {
            Profesor prof(nombre);  // Crear instancia de profesor
            prof.menu(&gestorPreguntas, &gestorPruebas);  // Mostrar menú de profesor
        } else if (opcion == 2) {
            Alumno alum(nombre);    // Crear instancia de alumno
            alum.menu(&gestorPreguntas, &gestorPruebas);  // Mostrar menú de alumno
        } else if (opcion != 3) {
            cout << "Opcion invalida." << endl;
        }
    } while(opcion != 3);  // Continuar hasta que se elija salir

    return 0;
}
