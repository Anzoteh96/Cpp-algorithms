#include <bits/stdc++.h>

using namespace std;

void graph(int n, int a, int b) {
    if (a > 1 && b > 1) {
        cout << "NO" << endl;
        return;
    }
    if (n == 1) {
        if (a == 1 && b == 1) {
            cout << "YES" << endl;
            cout << 0 << endl;
            return;
        }
        cout << "NO" << endl;
        return;
    }
    if (n <= 3 && a == 1 && b == 1) {
        cout << "NO" << endl;
        return;
    }
    if (a > n || b > n) {
        cout << "NO" << endl;
        return;
    }
    //now a==1 or b == 1 holds
    cout << "YES" << endl;
    vector<vector<int>>vec(n, vector<int>(n, 0));
    if (a == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (i == j || (i < n - b && j == i + 1)) {
                    vec[i][j] = vec[j][i] = 0;
                }
                else {
                    vec[i][j] = vec[j][i] = 1;
                }
            }
        }
    }
    else {
        //idea: b - 1 isolated elements, and 1 single big cycle
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (i < n - a && j == i + 1) {
                    vec[i][j] = vec[j][i] = 1;
                }
                else {
                    vec[i][j] = vec[j][i] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << vec[i][j];
        }
        cout << endl;
    }
}

int main () {
    int n, a, b;
    cin >> n >> a >> b;
    graph(n, a, b);
}
