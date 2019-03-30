#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll p = (ll)(1e9 + 7);

ll pwr(ll a, int b) {
    ll answer = 1;
    ll base = a;
    for (int i = 0; i < 32; ++i) {
        if (b & (1 << i)) {
            answer *= base;
            answer %= p;
        }
        base *= base;
        base %= p;
    }
    answer %= p;
    return answer;
}

ll inverse(ll a) {
    return pwr(a, p - 2);
}

int main () {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    ll m1 = max(n, m);
    vector<ll>fac(m1 + 1, 1);
    for (int i = 1; i <= m1; ++i) {
        fac[i] = fac[i - 1] * (ll)i;
        fac[i] %= p;
    }
    ll answer = 0;
    for (int i = 1; i < n; ++i) {
        // suppose the distance is i
        // then we have i + 1 rooted trees
        ll subanswer = (i == n - 1) ? (ll) 1 : (ll)(i + 1) * pwr(n, n - (i + 1) - 1);
        subanswer %= p;
        //cout << subanswer << "cp1"<<endl;
        ll perm = fac[n-2] * inverse(fac[n-1-i]);
        perm %= p;
        //cout<< fac[i-1]<< " " << perm << endl;
        subanswer *= perm;
        subanswer %= p;
        //cout << subanswer << "cp2" << endl;
        //cout << pow((ll)m, n - i - 1) << " " << subanswer * pwr((ll)m, n - i - 1) << endl;
        subanswer *= pwr((ll)m, n - i - 1);
        subanswer %= p;
        //cout << subanswer << "cp3" << endl;
        // finally we need a formula for the sum of i numbers adding to m
        if (m < i) continue;
        ll comb = fac[m - 1];
        comb *= inverse(fac[i - 1]);
        comb %= p;
        //cout << comb << "cp4" << endl;
        comb *= inverse(fac[m - i]);
        comb %= p;
        //cout << comb << "cp5" << endl;
        subanswer *= comb;
        subanswer %= p;
        answer += subanswer;
        //cout << subanswer << " " << endl;
        answer %= p;
    }
    cout << answer << endl;
}
