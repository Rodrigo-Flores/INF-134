#include <bits/stdc++.h>

using namespace std;

int main () {
    int M, N, P, Q;
    cin >> M >> N >> P >> Q;

    int AdjMatrix[M][N];
    int costo = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> AdjMatrix[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if ((AdjMatrix[i][j] == 1) && (j != N-1) && (j != 0)){
                if (AdjMatrix[i][j-1] != 0) {
                    AdjMatrix[i][j-1] = 0;
                    costo += Q;
                    if (AdjMatrix[i][j+1] != 0) {
                        AdjMatrix[i][j+1] = 0;
                        costo += Q;
                    }
                }

            }
            if ((AdjMatrix[i][j] == 0) && (j != N-1) && (j != 0)){
                if (AdjMatrix[i][j-1] != 1) {
                    AdjMatrix[i][j-1] = 1;
                    costo += P;
                    if (AdjMatrix[i][j+1] != 1) {
                        AdjMatrix[i][j+1] = 1;
                        costo += P;
                    }
                }

            }
        }
    }

    cout << "\nIMPRIMIENDO DATOS" << "\n\n";

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nCosto: " << costo << endl;

    return 0;
}