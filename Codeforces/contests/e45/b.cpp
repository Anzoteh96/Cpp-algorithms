#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    vector<int> bac(n);
    for (int i = 0; i < n; ++i) {
        cin >> bac[i];
    }
    map<int, int>sz;
    for (int i = 0; i < n; ++i) {
        ++sz[bac[i]];
    }
    for (auto& it: sz) {
        //cout << it.first << endl;
        auto it_lo = sz.upper_bound(it.first);
        //if (it_lo != sz.end()) cout << it.first << " " << it_lo->first << endl;
        if (it_lo != sz.end() && it_lo->first <= it.first + k) {
            it.second = 0;
        }
    }
    int answer = 0;
    for (auto it: sz) {
        //cout << it.first << " " << it.second << endl;
        answer += it.second;
    }
    cout << answer << endl;
}
