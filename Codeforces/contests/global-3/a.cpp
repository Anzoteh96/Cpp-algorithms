#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll a, b, c;
    cin >> a >> b >> c;
    ll answer = (ll)2 * c;
    if (a == b) answer += (a + b);
    else answer += ((ll)2 * min(a, b) + 1);
    cout << answer << endl;
}
