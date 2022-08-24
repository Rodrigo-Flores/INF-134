#include <bits/stdc++.h>

using namespace std;

int factorial (int N) {
    if (N == 1) {
        return 1;
    }

    return N * factorial(N-1);
}

/*

    SE EJECUTA TANTAS VECES SEA NECESARIA LA RECURSIÓN

    facotrial(5) = 5 * 24;
    factorial(4) = 4 * 6;
    factorial(3) = 3 * 2;
    factorial(2) = 2 * 1;
    factorial(1) = 1;

*/

int main () {
    cout << factorial (5) << endl;

    return 0;
}