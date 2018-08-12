#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll answer (ll n) {
    ll hi = (n + 1) / 2;
    ll lo = 1;
    while (hi > lo) {
        ll total = n;
        ll v = 0;
        ll p = 0;
        ll mid = lo + (hi - lo) / 2;
        while (total) {
            v += min(mid, total);
            total -= min(mid, total);
            p += total / 10;
            total -= (total / 10);
        }
        if (v >= p) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return hi;
}

int main () {
    ll n;
    cin >> n;
    cout << answer(n) << endl;
}
