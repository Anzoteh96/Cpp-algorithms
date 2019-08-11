#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2) {
        cout << ":(" << endl;
        return 0;
    }
    int open = n / 2;
    int close = n / 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') --open;
        if (s[i] == ')') --close;
        if (open < 0 || close < 0) {
            cout << ":(" << endl;
            return 0;
        }
    }
    string answer = s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (open) {
                answer[i] = '(';
                --open;
            }
            else {
                answer[i] = ')';
                --close;
            }
        }
    }
    int balance = 0;
    for (int i = 0; i < n; ++i) {
        if (answer[i] == '(') ++balance;
        else --balance;
        if (balance < 0) {
            cout << ":(" << endl;
            return 0;
        }
        if (balance == 0 && i < n - 1) {
            cout << ":(" << endl;
            return 0;
        }
    }
    cout << answer << endl;
}
