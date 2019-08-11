#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n;
    vector<ll>dp(10, (ll)-1);
    scanf("%d", &n);
    dp[0] = 0;
    for (int tc = 1; tc <= n; ++tc) {
        vector<ll>temp = dp;
        vector<vector<ll>>cards(4);
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            int u;
            ll v;
            scanf("%d %lld", &u, &v);
            cards[u].push_back(v);
            //printf("%d %d\n", u, v);
        }
        sort(cards[1].begin(), cards[1].end(), greater<ll>());
        sort(cards[2].begin(), cards[2].end(), greater<ll>());
        sort(cards[3].begin(), cards[3].end(), greater<ll>());
        vector<vector<ll>>biggest;
        if (k >= 1) {
            ll now = 0;
            for (int i = 1; i <= 3; ++i) {
                if (cards[i].size()) now = max(now, cards[i][0]);
            }
            biggest.push_back(vector<ll>{now});
        }
        
        if (cards[1].size() && cards[1].size() + cards[2].size() >= 2) {
            ll big_one = cards[1][0];
            ll big_two = 0;
            if (cards[1].size() >= 2) big_two = cards[1][1];
            if (cards[2].size()) big_two = max(big_two, cards[2][0]);
            vector<ll>bigs = vector<ll>{big_one, big_two};
            sort(bigs.begin(), bigs.end(), greater<ll>());
            biggest.push_back(bigs);
        }
        
        if (cards[1].size() >= 3) {
            vector<ll>bigs = vector<ll>(cards[1].begin(), cards[1].begin() + 3);
            sort(bigs.begin(), bigs.end(), greater<ll>());
            biggest.push_back(bigs);
        }
        
        for (int i = 0; i < 10; ++i) {
            if (dp[i] == -1) continue;
            for (auto &vec: biggest) {
                int sz = vec.size();
                //cout << sz << endl;
                ll sum = (ll)0;
                for (ll g: vec) sum += g;
                if (sz + i >= 10) sum += vec[0];
                int ind = (sz + i) % 10;
                temp[ind] = max(temp[ind], dp[i] + sum);
            }
        }
        
        dp = temp;
        /*
        for (int i = 0; i < 10; ++i) {
            cout << dp[i] << " ";
        }cout << endl;
         */
    }
    printf("%lld\n", *max_element(dp.begin(), dp.end()));
}
