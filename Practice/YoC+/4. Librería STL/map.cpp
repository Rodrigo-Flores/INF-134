#include <bits/stdc++.h>

using namespace std;

int main () {
    map <char, int> mapita;

    mapita['a'] = 50;
    mapita['b'] = 50;
    mapita['c'] = 200;

    mapita.insert(pair<char, int>('d', 400));

    mapita.erase('b');

    mapita.find('a');

    if(mapita.find('c') != mapita.end()) {
        cout << "Si existe" << endl;
        cout << mapita.find('c')->second << endl;
    } else {
        cout << "No existe" << endl;
    }


    return 0;
}