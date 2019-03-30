#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll n, k;
    cin >> n >> k;
    if (n + n - 1 < k) {
        cout << 0 << endl;
    }
    else if (k <= n + 1) {
        ll answer = (k - 1) / (ll) 2;
        cout << answer << endl;
    }
    else {
        ll answer = n - (k / (ll) 2);
        cout << answer << endl;
    }
}
