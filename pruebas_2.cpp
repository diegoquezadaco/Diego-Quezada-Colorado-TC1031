//en este main, probamos las funciones de ClosetLavadora, usando el constructor con parametros

#include <iostream>
#include <string>
#include "ClosetLavadora.h"
#include "Arbol.h"
#include "PrendaRopa.h"

using namespace std;

int main(){
    cout << "Se creo el main" << endl;
    ClosetLavadora c1 = ClosetLavadora();
    cout << "Se creo el closet" << endl;
    c1.consultarCloset();
    //cout << "Se consulto el closet" << endl;
    cout << c1.getCloset()->search(2)->getValue().mostrarDatos() << endl;
    cout << "Se imprimio la prenda 4" << endl;
    //eliminamos la prenda 4
    c1.desecharPrenda(2);
    cout << "Se elimino la prenda 4" << endl;
    //c1.consultarCloset();
    //imprimimos la prenda 4
    cout << c1.getCloset()->search(3)->getValue().mostrarDatos() << endl;
    cout << "Se consulto el closet" << endl;
    //actualizamos el archivo csv con los cambios
    c1.actualizaArchivo(c1.getCloset());


    
};
    



