#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 998244353;

int main () {
    int n;
    cin >> n;
    
    vector<vector<ll>>comb(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i < j) comb[i][j] = 0;
            else if (j == 0) comb[i][j] = 1;
            else {
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
                comb[i][j] %= mod;
            }
        }
    }
    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << i << " " << j << "comb" << comb[i][j] << endl;
        }
    }
     */
    vector<ll>vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    vector<ll>ans(n, 0);
    vector<ll>cum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (vec[j] <= 0) continue;
            if (vec[j] > n) continue;
            ll temp = comb[i - j - 1][vec[j] - 1];
            ll multiplier = 1;
            if (j > 0) {
                multiplier += cum[j]; // ans[0] + ... + ans[j - 1]
            }
            ans[i] += ((temp * multiplier) % mod);
            ans[i] %= mod;
        }
        cum[i + 1] = cum[i] + ans[i];
        cum[i + 1] %= mod;
    }
    for (int i = 0; i < n; ++i) {
        //cout << i << " " << ans[i] << " " << cum[i + 1] << endl;
    }
    cout << cum[n] << endl;
}
