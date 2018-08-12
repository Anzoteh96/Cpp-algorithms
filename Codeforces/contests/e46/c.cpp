#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n;
    cin >> n;
    map<ll, int>freq;
    for (int i = 0; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        ++freq[u];
        --freq[v + 1];
    }
    int cov = 0;
    vector<ll>answer(n);
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        //cout << it->first << " " << it->second << endl;
        auto ir = it;
        ++ir;
        if (ir != freq.end()) {
            cov += it->second;
            ll start = it->first;
            ll finish = ir->first;
            if (cov) {
                answer[cov - 1] += (finish - start);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
}
