#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll maxi = (ll)10e18;

int main () {
    int n = 200000;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        ll u = (ll)rand();
        ll v = (ll)rand();
        if (v < u) {
            ll temp = u;
            u = v;
            v = temp;
        }
        cout << u << " " << v << endl;
    }
}
