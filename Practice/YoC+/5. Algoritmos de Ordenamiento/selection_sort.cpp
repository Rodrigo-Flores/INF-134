/*

    SELECTION SORT BUSCA EL MENOR NÚMERO EN TODO EL ARREGLO Y LO INTERCAMBIA CON EL PRIMER
    ELEMENTO DEL MISMO.

    DADO QUE EL ELEMENTO INTERCAMBIADO YA ESTÁ EN SU POSICIÓN CORRECTA, NO ES NECESARIO VOLVER
    A RECORRER POR AHÍ.

*/

#include <bits/stdc++.h>

using namespace std;

void swap(vector <int> &vec, int i, int j) {
    int aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;
}

void selectionSort(vector <int> &vec) {
    int size = vec.size();
    for(int i = 0; i < size - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j < size - i; j++) {
            if(vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        swap(vec, min_index, i);
    }
}

int main () {
    int n; cin >> n;
    vector <int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    selectionSort(vec);
    for(int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << vec[n - 1] << endl;

    return 0;
}