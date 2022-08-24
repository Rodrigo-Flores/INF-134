#include <bits/stdc++.h>

using namespace std;

int main () {
    set <int> conjunto;

    for(int i = 0; i < 10; i++) {
        conjunto.insert(i);
    }

    set <int>::iterator it;
    it = conjunto.find(7);

    if(it != conjunto.end()) {
        cout << *it << endl;
    } else {
        cout << "No se encontró el elemento" << endl;
    }

    for(it = conjunto.begin(); it != conjunto.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    map <char, int> mapita;

    mapita['a'] = 1;
    mapita['b'] = 2;
    mapita['c'] = 3;

    map <char, int>::iterator it2;
    it2 = mapita.find('a');

    if(it2 != mapita.end()) {
        cout << it2->first << " " << it2->second << endl;
    } else {
        cout << "No se encontró el elemento" << endl;
    }

    for (it2 = mapita.begin(); it2 != mapita.end(); it2++) {
        cout << it2->first << " " << it2->second << endl;
    }

    return 0;
}