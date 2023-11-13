/**
 * Proyecto Integrador - TC1031
 * Proyecto ClosetLavadora inteligente
 * Diego Quezada Colorado A01710024
 * 15/10/2023 
*/
/**
 * Clase Arbol
 * Esta será la clase que defina la estructura del arbol cuyos nodos almacenarán objetos de tipo PrendaRopa
 * estará basada en practicamente en el código de la clase AVL, solo que ya NO será un template y se le agregarán
 * métodos para poder realizar las operaciones de un arbol binario de búsqueda, solo que sin ser AVL
 * Arbol sera un BST
*/

#ifndef   ARBOL_H
#define   ARBOL_H
#include <iostream>
#include <string>
#include "PrendaRopa.h"
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

//Clase Nodo

class Nodo {
    private:
    //Declaro las variables de instancia
    PrendaRopa value;
    Nodo *left, *right;
    Nodo* succesor();

    public:
    //Declaro los metodos de clase
    PrendaRopa getValue();
    Nodo(PrendaRopa);
    Nodo(PrendaRopa, Nodo*, Nodo*);
    void add(PrendaRopa);
    bool find(PrendaRopa);
    void remove(PrendaRopa);
    void removeChilds();
    void inorder(std::stringstream&) ;
    void preorder(std::stringstream&) ;
    string mostrarDatoss();
    Nodo* search(int _id);
    void filtrarTipo(string _query);
    void filtrarColor(string _query);
    void filtrarTalla(string _query);
    void filtrarMaterial(string _query);
    void filtrarEstado(string _query);
    void ordenarPuestas(int _p, string _tipo);
    int contar_prendas();
    void reasignarID(int contador);
    friend class Arbol;
    friend class ClosetLavadora;
};

//Constructor de la clase Nodo
Nodo::Nodo(PrendaRopa val) : value(val), left(0), right(0) {}

//Constructor de la clase Nodo
Nodo::Nodo(PrendaRopa val, Nodo *le, Nodo *ri)
    : value(val), left(le), right(ri) {}

//Metodo para obtener el valor del nodo
PrendaRopa Nodo::getValue() {
    return value;
}

//Metodo para agregar un nodo al arbol
void Nodo::add(PrendaRopa val) {
    if (val.getID() < value.getID()) {
        if (left != 0) {
            left->add(val);
        } else {
            left = new Nodo(val);
        }
    } else {
        if (right != 0) {
            right->add(val);
        } else {
            right = new Nodo(val);
        }
    }
}

//Metodo para buscar un nodo en el arbol
bool Nodo::find(PrendaRopa val) {
    if (val.getID() == value.getID()) {
        return true;
    } else if (val.getID() < value.getID()) {
        return (left != 0 && left->find(val));
    } else if (val.getID() > value.getID()) {
        return (right != 0 && right->find(val));
    }
    return false;
}

//Metodo para eliminar un nodo del arbol
void Nodo::remove(PrendaRopa val) {
    Nodo* succ, *old;

    if (val < value) {
        if (left != nullptr){
            if (left->value == val) {
                old = left;
                succ = left->succesor();

                if (succ != nullptr) {
                    // Conectar los nodos hijos del sucesor con el nodo actual
                    succ->left = old->left;
                    succ->right = old->right;
                }

                left = succ;
                delete old;
        } else {
            left->remove(val);
        }
        }
        
    } else if (val > value ) {
        cout << "entro al else nodo" << endl;
        if (right != nullptr){
            if (right->value == val) {
                old = right;
                succ = right->succesor();
                //imprimimos el sucesor
                cout << succ->value.mostrarDatos() << endl;

                if (succ != nullptr) {
                    cout << "entro al conecte" << endl;
                    // Conectar los nodos hijos del sucesor con el nodo actual
                    succ->left = old->left;
                    succ->right = old->right;
                }

                right = succ;
                delete old;
            } else {
                right->remove(val);
            }
        }
        
    }
}


//Metodo para eliminar los hijos de un nodo

void Nodo::removeChilds() {
    if (left != 0) {
        left->removeChilds();
        delete left;
        left = 0;
    }
    if (right != 0) {
        right->removeChilds();
        delete right;
        right = 0;
    }
}

//succesor

Nodo* Nodo::succesor() {
    Nodo *le, *ri;

    le = left;
    ri = right;

    if (left == 0) {
        if (right != 0) {
            right = 0;
        }
        return ri;
    }

    if (left->right == 0) {
        left = left->left;
        le->left = 0;
        return le;
    }

    Nodo *parent, *child;
    parent = left;
    child = left->right;
    while (child->right != 0) {
        parent = child;
        child = child->right;
    }
    parent->right = child->left;
    child->left = 0;
    return child;
}

//Metodo para recorrer el arbol en inorden

void Nodo::inorder(std::stringstream &aux) {
    if (left != 0) {
        left->inorder(aux);
    }
    aux << value.getID() << " ";
    if (right != 0) {
        right->inorder(aux);
    }
}

//Metodo para recorrer el arbol en preorden

void Nodo::preorder(std::stringstream &aux) {
    aux << value.getID() << " ";
    if (left != 0) {
        left->preorder(aux);
    }
    if (right != 0) {
        right->preorder(aux);
    }
}

//Metodo para mostrar los datos de un nodo
string Nodo::mostrarDatoss(){
    string datos;
    if (left != 0){
        datos += left->mostrarDatoss();
    }
    datos += value.mostrarDatos() + "\n";
    if (right != 0){
        datos += right->mostrarDatoss();
    }
    return datos;
}

//Metodo para buscar un nodo en el arbol por su id recorriendo todo el arbol con funciones recursivas

Nodo* Nodo::search(int _id){
    if (value.getID() == _id){
        return this;
    } else if (value.getID() > _id){
        if (left != 0){
            return left->search(_id);
        } else {
            return nullptr;
        }
    } else {
        if (right != 0){
            return right->search(_id);
        } else {
            return nullptr;
        }
    }
}

//Metodo para filtrar por tipo

void Nodo::filtrarTipo(string _query){
    if (left != 0){
        left->filtrarTipo(_query);
    }
    if (value.getTipo() == _query){
        cout << value.mostrarDatos() << endl;
    }
    if (right != 0){
        right->filtrarTipo(_query);
    }
}

//Metodo para filtrar por color

void Nodo::filtrarColor(string _query){
    if (left != 0){
        left->filtrarColor(_query);
    }
    if (value.getColor() == _query){
        cout << value.mostrarDatos() << endl;
    }
    if (right != 0){
        right->filtrarColor(_query);
    }
}

//Metodo para filtrar por talla

void Nodo::filtrarTalla(string _query){
    if (left != 0){
        left->filtrarTalla(_query);
    }
    if (value.getTalla() == _query){
        cout << value.mostrarDatos() << endl;
    }
    if (right != 0){
        right->filtrarTalla(_query);
    }
}

//Metodo para filtrar por material

void Nodo::filtrarMaterial(string _query){
    if (left != 0){
        left->filtrarMaterial(_query);
    }
    if (value.getMaterial() == _query){
        cout << value.mostrarDatos() << endl;
    }
    if (right != 0){
        right->filtrarMaterial(_query);
    }
}

//Metodo para filtrar por estado

void Nodo::filtrarEstado(string _query){
    if (left != 0){
        left->filtrarEstado(_query);
    }
    if (value.getEstado() == _query){
        cout << value.mostrarDatos() << endl;
    }
    if (right != 0){
        right->filtrarEstado(_query);
    }
}

//Metodo para ordenar por puestas

void Nodo::ordenarPuestas(int _p, string _tipo){
    if (left != 0){
        left->ordenarPuestas(_p, _tipo);
    }
    if (value.getPuestas() >= _p && value.getTipo() == _tipo){
        cout << value.mostrarDatos() << endl;
    }
    if (right != 0){
        right->ordenarPuestas(_p, _tipo);
    }
}

//Metodo para contar las prendas

int Nodo::contar_prendas(){
    int contador = 0;
    if (left == nullptr && right == nullptr){
        return contador+1;
    }
    if (left != 0){
        contador += left->contar_prendas();
    }
    contador++;
    if (right != 0){
        contador += right->contar_prendas();
    }
    return contador;
}

//metodo que verifica que no haya ids repetidos y que no haya huecos en los ids
//generando una lista que lleve el conteo de los mismos y pueda hacer los cambios pertinentes
//con ayuda de la función contar prendas y haciendo un chequeo con los ids de las prendas


void Nodo::reasignarID(int contador){
    if (left != 0){
        left->reasignarID(contador);
    }
    value.setID(contador);
    contador++;
    if (right != 0){
        right->reasignarID(contador);
    }
}



//Clase Arbol

class Arbol {
    private:
    //Declaro las variables de instancia
    Nodo *root;

    public:
    //Declaro los metodos de clase
    Arbol();
    ~Arbol();
    Nodo *getRoot();
    bool empty() const;
    void add(PrendaRopa);
    bool find(PrendaRopa) const;
    void remove(PrendaRopa);
    void removeAll();
    string inorder() const;
    string preorder() const;
    string mostrarDatos();
    void filtrarTipo(string _query);
    void filtrarColor(string _query);
    void filtrarTalla(string _query);
    void filtrarMaterial(string _query);
    void filtrarEstado(string _query);
    void ordenarPuestas(int _p, string _tipo);
    int contar_prendas();
    Nodo* search(int _id);
    void reasignarID();
    friend class ClosetLavadora;
};

//Constructor de la clase Arbol
Arbol::Arbol() : root(0) {}

//Destructor de la clase Arbol
Arbol::~Arbol() {
    removeAll();
}

//Metodo para obtener la raiz del arbol
Nodo* Arbol::getRoot() {
    return root;
}

//Metodo para saber si el arbol esta vacio
bool Arbol::empty() const {
    return (root == 0);
}

//Metodo para agregar un nodo al arbol

void Arbol::add(PrendaRopa val) {
    if (root != 0) {
        if (!root->find(val)) {
            root->add(val);
            reasignarID();
        }
    } else {
        root = new Nodo(val);
    }
}

//Metodo para buscar un nodo en el arbol

bool Arbol::find(PrendaRopa val) const {
    if (root != 0) {
        return root->find(val);
    } else {
        return false;
    }
}

//Metodo para eliminar un nodo del arbol

void Arbol::remove(PrendaRopa val) {
    if (root != 0) {
        if (val == root->value) {
            Nodo *succ = root->succesor();
            if (succ != 0) {
                succ->left = root->left;
                succ->right = root->right;
            }
            delete root;
            root = succ;
        } else {
            cout << "entro al else" << endl;
            root->remove(val);
        }
        reasignarID();
        
    }
}

//Metodo para eliminar los hijos de un nodo

void Arbol::removeAll() {
    if (root != 0) {
        root->removeChilds();
    }
    delete root;
    root = 0;
}

//Metodo para recorrer el arbol en inorden

string Arbol::inorder() const {
    stringstream aux;

    aux << "[";
    if (!empty()) {
        root->inorder(aux);
    }
    aux << "]";
    return aux.str();
}

//Metodo para recorrer el arbol en preorden

string Arbol::preorder() const {
    stringstream aux;

    aux << "[";
    if (!empty()) {
        root->preorder(aux);
    }
    aux << "]";
    return aux.str();
}

//Metodo para mostrar los datos de un nodo

string Arbol::mostrarDatos(){
    string datos;
    if (root != 0){
        datos += root->mostrarDatoss();
    }
    return datos;
}

//Metodo para buscar un nodo en el arbol por su id recorriendo todo el arbol con funciones recursivas

Nodo* Arbol::search(int _id){
    if (root != 0){
        return root->search(_id);
    } else {
        return nullptr;
    }
}

//Metodo para filtrar por tipo

void Arbol::filtrarTipo(string _query){
    if (root != 0){
        root->filtrarTipo(_query);
    }
}

//Metodo para filtrar por color

void Arbol::filtrarColor(string _query){
    if (root != 0){
        root->filtrarColor(_query);
    }
}

//Metodo para filtrar por talla

void Arbol::filtrarTalla(string _query){
    if (root != 0){
        root->filtrarTalla(_query);
    }
}

//Metodo para filtrar por material

void Arbol::filtrarMaterial(string _query){
    if (root != 0){
        root->filtrarMaterial(_query);
    }
}

//Metodo para filtrar por estado

void Arbol::filtrarEstado(string _query){
    if (root != 0){
        root->filtrarEstado(_query);
    }
}

//Metodo para ordenar por puestas

void Arbol::ordenarPuestas(int _p, string _tipo){
    if (root != 0){
        root->ordenarPuestas(_p, _tipo);
    }
}

//Metodo para contar las prendas

int Arbol::contar_prendas(){
    if (root != 0){
        return root->contar_prendas();
    } else {
        return 0;
    }
}

void Arbol::reasignarID(){
    if (root != 0){
        root->reasignarID(1);
    }
}

//metodo que verifica que no haya ids repetidos y que no haya huecos en los ids
//generando una lista que lleve el conteo de los mismos y pueda hacer los cambios pertinentes










#endif /* ARBOL_H */