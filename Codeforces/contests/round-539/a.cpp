#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int mymax = (1 << 21);

ll ctwo(ll n) {
    return (n * (n - 1)) / (ll)2;
}

int main () {
    int n;
    scanf("%d", &n);
    int number[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number[i]);
    }
    vector<ll> even(mymax);
    vector<ll> odd(mymax);
    for (int i = 0; i < n; ++i) {
        even[i] = odd[i] = (ll)0;
    }
    even[0] = (ll)1;
    int now = 0;
    for (int i = 0; i < n; ++i) {
        now = now ^ number[i];
        if (i % 2) {
            ++even[now];
        }
        else {
            ++odd[now];
        }
    }
    ll answer = 0;
    
    for (int i = 0; i < mymax; ++i) {
        answer += ctwo(even[i]);
        answer += ctwo(odd[i]);
        //if (even[i] > 1) cout << i << " even" << endl;
        //if (odd[i] > 1) cout << i << " odd" << endl;
    }
    printf("%lld\n", answer);
    
}
