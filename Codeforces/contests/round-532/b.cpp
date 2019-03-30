#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n, m;
    cin >> n >> m;
    set<int>diffs;
    
    int a[n+1];
    for (int i = 0; i <= n; ++i) {
        a[i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        diffs.insert(i);
    }
    
    for (int i = 0; i < m; ++i) {
        int u;
        cin >> u;
        ++a[u];
        diffs.erase(u);
        //for (auto num: diffs)cout << num;cout << endl;
        if (diffs.empty()) {
            cout << 1;
            for (int j = 1; j <= n; ++j) {
                --a[j];
                if (a[j] == 0) diffs.insert(j);
            }
        }
        
        else cout << 0;
    }
    cout << endl;
}
