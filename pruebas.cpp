#include <iostream>
#include "ClosetLavadora.h"
#include "PrendaRopa.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "Tienda.csv"
#include "PrendaRopa.h"
#include "AVL.h"
#include "Closet.csv"


using namespace std;
//archivo para probar todas las funciones de la clase ClosetLavadora

int main(){
    //creamos un objeto de tipo ClosetLavadora
    ClosetLavadora closet;
    //creamos y consultamos el closet
    closet.creaCloset();
    //caso de prueba para la función limpias
    cout << "caso de prueba para la función limpias" << endl;
    cout << closet.limpias() << endl;
    //caso de prueba para la función lavando
    cout << "caso de prueba para la función lavando" << endl;
    cout << closet.lavando() << endl;
    //caso de prueba para la función consultarCloset
    cout << "caso de prueba para la función consultarCloset" << endl;
    closet.consultarCloset();
    //caso de prueba para la función usarPrenda
    cout << "caso de prueba para la función usarPrenda" << endl;
    closet.usarPrenda(1);
    //caso de prueba para la función comprarPrenda
    cout << "caso de prueba para la función comprarPrenda" << endl;
    closet.comprarPrenda(1);
    //caso de prueba para la función desecharPrenda
    cout << "caso de prueba para la función desecharPrenda" << endl;
    closet.desecharPrenda(1);
    //caso de prueba para la función filtrarClosetTipo
    cout << "caso de prueba para la función filtrarClosetTipo" << endl;
    closet.filtrarClosetTipo("Playera");
    //caso de prueba para la función filtrarClosetColor
    cout << "caso de prueba para la función filtrarClosetColor" << endl;
    closet.filtrarClosetColor("Rojo");
    //caso de prueba para la función filtrarClosetTalla
    cout << "caso de prueba para la función filtrarClosetTalla" << endl;
    closet.filtrarClosetTalla("M");
    //caso de prueba para la función filtrarClosetMaterial
    cout << "caso de prueba para la función filtrarClosetMaterial" << endl;
    closet.filtrarClosetMaterial("Algodon");
    //caso de prueba para la función filtrarClosetEstado
    cout << "caso de prueba para la función filtrarClosetEstado" << endl;
    closet.filtrarClosetEstado("Lavando");
    //caso de prueba para la función ordenarClosetPuestasPlayeras
    cout << "caso de prueba para la función ordenarClosetPuestasPlayeras" << endl;
    closet.ordenarClosetPuestasPlayeras();
    //caso de prueba para la función ordenarClosetPuestasPantalones
    cout << "caso de prueba para la función ordenarClosetPuestasPantalones" << endl;
    closet.ordenarClosetPuestasPantalones();
    //caso de prueba para la función ordenarClosetPuestasChamarras
    cout << "caso de prueba para la función ordenarClosetPuestasChamarras" << endl;
    closet.ordenarClosetPuestasChamarras();
    //caso de prueba para la función ordenarClosetPuestasZapatos
    cout << "caso de prueba para la función ordenarClosetPuestasZapatos" << endl;
    closet.ordenarClosetPuestasZapatos();
    //caso de prueba para la función ordenarClosetPuestasAccesorios
    cout << "caso de prueba para la función ordenarClosetPuestasAccesorios" << endl;
    closet.ordenarClosetPuestasAccesorios();
    //caso de prueba para la función ordenarClosetPuestasRopaInterior
    cout << "caso de prueba para la función ordenarClosetPuestasRopaInterior" << endl;
    closet.ordenarClosetPuestasRopaInterior();
    //caso de prueba para la función ordenarClosetPuestasCalcetines
    cout << "caso de prueba para la función ordenarClosetPuestasCalcetines" << endl;
    closet.ordenarClosetPuestasCalcetines();
    //caso de prueba para la función reasignarID
    cout << "caso de prueba para la función reasignarID" << endl;
    closet.reasignarID();
};



