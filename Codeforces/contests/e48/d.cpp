#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int ans_a = 0;
    int ans_b = 0;
    for (int i = 0; i < n; ++i) {
        ans_a ^= a[i];
    }
    for (int i = 0; i < m; ++i) {
        ans_b ^= b[i];
    }
    if (ans_a != ans_b) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                cout << 0 << " ";
            }
            cout << a[i - 1] << endl;
        }
        for (int j = 0; j < m - 1; ++j) {
            cout << b[j] << " ";
        }
        int final_ans = b[m - 1];
        for (int i = 0; i < n - 1; ++i) {
            final_ans ^= a[i];
        }
        cout << final_ans << endl;
    }
}
