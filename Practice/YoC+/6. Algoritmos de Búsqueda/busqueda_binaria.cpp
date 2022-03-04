#include <bits/stdc++.h>

using namespace std;

int busqueda_binaria(int arr[], int N, int X){
    int l = 0;
    int r = N - 1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if(arr[mid] == X) {
            return mid;
        }

        if(arr[mid] > X) {
            r = mid - 1;
        } else {
            l = mid +1;
        }
    }

    return -1;
}

int main () {
    vector <int> v = {3, 5, 1, 10, 2, 5, 0, 5};
    int arr[] = {3, 5, 1, 10, 2, 5, 0, 5};

    vector <int>::iterator lo, up;

    int N = 8;
    int X = 5;

    sort(v.begin(), v.end());

    int pos = busqueda_binaria(arr, N, X);

    if(pos != -1) {
        cout << "El elemento " << X << " se encuentra en la posicion " << pos << endl;
    } else {
        cout << "El elemento " << X << " no se encuentra en el arreglo" << endl;
    }

    sort(arr, arr + N);
    bool encontrado = binary_search(arr, arr + N, X);

    if (encontrado == true) {
        cout << "Encontrado" << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    return 0;
}