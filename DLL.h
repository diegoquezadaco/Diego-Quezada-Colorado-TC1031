/**
 * Proyecto Integrador - TC1031
 * Proyecto ClosetLavadora inteligente
 * Diego Quezada Colorado A01710024
 * 15/10/2023 
*/
/**
 * Clase PrendaRopa
 * Esta es la clase que define la estructura de datos
 * donde se guardaran las prendas de ropa, es una lista doblemente ligada
 * 
 * 
 */

#ifndef DLL_H_
#define DLL_H_
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include "PrendaRopa.h"
#include "exception.h"  

using namespace std;

class DLink{
    private:
        PrendaRopa value;
        DLink* next;
        DLink* prev;
    public:
        DLink();
        DLink(PrendaRopa);
        DLink(PrendaRopa, DLink*, DLink*);
        PrendaRopa getData();
        void setData(PrendaRopa);
        DLink* getNext() const;
        void setNext(DLink*);
        DLink* getPrev() const;
        void setPrev(DLink*);
        friend class DLL;
};

/**
 * Constructor default
 * @param
 * @return 
*/

DLink::DLink(){
    next = NULL;
    prev = NULL;
}

/**
 * Constructor con parámetros
 * @param PrendaRopa val
 * @return 
*/

DLink::DLink(PrendaRopa val){
    value = val;
    next = NULL;
    prev = NULL;
}

/**
 * Constructor con parámetros
 * @param PrendaRopa val, DLink* nxt, DLink* prv
 * @return 
*/

DLink::DLink(PrendaRopa val, DLink* nxt, DLink* prv){
    value = val;
    next = nxt;
    prev = prv;
}

/**
 * getData
 * @param
 * @return PrendaRopa value
*/

PrendaRopa DLink::getData() {
    return value;
}

/**
 * setData
 * @param PrendaRopa val
 * @return 
*/

void DLink::setData(PrendaRopa val){
    value = val;
}

/**
 * getNext
 * @param
 * @return DLink* next
*/

DLink* DLink::getNext() const{
    return next;
}

/**
 * setNext
 * @param DLink* nxt
 * @return 
*/

void DLink::setNext(DLink* nxt){
    next = nxt;
}

/**
 * getPrev
 * @param
 * @return DLink* prev
*/

DLink* DLink::getPrev() const{
    return prev;
}

/**
 * setPrev
 * @param DLink* prv
 * @return 
*/

void DLink::setPrev(DLink* prv){
    prev = prv;
}


class DLL{
    private:
        DLink* head;
        DLink* tail;
        int size;
    public:
        DLL();
        DLL(const DLL&);
        ~DLL();
        DLink *getHead() const;
        DLink *getTail() const;
        int getSize() const;
        bool empty() const;
        void add(PrendaRopa);
        bool find(PrendaRopa) const;
        void remove(PrendaRopa);
        void removeAll();
        string mostrarDatos();
        void filtrarTipo(string _query);
        void filtrarColor(string _query);
        void filtrarTalla(string _query);
        void filtrarMaterial(string _query);
        void filtrarEstado(string _query);
        void ordenarPuestas(string _tipo);
        DLink* search(int _id);
        void reasignarID();
        friend class ClosetLavadora;
};

/**
 * Constructor default
 * @param
 * @return 
*/

DLL::DLL(){
    head = NULL;
    tail = NULL;
    size = 0;
}

/**
 * Constructor copia
 * @param DLL dll
 * @return 
*/

DLL::DLL(const DLL& dll){
    head = dll.head;
    tail = dll.tail;
    size = dll.size;
}

/**
 * Destructor
 * @param
 * @return 
*/

DLL::~DLL(){
    removeAll();
}

/**
 * getHead
 * @param
 * @return DLink* head
*/

DLink* DLL::getHead() const{
    return head;
}

/**
 * getTail
 * @param
 * @return DLink* tail
*/

DLink* DLL::getTail() const{
    return tail;
}

/**
 * getSize
 * @param
 * @return int size
*/

int DLL::getSize() const{
    return size;
}

/**
 * empty
 * @param
 * @return bool
*/

bool DLL::empty() const{
    return (head == NULL && tail == NULL);
}

/**
 * add
 * Este metodo agrega una prenda al final de la lista
 * @param PrendaRopa val
 * @return
*/

void DLL::add(PrendaRopa val){
    DLink* newLink = new DLink(val);
    if(empty()){
        head = newLink;
        tail = newLink;
    }else{
        tail->setNext(newLink);
        newLink->setPrev(tail);
        tail = newLink;
    }
    size++;
}

/**
 * find
 * Este metodo busca una prenda en la lista y regresa un bool
 * @param PrendaRopa val
 * @return bool
*/

bool DLL::find(PrendaRopa val) const{
    DLink* tmp = head;
    while(tmp != NULL){
        if(tmp->getData() == val){
            return true;
        }
        tmp = tmp->getNext();
    }
    return false;
}

/**
 * remove
 * Este metodo elimina una prenda de la lista
 * @param PrendaRopa val
 * @return
*/

void DLL::remove(PrendaRopa val){
    DLink* tmp = head;
    while(tmp != NULL){
        if(tmp->value == val){
            if(tmp == head){
                head = tmp->getNext();
                head->setPrev(NULL);
            }else if(tmp == tail){
                tail = tmp->getPrev();
                tail->setNext(NULL);
            }else{
                tmp->getPrev()->setNext(tmp->getNext());
                tmp->getNext()->setPrev(tmp->getPrev());
            }
            delete tmp;
            size--;
            return;
        }
        tmp = tmp->getNext();
    }
    throw NoSuchElement();
}

/**
 * removeAll
 * Este metodo elimina todas las prendas de la lista
 * @param
 * @return
*/

void DLL::removeAll(){
    DLink* tmp = head;
    while(tmp != NULL){
        head = tmp->getNext();
        delete tmp;
        tmp = head;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}

/**
 * mostrarDatos
 * Este metodo regresa un string con los datos de todas las prendas
 * @param
 * @return string
*/

string DLL::mostrarDatos(){
    stringstream aux;
    DLink* tmp = head;
    while(tmp != NULL){
        aux << tmp->getData().mostrarDatos() + "\n";
        tmp = tmp->getNext();
    }
    return aux.str();
}

/*
 *filtrarTipo
    *Este metodo recibe un string con el tipo de prenda que se quiere filtrar 
    *e imprime los datos de las prendas que coinciden con ese tipo
* @param string _query
* @return 
*/

void DLL::filtrarTipo(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getTipo() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

/**
 * filtrarColor
 * Este metodo recibe un string con el color de prenda que se quiere filtrar
 * e imprime los datos de las prendas que coinciden con ese color
 * @param string _query
 * @return 
*/

void DLL::filtrarColor(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getColor() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

/**
 * filtrarTalla
 * Este metodo recibe un string con la talla de prenda que se quiere filtrar
 * e imprime los datos de las prendas que coinciden con esa talla
 * @param string _query
 * @return 
*/

void DLL::filtrarTalla(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getTalla() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

/**
 * filtrarMaterial
 * Este metodo recibe un string con el material de prenda que se quiere filtrar
 * e imprime los datos de las prendas que coinciden con ese material
 * @param string _query
 * @return 
*/

void DLL::filtrarMaterial(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getMaterial() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

/**
 * filtrarEstado
 * Este metodo recibe un string con el estado de prenda que se quiere filtrar
 * e imprime los datos de las prendas que coinciden con ese estado
 * @param string _query
 * @return 
*/

void DLL::filtrarEstado(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getEstado() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

/**
 * ordenarPuestas
 * Este metodo recibe un string con el tipo de prenda que se quiere ordenar
 * e imprime los datos de las prendas que coinciden con ese tipo ordenadas por numero de puestas
 * en orden ascendente, con ayuda de la funcion sort de la libreria algorithm
 * @param string _tipo
 * @return 
*/



void DLL::ordenarPuestas(string _tipo){
    vector<PrendaRopa> prendas;
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getTipo() == _tipo){
            prendas.push_back(tmp->getData());
        }
        tmp = tmp->getNext();
    }
    sort(prendas.begin(), prendas.end(), [](const PrendaRopa& lhs, const PrendaRopa& rhs) {
        return lhs.getPuestass() < rhs.getPuestass();
    });
    for (int i = 0; i < prendas.size(); i++){
        cout << prendas[i].mostrarDatos() << endl;
    }
}

/**
 * search
 * Este metodo recibe un int con el id de la prenda que se quiere buscar
 * y regresa un apuntador a la prenda que coincide con ese id
 * @param int _id
 * @return DLink*
*/

DLink* DLL::search(int _id){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->value.getID() == _id){
            return tmp;
        }
        tmp = tmp->getNext();
    }
    throw NoSuchElement();
}

/**
 * reasignarID
 * Este metodo reasigna los ids de las prendas en orden ascendente
 * @param
 * @return 
*/

void DLL::reasignarID(){
    DLink* tmp = head;
    int i = 1;
    while(tmp != NULL){
        tmp->value.setID(i);
        i++;
        tmp = tmp->getNext();
    }
}
#endif /* DLL_H_ */
