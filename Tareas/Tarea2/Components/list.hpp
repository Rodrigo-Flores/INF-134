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
private:
    tipoNodo *head;
    tipoNodo *tail;
    tipoNodo *current;
    unsigned int size;
    unsigned int pos;

public:
    Lista()
    {
        head = tail = current = new tipoNodo;
        size = 0;
        pos = 0;
    }
    int insert(tipoElementoLista elemento)
    {
        tipoNodo *aux = current->next;
        current->next = new tipoNodo;
        current->next->info = elemento;
        current->next->next = aux;
        if (current == tail)
        {
            tail = current->next;
        }
        size++;
        return pos;
    }
    void moveToStart()
    {
        current = head;
        pos = 0;
    }
    void moveToEnd()
    {
        current = tail;
        pos = size;
    }
    void moveToPos(unsigned int pos)
    {
        if (pos < size)
        {
            current = head;
            for (unsigned int i = 0; i < pos; i++)
            {
                current = current->next;
            }
            this->pos = pos;
        }
    }
    void next_value()
    {
        if (current != tail)
        {
            current = current->next;
            pos++;
        }
    }
    void prev_value()
    {
        if (current != head)
        {
            tipoNodo *aux = current;
            current = head;
            while (current->next != aux)
            {
                current = current->next;
            }
        }
    }
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
    tipoNodo *get_head() { return head; }
    tipoNodo *get_tail() { return tail; }
    tipoNodo *get_current() { return current; }
    unsigned int get_size() { return size; }
    unsigned int get_pos() { return pos; }
};