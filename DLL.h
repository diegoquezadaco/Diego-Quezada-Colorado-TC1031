/**
 * Proyecto Integrador - TC1031
 * Proyecto ClosetLavadora inteligente
 * Diego Quezada Colorado A01710024
 * 15/10/2023 
*/
/**
 * @file DLL.h
 * @version 1.0
 * @date 15/10/2023
 * @title DLL
 * @brief Clase DLL
 * @code
 * 
*/
//DLL stands for Doubly Linked List
/**
 * this will be the class that defines the structure of ClosetLavadora
 * should contain the same functions as the specified in the file Arbol.h
 * so the rest of the code can work without any changes
 * 
 * so it should contain the following functions:
 *  bool empty() const;
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
*/

// };

//it is not going to have template <class T> because it is going to be a list of PrendaRopa
//Dlink is going to be the node of the list

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

DLink::DLink(){
    next = NULL;
    prev = NULL;
}

DLink::DLink(PrendaRopa val){
    value = val;
    next = NULL;
    prev = NULL;
}

DLink::DLink(PrendaRopa val, DLink* nxt, DLink* prv){
    value = val;
    next = nxt;
    prev = prv;
}

PrendaRopa DLink::getData() {
    return value;
}

void DLink::setData(PrendaRopa val){
    value = val;
}

DLink* DLink::getNext() const{
    return next;
}

void DLink::setNext(DLink* nxt){
    next = nxt;
}

DLink* DLink::getPrev() const{
    return prev;
}

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
        string inorder() const;
        string preorder() const;
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

DLL::DLL(){
    head = NULL;
    tail = NULL;
    size = 0;
}

DLL::DLL(const DLL& dll){
    head = dll.head;
    tail = dll.tail;
    size = dll.size;
}

DLL::~DLL(){
    removeAll();
}

DLink* DLL::getHead() const{
    return head;
}

DLink* DLL::getTail() const{
    return tail;
}

int DLL::getSize() const{
    return size;
}

bool DLL::empty() const{
    return (head == NULL && tail == NULL);
}

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

string DLL::inorder() const{
    stringstream aux;
    DLink* tmp = head;
    while(tmp != NULL){
        aux << tmp->getData().getID() << " ";
        tmp = tmp->getNext();
    }
    return aux.str();
}

string DLL::preorder() const{
    stringstream aux;
    DLink* tmp = tail;
    while(tmp != NULL){
        aux << tmp->getData().getID() << " ";
        tmp = tmp->getPrev();
    }
    return aux.str();
}

//mostarDatos
//se apoya de la función mostrarDatos de PrendaRopa

string DLL::mostrarDatos(){
    stringstream aux;
    DLink* tmp = head;
    while(tmp != NULL){
        aux << tmp->getData().mostrarDatos() + "\n";
        tmp = tmp->getNext();
    }
    return aux.str();
}

//filtrarTipo
//se apoya de la función getTipo de PrendaRopa

//debería tener una linea asi:
/**
 * if (value.getTipo() == _query){
        cout << value.mostrarDatos() << endl;
    }
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

//filtrarColor

void DLL::filtrarColor(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getColor() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

//filtrarTalla

void DLL::filtrarTalla(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getTalla() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

//filtrarMaterial

void DLL::filtrarMaterial(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getMaterial() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

//filtrarEstado

void DLL::filtrarEstado(string _query){
    DLink* tmp = head;
    while(tmp != NULL){
        if (tmp->getData().getEstado() == _query){
            cout << tmp->getData().mostrarDatos() << endl;
        }
        tmp = tmp->getNext();
    }
}

//ordenarPuestas
//planteamos la función, obteniendo todas ls prendas de un tipo en especifico, que se recibe como parámetro, y haciendo uso de la función sort de la librería algorithm
//para ordenar las prendas de ese tipo por el número de puestas que tienen

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

//search

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

//reasignarID

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
