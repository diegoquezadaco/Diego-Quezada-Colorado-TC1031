#include <iostream>
#include "ClosetLavadora.h"
#include "PrendaRopa.h"
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ClosetLavadora miCloset;

    cout << "Número de prendas en el closet: " << miCloset.getNumPrendas() << endl;

    cout << "\nConsultar el estado del closet:" << endl;
    miCloset.consultarCloset();

    cout << "\nUsar una prenda:" << endl;
    miCloset.usarPrenda("Playera 1");

    cout << "\nConsultar el estado del closet después de usar una prenda:" << endl;
    miCloset.consultarCloset();

    cout << "\nComprar una prenda de la tienda:" << endl;
    miCloset.comprarPrenda("Camiseta9");

    cout << "\nConsultar el estado del closet después de comprar una prenda:" << endl;
    miCloset.consultarCloset();

    cout << "\nFiltrar el closet por tipo 'Playera':" << endl;
    miCloset.filtrarClosetTipo("Playera");

    cout << "\nFiltrar el closet por color 'Negro':" << endl;
    miCloset.filtrarClosetColor("Negro");

    cout << "\nFiltrar el closet por talla 'M':" << endl;
    miCloset.filtrarClosetTalla("M");

    cout << "\nFiltrar el closet por material 'Algodon':" << endl;
    miCloset.filtrarClosetMaterial("Algodon");

    cout << "\nFiltrar el closet por estado 'Limpia':" << endl;
    miCloset.filtrarClosetEstado("Limpia");

    cout << "\nOrdenar el closet por número de puestas:" << endl;
    miCloset.ordenarClosetPuestas();

    cout << "\nConsultar el estado del closet después de ordenar por número de puestas:" << endl;
    miCloset.consultarCloset();

    return 0;
}

