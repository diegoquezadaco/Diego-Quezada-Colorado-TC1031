/**
 * Proyecto Integrador - TC1031
 * Proyecto ClosetLavadora intelugente
 * Diego Quezada Colorado A01710024
 * 08/09/2023 
*/
/**
 * Clase ClosetLavadora
 * Esta es la clase que contiene las prendas de ropa
 * Sera compuesta por objetos de ClosetLavadora
 * 
*/

#ifndef   CLOSETLAVADORA_H
#define   CLOSETLAVADORA_H
#include <iostream>
#include <string>
#include <algorithm>
#include "PrendaRopa.h"
using namespace std;

//Clase ClosetLavadora
class ClosetLavadora {
        
    private:
    //Declaro las variables de instancia
    PrendaRopa *closet[100];
    PrendaRopa *tienda[50];
    int num_prendas;

    public:
    //Declaro los metodos de clase
    ClosetLavadora();
    ClosetLavadora(int _num_prendas);
    void setNumPrendas(int _num_prendas);
    int getNumPrendas();



    //métodos para interactuar con las prendas
    int limpias();
    int lavando();
    void consultarCloset();
    void usarPrenda(string _nombre);
    void comprarPrenda(string _nombre);
    void desecharPrenda(string _nombre);
    void recorreCloset();
    void filtrarClosetTipo(string _tipo);
    void filtrarClosetColor(string _color);
    void filtrarClosetTalla(string _talla);
    void filtrarClosetMaterial(string _material);
    void filtrarClosetEstado(string _estado);
    void ordenarClosetPuestas();
    void creaCloset();
    void creaTienda();


};
//Metodos de clase
/**
 * Constructor default
 * Este metodo es el constructor default de la clase
 * 
 * @param
 * @return
 * 
 */
ClosetLavadora::ClosetLavadora(){
    creaCloset();
    creaTienda();
    getNumPrendas();
}
/**
 * Constructor con parametros
 * Este metodo es el constructor con parametros de la clase
 * 
 * @param int _num_prendas
 * @return
 * 
 */
ClosetLavadora::ClosetLavadora(int _num_prendas){
    num_prendas = _num_prendas;
}
/**
 * setNumPrendas
 * Este metodo asigna el numero de prendas
 * 
 * @param int _num_prendas
 * @return
 * 
 */
void ClosetLavadora::setNumPrendas(int _num_prendas){
    num_prendas = _num_prendas;
}
/**
 * getNumPrendas
 * Este metodo regresa el numero de prendas
 * 
 * @param
 * @return int num_prendas
 * 
 */
int ClosetLavadora::getNumPrendas(){
    int _num_prendas = 0;
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            _num_prendas++;
        }
    }
    num_prendas = _num_prendas;
    return num_prendas;
}
/**
 * limpias
 * Este metodo regresa el numero de prendas limpias
 * 
 * @param
 * @return int limpias
 * 
 */
int ClosetLavadora::limpias(){
    int limpias = 0;
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getEstado() == "Limpia"){
                limpias++;
            }
        }
    }
    return limpias;
}
/**
 * lavando
 * Este metodo regresa el numero de prendas lavando
 * 
 * @param
 * @return int lavando
 * 
 */
int ClosetLavadora::lavando(){
    int lavando = 0;
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getEstado() == "Lavando"){
                lavando++;
            }
        }
    }
    return lavando;
}
/**
 * consultarCloset
 * Este metodo imprime los datos de las prendas
 * 
 * @param
 * @return
 * 
 */
void ClosetLavadora::consultarCloset(){
    cout << "Prendas Totales en el closet: " << getNumPrendas() <<  endl;
    cout << "Prendas limpias: " << limpias() << endl;
    cout << "Prendas lavándose: " << lavando() << endl;
    string o;
    cout << "¿Desea ver las prendas? (si/no)" << endl;
    cin >> o;
    if (o == "si"){
        for (int i = 0; i < 100; i++){
            if (closet[i] != nullptr){
                cout << "Prenda " << i + 1 << endl;
                closet[i]->mostrarDatos();
                
            }
        }
    }else{
        cout << "Ok" << endl;
    }
}
/**
 * usarPrenda
 * Este metodo cambia el estado de la prenda a lavando
 * 
 * @param string _nombre
 * @return
 * 
*/
void ClosetLavadora::usarPrenda(string _nombre){
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getNombre() == _nombre){
                closet[i]->setEstado("Lavando");
                closet[i]->setPuestas(closet[i]->getPuestas() + 1);
                cout << "Prenda en proceso de lavado" << endl;
            }
        }
    }
}
/**
 * comprarPrenda
 * Este metodo agrega una prenda al closet
 * 
 * @param string _nombre
 * @return
 * 
*/
void ClosetLavadora::comprarPrenda(string _nombre){
    for (int i = 0; i < 50; i++){
        if (tienda[i] != nullptr){
            if (tienda[i]->getNombre() == _nombre){
                for (int j = 0; j < 100; j++){
                    if (closet[j] == nullptr){
                        closet[j] = tienda[i];
                        tienda[i] = nullptr;
                        cout << "Prenda comprada" << endl;
                        return;
                    }
                }
            }
        }
    }
}
/**
 * desecharPrenda
 * Este metodo elimina una prenda del closet
 * 
 * @param string _nombre
 * @return
 * 
*/
void ClosetLavadora::desecharPrenda(string _nombre){
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getNombre() == _nombre){
                closet[i] = nullptr;
                cout << "Prenda desechada" << endl;
            }
        }
    }
}
/**
 * recorreCloset
 * Este metodo recorre el closet para llenar los espacios vacios
 * por nullptr, por los que estan llenos, recorriendo todos a la derecha
 * 
 * @param
 * @return
 * 
*/
void ClosetLavadora::recorreCloset(){
    for (int i = 0; i < 100; i++){
        if (closet[i] == nullptr){
            for (int j = i; j < 100; j++){
                if (closet[j] != nullptr){
                    closet[i] = closet[j];
                    closet[j] = nullptr;
                    break;
                }
            }
        }
    }
}
/**
 * filtrarClosetTipo
 * Este metodo filtra el closet por tipo de prenda
 * 
 * @param string _tipo
 * @return
 * 
*/
void ClosetLavadora::filtrarClosetTipo(string _tipo){
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getTipo() == _tipo){
                closet[i]->mostrarDatos();
            }
        }
    }
}
/**
 * filtrarClosetColor
 * Este metodo filtra el closet por color de prenda
 * 
 * @param string _color
 * @return
 * 
*/
void ClosetLavadora::filtrarClosetColor(string _color){
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getColor() == _color){
                closet[i]->mostrarDatos();
            }
        }
    }
}
/**
 * filtrarClosetTalla
 * Este metodo filtra el closet por talla de prenda
 * 
 * @param string _talla
 * @return
 * 
*/
void ClosetLavadora::filtrarClosetTalla(string _talla){
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getTalla() == _talla){
                closet[i]->mostrarDatos();
            }
        }
    }
}
/**
 * filtrarClosetMaterial
 * Este metodo filtra el closet por material de prenda
 * 
 * @param string _material
 * @return
 * 
*/
void ClosetLavadora::filtrarClosetMaterial(string _material){
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getMaterial() == _material){
                closet[i]->mostrarDatos();
            }
        }
    }
}
/**
 * filtrarClosetEstado
 * Este metodo filtra el closet por estado de prenda
 * 
 * @param string _estado
 * @return
 * 
*/
void ClosetLavadora::filtrarClosetEstado(string _estado){
    for (int i = 0; i < 100; i++){
        if (closet[i] != nullptr){
            if (closet[i]->getEstado() == _estado){
                closet[i]->mostrarDatos();
            }
        }
    }
}
/**
 * ordenarClosetPuestas
 * Este metodo ordena el closet por numero de puestas de prenda
 * de mayor a menor,usando sort de la biblioteca de algorithm
 * @param
 * @return
 * 
*/
void ClosetLavadora::ordenarClosetPuestas(){
    sort(closet, closet + 100, [](PrendaRopa *a, PrendaRopa *b){
        return a->getPuestas() > b->getPuestas();
    });
}
/**
 * creaCloset
 * Este metodo crea el closet con 10 prendas por default
 * con ayuda del constructor de PrendaRopa
 * 
 * @param
 * @return
 * 
*/
void ClosetLavadora::creaCloset(){
    closet[0] = new PrendaRopa("Pantaloncito","Pantalon", "Azul", "M", 
                                "Algodon", "Limpia", 0);
    closet[1] = new PrendaRopa("Playera 1","Playera", "Blanco", "M",
                                "Algodon", "Limpia", 0);
    closet[2] = new PrendaRopa("Playera 2","Playera", "Negro", "M",
                                "Algodon", "Limpia", 0);
    closet[3] = new PrendaRopa("Playera 3","Playera", "Rosa", "M",
                                "Algodon", "Limpia", 0);
    closet[4] = new PrendaRopa("Playera 4","Playera", "Rojo", "M",
                                "Algodon", "Limpia", 0);        
    closet[5] = new PrendaRopa("Playera 5","Playera", "Verde", "M",
                                "Algodon", "Limpia", 0);    
    closet[6] = new PrendaRopa("Sneakers","Zapatos", "Blanco", "L",
                                "Tela", "Limpia", 0);
    closet[7] = new PrendaRopa("Zapatos de vestir","Zapatos", "Negro", "L",
                                "Piel", "Limpia", 0);
    closet[8] = new PrendaRopa("Cinturón","Accesorio", "Negro", "M",
                                "Piel", "Limpia", 0);
    closet[9] = nullptr;
    closet[10] = nullptr;
    closet[11] = nullptr;
    closet[12] = nullptr;
    closet[13] = nullptr;
    closet[14] = nullptr;
    closet[15] = nullptr;
    closet[16] = nullptr;
    closet[17] = nullptr;
    closet[18] = nullptr;
    closet[19] = nullptr;
    closet[20] = nullptr;
    closet[21] = nullptr;
    closet[22] = nullptr;
    closet[23] = nullptr;
    closet[24] = nullptr;
    closet[25] = nullptr;
    closet[26] = nullptr;
    closet[27] = nullptr;
    closet[28] = nullptr;
    closet[29] = nullptr;
    closet[30] = nullptr;
    closet[31] = nullptr;
    closet[32] = nullptr;
    closet[33] = nullptr;
    closet[34] = nullptr;
    closet[35] = nullptr;
    closet[36] = nullptr;
    closet[37] = nullptr;
    closet[38] = nullptr;
    closet[39] = nullptr;
    closet[40] = nullptr;
    closet[41] = nullptr;
    closet[42] = nullptr;
    closet[43] = nullptr;
    closet[44] = nullptr;
    closet[45] = nullptr;
    closet[46] = nullptr;
    closet[47] = nullptr;
    closet[48] = nullptr;
    closet[49] = nullptr;
    closet[50] = nullptr;
    closet[51] = nullptr;
    closet[52] = nullptr;
    closet[53] = nullptr;
    closet[54] = nullptr;
    closet[55] = nullptr;
    closet[56] = nullptr;
    closet[57] = nullptr;
    closet[58] = nullptr;
    closet[59] = nullptr;
    closet[60] = nullptr;
    closet[61] = nullptr;
    closet[62] = nullptr;
    closet[63] = nullptr;
    closet[64] = nullptr;
    closet[65] = nullptr;
    closet[66] = nullptr;
    closet[67] = nullptr;
    closet[68] = nullptr;
    closet[69] = nullptr;
    closet[70] = nullptr;
    closet[71] = nullptr;
    closet[72] = nullptr;
    closet[73] = nullptr;
    closet[74] = nullptr;
    closet[75] = nullptr;
    closet[76] = nullptr;
    closet[77] = nullptr;
    closet[78] = nullptr;
    closet[79] = nullptr;
    closet[80] = nullptr;
    closet[81] = nullptr;
    closet[82] = nullptr;
    closet[83] = nullptr;
    closet[84] = nullptr;
    closet[85] = nullptr;
    closet[86] = nullptr;
    closet[87] = nullptr;
    closet[88] = nullptr;
    closet[89] = nullptr;
    closet[90] = nullptr;
    closet[91] = nullptr;
    closet[92] = nullptr;
    closet[93] = nullptr;
    closet[94] = nullptr;
    closet[95] = nullptr;
    closet[96] = nullptr;
    closet[97] = nullptr;
    closet[98] = nullptr;
    closet[99] = nullptr;


}

/**
 * /**
 * creaTienda
 * Este metodo crea la tienda con 50 prendas por default
 * con ayuda del constructor de PrendaRopa
 * 
 * @param
 * @return
 * 
*/
void ClosetLavadora::creaTienda(){
    tienda[0] = new PrendaRopa("Pantaloncito","Pantalon", "Azul", "M", "Algodon", "Limpia", 0);
    tienda[1] = new PrendaRopa("Camiseta1","Camiseta", "Rojo", "S", "Algodon", "Limpia", 10);
    tienda[2] = new PrendaRopa("Vestido1","Vestido", "Blanco", "L", "Seda", "Limpia", 20);
    tienda[3] = new PrendaRopa("Short1","Short", "Negro", "M", "Denim", "Limpia", 15);
    tienda[4] = new PrendaRopa("Chaqueta1","Chaqueta", "Gris", "XL", "Lana", "Limpia", 30);
    tienda[5] = new PrendaRopa("Sudadera1","Sudadera", "Verde", "S", "Poliester", "Limpia", 25);
    tienda[6] = new PrendaRopa("Pantaloncito2","Pantalon", "Azul", "M", "Algodon", "Limpia", 10);
    tienda[7] = new PrendaRopa("Camiseta2","Camiseta", "Rojo", "S", "Algodon", "Limpia", 15);
    tienda[8] = new PrendaRopa("Vestido2","Vestido", "Blanco", "L", "Seda", "Limpia", 25);
    tienda[9] = new PrendaRopa("Short2","Short", "Negro", "M", "Denim", "Limpia", 20);
    tienda[10] = new PrendaRopa("Chaqueta2","Chaqueta", "Gris", "XL", "Lana", "Limpia", 35);
    tienda[11] = new PrendaRopa("Sudadera2","Sudadera", "Verde", "S", "Poliester", "Limpia", 30);
    tienda[12] = new PrendaRopa("Pantaloncito3","Pantalon", "Azul", "M", "Algodon", "Limpia", 5);
    tienda[13] = new PrendaRopa("Camiseta3","Camiseta", "Negro", "S", "Algodon", "Limpia", 18);
    tienda[14] = new PrendaRopa("Vestido3","Vestido", "Rojo", "L", "Seda", "Limpia", 22);
    tienda[15] = new PrendaRopa("Short3","Short", "Gris", "M", "Denim", "Limpia", 17);
    tienda[16] = new PrendaRopa("Chaqueta3","Chaqueta", "Azul", "XL", "Lana", "Limpia", 28);
    tienda[17] = new PrendaRopa("Sudadera3","Sudadera", "Blanco", "S", "Poliester", "Limpia", 32);
    tienda[18] = new PrendaRopa("Pantaloncito4","Pantalon", "Verde", "M", "Algodon", "Limpia", 12);
    tienda[19] = new PrendaRopa("Camiseta4","Camiseta", "Negro", "S", "Algodon", "Limpia", 14);
    tienda[20] = new PrendaRopa("Vestido4","Vestido", "Rojo", "L", "Seda", "Limpia", 24);
    tienda[21] = new PrendaRopa("Short4","Short", "Gris", "M", "Denim", "Limpia", 19);
    tienda[22] = new PrendaRopa("Chaqueta4","Chaqueta", "Azul", "XL", "Lana", "Limpia", 31);
    tienda[23] = new PrendaRopa("Sudadera4","Sudadera", "Blanco", "S", "Poliester", "Limpia", 29);
    tienda[24] = new PrendaRopa("Pantaloncito5","Pantalon", "Azul", "M", "Algodon", "Limpia", 9);
    tienda[25] = new PrendaRopa("Camiseta5","Camiseta", "Negro", "S", "Algodon", "Limpia", 12);
    tienda[26] = new PrendaRopa("Vestido5","Vestido", "Rojo", "L", "Seda", "Limpia", 28);
    tienda[27] = new PrendaRopa("Short5","Short", "Gris", "M", "Denim", "Limpia", 23);
    tienda[28] = new PrendaRopa("Chaqueta5","Chaqueta", "Azul", "XL", "Lana", "Limpia", 37);
    tienda[29] = new PrendaRopa("Sudadera5","Sudadera", "Blanco", "S", "Poliester", "Limpia", 33);
    tienda[30] = new PrendaRopa("Pantaloncito6","Pantalon", "Verde", "M", "Algodon", "Limpia", 7);
    tienda[31] = new PrendaRopa("Camiseta6","Camiseta", "Negro", "S", "Algodon", "Limpia", 16);
    tienda[32] = new PrendaRopa("Vestido6","Vestido", "Rojo", "L", "Seda", "Limpia", 27);
    tienda[33] = new PrendaRopa("Short6","Short", "Gris", "M", "Denim", "Limpia", 21);
    tienda[34] = new PrendaRopa("Chaqueta6","Chaqueta", "Azul", "XL", "Lana", "Limpia", 36);
    tienda[35] = new PrendaRopa("Sudadera6","Sudadera", "Blanco", "S", "Poliester", "Limpia", 31);
    tienda[36] = new PrendaRopa("Pantaloncito7","Pantalon", "Azul", "M", "Algodon", "Limpia", 8);
    tienda[37] = new PrendaRopa("Camiseta7","Camiseta", "Negro", "S", "Algodon", "Limpia", 11);
    tienda[38] = new PrendaRopa("Vestido7","Vestido", "Rojo", "L", "Seda", "Limpia", 23);
    tienda[39] = new PrendaRopa("Short7","Short", "Gris", "M", "Denim", "Limpia", 18);
    tienda[40] = new PrendaRopa("Chaqueta7","Chaqueta", "Azul", "XL", "Lana", "Limpia", 34);
    tienda[41] = new PrendaRopa("Sudadera7","Sudadera", "Blanco", "S", "Poliester", "Limpia", 27);
    tienda[42] = new PrendaRopa("Pantaloncito8","Pantalon", "Verde", "M", "Algodon", "Limpia", 6);
    tienda[43] = new PrendaRopa("Camiseta8","Camiseta", "Negro", "S", "Algodon", "Limpia", 13);
    tienda[44] = new PrendaRopa("Vestido8","Vestido", "Rojo", "L", "Seda", "Limpia", 26);
    tienda[45] = new PrendaRopa("Short8","Short", "Gris", "M", "Denim", "Limpia", 22);
    tienda[46] = new PrendaRopa("Chaqueta8","Chaqueta", "Azul", "XL", "Lana", "Limpia", 39);
    tienda[47] = new PrendaRopa("Sudadera8","Sudadera", "Blanco", "S", "Poliester", "Limpia", 35);
    tienda[48] = new PrendaRopa("Pantaloncito9","Pantalon", "Azul", "M", "Algodon", "Limpia", 4);
    tienda[49] = new PrendaRopa("Camiseta9","Camiseta", "Negro", "S", "Algodon", "Limpia", 9);

}







#endif