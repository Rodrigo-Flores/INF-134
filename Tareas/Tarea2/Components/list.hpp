#include <iostream>
#include <fstream>
using namespace std;

typedef char tipoElementoLista;

struct tipoNodo
{
    tipoElementoLista info;
    tipoNodo *next = NULL;
};

class Lista
{
// atribustos del objeto
private:
    tipoNodo *head;
    tipoNodo *tail;
    tipoNodo *current;
    unsigned int size;
    unsigned int pos;
// dináminca y estática del objeto
public:
    /*****
    * Lista Lista
    ******
    * constructor del TDA lista
    ******
    * Input:
    * no tiene parametros
    ******
    * Returns:
    * retorna el objeto en cuestión y permite crear una isntancia del mismo
    *****/
    Lista()
    {
        head = tail = current = new tipoNodo;
        size = 0;
        pos = 0;
    }
    /*****
    * Int insert
    ******
    * La función Inserta un elemento a la lista en cualquier posición
    ******
    * Input:
    * Char tipoElementoLista: Char con el elemento que se desee insertar a la lista
    ******
    * Returns:
    * Int, retorna la posición
    *****/
    int insert(tipoElementoLista elemento)
    {
        tipoNodo *aux = current->next;
        current->next = new tipoNodo;
        current->next->info = elemento;
        current->next->next = aux;
        if (current == tail) { tail = current->next; }
        size++;
        return pos;
    }
    /*****
    * void move to start
    ******
    * El indicador se mueve hacia la posición inicial
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * No retorna nada
    *****/
    void moveToStart()
    {
        current = head;
        pos = 0;
    }
    /*****
    * void moveToEnd
    ******
    * El indicador se mueve hacia la posición final
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * No retorna nada
    *****/
    void moveToEnd()
    {
        current = tail;
        pos = size;
    }
    /*****
    * void moveToPos
    ******
    * El indicador se mueve a la posición que se indique
    ******
    * Input:
    * Unsigned int pos: Valor con la posición que se desea ir
    * .......
    ******
    * Returns:
    * No retorna nada
    *****/
    void moveToPos(unsigned int pos)
    {
        if (pos < size)
        {
            current = head;
            for (unsigned int i = 0; i < pos; i++) { current = current->next; }
            this->pos = pos;
        }
    }
    /*****
    * void next_value
    ******
    * mueve el indicador a la siguiente posición
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * No retorna nada
    *****/
    void next_value()
    {
        if (current != tail)
        {
            current = current->next;
            pos++;
        }
    }
    /*****
    * void prev_value
    ******
    * mueve el indicador hacia la posición anterior al actual
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * no retorna nada
    *****/
    void prev_value()
    {
        if (current != head)
        {
            tipoNodo *aux = current;
            current = head;
            while (current->next != aux) { current = current->next; }
        }
    }
    /*****
    * void restore_list
    ******
    * vuelve a la lista original (sin modificaciones)
    ******
    * Input:
    * No recibe datos
    * .......
    ******
    * Returns:
    * no retorna nada
    *****/
    void restore_list()
    {
        current = head;
        pos = 0;
        while (current->next != NULL)
        {
            tipoNodo *aux = current->next;
            current->next = aux->next;
            delete aux;
        }
        head = tail = current;
        size = 0;
    }
    /*****
    * void delete_list
    ******
    * Elimina la lista de la memoria heap
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * No retorna nada
    *****/
    void delete_list()
    {
        tipoNodo *aux = head;
        while (aux != NULL)
        {
            tipoNodo *aux2 = aux->next;
            delete aux;
            aux = aux2;
        }
        head = tail = current = NULL;
        size = 0;
        pos = 0;
    }
    /*****
    * void export_list
    ******
    * Resumen Función
    * exporta la lista formateada a un archivo externo (hay archivo de texto en la raiz por defecto)
    ******
    * Input:
    * const char *filename: recibe la cadena de caracteres con el nombre del archivo, tiene por defecto el nombre de archivo "output.txt"
    * .......
    ******
    * Returns:
    * no retorna nada
    *****/
    void export_list(const char *filename = "output.txt")
    {
        ofstream file;
        file.open(filename, ios::app);
        current = tail;
        for (unsigned int i = size; i > 0; i--)
        {
            file << current->info;
            this->prev_value();            
        }
        file << endl;
        file.close();
    }
    /*****
    * void print_reverse
    ******
    * Imprime los elementos de la lista de manera inversa (pues el algoritmo guarda los elementos en la lista de forma inversa)
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * no retorna nada
    *****/
    void print_reverse()
    {
        current = tail;
        for (unsigned int i = size; i > 0; i--)
        {
            cout << current->info;
            this->prev_value();
        }
        cout << endl;
    }
    /*****
    * tipoNodo *get_head
    ******
    * Retorna el puntero al nodo head (el nodo inicial)
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * tipoNodo *, puntero al nodo head
    *****/
    tipoNodo *get_head() { return head; }
    /*****
    * tipoNodo *get_tail
    ******
    * Retorna el puntero al nodo tail (el nodo final)
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * tipoNodo *, puntero al nodo tail
    *****/
    tipoNodo *get_tail() { return tail; }
    /*****
    * tipoNodo *get_current
    ******
    * Retorna el puntero al nodo actual
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * tipoNodo *, puntero al nodo actual
    *****/
    tipoNodo *get_current() { return current; }
    /*****
    * unsigned int get_size
    ******
    * Retorna el tamaño de la lista
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * unsigned int get_size, tamaño de la lista
    *****/
    unsigned int get_size() { return size; }
    /*****
    * unsigned int get_pos
    ******
    * Retorna la posición del puntero actual en la lista de forma "0-based"
    ******
    * Input:
    * No recibe datos
    ******
    * Returns:
    * unsigned int get_pos, posición del puntero actual en la lista
    *****/
    unsigned int get_pos() { return pos; }
};