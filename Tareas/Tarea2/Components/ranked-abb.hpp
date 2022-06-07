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
    /*****
    * ABB ABB
    ******
    * Resumen Función
    * Constructor de la clase ABB
    ******
    * Input:
    * No recibe ningún parámetro
    * .......
    ******
    * Returns:
    * ABB, retirna el objeto en si, esto permite crear el objeto y usarlo en el resto de los métodos
    *****/
    ABB()
    {
        raiz = new tipoNodoArbolBin;
        nElems = 0;
    }
    /*****
    * void recursive_insert
    ******
    * Resumen Función
    * Inserta una elemento en el ABB de forma recursiva
    ******
    * Input:
    * tipoElementoArbol elemento: elemento a insertar
    * tipoNodoArbolBin *nodo: en un principio es la raiz, pero luego será cada nodo del árbol por la recursividad
    * .......
    ******
    * Returns:
    * No retorna ningún valor
    *****/
    void recursive_insert(tipoElementoArbol elemento, tipoNodoArbolBin *nodo)
    {
        if (elemento > nodo->info)
        {
            if (nodo->der == int(NULL))
            {
                nodo->der = new tipoNodoArbolBin;
                nodo->der->info = elemento;
                nElems++;
            }
            else { recursive_insert(elemento, nodo->der); }
        }
        else if (elemento < raiz->info)
        {
            if (nodo->izq == int(NULL))
            {
                nodo->izq = new tipoNodoArbolBin;
                nodo->izq->info = elemento;
                nElems++;
            }
            else { recursive_insert(elemento, nodo->izq); }
        }
    }
    /*****
    * void insert
    ******
    * Resumen Función
    * Es la función que se usa para llamar a la versión recursiva de insert
    ******
    * Input:
    * tipoElementoArbol e: elemento a insertar
    * tipoNodoArbolBin *nodo: en un principio es la raiz, pero luego será cada nodo del árbol por la recursividad
    * .......
    ******
    * Returns:
    * No retorna ningún valor
    *****/
    void insert(tipoElementoArbol elemento)
    {
        if (raiz->info == int(NULL))
        {
            raiz->info = elemento;
            nElems++;
        }
        else { recursive_insert(elemento, raiz); }
    }
    /*****
    * void recursive_print
    ******
    * Resumen Función
    * Imprime el árbol de forma recursiva en in-order
    ******
    * Input:
    * tipoNodoArbolBin *nodo: en un principio es la raiz, pero luego será cada nodo del árbol por la recursividad
    * .......
    ******
    * Returns:
    * No retorna ningún valor
    *****/
    void recursive_print(tipoNodoArbolBin *nodo)
    {
        if (nodo->izq != int(NULL))
        { recursive_print(nodo->izq); }
        cout << nodo->info << " ";
        if (nodo->der != int(NULL)) { recursive_print(nodo->der); }
    }
    /*****
    * void print
    ******
    * Resumen Función
    * es la función que se usa para llamar a la versión recursiva de print
    ******
    * Input:
    * no recibe parametros
    * .......
    ******
    * Returns:
    * no retorna ningún valor
    *****/
    void print()
    {
        if (raiz->info == int(NULL)) { cout << "El arbol esta vacio" << endl; }
        else
        {
            cout << raiz->info << "\n";
            recursive_print(raiz);
        }
    }
    /*****
    * bool find
    ******
    * Resumen Función
    * recorre el árbol a través de un ciclo while, para buscar el elemento que se le pasa por parámetro
    ******
    * Input:
    * tipoElementoArbol elemento: elemento a buscar
    * .......
    ******
    * Returns:
    * true: si el elemento se encuentra en el árbol
    * false: si el elemento no se encuentra en el árbol
    *****/
    bool find(tipoElementoArbol elemento)
    {
        tipoNodoArbolBin *nodo = raiz;
        while (nodo != int(NULL))
        {
            if (elemento == nodo->info) { return true; }
            else if (elemento > nodo->info) { nodo = nodo->der; }
            else { nodo = nodo->izq; }
        }
        return false;
    }
    /*****
    * int recursive_rank
    ******
    * Resumen Función
    * busca la cantidad de elementos menores o iguales que el elemento que se le pasa por parámetro
    ******
    * Input:
    * tipoElementoArbol elemento: elemento a buscar
    * tipoNodoArbolBin *nodo: en un principio es la raiz, pero luego será cada nodo del árbol por la recursividad
    * int &count: contador que se incrementa cada vez que se encuentra un elemento menor o igual que el elemento que se le pasa por parámetro
    * .......
    ******
    * Returns:
    * count: retorna la cantidad de elementos menores o iguales que el elemento que se le pasa por parámetro
    *****/
    int recursive_rank(tipoElementoArbol elemento, tipoNodoArbolBin *nodo, int &count) {
        if (nodo->izq != int(NULL)) { recursive_rank(elemento, nodo->izq, count); }
        if (nodo->der != int(NULL)) { recursive_rank(elemento, nodo->der, count); }
        if (elemento >= nodo->info) { count++; }
        return count;
    }
    /*****
    * int rank
    ******
    * Resumen Función
    * se usa para llamar a la versión recursiva de rank
    ******
    * Input:
    * tipoElementoArbol elemento: elemento a buscar
    * .......
    ******
    * Returns:
    * recursive_rank(elemento, raiz, count): retorna el resultado de la recursividad de buscar los elementos menores o iguales al elemento dado
    *****/
    int rank(tipoElementoArbol elemento)
    {   
        int count = 0;
        return recursive_rank(elemento, raiz, count);   
    }
    /*****
    * void erase_abb
    ******
    * Resumen Función
    * es el destructor de la clase
    ******
    * Input:
    * tipoNodoArbolBin *nodo: la raiz del árbol, por la cual se recorre para borrar en post-order
    * .......
    ******
    * Returns:
    * recursive_rank(elemento, raiz, count): retorna el resultado de la recursividad de buscar los elementos menores o iguales al elemento dado
    *****/
    void erase_abb(tipoNodoArbolBin *nodo)
    {
        if (nodo->izq != int(NULL)) { erase_abb(nodo->izq); }
        if (nodo->der != int(NULL)) { erase_abb(nodo->der); }
        delete nodo;
    }
    /*****
    * tipoNodoArbolBin *get_raiz
    ******
    * Resumen Función
    * getter de la raiz
    ******
    * Input:
    * no recibe parametros
    * .......
    ******
    * Returns:
    * raiz: retorna la raiz del árbol
    *****/
    tipoNodoArbolBin *get_raiz() { return raiz; }
    /*****
    * unsigned int get_nElems
    ******
    * Resumen Función
    * getter de la cantidad de elementos del árbol
    ******
    * Input:
    * no recibe parametros
    * .......
    ******
    * Returns:
    * raiz: retorna la raiz del árbol
    *****/
    unsigned int get_nElems() { return nElems; }
};