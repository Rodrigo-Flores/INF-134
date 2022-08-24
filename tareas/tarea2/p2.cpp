#include <iostream>
using namespace std;

typedef int tipoElementoArbol;

struct tipoNodoArbolBin
{
    tipoElementoArbol info = NULL;
    tipoNodoArbolBin *izq = NULL;
    tipoNodoArbolBin *der = NULL;
};

class ABB
{
private:
    tipoNodoArbolBin *raiz;
    unsigned int nElems;

public:
    ABB()
    {
        raiz = new tipoNodoArbolBin;
        nElems = 0;
    }
    void recursive_insert(tipoElementoArbol e, tipoNodoArbolBin *nodo) {
        if (e > nodo->info) {
            if (nodo->der == NULL) {
                nodo->der = new tipoNodoArbolBin;
                nodo->der->info = e;
                nElems++;
            }
            else {
                recursive_insert(e, nodo->der);
            }
        } else if (e < raiz->info) {
            if (nodo->izq == NULL) {
                nodo->izq = new tipoNodoArbolBin;
                nodo->izq->info = e;
                nElems++;
            }
            else {
                recursive_insert(e, nodo->izq);
            }
        } else {
            return;
        }
    }
    void insert(tipoElementoArbol elemento) {
        if (raiz->info == NULL) {
            raiz = new tipoNodoArbolBin;
            raiz->info = elemento;
            nElems++;
        } else {
            recursive_insert(elemento, raiz);
        }
    }
    void recursive_print(tipoNodoArbolBin *nodo) {
        if (nodo->izq != NULL) {
            recursive_print(nodo->izq);
        }
        cout << nodo->info << " ";
        if (nodo->der != NULL) {
            recursive_print(nodo->der);
        }
    }
    void print() {
        if (raiz->info == NULL) {
            cout << "El arbol esta vacio" << endl;
        } else {
            recursive_print(raiz);
        }
    }
    void eraseABB(tipoNodoArbolBin *nodo)
    {
        if (nodo->izq != NULL)
            eraseABB(nodo->izq);
        if (nodo->der != NULL)
            eraseABB(nodo->der);
        delete nodo;
    }
    tipoNodoArbolBin *get_raiz() { return raiz; }
};

int main()
{
    ABB arbol;
    arbol.insert(5);
    arbol.insert(3);
    arbol.insert(7);
    arbol.insert(2);
    arbol.insert(4);
    arbol.insert(6);

    arbol.print();

    arbol.eraseABB(arbol.get_raiz());
    return 0;
}