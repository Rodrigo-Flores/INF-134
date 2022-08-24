#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> IF;

int main () {
    int N; cin >> N;
    int p, q;
    int rooms = 1;

    vector <IF> meetings; // [[inicio, fin], [inicio, fin], [inicio, fin]]

    for (int i = 0; i < N; i++) {
        cin >> p >> q;
        meetings.push_back(make_pair(p,q));
    }

    sort(meetings.begin(), meetings.end());

    /*
    cout << "SORTED VECTOR" << endl;
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << i << ": " << meetings[i].first << " " << meetings[i].second << endl;
    }
    */


    for (int i = 1; i < N; i++) {
        if ((meetings[i].first >= meetings[i-1].first) && (meetings[i].first < meetings[i-1].first)) {
            rooms += 1;
        }
    }

    cout << rooms << endl;

    return 0;
}