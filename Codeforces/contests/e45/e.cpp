#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool>blocked(n + 1, false);
    //cout <<"cp-1" << endl;
    for (int i = 0; i < m; ++i) {
        int loc;
        scanf("%d", &loc);
        if (loc == 0) {
            cout << -1 << endl;
            return 0;
        }
        blocked[loc] = true;
    }
    //cout <<"cp0" << endl;
    vector<ll>costs(k);
    for (int i = 0; i < k; ++i) {
        scanf("%lld", &costs[i]);
    }
    //cout <<"cp1" << endl;
    vector<int>coord(n + 1);
    coord[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (blocked[i]) {
            coord[i] = coord[i - 1];
        }
        else {
            coord[i] = i;
        }
    }
    //cout <<"cp2" << endl;
    int now = 0;
    int cons = 0;
    for (int i = 0; i <= n; ++i) {
        if (blocked[i]) {
            ++now;
            if (now > cons) cons = now;
        }
        else {
            now = 0;
        }
    }
    //cout << cons << endl;
    if (cons >= k) {
        cout << -1 << endl;
        return 0;
    }
    //cout << "cp3" << endl;
    ll answer = (ll)n * (ll)10000000;
    for (int i = cons + 1; i <= k; ++i) {
        ll count = 0;
        ll here = 0;
        while (true) {
            //cout << costs[i - 1] << endl;
            count += costs[i - 1];
            if (here + i >= n) {
                break;
            }
            else {
                here = coord[here + i];
            }
        }
        //cout << count << endl;
        if (count < answer) answer = count;
    }
    cout << answer << endl;
}
