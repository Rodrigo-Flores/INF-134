#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;

int main () {
    
    /*

        5 4

        1 2 0
        1 4 2
        2 3 5
        4 1 2

    */

   int V, E;
   int u, v, costo;

    cin >> V >> E;

   AdjList.assign(V, vii());
   for (int i = 0; i < E; i++) {
       cin >> u >> v >> costo;
        v--;
        u--;
       AdjList[u].push_back(make_pair(v, costo));
   }

    for (int i = 0; i < V; i++) {
        cout << "u[" << i + 1 <<  "] conecta con: ";
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << AdjList[i][j].first +1 << " ";
        }
        cout << endl;
    }

    return 0;
}