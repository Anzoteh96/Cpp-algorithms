#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll lb(vector<ll>&vec, ll thresh) {
    int n = vec.size();
    if (thresh > vec[n - 1]) return n;
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (vec[mid] < thresh) {
            lo = mid + 1;
        } else if (vec[mid] >= thresh) {
            hi = mid;
        }
    }
    return lo;
}

int main () {
    int n, m;
    ll ta, tb;
    int k;
    scanf("%d %d %lld %lld %d", &n, &m, &ta, &tb, &k);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    vector<ll> b(m);
    // a and b are sorted
    for (int i = 0; i < m; ++i) {
        scanf("%lld", &b[i]);
    }
    if (k >= n || k >= m) {
        //cerr << "All the flights in one place can be cancelled" << endl;
        printf("%d\n", -1);
        return 0;
    }
    ll answer = (ll)0;
    for (int i = 0; i <= min(k, n); ++i) {
        int j = k - i;
        ll arr_at_b = a[i] + ta;
        
        int ind = lb(b, arr_at_b);
        
        if (ind + j >= m) {
            printf("%d\n", -1);
            return 0;
        }
        answer = max(answer, b[ind + j] + tb);
        //cout << i << " " << j << " " << ind << " " << b[ind + j] + tb << endl;
    }
    printf("%lld\n", answer);
}
