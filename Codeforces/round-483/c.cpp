#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
    if (a < 0 || b < 0) {
        return gcd(abs(a), abs(b));
    }
    if (a > b) {
        return gcd(b, a);
    }
    //so a <= b now
    if (a == 0) {
        return b;
    }
    //cout << a << b << endl;
    return gcd(b % a, a);
}

bool finite (ll q, ll b) {
    ll g = gcd(q, b);
    while (g > 1) {
        q /= g;
        g = b = gcd(q, b);
    }
    return (q == 1);
}

int main () {
    int n;
    cin >> n;
    ll p[n], q[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> q[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        ll d = gcd(p[i], q[i]);
        q[i] /= d;
        if (finite (q[i], b[i])) {
            cout << "Finite" << endl;
        }
        else {
            cout << "Infinite" << endl;
        }
    }
}
