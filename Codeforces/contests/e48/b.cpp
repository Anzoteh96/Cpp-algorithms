#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    vector<bool>answer(n, false);
    for (int i = 0; m + i <= n; ++i) {
        bool flag = true;
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != t[j]) {
                flag = false;
            }
        }
        answer[i] = flag;
    }
    vector<int>total(n + 1, 0);
    vector<int>index(0);
    for (int i = 0; i < n; ++i) {
        if (answer[i]) {
            index.push_back(i);
        }
        total[i + 1] = index.size();
    }
    /*
    for (int i = 0; i <= n; ++i) {
        cout << total[i] << " ";
    }
    cout << endl;
     */
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (v - u + 1 < m) {
            cout << 0 << endl;
        }
        else {
            cout << total[v - m + 1] - total[u - 1] << endl;
        }
    }
}
