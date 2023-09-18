/**
 * Proyecto Integrador - TC1031
 * Proyecto ClosetLavadora intelugente
 * Diego Quezada Colorado A01710024
 * 08/09/2023   
 */
/**
 * Clase PrendaRopa
 * Esta es la clase padre de las prendas en general
 * Sera componente de ClosetLavadora
 * 
 * 
 */
#ifndef   PRENDAROPA_H
#define   PRENDAROPA_H
#include <iostream>
#include <string>
using namespace std;

//Clase PrendaRopa
class PrendaRopa {
        
    protected:
    //Declaro las variables de instancia
    string nombre;
    string tipo;
    string color;
    string talla;
    string material;
    string estado;
    int puestas;

    public:
    //Declaro los metodos de clase
    string getNombre();
    string getTipo();
    string getColor();
    string getTalla();
    string getMaterial();
    string getEstado();
    int getPuestas();
    void setNombre(string _nombre);
    void setPuestas(int _puestas);
    void setEstado(string _estado);
    void mostrarDatos();
    PrendaRopa(string _nombre, string _tipo, string _color, string _talla, 
                string _material, string _estado, int _puestas);





};

//Metodos de clase
/**
 * getNombre
 * Este metodo regresa el nombre de la prenda
 * 
 * @param
 * @return string nombre
 * 
 */
string PrendaRopa::getNombre(){
    return nombre;
}
/**
 * getTipo
 * Este metodo regresa el tipo de la prenda
 * 
 * @param
 * @return string tipo
 * 
 */
string PrendaRopa::getTipo(){
    return tipo;
}
/**
 * getColor
 * Este metodo regresa el color de la prenda
 * 
 * @param
 * @return string color
 * 
 */
string PrendaRopa::getColor(){
    return color;
}
/**
 * getTalla
 * Este metodo regresa la talla de la prenda
 * 
 * @param
 * @return string talla
 * 
 */
string PrendaRopa::getTalla(){
    return talla;
}
/**
 * getMaterial
 * Este metodo regresa el material de la prenda
 * 
 * @param
 * @return string material
 * 
 */
string PrendaRopa::getMaterial(){
    return material;
}
/**
 * getEstado
 * Este metodo regresa el estado de la prenda
 * 
 * @param
 * @return string estado
 * 
 */
string PrendaRopa::getEstado(){
    return estado;
}
/**
 * getPuestas
 * Este metodo regresa el numero de puestas de la prenda
 * 
 * @param
 * @return int puestas
 * 
 */
int PrendaRopa::getPuestas(){
    return puestas;
}
/**
 * setNombre
 * Este metodo asigna el nombre de la prenda
 * 
 * @param string _nombre
 * @return
 * 
 */
void PrendaRopa::setNombre(string _nombre){
    nombre = _nombre;
}
/**
 * setPuestas
 * Este metodo asigna el numero de puestas de la prenda
 * 
 * @param int _puestas
 * @return
 * 
 */
void PrendaRopa::setPuestas(int _puestas){
    puestas = _puestas;
}
/**
 * setEstado
 * Este metodo asigna el estado de la prenda
 * 
 * @param string _estado
 * @return
 * 
 */
void PrendaRopa::setEstado(string _estado){
    estado = _estado;
}
void PrendaRopa::mostrarDatos(){
    cout << "______________________________________________________ " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Color: " << color << endl;
    cout << "Talla: " << talla << endl;
    cout << "Material: " << material << endl;
    cout << "Estado: " << estado << endl;
    cout << "Puestas: " << puestas << endl;
    cout << endl;
}
/**
 * Constructor
 * Este metodo asigna los valores de las variables de instancia
 * 
 * @param string _nombre
 * @param string _tipo
 * @param string _color
 * @param string _talla
 * @param string _material
 * @param string _estado
 * @param int _puestas
 * @return
 * 
 */
PrendaRopa::PrendaRopa(string _nombre, string _tipo, string _color, string _talla, 
                string _material, string _estado, int _puestas){
    nombre = _nombre;
    tipo = _tipo;
    color = _color;
    talla = _talla;
    material = _material;
    estado = _estado;
    puestas = _puestas;
}
#endif