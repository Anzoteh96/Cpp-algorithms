#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll n, h, a, b, k;
    scanf("%lld %lld %lld %lld %lld", &n, &h, &a, &b, &k);
    for (int i = 0; i < k; ++i) {
        ll ta, fa, tb, fb;
        scanf("%lld %lld %lld %lld", &ta, &fa, &tb, &fb);
        ll dist = abs(ta - tb);
        ll answer;
        if (ta == tb) {
            answer = abs(fa - fb);
        }
        else if (fa <= a && fb <= a) {
            answer = (a - fa) + (a - fb) + dist;
        }
        else if (fa >= b && fb >= b) {
            answer = (fa - b) + (fb - b) + dist;
        }
        else {
            answer = abs(fa - fb) + dist;
        }
        printf("%lld\n", answer);
    }
}
