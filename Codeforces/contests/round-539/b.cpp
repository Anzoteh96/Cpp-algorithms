#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int answer(string &s) {
    //we first see if the answer is "impossible"
    int n = s.length();
    int half_length = n / 2;
    bool flag = true;
    for (int i = 0; i < half_length - 1; ++i) {
        if (s[i] != s[i + 1]) {
            //cout << i << " " << i + 1 << endl;
            flag = false;
        }
    }
    if (flag) return -1;
    
    // now we brute force on k = 1
    for (int i = 1; i < n; ++i) {
        string t = s.substr(i, n - i) + s.substr(0, i);
        //cout << t << endl;
        bool issame = true;
        bool ispal = true;
        for (int i = 0; i <= half_length; ++i) {
            if (t[i] != t[n - i - 1]) ispal = false;
        }
        for (int i = 0; i < n; ++i) {
            if (t[i] != s[i]) issame = false;
        }
        if (!issame && ispal) return 1;
    }
    return 2;
}

int main () {
    string s;
    cin >> s;
    int k = answer(s);
    if (k == -1) cout << "Impossible" << endl;
    else cout << k << endl;
}
