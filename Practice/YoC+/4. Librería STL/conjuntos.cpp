#include <bits/stdc++.h>

using namespace std;

int main () {
    set <int> conjunto;

    conjunto.insert(10); /*  SOLO SE INSERTA ESTE, PUES NO SE PUEDEN TNER ELEMENTOS REPETIDOS */
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);
    conjunto.insert(10);

    /* INSERT RETORNA UNA VALOR BOOLEANO PARA VERIFICAR LA CORRECTA INSERCION */

    if(conjunto.insert(20).second) {
        cout << "Se inserto el elemento 20" << endl;
    }
    else {
        cout << "No se inserto el elemento 20" << endl;
    }

    conjunto.erase(10);

    conjunto.insert(20);
    conjunto.insert(30);

    if (conjunto.find(20) != conjunto.end()) {
        cout << "Se encontro el elemento 20" << endl;
    }
    else {
        cout << "No se encontro el elemento 20" << endl;
    }

    cout << "El tamaño del conjunto es: " << conjunto.size() << endl;

    return 0;
}