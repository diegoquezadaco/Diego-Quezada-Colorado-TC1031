/**
 * Proyecto Integrador - TC1031
 * Proyecto ClosetLavadora inteligente
 * Diego Quezada Colorado A01710024
 * 15/10/2023 
*/
/**
 * Clase ClosetLavadora
 * Esta es la clase que contiene las prendas de ropa
 * Sera compuesta por objetos de la clase PrendaRopa
 * Estará basado en la funcionalidad original de ClosetLavadora_borrador.h
 * sin emabrgo, ahora utilizará un arbol AVL para almacenar las prendas, en lugar de un arreglo
 * pero implementará el AVL como una clase
 * 
*/

#ifndef CLOSETLAVADORA_H
#define CLOSETLAVADORA_H
#include <iostream>
#include <string>
#include "PrendaRopa.h"
#include "AVL.h"
#include "Closet.csv"
#include "Tienda.csv"
#include <fstream>
using namespace std;

//Clase ClosetLavadora
class ClosetLavadora {
    private:
    //Declaro las variables de instancia
    AVL<PrendaRopa> *Closet;
    int num_prendas;
    AVL<PrendaRopa> *Tienda;
    int num_prendas_tienda;
    public:
    //Declaro los metodos de clase
    ClosetLavadora();
    void setNumPrendas();
    void setNumPrendasTienda();
    int getNumPrendas();
    int getNumPrendasTienda();

    //Metodos para interactuar con las prendas
    void crearPrenda(string _nombre, string _tipo, string _color, string _talla, 
                string _material, string _estado, int _puestas, int _id);
    int limpias();
    int lavando();
    void consultarCloset();
    void usarPrenda(int _id);
    void comprarPrenda(int _id);
    void desecharPrenda(int _id);
    void filtrarClosetTipo(string _tipo);
    void filtrarClosetColor(string _color);
    void filtrarClosetTalla(string _talla);
    void filtrarClosetMaterial(string _material);
    void filtrarClosetEstado(string _estado);
    void ordenarClosetPuestasPlayeras();
    void ordenarClosetPuestasPantalones();
    void ordenarClosetPuestasChamarras();
    void ordenarClosetPuestasZapatos();
    void ordenarClosetPuestasAccesorios();
    void ordenarClosetPuestasRopaInterior();
    void ordenarClosetPuestasCalcetines();
    void reasignarID();
    void creaCloset();
    void creaTienda();

};

//Metodos de clase
/**
 * Constructor
 * Este metodo inicializa las variables de instancia
 * 
 * @param
 * @return
 * 
 */
ClosetLavadora::ClosetLavadora(){
    creaCloset();
    creaTienda();
    setNumPrendas();
    setNumPrendasTienda();
}

/**
 * setNumPrendas
 * Este metodo inicializa el numero de prendas en el closet, recorriendo el
 * arbol con un fory contando el numero total de nodos, en este caso 
 * del árbol del closet y asigna ese valor a la variable de instancia 
 * num_prendas
 * 
 * 
 * @param
 * @return
 * 
 */
void ClosetLavadora::setNumPrendas(){
    string inor = Closet->inorder();
    int num = 0;
    for(int i = 0; i < inor.length(); i++){
        if(inor[i] == '\n'){
            num++;
        }
    }
    num_prendas = num;
}

/**
 * setNumPrendasTienda
 * Este metodo inicializa el numero de prendas en la tienda, recorriendo el
 * arbol con un fory contando el numero total de nodos, en este caso 
 * del árbol de la tienda y asigna ese valor a la variable de instancia 
 * num_prendas_tienda
 * 
 * 
 * @param
 * @return
 * 
 */

void ClosetLavadora::setNumPrendasTienda(){
    string inor = Tienda->inorder();
    int num = 0;
    for(int i = 0; i < inor.length(); i++){
        if(inor[i] == '\n'){
            num++;
        }
    }
    num_prendas_tienda = num;
}

/**
 * getNumPrendas
 * Este metodo regresa el numero de prendas en el closet
 * 
 * @param
 * @return int num_prendas
 * 
 */
int ClosetLavadora::getNumPrendas(){
    return num_prendas;
}

/**
 * getNumPrendasTienda
 * Este metodo regresa el numero de prendas en la tienda
 * 
 * @param
 * @return int num_prendas_tienda
 * 
 */
int ClosetLavadora::getNumPrendasTienda(){
    return num_prendas_tienda;
}

/**
 * crearPrenda
 * Este metodo agrega una prenda al closet, creando un objeto de la clase PrendaRopa
 * y agregandolo al arbol del closet o de la tienda, dependiendo de si se trata de una
 * prenda nueva o de una prenda comprada, obtiene la información de esta prenda
 * por medio de un archivo csv
 * 
 * esta función será llamada desde las funciones crearCloset y crearTienda
 * 
 * @param string _nombre, string _tipo, string _color, string _talla, 
 *        string _material, string _estado, int _puestas, int _id
 * @return
 * 
 */
void ClosetLavadora::crearPrenda(string _nombre, string _tipo, string _color, string _talla, 
                string _material, string _estado, int _puestas, int _id){
    PrendaRopa prenda(_nombre, _tipo, _color, _talla, _material, _estado, _puestas, _id);
    if (prenda.getEstado() == "Nueva"){
        Tienda->add(prenda);
    } else {
        Closet->add(prenda);
    }
}

/**
 * limpias
 * Este metodo regresa el numero de prendas limpias en el closet
 * recorre todas las prendas del arbol de closet y cuenta las que estan limpias
 * debido a que 
 * 
 * 
 * 
 * @param
 * @return int num_prendas
 * 
 */
int ClosetLavadora::limpias(){
    string inor = Closet->inorder();
    int num = 0;
    for(int i = 0; i < inor.length(); i++){
        if(inor[i] == 'L'){
            if (inor[i+1] == 'i'){
                if (inor[i+2] == 'm'){
                    if (inor[i+3] == 'p'){
                        if (inor[i+4] == 'i'){
                            if (inor[i+5] == 'a'){
                                num++;
                        }
                    }
                }
            }
        }
    }
}
return num;
}

/**
 * lavando
 * Este metodo regresa el numero de prendas en el closet que estan lavandose
 * recorre todas las prendas del arbol de closet y cuenta las que estan lavandose
 * con un for que busca en el arbol con la funcion search de la clase AVL
 * y después cambia el estado de las prendas que estan lavandose a "Limpias"
 * 
 * 
 * 
 * @param
 * @return int num_prendas
 * 
 */
int ClosetLavadora::lavando(){
    string inor = Closet->inorder();
    int num = 0;
    for(int i = 0; i < inor.length(); i++){
        if(inor[i] == 'L'){
            if (inor[i+1] == 'a'){
                if (inor[i+2] == 'v'){
                    if (inor[i+3] == 'a'){
                        if (inor[i+4] == 'n'){
                            if (inor[i+5] == 'd'){
                                if (inor[i+6] == 'o'){
                                    num++;
                                    PrendaRopa prenda = Closet->search(i+10);
                                    prenda.setEstado("Limpia");
                        }
                    }
                }
            }
        }
    }
}
}
return num;
}




/**
 * consultarCloset
 * Este metodo imprime el arbol del closet y los datos de cada prenda
 * separados por un salto de linea
 * 
 * 
 * 
 * @param
 * @return
 * 
 */
void ClosetLavadora::consultarCloset(){
    cout << "Prendas en el closet: " << getNumPrendas() << endl;
    cout << "Prendas limpias: " << limpias() << endl;
    cout << "Prendas lavandose: " << lavando() << endl;
    string o;
    cout << "¿Desea ver las prendas? (si/no)" << endl;
    cin >> o;
    if (o == "si"){
        cout << Closet->mostrarDatoss() << endl;
    }

}

/**
 * usarPrenda
 * Este metodo cambia el estado de una prenda de "limpia" a "usada"
 * recorre todas las prendas del arbol de closet y cambia el estado de la prenda
 * que se le indique, usando ek método search de la clase AVL
 * 
 * 
 * 
 * @param int _ID
 * @return
 * 
 */
void ClosetLavadora::usarPrenda(int _id){
        PrendaRopa prenda = Closet->search(_id);
        if (prenda.getID() == _id){
            if (prenda.getEstado()== "Limpia"){
                prenda.setPuestas(prenda.getPuestas() + 1);
                if (prenda.getTipo() == "Playera" ){
                    if (prenda.getPuestas() >= 1){
                        prenda.setEstado("Lavando");
                    }
                } else if (prenda.getTipo() == "Pantalon" ){
                    if (prenda.getPuestas() >= 4){
                        prenda.setEstado("Lavando");
                    }
                } else if (prenda.getTipo() == "Chamarra" ){
                    if (prenda.getPuestas() >= 5){
                        prenda.setEstado("Lavando");
                    }
                } else if (prenda.getTipo() == "Zapatos" ){
                    if (prenda.getPuestas() >= 15){
                        prenda.setEstado("Lavando");
                    }
                } else if (prenda.getTipo() == "Accesorio" ){
                    if (prenda.getPuestas() >= 20){
                        prenda.setEstado("Lavando");
                    }
                } else if (prenda.getTipo() == "Ropa interior" ){
                    if (prenda.getPuestas() >= 1){
                        prenda.setEstado("Lavando");
                    }
                } else if (prenda.getTipo() == "Calcetines" ){
                    if (prenda.getPuestas() >= 1){
                        prenda.setEstado("Lavando");
                    }
                }     
        } else {
            cout << "No se encontró la prenda" << endl;
        }
    }
}

/**
 * comprarPrenda
 * Este método le permite al usuario comprar una prenda del arbol de tienda
 * y agregarla al arbol de closet, el método además verifica que la prenda
 * que se desea comprar esté en la tienda y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * 
 * @param int _id
 * @return
*/
void ClosetLavadora::comprarPrenda(int _id){
    cout << "Mostrando prendas disponibles" << endl;
    cout << Tienda->mostrarDatoss() << endl;
    string o;
    cout << "¿Desea filtrar? (si/no)" << endl;
    cin >> o;
    if (o == "si"){
        string o2;
        cout << "¿Por qué atributo desea filtrar? (tipo/color/talla/material/estado)" << endl;
        cin >> o2;
        if (o2 == "tipo"){
            string tipo;
            cout << "¿Qué tipo de prenda desea?" << endl;
            cin >> tipo;
            filtrarClosetTipo(tipo);
        } else if (o2 == "color"){
            string color;
            cout << "¿Qué color de prenda desea?" << endl;
            cin >> color;
            filtrarClosetColor(color);
        } else if (o2 == "talla"){
            string talla;
            cout << "¿Qué talla de prenda desea?" << endl;
            cin >> talla;
            filtrarClosetTalla(talla);
        } else if (o2 == "material"){
            string material;
            cout << "¿Qué material de prenda desea?" << endl;
            cin >> material;
            filtrarClosetMaterial(material);
        } else if (o2 == "estado"){
            string estado;
            cout << "¿Qué estado de prenda desea?" << endl;
            cin >> estado;
            filtrarClosetEstado(estado);
        }
    }

    PrendaRopa prenda = Tienda->search(_id);
    if (prenda.getID() == _id){
        Closet->add(prenda);
        prenda.setEstado("Limpia");
        Tienda->remove(prenda);
        Tienda->balance_tree();
        Closet->balance_tree();
        setNumPrendas();
        setNumPrendasTienda();
        reasignarID();
    } else {
        cout << "No se encontró la prenda en la tienda" << endl;
    }
}

/**
 * desecharPrenda
 * Este método le permite al usuario desechar una prenda del arbol de closet
 * y eliminarla del arbol, el método además verifica que la prenda
 * que se desea desechar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * 
 * @param int _id
 * @return
*/

void ClosetLavadora::desecharPrenda(int _id){
    PrendaRopa prenda = Closet->search(_id);
    if (prenda.getID() == _id){
        Closet->remove(prenda);
        Closet->balance_tree();
        setNumPrendas();
        reasignarID();
    } else {
        cout << "No se encontró la prenda en el closet" << endl;
    }
}

/**
 * filtrarClosetTipo
 * Este método le permite al usuario filtrar las prendas del closet por tipo
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea filtrar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de filtrar Tipo de la clase AVL
 * 
 * @param string _tipo
 * @return
*/

void ClosetLavadora::filtrarClosetTipo(string _tipo){
    Closet->filtrarTipo(_tipo);
}

/**
 * filtrarClosetColor
 * Este método le permite al usuario filtrar las prendas del closet por color
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea filtrar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de filtrar Color de la clase AVL
 * 
 * @param string _color
 * @return
*/

void ClosetLavadora::filtrarClosetColor(string _color){
    Closet->filtrarColor(_color);
}

/**
 * filtrarClosetTalla
 * Este método le permite al usuario filtrar las prendas del closet por talla
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea filtrar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de filtrar Talla de la clase AVL
 * 
 * @param string _talla
 * @return
*/

void ClosetLavadora::filtrarClosetTalla(string _talla){
    Closet->filtrarTalla(_talla);
}

/**
 * filtrarClosetMaterial
 * Este método le permite al usuario filtrar las prendas del closet por material
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea filtrar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de filtrar Material de la clase AVL
 * 
 * @param string _material
 * @return
*/

void ClosetLavadora::filtrarClosetMaterial(string _material){
    Closet->filtrarMaterial(_material);
}

/**
 * filtrarClosetEstado
 * Este método le permite al usuario filtrar las prendas del closet por estado
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea filtrar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de filtrar Estado de la clase AVL
 * 
 * @param string _estado
 * @return
*/

void ClosetLavadora::filtrarClosetEstado(string _estado){
    Closet->filtrarEstado(_estado);
}

/**
 * ordenarClosetPuestasPlayeras
 * Este método le permite al usuario ordenar las prendas del closet por numero de puestas
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea ordenar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de ordenar Puestas de la clase AVL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasPlayeras(){
    Closet->ordenarPuestas(0, "Playera");
}

/**
 * ordenarClosetPuestasPantalones
 * Este método le permite al usuario ordenar las prendas del closet por numero de puestas
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea ordenar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de ordenar Puestas de la clase AVL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasPantalones(){
    Closet->ordenarPuestas(0, "Pantalon");
    Closet->ordenarPuestas(1, "Pantalon");
    Closet->ordenarPuestas(2, "Pantalon");
    Closet->ordenarPuestas(3, "Pantalon");
}

/**
 * ordenarClosetPuestasChamarras
 * Este método le permite al usuario ordenar las prendas del closet por numero de puestas
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea ordenar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de ordenar Puestas de la clase AVL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasChamarras(){
    Closet->ordenarPuestas(0, "Chamarra");
    Closet->ordenarPuestas(1, "Chamarra");
    Closet->ordenarPuestas(2, "Chamarra");
    Closet->ordenarPuestas(3, "Chamarra");
    Closet->ordenarPuestas(4, "Chamarra");
}

/**
 * ordenarClosetPuestasZapatos
 * Este método le permite al usuario ordenar las prendas del closet por numero de puestas
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea ordenar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de ordenar Puestas de la clase AVL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasZapatos(){
    Closet->ordenarPuestas(0, "Zapatos");
    Closet->ordenarPuestas(1, "Zapatos");
    Closet->ordenarPuestas(2, "Zapatos");
    Closet->ordenarPuestas(3, "Zapatos");
    Closet->ordenarPuestas(4, "Zapatos");
    Closet->ordenarPuestas(5, "Zapatos");
    Closet->ordenarPuestas(6, "Zapatos");
    Closet->ordenarPuestas(7, "Zapatos");
    Closet->ordenarPuestas(8, "Zapatos");
    Closet->ordenarPuestas(9, "Zapatos");
    Closet->ordenarPuestas(10, "Zapatos");
    Closet->ordenarPuestas(11, "Zapatos");
    Closet->ordenarPuestas(12, "Zapatos");
    Closet->ordenarPuestas(13, "Zapatos");
    Closet->ordenarPuestas(14, "Zapatos");
}

/**
 * ordenarClosetPuestasAccesorios
 * Este método le permite al usuario ordenar las prendas del closet por numero de puestas
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea ordenar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de ordenar Puestas de la clase AVL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasAccesorios(){
    Closet->ordenarPuestas(0, "Accesorio");
    Closet->ordenarPuestas(1, "Accesorio");
    Closet->ordenarPuestas(2, "Accesorio");
    Closet->ordenarPuestas(3, "Accesorio");
    Closet->ordenarPuestas(4, "Accesorio");
    Closet->ordenarPuestas(5, "Accesorio");
    Closet->ordenarPuestas(6, "Accesorio");
    Closet->ordenarPuestas(7, "Accesorio");
    Closet->ordenarPuestas(8, "Accesorio");
    Closet->ordenarPuestas(9, "Accesorio");
    Closet->ordenarPuestas(10, "Accesorio");
    Closet->ordenarPuestas(11, "Accesorio");
    Closet->ordenarPuestas(12, "Accesorio");
    Closet->ordenarPuestas(13, "Accesorio");
    Closet->ordenarPuestas(14, "Accesorio");
    Closet->ordenarPuestas(15, "Accesorio");
    Closet->ordenarPuestas(16, "Accesorio");
    Closet->ordenarPuestas(17, "Accesorio");
    Closet->ordenarPuestas(18, "Accesorio");
    Closet->ordenarPuestas(19, "Accesorio");
}

/**
 * ordenarClosetPuestasRopaInterior
 * Este método le permite al usuario ordenar las prendas del closet por numero de puestas
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea ordenar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de ordenar Puestas de la clase AVL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasRopaInterior(){
    Closet->ordenarPuestas(0, "Ropa interior");
}

/**
 * ordenarClosetPuestasCalcetines
 * Este método le permite al usuario ordenar las prendas del closet por numero de puestas
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea ordenar esté en el closet y acomoda nuevamente el arbol AVL
 * con los métodos del archivo AVL.h
 * usa el metodo de ordenar Puestas de la clase AVL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasCalcetines(){
    Closet->ordenarPuestas(0, "Calcetines");
}

/**
 * reasignarID
 * Este método reasigna los ID de las prendas en el closet, para que no haya
 * huecos en los ID, recorre todas las prendas del arbol de closet y cambia el ID de la prenda
 * que se le indique, usando ek método search de la clase AVL
 * hace uso de la función balance_tree de la clase AVL, y check_tree
 * 
 * 
 * 
 * @param 
 * @return
 * 
 */
void ClosetLavadora::reasignarID(){
    string inor = Closet->inorder();
    int num = 0;
    for(int i = 0; i < inor.length(); i++){
        if(inor[i] == '\n'){
            num++;
        }
    }
    int id = 0;
    for (int i = 0; i < num; i++){
        PrendaRopa prenda = Closet->search(i);
        if (prenda.getID() == i){
            prenda.setID(id);
            id++;
        } else {

        }
    }
    Closet->balance_tree();
}

/**
 * creaCloset
 * Este método crea el arbol del closet, leyendo un archivo csv
 * importado como un arreglo de strings, y separando los datos de cada prenda
 * en variables de tipo string, para después convertir los datos que lo requieran
 * a su tipo de dato correspondiente, y crear un objeto de la clase PrendaRopa
 * con estos datos con el metodo creaPrenda, y agregarlo al arbol del closet
 * 
 * 
 * 
 * @param 
 * @return
 * 
 */

void ClosetLavadora::creaCloset(){
    using namespace std;
    string prendas[100];
    ifstream archivoCSV("Closet.csv");
    string texto;
    int num = 0;
    if(archivoCSV.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while(getline(archivoCSV, texto)){
        prendas[num] = texto;
        num++;
    }
    archivoCSV.close();
    for (int i = 0; i < num; i++){
        string nombre;
        string tipo;
        string color;
        string talla;
        string material;
        string estado;
        int puestas;
        int id;
        string aux;
        int cont = 0;
        for (int j = 0; j < prendas[i].length(); j++){
            if (prendas[i][j] == ','){
                if (cont == 0){
                    nombre = aux;
                    aux = "";
                    cont++;
                } else if (cont == 1){
                    tipo = aux;
                    aux = "";
                    cont++;
                } else if (cont == 2){
                    color = aux;
                    aux = "";
                    cont++;
                } else if (cont == 3){
                    talla = aux;
                    aux = "";
                    cont++;
                } else if (cont == 4){
                    material = aux;
                    aux = "";
                    cont++;
                } else if (cont == 5){
                    estado = aux;
                    aux = "";
                    cont++;
                } else if (cont == 6){
                    puestas = stoi(aux);
                    aux = "";
                    cont++;
                }
            } else {
                aux = aux + prendas[i][j];
            }
        }
        id = stoi(aux);
        crearPrenda(nombre, tipo, color, talla, material, estado, puestas, id);
    }
}

/**
 * creaTienda
 * Este método crea el arbol de la tienda, leyendo un archivo csv
 * importado como un arreglo de strings, y separando los datos de cada prenda
 * en variables de tipo string, para después convertir los datos que lo requieran
 * a su tipo de dato correspondiente, y crear un objeto de la clase PrendaRopa
 * con estos datos con el metodo creaPrenda, y agregarlo al arbol de la tienda
 * 
 * 
 * 
 * @param 
 * @return
 * 
 */

void ClosetLavadora::creaTienda(){
    using namespace std;
    string prendas[100];
    ifstream archivoCSV("Tienda.csv");
    string texto;
    int num = 0;
    if(archivoCSV.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while(getline(archivoCSV, texto)){
        prendas[num] = texto;
        num++;
    }
    archivoCSV.close();
    for (int i = 0; i < num; i++){
        string nombre;
        string tipo;
        string color;
        string talla;
        string material;
        string estado;
        int puestas;
        int id;
        string aux;
        int cont = 0;
        for (int j = 0; j < prendas[i].length(); j++){
            if (prendas[i][j] == ','){
                if (cont == 0){
                    nombre = aux;
                    aux = "";
                    cont++;
                } else if (cont == 1){
                    tipo = aux;
                    aux = "";
                    cont++;
                } else if (cont == 2){
                    color = aux;
                    aux = "";
                    cont++;
                } else if (cont == 3){
                    talla = aux;
                    aux = "";
                    cont++;
                } else if (cont == 4){
                    material = aux;
                    aux = "";
                    cont++;
                } else if (cont == 5){
                    estado = aux;
                    aux = "";
                    cont++;
                } else if (cont == 6){
                    puestas = stoi(aux);
                    aux = "";
                    cont++;
                }
            } else {
                aux = aux + prendas[i][j];
            }
        }
        id = stoi(aux);
        crearPrenda(nombre, tipo, color, talla, material, estado, puestas, id);
    }
}




        


                           

        
        







#endif /* CLOSETLAVADORA_H */










