/*

    BUBBLE SORT, COMPARA UNO A UNO LOS ELEMENTOS PARA VER CUÁL ES MAYOR.

    lUEGO DE COMPARAR, LOS INTERCAMBIA HASTA DEJAR TODO ORDENADO DE MANERA DESCENDIENTE.
    
    CUANDO UN ELEMENTO ES ORDENADO Y ESTÁ EN SU POSICIÓN "CORRECTA", EL ALGORITMO YA NO DEBERÁ CONSULTAR
    EN ESE ORDEN, PUES SUPUESTAMENTE YA NO SERÁ NECESARIO INTERACTUAR CON ÉL.

*/

#include <bits/stdc++.h>

using namespace std;

void swap(vector <int> &vec, int i, int j) {
    int aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;
}

void bubleSort(vector <int> &vec) {
    int size = vec.size();
    for(int i = 1; i <= size; i++) {
        for (int j = 0; j < size -i; j++) {
            if(vec[j] > vec[j + 1]) {
                swap(vec, j, j + 1);
            }
        }
    }
}

int main () {
    int n; cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    bubleSort(vec);
    for (int i = 0; i < n -1; i++) {
        cout << vec[i] << " ";
    }
    cout << vec[n - 1] << endl;

    return 0;
}