#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll ans(ll n) {
    ll smallest = n;
    ll biggest = 50 * n;
    ll small_plus = n + 100;
    ll big_plus = max(n + 101, biggest - 2000);
    ll count = 0;
    for (ll i = smallest; i <= small_plus; ++i) {
        bool found = false;
        ll start = (ll)5 * (n / (ll)5) + (i % (ll)5);
        if (start > n) {
            start -= 5;
        }
        for (ll j = start; !found && j >= 0 && j + (ll)5 * (n - j) <= i; j -= (ll)5) {
            //cout << i << " " << j << " " << endl;
            ll beg = (ll)2 * ((n - j) / (ll) 2) + (i - j) % (ll)2;
            if (beg > n - j) {
                beg -= 2;
            }
            for (ll k = beg; !found && k >= 0 && j + (ll)5 * k + (n - j - k) * (ll)10 <= i; k -= 2) {
                ll target = i - j - (ll)5 * k;
                if (target % 10 != 0) {
                    cout << "errorerror" << endl;
                }
                target /= 10;
                if ((target - (n - j - k)) % 4 == 0 && (target - (n - j - k)) >= 0 && (target - 5 * (n - j - k)) <= 0) {
                    //cout << i << endl;
                    found = true;
                }
            }
        }
        if (found) ++ count;
    }
    for (ll i = big_plus; i <= biggest; ++i) {
        bool found = false;
        for (ll j = i % (ll)5; !found && j <= n && j + (ll)50 * (n - j) >= i; j += (ll)5) {
            for (ll k = (i - j) % 2; !found && (j + k) <= n && j + (ll)5 * k + (n - j - k) * (ll)50 >= i; k += 2) {
                ll target = i - j - (ll)5 * k;
                if (target % 10 != 0) {
                    cout << "errorerror" << endl;
                }
                target /= 10;
                if ((target - (n - j - k)) % 4 == 0 && (target - (n - j - k)) >= 0 && (target - 5 * (n - j - k)) <= 0) {
                    found = true;
                }
            }
        }
        if (found) ++ count;
    }
    count += max((big_plus - small_plus - 1), (ll)0);
    return count;
}

int main () {
    ll n;
    cin >> n;
    ll count = ans(n);
    cout << count;
}
