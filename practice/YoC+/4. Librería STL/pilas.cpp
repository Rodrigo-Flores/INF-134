#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main () {
    stack <int> mipila;

    mipila.push(10);
    mipila.push(20);

    mipila.push(30);
    mipila.push(40);

    // tamaño de la pila
    cout << mipila.size() << endl;

    // ver el tope de la pila
    cout << "Antiguo: " << mipila.top() << endl;

    // sacar el tope de la pila
    mipila.pop();

    // ver el nuevo tope de la pila
    cout << "Nuevo: " << mipila.top() << endl;

    // ver elementos de la pila

    while(!mipila.empty()) {
        cout << mipila.top() << endl;
        mipila.pop();
    }

    cout << "Tamaño final de la pila: " << mipila.size() << endl;

    // ver si la pila está vacía
    if(mipila.empty()) {
        cout << "La pila está vacía" << endl;
    }


    return 0;
}