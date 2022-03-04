#include <bits/stdc++.h>

using namespace std;

int fib (int N) {
    if (N == 0) {
        return 0;
    }

    if (N == 1) {
        return 1;
    }

    return fib(N - 1) + fib(N - 2);
}

/*

    fib(3) = fib(2) + fib(1);
    fib(2) = fib(1) + fib(0); => fib(1) = 1 ^ fib(0) = 0;

*/


int main () {

    cout << fib (3) << endl;

    return 0;
}