#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, k;
    n = 200000;
    k = 3;
    cout << n << " " << k << endl;
    for (int i = 0; i < n; ++i) {
        cout << rand()% n + 1 << " ";
    }
}
