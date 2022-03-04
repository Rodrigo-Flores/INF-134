#include <bits/stdc++.h>

using namespace std;

int main () {
    vector <int> v = {3, 5, 1, 10, 2, 5, 0, 5};
    int arr[] = {3, 5, 1, 10, 2, 5, 0, 5};

    vector <int>::iterator lo, up;

    int N = 8;
    int X = 7;

    sort(v.begin(), v.end());

    lo = lower_bound(v.begin(), v.end(), X);
    up = upper_bound(v.begin(), v.end(), X);

    // cout << (*lo) << endl;
    // cout << (*up) << endl;

    int ind = lo - v.begin();

    if (ind < N && v[ind] == X) {
        cout << "Presente en el arreglo" << endl;
    } else {
        cout << "Ausente en el arreglo" << endl;
    }

    int total = up - lo;

    cout << X << "Esta un total de: " << total << " veces" << endl;
 
    return 0;
}