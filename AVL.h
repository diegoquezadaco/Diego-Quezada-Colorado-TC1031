/**
 * Proyecto Integrador - TC1031
 * Proyecto ClosetLavadora inteligente
 * Diego Quezada Colorado A01710024
 * 15/10/2023 
*/
/**
 * Clase AVL
 * Esta es la clase que se va a encargar de establecer la estructura de datos
 * que utilizará ClosetLavadora para almacenar elementos de la clase PrendaRopa
 * será la implementación de un arbol AVL con sus metodos de inserción, 
 * eliminación, etc.
*/

#ifndef   AVL_H
#define   AVL_H
#include <iostream>
#include <string>
#include <sstream>
#include "PrendaRopa.h"

using namespace std;

template <class T> class AVL;

template <class T>
class Node {
private:
    Node *left, *right;
    int level, balance;
    Node<T>* predecesor();

public:
    T value;
    Node(T);
    Node(T, Node<T>*, Node<T>*, int, int);
    void add(T);
    bool find(T);
    void remove(T);
    void removeChilds();
    void inorder(std::stringstream&) const;
    void preorder(std::stringstream&) const;
    int max_depth();
    Node<T>* check_tree(T*, Node<T>*, bool*);
    Node<T>* balance_tree();
    Node<T>* rot_left(Node<T>* );
    Node<T>* rot_right(Node<T>* );
    Node<T>* rot_left_right(Node<T>* );
    Node<T>* rot_right_left(Node<T>* );
    string mostrarDatoss();
    Node<T>* search(int _id);
    void filtrarTipo(string _query);
    void filtrarColor(string _query);
    void filtrarTalla(string _query);
    void filtrarMaterial(string _query);
    void filtrarEstado(string _query);
    void ordenarPuestas(int _p, string _tipo);
    operator == (const Node<T> &n1, const Node<T> &n2){
        return n1.value == n2.value;
    }
    operator < (const Node<T> &n1, const Node<T> &n2){
        return n1.value < n2.value;
    }
    operator > (const Node<T> &n1, const Node<T> &n2){
        return n1.value > n2.value;
    }
    operator <= (const Node<T> &n1, const Node<T> &n2){
        return n1.value <= n2.value;
    }
    operator >= (const Node<T> &n1, const Node<T> &n2){
        return n1.value >= n2.value;
    }
    operator != (const Node<T> &n1, const Node<T> &n2){
        return n1.value != n2.value;
    }
    friend class AVL<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), level(0), balance(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, int lev, int bal)
    : value(val), left(le), right(ri), level(lev), balance(bal) {}

template <class T>
void Node<T>::add(T val) {
    if (val.id < value.id) {
        if (left != 0) {
            left->add(val);
        } else {
            left = new Node<T>(val);
        }
    } else {
        if (right != 0) {
            right->add(val);
        } else {
            right = new Node<T>(val);
        }
    }
}


template <class T>
bool Node<T>::find(T val) {
    if (val.id == value.id) {
        return true;
    } else if (val.id < value.id) {
        return (left != 0 && left->find(val));
    } else if (val.id > value.id) {
        return (right != 0 && right->find(val));
    }
    return false;
}

template <class T>
void Node<T>::remove(T val) {
    Node<T> * succ, *old;
    if (val.id < value.id) {
        if (left != 0) {
            if ((left->value).id == val.id) {
                old = left;
                if (old->right == 0) {
                    left = old->left;
                } else {
                    succ = old->right->predecesor();
                    if (succ != 0) {
                        succ->left = old->left;
                    }
                    left = old->right;
                }
                delete old;
            } else {
                left->remove(val);
            }
        }
    } else if (val.id > value.id) {
        if (right != 0) {
            if ((right->value).id == val.id) {
                old = right;
                if (old->right == 0) {
                    right = old->left;
                } else {
                    succ = old->right->predecesor();
                    if (succ != 0) {
                        succ->left = old->left;
                    }
                    right = old->right;
                }
                delete old;
            } else {
                right->remove(val);
            }
        }
    }
}

template <class T>
void Node<T>::removeChilds() {
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

template <class T>
Node<T>* Node<T>::predecesor() {
    Node<T> *parent, *child;
    parent = this;
    child = left;
    while (child->right != 0) {
        parent = child;
        child = child->right;
    }
    parent->right = child->left;
    child->left = 0;
    return child;
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
    if (left != 0) {
        left->inorder(aux);
    }
    if (aux.tellp() != 1) {
        aux << " ";
    }
    aux << value.id;
    if (right != 0) {
        right->inorder(aux);
    }
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
    aux << value->id;
    if (left != 0) {
        aux << " ";
        left->preorder(aux);
    }
    if (right != 0) {
        aux << " ";
        right->preorder(aux);
    }
}

template <class T>
int Node<T>::max_depth() {
    int left_depth = 0;
    int right_depth = 0;
    if (left != 0) {
        left_depth = left->max_depth();
    }
    if (right != 0) {
        right_depth = right->max_depth();
    }
    return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
}

template <class T>
Node<T>* Node<T>::check_tree(T* arr, Node<T>* root, bool* flag) {
    Node<T>* aux = 0;
    if (left != 0) {
        aux = left->check_tree(arr, root, flag);
        if (aux != 0) {
            return aux;
        }
    }
    if (arr[value] == 0) {
        *flag = true;
        return this;
    } else {
    }
        arr[value]--;
    if (right != 0) {
        aux = right->check_tree(arr, root, flag);
        if (aux != 0) {
            return aux;
        }
    }
    return 0;
}

template <class T>
Node<T>* Node<T>::balance_tree() {
    Node<T> *a, *b, *c, *d;
    if (balance < -1) {
        a = this;
        b = right;
        if (b->balance <= 0) {
            c = b;
            a->right = b->left;
            c->left = a;
            a->balance = 0;
            b->balance = 0;
            return c;
        } else {
            c = b->left;
            d = c->left;
            b->left = c->right;
            a->right = c->left;
            c->right = b;
            c->left = a;
            switch (d->balance) {
                case -1:
                    a->balance = 0;
                    b->balance = 1;
                    break;
                case 0:
                    a->balance = 0;
                    b->balance = 0;
                    break;
                case 1:
                    a->balance = -1;
                    b->balance = 0;
                    break;
            }
            c->balance = 0;
            return c;
        }
    } else {
        a = this;
        b = left;
        if (b->balance >= 0) {
            c = b;
            a->left = b->right;
            c->right = a;
            a->balance = 0;
            b->balance = 0;
            return c;
        } else {
            c = b->right;
            d = c->right;
            b->right = c->left;
            a->left = c->right;
            c->left = b;
            c->right = a;
            switch (d->balance) {
                case -1:
                    a->balance = 1;
                    b->balance = 0;
                    break;
                case 0:
                    a->balance = 0;
                    b->balance = 0;
                    break;
                case 1:
                    a->balance = 0;
                    b->balance = -1;
                    break;
            }
            c->balance = 0;
            return c;
        }
    }
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* a){
    Node<T> *b, *temp = 0;
    if (a->right != 0){
        b= a->right;
        if (b->left != 0)
        temp= b->left;
        
        if (temp != 0){
            a->right= temp;
            b->left= a;
        }else{
        a->right = 0;
        }
    }
    return b;
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* a){
    Node<T> *b, *temp = 0;
    if (a->left != 0){
        b= a->left;
        if (b->left != 0)
        temp= b->right;
        
        if (temp != 0){
            a->left= temp;
            b->right= a;
        }else{
        a->left = 0;
        }
    }
    return b;
    
}

template <class T>
Node<T>* Node<T>::rot_left_right(Node<T>* a){
    a->left = rot_left(a->left);
    a= rot_right(a);
    return a;
}

template <class T>
Node<T>*  Node<T>::rot_right_left(Node<T>* a){
    a->right = rot_right(a->right);
    a= rot_left(a);
    return a;
}

template <class T>
string Node<T>::mostrarDatoss(){
    stringstream aux;
    if (left != 0){
        left->mostrarDatoss();
    }
    value.mostrarDatos();
    if (right != 0){
        right->mostrarDatoss();
    }
    return aux.str();
}

template <class T>
Node<T>* Node<T>::search(int _id){
    if (left != 0){
        left->search(_id);
    }
    if (value.getID() == _id){
        return this;
    }
    if (right != 0){
        right->search(_id);
    }
    return 0;
}

template <class T>
void Node<T>::filtrarTipo(string _query){
    if (left != 0){
        left->filtrarTipo(_query);
    }
    if (value.getTipo() == _query){
        value.mostrarDatos();
    }
    if (right != 0){
        right->filtrarTipo(_query);
    }
}

template <class T>
void Node<T>::filtrarColor(string _query){
    if (left != 0){
        left->filtrarColor(_query);
    }
    if (value.getColor() == _query){
        value.mostrarDatos();
    }
    if (right != 0){
        right->filtrarColor(_query);
    }
}

template <class T>
void Node<T>::filtrarTalla(string _query){
    if (left != 0){
        left->filtrarTalla(_query);
    }
    if (value.getTalla() == _query){
        value.mostrarDatos();
    }
    if (right != 0){
        right->filtrarTalla(_query);
    }
}

template <class T>
void Node<T>::filtrarMaterial(string _query){
    if (left != 0){
        left->filtrarMaterial(_query);
    }
    if (value.getMaterial() == _query){
        value.mostrarDatos();
    }
    if (right != 0){
        right->filtrarMaterial(_query);
    }
}

template <class T>
void Node<T>::filtrarEstado(string _query){
    if (left != 0){
        left->filtrarEstado(_query);
    }
    if (value.getEstado() == _query){
        value.mostrarDatos();
    }
    if (right != 0){
        right->filtrarEstado(_query);
    }
}

/**
 * ordenaPuestas
 * función que ordena las prendas por el número de veces que se han puesto
 * e imprime los datos de las mismas de menor a mayor número de puestas
*/

template <class T>
void Node<T>::ordenarPuestas(int _p, string _tipo){
    if (left != 0){
        left->ordenarPuestas(_p, _tipo);
    }
    if (value.getPuestas() == _p && value.getTipo() == _tipo){
        value.mostrarDatos();
    }
    if (right != 0){
        right->ordenarPuestas(_p, _tipo);
    }
}



template <class T>
class AVL {
private:
    Node<T> *root;

public:
    AVL();
    ~AVL();
    bool empty() const;
    void add(T);
    bool find(T) const;
    void remove(T);
    void removeAll();
    std::string inorder() const;
    std::string preorder() const;
    int max_depth();
    void check_tree(T*, bool*);
    void balance_tree();
    void rot_left();
    void rot_right();
    void rot_left_right();
    void rot_right_left();
        /**
     * creamos el método buscar para poder buscar un elemento en el arbol
     * por medio de su nombre
     * 
    */
    Node<T>* search(int _id);
    /**
     * creamos un metodo para poder mostrar los datos en ClosetLavadora,
     * con un iterador que recorra el arbol con ayuda del ID de la prenda y vaya mostrando los datos,
     * con ayuda de la función mostrarDatos de la clase PrendaRopa 
    */
    string mostrarDatoss();
    void filtrarTipo(string _query);
    void filtrarColor(string _query);
    void filtrarTalla(string _query);
    void filtrarMaterial(string _query);
    void filtrarEstado(string _query);
    void ordenarPuestas(int _p, string _tipo);
};

template <class T>
AVL<T>::AVL() : root(0) {
} 

template <class T>
AVL<T>::~AVL() {
    removeAll();
}

template <class T>
bool AVL<T>::empty() const {
    return (root == 0);
}

template<class T>
void AVL<T>::add(T val) {
    if (root != 0) {
        if (!root->find(val)) {
            Node <T> *temp;
            T check_val = false;
            bool aux = false;
            root->add(val);
            root->max_depth();
            temp = root->check_tree(&check_val, 0, &aux);
            if (aux) {
                root = temp;
            }
        }
    } else {
        root = new Node<T>(val);
    }
}

template <class T>
bool AVL<T>::find(T val) const {
    if (root != 0) {
        return root->find(val);
    } else {
        return false;
    }
}

template <class T>
void AVL<T>::remove(T val) {
    if (root != 0) {
        if (val == root->value) {
            Node<T> *succ = root->predecesor();
            if (succ != 0) {
                succ->left = root->left;
                succ->right = root->right;
            }
            delete root;
            root = succ;
        } else {
            root->remove(val);
        }
    }
}

template <class T>
void AVL<T>::removeAll() {
    if (root != 0) {
        root->removeChilds();
    }
    delete root;
    root = 0;
}

template <class T>
std::string AVL<T>::inorder() const {
    std::stringstream aux;
    aux << "[";
    if (!empty()) {
        root->inorder(aux);
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::string AVL<T>::preorder() const {
    std::stringstream aux;
    aux << "[";
    if (!empty()) {
        root->preorder(aux);
    }
    aux << "]";
    return aux.str();
}

template <class T>
int AVL<T>::max_depth(){
    if (root != 0){
        return root->max_depth();
    }else{
        return 0;
    }
}

template <class T>
void AVL<T>::check_tree(T* arr, bool* flag){
    if (root != 0){
        root->check_tree(arr, root, flag);
    }
}

template <class T>
void AVL<T>::balance_tree(){
    if (root != 0){
        root->balance_tree();
    }
}

template <class T>
void AVL<T>::rot_left(){
    if (root != 0){
        root->rot_left(root);
    }
}

template <class T>
void AVL<T>::rot_right(){
    if (root != 0){
        root->rot_right(root);
    }
}

template <class T>
void AVL<T>::rot_left_right(){
    if (root != 0){
        root->rot_left_right(root);
    }
}

template <class T>
void AVL<T>::rot_right_left(){
    if (root != 0){
        root->rot_right_left(root);
    }
}

template <class T>
Node<T>* AVL<T>::search(int _id){
    if (root != 0){
        return root->search(_id);
    }else{
        return 0;
    }
}
/**
 * creamos un metodo para poder mostrar los datos en ClosetLavadora,
 * con un iterador que recorra el arbol con ayuda del ID de la prenda y vaya mostrando los datos,
 * con ayuda de la función mostrarDatos de la clase PrendaRopa
 * pero que muestre los datos de todos los nodos del arbol, recorriendo
 * los nodos de izquierda a derecha
*/
template <class T>
string AVL<T>::mostrarDatoss(){
    if (root != 0){
        return root->mostrarDatoss();
    }
}
/**
 * filtrar
 * función auxiliar para filtrar los datos de las prendas, y usarla en ClosetLavadora para
 *  void filtrarClosetTipo(string _tipo);
    void filtrarClosetColor(string _color);
    void filtrarClosetTalla(string _talla);
    void filtrarClosetMaterial(string _material);
    void filtrarClosetEstado(string _estado);
*/
template <class T>
void AVL<T>::filtrarTipo(string _query){
    if (root != 0){
        root->filtrarTipo(_query);
    }
}

template <class T>
void AVL<T>::filtrarColor(string _query){
    if (root != 0){
        root->filtrarColor(_query);
    }
}

template <class T>
void AVL<T>::filtrarTalla(string _query){
    if (root != 0){
        root->filtrarTalla(_query);
    }
}

template <class T>
void AVL<T>::filtrarMaterial(string _query){
    if (root != 0){
        root->filtrarMaterial(_query);
    }
}

template <class T>
void AVL<T>::filtrarEstado(string _query){
    if (root != 0){
        root->filtrarEstado(_query);
    }
}

template <class T>
void AVL<T>::ordenarPuestas(int _p, string _tipo){
    if (root != 0){
        root->ordenarPuestas(_p, _tipo);
    }
}


        



#endif /* AVL_H */
