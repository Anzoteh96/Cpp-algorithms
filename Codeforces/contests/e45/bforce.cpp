#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    vector<int> bac(n);
    for (int i = 0; i < n; ++i) {
        cin >> bac[i];
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            if (bac[j] > bac[i] && bac[j] <= bac[i] + k) {
                flag = true;
            }
        }
        if (!flag) ++ answer;
    }
    cout << answer << endl;
}

