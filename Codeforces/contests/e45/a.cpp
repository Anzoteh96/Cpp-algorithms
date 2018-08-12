#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll answer = 0;
    if (n % m) {
        ll floor = n / m;
        ll extra = (floor + 1) * m - n;
        answer = min ((n % m) * b, extra * a);
    }
    cout << answer << endl;
}
