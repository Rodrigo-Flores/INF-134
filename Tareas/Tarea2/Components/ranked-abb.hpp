#include <iostream>
using namespace std;

typedef int tipoElementoArbol;

struct tipoNodoArbolBin
{
    tipoElementoArbol info = int(NULL);
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
    void recursive_insert(tipoElementoArbol e, tipoNodoArbolBin *nodo)
    {
        if (e > nodo->info)
        {
            if (nodo->der == int(NULL))
            {
                nodo->der = new tipoNodoArbolBin;
                nodo->der->info = e;
                nElems++;
            }
            else
            {
                recursive_insert(e, nodo->der);
            }
        }
        else if (e < raiz->info)
        {
            if (nodo->izq == int(NULL))
            {
                nodo->izq = new tipoNodoArbolBin;
                nodo->izq->info = e;
                nElems++;
            }
            else
            {
                recursive_insert(e, nodo->izq);
            }
        }
    }
    void insert(tipoElementoArbol elemento)
    {
        if (raiz->info == int(NULL))
        {
            raiz->info = elemento;
            nElems++;
        }
        else
        {
            recursive_insert(elemento, raiz);
        }
    }
    void recursive_print(tipoNodoArbolBin *nodo)
    {
        if (nodo->izq != int(NULL))
        {
            recursive_print(nodo->izq);
        }
        cout << nodo->info << " ";
        if (nodo->der != int(NULL))
        {
            recursive_print(nodo->der);
        }
    }
    void print()
    {
        if (raiz->info == int(NULL))
        {
            cout << "El arbol esta vacio" << endl;
        }
        else
        {
            cout << raiz->info << "\n";
            recursive_print(raiz);
        }
    }
    bool find(tipoElementoArbol e)
    {
        tipoNodoArbolBin *nodo = raiz;
        while (nodo != int(NULL))
        {
            if (e == nodo->info)
            {
                return true;
            }
            else if (e > nodo->info)
            {
                nodo = nodo->der;
            }
            else
            {
                nodo = nodo->izq;
            }
        }
        return false;
    }
    int recursive_rank(tipoElementoArbol e, tipoNodoArbolBin *nodo) {
        // search for the number of elements less than e in the tree
        if (nodo == int(NULL)) {
            return 0;
        }
        if (e < nodo->info) {
            return recursive_rank(e, nodo->izq);
        }
        if (e >= nodo->info) {
            return 1 + recursive_rank(e, nodo->der);
        }
        return 0;
    }
    int rank(tipoElementoArbol e)
    {   
        return recursive_rank(e, raiz);   
    }
    void eraseABB(tipoNodoArbolBin *nodo)
    {
        if (nodo->izq != int(NULL))
            eraseABB(nodo->izq);
        if (nodo->der != int(NULL))
            eraseABB(nodo->der);
        delete nodo;
    }
    tipoNodoArbolBin *get_raiz() { return raiz; }
};