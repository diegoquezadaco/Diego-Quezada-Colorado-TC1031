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
 * sin emabrgo, ahora utilizará un DLL DLL para almacenar las prendas, en lugar de un arreglo
 * pero implementará el DLL como una clase
 * 
*/

#ifndef CLOSETLAVADORA_H
#define CLOSETLAVADORA_H
#include <iostream>
#include <string>
#include "PrendaRopa.h"
#include <sstream>
#include <fstream>
#include <vector>
#include "exception.h"
#include <algorithm>
#include "DLL.h"
//#include "DLL.h"

using namespace std;

//Clase ClosetLavadora
class ClosetLavadora {
    private:
    //Declaro las variables de instancia
    int num_prendas=0;
    DLL *Tienda;
    int num_prendas_tienda=0;
    DLL *Closet;
    public:
    //Declaro los metodos de clase

    DLL* getCloset();
    DLL* getTienda();
    ClosetLavadora();
    ClosetLavadora(string _s);
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
    void creaCloset();
    void creaTienda();
    void actualizaArchivo(DLL* DLL);

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
    Closet = new DLL;
    Tienda = new DLL;
    creaCloset();
    creaTienda();
    setNumPrendas();
    setNumPrendasTienda();
}

/**
 * Constructor
 * Este metodo inicializa las variables de instancia
 * 
 * @param string _s
 * @return
 * 
 */

ClosetLavadora::ClosetLavadora(string _s){
    //setNumPrendas();
    //setNumPrendasTienda();
    Closet = new DLL;
    setNumPrendas();


}

//getCloset

/**
 * getCloset
 * Este metodo regresa el DLL del closet
 * 
 * @param
 * @return DLL *Closet
 * 
 */

DLL* ClosetLavadora::getCloset(){
    return Closet;
}

/**
 * getTienda
 * Este metodo regresa el DLL de la tienda
 * 
 * @param
 * @return DLL *Tienda
 * 
 */

DLL* ClosetLavadora::getTienda(){
    return Tienda;
}


/**
 * setNumPrendas
 * Este metodo inicializa el numero de prendas en el closet, recorriendo el
 * DLL, nodo por nodo y contando el numero total de nodos en el DLL, en este caso
 * partiendo desde la raiz, y asigna ese valor a la variable de instancia
 * num_prendas, checando si el value de cada nodo es diferente de nullptr
 * 
 * 
 * @param
 * @return
 * 
 */

void ClosetLavadora::setNumPrendas(){
    //nos apoyamos de la función de DLL de contar_prendas para contar el numero de prendas en el closet
    if (!Closet->empty()){
        num_prendas = Closet->size;
    } else {
        num_prendas = 0;
    }
}




/**
 * setNumPrendasTienda
 * Este metodo inicializa el numero de prendas en la tienda, recorriendo el
 * DLL con un fory contando el numero total de nodos, en este caso 
 * del árbol de la tienda y asigna ese valor a la variable de instancia 
 * num_prendas_tienda
 * 
 * 
 * @param
 * @return
 * 
 */

void ClosetLavadora::setNumPrendasTienda(){
    //nos apoyamos de la función de DLL de contar_prendas para contar el numero de prendas en la tienda
    if (Tienda->getHead() != nullptr){
        num_prendas_tienda = Tienda->getSize();
    } else {
        num_prendas_tienda = 0;
    }
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
 * y agregandolo al DLL del closet o de la tienda, dependiendo de si se trata de una
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
        setNumPrendas();
    }
}

/**
 * limpias
 * Este metodo regresa el numero de prendas limpias en el closet
 * recorre todas las prendas del DLL de closet y cuenta las que estan limpias,
 * recorriendo todos los elementos del DLL con ayuda de su atributo id y checando elemento por elemento si es limpia o lavando
 * 
 * 
 * 
 * @param
 * @return int num_prendas
 * 
 */

int ClosetLavadora::limpias(){
    
    int i= num_prendas;
    int num = 0;
    for (int j = 1; j < i; j++){
        DLink* nodo = Closet->search(j);
        if (nodo != Closet->getTail() && nodo->getData().getEstado() == "Limpia"){
            num++;
        }
    }
    return num;
}

/**
 * lavando
 * Este metodo regresa el numero de prendas en el closet que estan lavandose
 * recorre todas las prendas del DLL de closet y cuenta las que estan lavandose
 * con un for que busca en el DLL con la funcion search de la clase DLL
 * y después cambia el estado de las prendas que estan lavandose a "Limpias"
 * 
 * 
 * 
 * @param
 * @return int num_prendas
 * 
 */

int ClosetLavadora::lavando(){
    int i= num_prendas;
    int num = 0;
    for (int j = 1; j < i; j++){
        DLink* nodo = Closet->search(j);
        if (nodo != nullptr && nodo->getData().getEstado() == "Lavando"){
            num++;
            Closet->search(j)->getData().setEstado("Limpia");
        }
    }
    return num;
}






/**
 * consultarCloset
 * Este metodo imprime el DLL del closet y los datos de cada prenda
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
    //cout << "Prendas limpias: " << limpias() << endl;
    //cout << "Prendas lavandose: " << lavando() << endl;
    string o;
    cout << "¿Desea ver las prendas? (si/no)" << endl;
    cin >> o;
    if (o == "si"){
        //desplegamos los valores en forma de una tabla con los atributos de cada prenda
        cout << "------------------------------------------------------------------------------------------------"<< endl;
        cout << "ID" << "\t" << "Nombre" << "\t" << "\t" << "Tipo" << "\t" << "\t"<< "Color" << "\t" << "Talla" << "\t" << "Material" << "\t" << "Estado" << "\t" << "Puestas" << endl;
        cout << Closet->mostrarDatos() << endl;
        cout << "------------------------------------------------------------------------------------------------"<< endl;
    }

}

/**
 * usarPrenda
 * Este metodo cambia el estado de una prenda de "limpia" a "usada"
 * recorre todas las prendas del DLL de closet y cambia el estado de la prenda
 * que se le indique, usando ek método search de la clase DLL
 * 
 * 
 * 
 * @param int _ID
 * @return
 * 
 */
void ClosetLavadora::usarPrenda(int _id){
    
    
        PrendaRopa prenda = (Closet->search(_id))->getData();

        if (prenda.getID() == _id){
            if (prenda.getEstado()== "Limpia"){
                prenda.setPuestas(prenda.getPuestas() + 1);
                if (prenda.getTipo() == "Playera" ){
                    cout << prenda.getPuestas() << endl;
                    if (prenda.getPuestas() > 1){
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
 * Este método le permite al usuario comprar una prenda del DLL de tienda
 * y agregarla al DLL de closet, el método además verifica que la prenda
 * que se desea comprar esté en la tienda y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * 
 * @param int _id
 * @return
*/

void ClosetLavadora::comprarPrenda(int _id){
    DLink* nodo = Tienda->search(_id);
    if (nodo != nullptr){
        PrendaRopa prenda = nodo->getData();
        prenda.setEstado("Limpia");
        Closet->add(prenda);
        Tienda->remove(prenda);
        setNumPrendas();
        setNumPrendasTienda();
        Closet->reasignarID();
    } else {
        cout << "No se encontró la prenda en la tienda" << endl;
    }
}

/**
 * desecharPrenda
 * Este método le permite al usuario desechar una prenda del DLL de closet
 * y eliminarla del DLL, el método además verifica que la prenda
 * que se desea desechar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * 
 * @param int _id
 * @return
*/

//creamos desechar prenda, que elimina una prenda del closet
//hacemos uso de la nueva implementacion de DLL

void ClosetLavadora::desecharPrenda(int _id){
    DLink* nodo = Closet->search(_id);
    if (nodo != nullptr){
        PrendaRopa prenda = nodo->getData();
        Closet->remove(prenda);
        setNumPrendas();
        Closet->reasignarID();
    } else {
        cout << "No se encontró la prenda en el closet" << endl;
    }
}

/**
 * filtrarClosetTipo
 * Este método le permite al usuario filtrar las prendas del closet por tipo
 * y mostrarlas en pantalla, el método además verifica que la prenda
 * que se desea filtrar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de filtrar Tipo de la clase DLL
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
 * que se desea filtrar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de filtrar Color de la clase DLL
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
 * que se desea filtrar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de filtrar Talla de la clase DLL
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
 * que se desea filtrar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de filtrar Material de la clase DLL
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
 * que se desea filtrar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de filtrar Estado de la clase DLL
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
 * que se desea ordenar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de ordenar Puestas de la clase DLL
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
 * que se desea ordenar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de ordenar Puestas de la clase DLL
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
 * que se desea ordenar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de ordenar Puestas de la clase DLL
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
 * que se desea ordenar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de ordenar Puestas de la clase DLL
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
 * que se desea ordenar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de ordenar Puestas de la clase DLL
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
 * que se desea ordenar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de ordenar Puestas de la clase DLL
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
 * que se desea ordenar esté en el closet y acomoda nuevamente el DLL DLL
 * con los métodos del archivo DLL.h
 * usa el metodo de ordenar Puestas de la clase DLL
 * 
 * @param
 * @return
*/

void ClosetLavadora::ordenarClosetPuestasCalcetines(){
    Closet->ordenarPuestas(0, "Calcetines");
}


/**
 * creacloset
 * 
 * función encargada de importar todos los datos de un archivo .csv "Closeet.csv" donde puede obtener 
 * datos acerca de las prendas, cada renglon son los datos de una prenda diferente, 
 * en el orden id, nombre, tipo, color, talla, material, estado, puestas
 * importa estos datos y crea objetos de tipo PrendaRopa con estos datos, y los agrega al DLL
*/

void ClosetLavadora::creaCloset(){
    using namespace std;
    string prendas[100];
    std::ifstream archivoCloset;
    archivoCloset.open("Closeet.csv");
    string texto;
    int num = 0;
    if(archivoCloset.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while(getline(archivoCloset, texto)){
        prendas[num] = texto;
        num++;
    }
    archivoCloset.close();
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
 * Este método crea el DLL de la tienda, leyendo un archivo csv
 * importado como un arreglo de strings, y separando los datos de cada prenda
 * en variables de tipo string, para después convertir los datos que lo requieran
 * a su tipo de dato correspondiente, y crear un objeto de la clase PrendaRopa
 * con estos datos con el metodo creaPrenda, y agregarlo al DLL de la tienda
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
    std::ifstream archivoTienda;
    archivoTienda.open("Tiendita.csv");
    string texto;
    int num = 0;
    if(archivoTienda.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while(getline(archivoTienda, texto)){
        prendas[num] = texto;
        num++;
    }
    archivoTienda.close();
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
 * actualizaArchivo
 * funcióon auxiliar que ayuda a que todos los cambios que se realicen en el DLL, se actualice inmediataente en el archivo csv
 * en el archivo Closet.csv o Tienda.csv, dependiendo de si se trata de un cambio en el DLL de closet o de tienda
 * esto se especificará en el argumento que reciba, y básicamente lo que hace es importar los datos del DLL, por el orden impuesto por 
 * los IDs de las prendas, y sobreescribir el archivo csv con estos datos
 * no crea prendas nuevas, y sobreescribe el archivo en el formato que se especifica en el método
 * creaTienda, de la manera en que se importan los datos, nombre, tipo, color, talla, material, estado, puestas, id
 * debería hacer algo parecido a esto
 * ofstream archivoSalida("residentes.csv");
    if (!archivoSalida) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 0;
    }

    for (int i = 0; i < residentesVector.size(); i++) {
        Residente *residente = residentesVector[i];
        archivoSalida << residente->getNumCasa() << ","
                      << residente->getPropietario() << ","
                      << residente->getContacto() << ","
                      << residente->getSaldoAPagar() << endl;
    }

    archivoSalida.close();
 * 
*/


void ClosetLavadora::actualizaArchivo(DLL* DLL){
    ofstream archivoSalida;
    if (DLL == Closet){
        archivoSalida.open("Closeet.csv");
    } else if (DLL == Tienda){
        archivoSalida.open("Tienda.csv");
    } else {
        cerr << "Error: DLL no reconocido." << endl;
        return;
    }
    if (!archivoSalida) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return;
    }
    //recorremos el DLL, y vamos escribiendo los datos de cada prenda en el archivo
    for (int i = 0; i < DLL->getSize(); i++) {
        PrendaRopa prenda = (DLL->search(i+1))->getData();
        archivoSalida << prenda.getNombre() << ","
                      << prenda.getTipo() << ","
                      << prenda.getColor() << ","
                      << prenda.getTalla() << ","
                      << prenda.getMaterial() << ","
                      << prenda.getEstado() << ","
                      << prenda.getPuestas() << ","
                      << prenda.getID() << endl;
    }
    archivoSalida.close();
}









        


                           

        
        







#endif /* CLOSETLAVADORA_H */










