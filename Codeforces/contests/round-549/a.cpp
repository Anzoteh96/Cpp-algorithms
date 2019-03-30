#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
    return (b == (ll)0) ? a : gcd(b, a % b);
}

int main () {
    ll n, k;
    cin >> n >> k; // n is the number of restaurants, k is their distance
    // assume that the first
    ll total = n * k;
    ll a, b;
    cin >> a >> b;
    ll mini = ((ll)(1e9+7)) * ((ll)(1e9+7));//cout << mini << endl;
    ll maxi = (ll)0;
    for (int i = 0; i < (int)n; ++i) {
        vector<ll>start{a, (ll)k - a};
        vector<ll>nxt{(ll)i * (ll)k + b, (ll)(i + 1) * (ll)k - b};
        for (int j = 0; j < 2; ++j) {
            for (int ind = 0; ind < 2; ++ind) {
                ll ell = nxt[ind] - start[j];
                if (ell < 0) ell += total;
                //cout << ell << " test" << endl;
                ll d = gcd(ell, total);
                mini = min(mini, total / d);
                maxi = max(maxi, total / d);
            }
        }
    }
    cout << mini << " " << maxi << endl;
}
