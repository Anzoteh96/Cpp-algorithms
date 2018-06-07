#include <bits/stdc++.h>

using namespace std;

int main () {
    int n = 2;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        int ni = 100000;
        cout << ni << endl;
        for (int j = 1; j <= ni; ++j) {
            cout << rand() % 100;
            if (j != ni) {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
