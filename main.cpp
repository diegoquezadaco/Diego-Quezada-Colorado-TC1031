/**
 * Proyecto Integrador TC1031
 * Programación de estructuras de datos y algoritmos fundamentales
 * Profesor: Benjamín Valdés Aguirre.
 * Nombre: Diego Quezada Colorado.
 * A01710024.
*/
/**
 * main.cpp
*/

//realizamos un caso de prueba para todas nuestras funciones
//asímismo creamos un objeto de la clase ClosetLavadora, y creamos
//un arreglo de objetos de la clase PrendaRopa para probar las funciones de 
//ClosetLavadora
#include <iostream>
#include <string>
#include <algorithm>
#include "PrendaRopa.h"
#include "ClosetLavadora.h"
using namespace std;

int main(){
    ClosetLavadora closet1 = ClosetLavadora();
    //crearemos el menú principal del programa que permita al usuario interactuar con su closet
    //mostramos el menú principal y solicitamos al usuario elija entre esas opciones
    int opcion;
    cout << "Bienvenido a tu closet inteligente" << endl;
    cout << "¿Qué deseas hacer?" << endl;
    cout << "1. Eliminar una prenda" << endl;
    cout << "2. Buscar una prenda" << endl;
    cout << "3. Mostrar todas las prendas" << endl;
    cout << "4. Mostrar las prendas por tipo" << endl;
    cout << "5. Mostrar las prendas por color" << endl;
    cout << "6. Mostrar las prendas por talla" << endl;
    cout << "7. Mostrar las prendas por material" << endl;
    cout << "8. Mostrar las prendas por estado" << endl;
    cout << "9. Mostrar las prendas por puestas" << endl;
    cout << "10. Mostrar las prendas por ID" << endl;
    cout << "11. Mostrar las prendas por nombre" << endl;
    cout << "12. Salir" << endl;
    cout << "Selecciona una opción: ";
    cin >> opcion;
    //creamos un ciclo while que se repita mientras el usuario no elija la opción de salir
    










return 0;
}