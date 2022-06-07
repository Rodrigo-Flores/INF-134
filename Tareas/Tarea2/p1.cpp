#include <iostream>
#include <fstream>
#include "Components/list.hpp"
using namespace std;

int main()
{
    char c;
    ifstream file;
    Lista list;

    file.open("./DatosPrueba/p1.txt");

    list.moveToStart();
    while (file.get(c))
    {
        if (c == '<') list.next_value();
        else if (c == '>') list.prev_value();
        else if (c == '[') list.moveToEnd();
        else if (c == ']') list.moveToStart();
        else if (c == '\n') {
            list.export_list();
            list.restore_list();
        }
        else if (file.peek() == EOF) {
            list.insert(c);
            list.export_list();
            list.delete_list();
        }
        else list.insert(c);
    }
    file.close();
    list.delete_list();

    return 0;
}