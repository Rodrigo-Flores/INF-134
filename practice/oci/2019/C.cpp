#include <bits/stdc++.h>
#include <string>

using namespace std;

int main () {
    int N, matches = 0;
    cin >> N;

    char aux;

    string bases = "";
    string pattern = "";

    for (int i = 0; i < N; i++) {
        cin >> aux;
        bases += aux;
    }

    for (int i = 0; i < 3; i++) {
        cin >> aux;
        pattern += aux;
    }

    for (int i = 0; i < N-2; i++) {
        if ((bases[i] == pattern[0]) && (bases[i+1] == pattern[1]) && (bases[i+2] == pattern[2])) {
            matches += 1;
        }
    }

    cout << matches << endl;

    return 0;
}