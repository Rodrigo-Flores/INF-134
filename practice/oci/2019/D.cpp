#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

bool order_by_length(pair <int, int> a, pair <int, int> b) {
    return a.second - a.first > b.second - b.first;
}

int main () {
    int N, T;
    cin >> N >> T;

    int A;

    vector <int> days;
    vector <ii> icpc_matches;

    float icpc_total = 0;
    float final = 0;

    for (int i = 0; i < N; i++) {
        cin >> A;
        days.push_back(A);
    }

    for (int i = 0; i < N; i++) {
        icpc_total = days[i];
        for (int j = i+1; j < N-1; j++) {
            icpc_total += days[j];
            final = (icpc_total/((j+1)-i));
            if (final == T) {
                icpc_matches.push_back(make_pair(i, j+1));
            }
        }
    }
    
    sort(icpc_matches.begin(), icpc_matches.end(), order_by_length);

    /*
    for (int i = 0; i < icpc_matches.size(); i++) {
        cout << icpc_matches[i].first << " , " << icpc_matches[i].second << endl;
    }
    */

    if (icpc_matches.size() != 0) {
        cout << icpc_matches[0].first << " " << icpc_matches[0].second << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
