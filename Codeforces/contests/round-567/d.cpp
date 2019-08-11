#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll>freq(m, 0);
    vector<ll>queries(q);
    for (int i = 0; i < n; ++i) {
        ll u;
        scanf("%lld", &u);
        ++freq[u];
    }
    for (int i = 0; i < q; ++i) {
        scanf("%lld", &queries[i]);
    }
    map<ll, vector<int>>all_freqs;
    for (int i = 0; i < m; ++i) {
        //cout << i << " " << freq[i] << endl;
        all_freqs[freq[i]].push_back(i);
    }//cout << endl;
    map<ll, ll>next_eds;
    ll int_now = (ll)(n + 1);
    int cum_sz = 0;
    for (auto it = all_freqs.begin(); it != all_freqs.end(); ++it) {
        auto ir = it;
        ll this_freq = it->first;
        int this_sz = it->second.size();
        cum_sz += this_sz;
        //cout << this_freq << " " << this_sz << endl;
        ++ir;
        if (ir != all_freqs.end()) {
            ll nxt_freq = ir->first;
            next_eds[int_now] = this_freq;
            int_now += (nxt_freq - this_freq) * (ll)(cum_sz);
        }
    }
    for (auto it: next_eds) {
        cout << it.first << " " << it.second << endl;
    }
    
}
