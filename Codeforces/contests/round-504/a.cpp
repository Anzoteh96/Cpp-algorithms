#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    string s, t;
    cin >> s >> t;
    //check for * in s
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            start = i;
        }
    }
    //cout << start << endl;
    if (start == -1) {
        cout << (s == t ? "YES" : "NO");
    }
    else {
        bool flag = true;
        if (m + 1 < n) flag = false;
        for (int i = 0; flag && i < start; ++i) {
            if (s[i] != t[i]) {
                flag = false;
            }
        }
        for (int i = 1; flag && i <= n - (start + 1); ++i) {
            if (s[n - i] != t[m - i]) {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO");
    }
    cout << endl;
}
