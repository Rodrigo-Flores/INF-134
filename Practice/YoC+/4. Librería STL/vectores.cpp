#include <bits/stdc++.h>
using namespace std;

int main () {
    // []
    vector<int> vec1;

    // [ , , , ]
    vector<int> vec2(4);
    // [0,0,0,0]
    vector<int> vec3(4, 0);
    // [0,0,0,0,0,0]
    int n = 6;
    vector<int> vec4(n, 0);

    // [0,0,-1,0,0,0]
    vec4[2] = -1;
    // [0,0,-1,2,0,0]
    vec4[3] = 2;

    // [0,0,-1,2,0,0,4]
    vec4.push_back(4);
    // [0,0,-1,2,0,0]
    vec4.pop_back();

    // [0,0,4,-1,2,0,0]
    vec4.insert(vec4.begin() + 2, 4);
    // [0,4,-1,2,0,0]
    vec4.erase(vec4.begin() + 1);

    for(int i = 0; i < vec4.size(); i++) {
        cout << vec4[i] << " ";
    }
    cout << endl;

    // [0,0,2,-1,4,0]
    sort(vec4.begin(), vec4.end());

    return 0;
}