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
#include "DLL.h"
using namespace std;

int main(){
    ClosetLavadora closet1 = ClosetLavadora();
    //crearemos el menú principal del programa que permita al usuario interactuar con su closet
    //mostramos el menú principal y solicitamos al usuario elija entre esas opciones
    int opcion;
    cout << "Bienvenido a tu closet inteligente" << endl;
    
    while (opcion !=7){
        cout << "MENU" << endl;
        cout << "¿Qué deseas hacer?" << endl;
        cout << "Si desea usar las funciones 4 y 6, le recomendamos que primero consulte el closet con las funciones entre la 1 y la 3 "<< endl;
        cout << "1. Consultar closet" << endl;
        cout << "2. Filtrar closet" << endl;
        cout << "3. Ordenar Closet por puestas" << endl;
        cout << "4. Usar prenda (requiere ID)" << endl;
        cout << "5. Comprar prenda" << endl;
        cout << "6. Desechar prenda (requiere ID)" << endl;
        
        cout << "7. Salir" << endl;
        cin >> opcion;
        if (opcion == 1){
            closet1.consultarCloset();
        } else if (opcion == 2){
            cout << "¿Por que atributo desea filtrar el closet?" << endl;
            cout << "1. Tipo" << endl;
            cout << "2. Color" << endl;
            cout << "3. Talla" << endl;
            cout << "4. Material" << endl;
            cout << "5. Estado" << endl;
            int opcion2;
            cin >> opcion2;
            if (opcion2 == 1){
                cout << "¿Qué tipo de prenda desea?" << endl;
                cout << "1. Playera" << endl;
                cout << "2. Pantalon" << endl;
                cout << "3. Chamarra" << endl;
                cout << "4. Zapatos" << endl;
                cout << "5. Accesorio" << endl;
                cout << "6. Ropa interior" << endl;
                cout << "7. Calcetines" << endl;
                int opcion3;
                cin >> opcion3;
                if (opcion3 == 1){
                    closet1.filtrarClosetTipo("Playera ");
                } else if (opcion3 == 2){
                    closet1.filtrarClosetTipo("Pantalon");
                } else if (opcion3 == 3){
                    closet1.filtrarClosetTipo("Chamarra");
                } else if (opcion3 == 4){
                    closet1.filtrarClosetTipo("Zapatos ");
                } else if (opcion3 == 5){
                    closet1.filtrarClosetTipo("Accesorio");
                } else if (opcion3 == 6){
                    closet1.filtrarClosetTipo("Ropa interior");
                } else if (opcion3 == 7){
                    closet1.filtrarClosetTipo("Calcetines");
                } else {
                    cout << "Opción no válida" << endl;
                }

                
            } else if (opcion2 == 2){
                cout << "¿Qué color de prenda desea?" << endl;
                cout << "1. Blanco" << endl;
                cout << "2. Negro" << endl;
                cout << "3. Azul" << endl;
                cout << "4. Verde" << endl;
                cout << "5. Rojo" << endl;
                cout << "6. Plata" << endl;
                cout << "7. Dorado" << endl;
                int opcion3;
                cin >> opcion3;
                if (opcion3 == 1){
                    closet1.filtrarClosetColor("Blanco");
                } else if (opcion3 == 2){
                    closet1.filtrarClosetColor("Negro");
                } else if (opcion3 == 3){
                    closet1.filtrarClosetColor("Azul");
                } else if (opcion3 == 4){
                    closet1.filtrarClosetColor("Verde");
                } else if (opcion3 == 5){
                    closet1.filtrarClosetColor("Rojo");
                } else if (opcion3 == 6){
                    closet1.filtrarClosetColor("Plata");
                } else if (opcion3 == 7){
                    closet1.filtrarClosetColor("Dorado");
                } else {
                    cout << "No cuentas con dicho color en tu closet" << endl;
                }
                
            } else if (opcion2 == 3){
                cout << "¿Por qué talla desea filtrar?" << endl;
                cout << "1. S" << endl;
                cout << "2. M" << endl;
                cout << "3. L" << endl;
                cout << "4. Unitalla" <<endl;
                int opcion3;
                cin >> opcion3;
                if (opcion3 == 1){
                    closet1.filtrarClosetTalla("S");
                } else if (opcion3 == 2){
                    closet1.filtrarClosetTalla("M");
                } else if (opcion3 == 3){
                    closet1.filtrarClosetTalla("L");
                } else if (opcion3 == 4){
                    closet1.filtrarClosetTalla("U");
                }else {
                    cout << "No es una talla válida" << endl;
                }
                
            } else if (opcion2 == 4){
                cout << "¿Por qué material desea filtrar?" << endl;
                cout << "1. Algodón" << endl;
                cout << "2. Lino" << endl;
                cout << "3. Seda" << endl;
                cout << "4. Plástico" << endl;
                cout << "5. Piel" << endl;
                cout << "6. Metal" << endl;
                int opcion3;
                cin >> opcion3;
                if (opcion3 == 1){
                    closet1.filtrarClosetMaterial("Algodón");
                } else if (opcion3 == 2){
                    closet1.filtrarClosetMaterial("Lino");
                } else if (opcion3 == 3){
                    closet1.filtrarClosetMaterial("Seda");
                } else if (opcion3 == 4){
                    closet1.filtrarClosetMaterial("Plastic");
                } else if (opcion3 == 5){
                    closet1.filtrarClosetMaterial("Piel");
                } else if (opcion3 == 6){
                    closet1.filtrarClosetMaterial("Metal");
                } else {
                    cout << "No es un material válido" << endl;
                }

            } else if (opcion2 == 5){
                cout << "¿Por qué estado desea filtrar?" << endl;
                cout << "1. Limpia" << endl;
                cout << "2. Lavando" << endl;
                int opcion3;
                cin >> opcion3;
                if (opcion3 == 1){
                    closet1.filtrarClosetEstado("Limpio");
                } else if (opcion3 == 2){
                    closet1.filtrarClosetEstado("Lavando");
                } else {
                    cout << "No es un estado válido" << endl;
                }
            } else {
                cout << "Opción no válida" << endl;
            }
        } else if (opcion == 3){
            cout << "¿Por qué tipo de prenda desea ordenar el closet por puestas?" << endl;
            cout << "1. Playera" << endl;
            cout << "2. Pantalon" << endl;
            cout << "3. Chamarra" << endl;
            cout << "4. Zapatos" << endl;
            cout << "5. Accesorio" << endl;
            cout << "6. Ropa interior" << endl;
            cout << "7. Calcetines" << endl;
            int opcion3;
            cin >> opcion3;
            if (opcion3 == 1){
                closet1.ordenarClosetPuestasPlayeras();
            } else if (opcion3 == 2){
                closet1.ordenarClosetPuestasPantalones();
            } else if (opcion3 == 3){
                closet1.ordenarClosetPuestasChamarras();
            } else if (opcion3 == 4){
                closet1.ordenarClosetPuestasZapatos();
            } else if (opcion3 == 5){
                closet1.ordenarClosetPuestasAccesorios();
            } else if (opcion3 == 6){
                closet1.ordenarClosetPuestasRopaInterior();
            } else if (opcion3 == 7){
                closet1.ordenarClosetPuestasCalcetines();
            } else {
                cout << "Opción no válida" << endl;
            }
        } else if (opcion == 4){
            cout << "Escriba el ID de la prenda que desea usar?" << endl;
            int id;
            cin >> id;
            closet1.usarPrenda(id);
        } else if (opcion == 5){
            cout << "Bienvenido a la tienda" << endl;
            cout << "Estos son los productos que tenemos disponibles" << endl;
            cout << "--------------------------------------------------------------"<< endl;
            cout << "ID" << "\t" << "Nombre" << "\t" << "\t" << "\t" << "Tipo" << "\t" << "\t"<< "Color" << "\t" << "Talla" << "\t" << "Material" << "\t" << "Estado" << "\t" << "Puestas" << endl;
            cout << closet1.getTienda()->mostrarDatos()<< endl;
            cout << "--------------------------------------------------------------"<< endl;
            cout << "Escriba el ID de la prenda que desea comprar?" << endl;
            int id;
            cin >> id;
            closet1.comprarPrenda(id);
            cout << "Prenda comprada" << endl;
        } else if (opcion == 6){
            cout << "Escriba el ID de la prenda que desea desechar?" << endl;
            int id;
            cin >> id;
            closet1.desecharPrenda(id);
            cout << "Prenda desechada" << endl;
        } else if (opcion == 7){
            closet1.actualizaArchivo(closet1.getTienda());
            closet1.actualizaArchivo(closet1.getCloset());

            cout << "Gracias por usar tu closet inteligente" << endl;
        } else {
            cout << "Opción no válida" << endl;
        }

        }

    

return 0;
}