#include <iostream>
#include <fstream>
using namespace std;

typedef char tipoElementoLista;

struct tipoNodo {
    tipoElementoLista info;
    tipoNodo *next = NULL;
};

class Lista {
    private:
        tipoNodo *head;
        tipoNodo *tail;
        tipoNodo *current;
        unsigned int size;
        unsigned int pos;
    public:
        Lista() {
            head = tail = current = new tipoNodo;
            size = 0;
            pos = 0;
        }
        int insert(tipoElementoLista elemento) {
            tipoNodo *aux = current->next;
            current->next = new tipoNodo;
            current->next->info = elemento;
            current->next->next = aux;
            if (current == tail) {
                tail = current->next;
            }
            size++;
            return pos;
        }
        void moveToStart() {
            current = head;
            pos = 0;
        }
        void moveToEnd() {
            current = tail;
            pos = size;
        }
        void moveToPos(unsigned int pos) {
            if (pos < size) {
                current = head;
                for (unsigned int i = 0; i < pos; i++) {
                    current = current->next;
                }
                this->pos = pos;
            }
        }
        void next_value() {
            if (current != tail) {
                current = current->next;
                pos++;
            }
        }
        void prev_value() {
            tipoNodo *aux = current;
            current = head;
            while (current->next != aux) {
                current = current->next;
            }
        }
        void delete_list() {
            tipoNodo *aux = head;
            while (aux != NULL) {
                tipoNodo *aux2 = aux->next;
                delete aux;
                aux = aux2;
            }
            head = tail = current = NULL;
            size = 0;
            pos = 0;
        }
        void print() {
            tipoNodo *aux = head;
            while (aux != NULL) {
                cout << aux->info << " ";
                aux = aux->next;
                cout << "while" << endl;
            }
            cout << endl;
        }
};

int main() {
    Lista list;
    ifstream file;
    string line;
    file.open("./DatosPrueba/p1.txt");
    getline(file, line);


    list.delete_list();
    return 0;
}