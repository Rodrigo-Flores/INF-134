#include <bits/stdc++.h>

using namespace std;

#define INF 100000000;

int main () {

    int AdjMatrix[200][200];

    /*

        5 6

        1 2 2
        1 3 1
        1 4 3
        2 1 1
        2 4 2
        5 6 10

    */

   int V, E;
   int u, v, w;

   cin >> V >> E;

   for (int i = 0; i < 200; i++) {
       for (int j = 0; j < 200; j++) {
           AdjMatrix[i][j] = INF;
       }
       AdjMatrix[i][i] = 0;
   }

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        AdjMatrix[u][v] = w;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}