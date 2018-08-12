#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    ll segze = 1 - (int(s[0]) - int('0'));
    int cur = int(s[0]) - int('0');
    for (int i = 1; i < n; ++i) {
        if (cur == 1 && s[i] == '0') {
            ++segze;
        }
        cur = int(s[i]) - int('0');
    }
    //cout << segze << endl;
    ll ans = min (y * segze, x * max((ll)0, (segze - 1)) + y);
    cout << ans;
}
