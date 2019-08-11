#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n = 1000;
    int m = 1000;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char g = (i % 2) ? 'a' : 'b';
            cout << g;
        }
        cout << endl;
    }
}
