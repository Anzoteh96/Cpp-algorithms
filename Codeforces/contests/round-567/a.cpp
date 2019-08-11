#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll x, y, z;
    cin >> x >> y >> z;
    ll quo = (x + y) / z;
    ll ans;
    if ((x/z) + (y/z) == quo) {
        ans = (ll)0;
    } else {
        ll ceil_1 = z - (x % z);
        ll ceil_2 = z - (y % z);
        ans = min(ceil_1, ceil_2);
    }
    cout << quo << " " << ans << endl;
}
