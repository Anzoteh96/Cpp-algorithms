#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    int vote[n + 1];
    ll money[n + 1];
    vector<vector<ll>>global_money;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %lld", &vote[i], &money[i]);
        if (vote[i] != 1) {
            vector<ll>temp(2);
            temp[0] = money[i];
            temp[1] = vote[i];
            global_money.push_back(temp);
        }
    }
    sort(global_money.begin(), global_money.end());
    /*
    for (int i = 0; i < global_money.size(); ++i) {
        cout << global_money[i][0] << " " << global_money[i][1] << " rrr" << endl;
    }
     */
    vector<vector<ll>>money_count(m + 1);
    for (int i = 1; i <= n; ++i) {
        money_count[vote[i]].push_back(money[i]);
    }
    vector<vector<ll>>partial_sum(m + 1);
    for (int i = 1; i <= m; ++i) {
        sort(money_count[i].begin(), money_count[i].end());
        partial_sum[i].push_back(0);
        for (int j = 0; j < money_count[i].size(); ++j) {
            partial_sum[i].push_back(partial_sum[i].back() + money_count[i][j]);
        }
    }
    /*
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < partial_sum[i].size(); ++j) {
            cout << partial_sum[i][j] <<" ";
        }
        cout << endl;
    }
     */
    ll start = 1 + (n + m - 2) / m;
    ll answer = -1;
    for (int now = start; now <= n; ++now) {
        vector<int> lookup(m+1);
        ll change = now - money_count[1].size();
        ll transfer = 0;
        ll themoney = 0;
        for (int i = 2; i <= m; ++i) {
            if (money_count[i].size() >= now) {
                themoney += partial_sum[i][money_count[i].size() - now + 1];
                transfer += money_count[i].size() - now + 1;
            }
            
        }
        //cout << transfer << "transfer" << themoney << endl;
        for (int ind = 0; ind < global_money.size() && transfer < change; ++ind) {
            int voter = global_money[ind][1];
            ll mon = global_money[ind][0];
            //cout << voter << "mon" << mon << endl;
            int sz = money_count[voter].size();
            //cout << lookup[voter] << " " << sz - now + 1 << "istrue" << endl;
            if (lookup[voter] >= sz - now + 1) {
                ++transfer;
                themoney += mon;
            }
            ++lookup[voter];
        }
        //cout << now << " " << themoney << endl;
        answer = (answer == -1 ? themoney : min(themoney, answer));
    }
    printf("%lld", answer);
}
