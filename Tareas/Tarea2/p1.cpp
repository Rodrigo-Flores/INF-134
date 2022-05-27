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
        if (current != head) {
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
    tipoNodo *getHead()
    {
        return head;
    }
    tipoNodo *getTail()
    {
        return tail;
    }
    tipoNodo *getCurrent()
    {
        return current;
    }
    unsigned int getSize()
    {
        return size;
    }
    unsigned int getPos()
    {
        return pos;
    }
};

int main()
{
    Lista list;
    ifstream file;
    file.open("./DatosPrueba/p1.txt");
    char c;
    list.moveToStart();
    while (file.get(c))
    {
        if (c == '<')
        {
            list.next_value();
        }
        else if (c == '>')
        {
            list.prev_value();
        }
        else if (c == '[')
        {
            list.moveToEnd();
        }
        else if (c == ']')
        {
            list.moveToStart();
        }
        else if (c == '\n')
        {
            list.print_reverse();
            list.restore_list();
        }
        else if (file.peek() == EOF)
        {
            list.insert(c);
            list.print_reverse();
            list.delete_list();
        }
        else
        {
            list.insert(c);
        }
    }
    list.print_reverse();

    file.close();

    list.delete_list();
    return 0;
}