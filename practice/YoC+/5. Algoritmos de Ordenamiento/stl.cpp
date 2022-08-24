#include <bits/stdc++.h>

using namespace std;

bool mayor_a_menor(int a, int b) {
    return a > b;
}

bool segunda_coordenada(pair <int, int> a, pair <int, int> b) {
    return a.second > b.second;
}

bool tamano_y_alfabeto(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    return a < b;
}

int main () {
    // vector <int> v = {1, 4, 11, 3, 12, 6};

    // sort(v.begin(), v.end(), mayor_a_menor);
    // reverse(v.begin(), v.end());

    // vector <pair <int, int>> pares = {{1,1}, {4,2}, {5,2}, {4,8}};
    // sort(pares.begin(), pares.end(), segunda_coordenada);

    vector <string> palabras = {"hola", "holanda", "hahaha", "jiji", "jibaro", "auto", "habano", "hospital"};

    sort(palabras.begin(), palabras.end(), tamano_y_alfabeto);

    for(int i = 0; i < palabras.size(); i++) {
        cout << palabras[i] << "\n";
    }

    cout << endl;

    return 0;
}