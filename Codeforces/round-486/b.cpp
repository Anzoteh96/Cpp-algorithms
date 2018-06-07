#include <bits/stdc++.h>

using namespace std;

bool substring(string s, string t) {
    //len(s) <= len(t)
    int m = s.length();
    int n = t.length();
    for (int i = 0; i <= n - m; ++i) {
        bool flag = true;
        for (int j = 0; j < m; ++j) {
            if (s[j] != t[i + j]) flag = false;
        }
        if (flag) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string>vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end(), [](string a, string b) {
        return a.length() < b.length();
    });
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!substring(vec[i], vec[j])) flag = false;
        }
    }
    if (!flag) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << vec[i] << endl;
        }
    }
}
