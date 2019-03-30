#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    
    vector<int>perm(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &perm[i]);
    }
    vector<int>arr(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &arr[i]);
    }
    vector<int>lookup(n + 1);
    for (int i = 0; i < n; ++i) {
        lookup[perm[i]] = i;
    }
    
    vector<int>next_ele(m, m);
    //vector<int>prev_ele(m, -1);
    vector<vector<int>>most_recent(n);
    for (int i = 0; i < m; ++i) {
        int k = lookup[arr[i]];
        //cout << i << " " << k << endl;
        int l = (k == 0) ? (n - 1) : k - 1;
        vector<int>& vec = most_recent[l];
        for (int j = 0; j < vec.size(); ++j) {
            next_ele[vec[j]] = i;
        }
        most_recent[l].clear();
        most_recent[k].push_back(i);
    }
    
    /*
    for (int i = 0; i < m; ++i) {
        cout << next_ele[i] << " ";
    }
    cout << endl;
     */
    
    vector<vector<int>>chains;
    vector<int>min_required(m, -1);
    vector<pair<int, int>>chain_check(m, make_pair(-1, -1));
    int chain_no = 0;
    for (int i = 0; i < m; ++i) {
        if (chain_check[i].first >= 0) continue;
        int start = i;
        chains.push_back(vector<int>{});
        while (start < m && chain_check[start].first == -1) {
            chains[chain_no].push_back(start);
            chain_check[start] = make_pair(chain_no, chains[chain_no].size() - 1);
            start = next_ele[start];
        }
        ++chain_no;
    }
    /*
    for (int i = 0; i < chains.size(); ++i) {
        for (auto& num: chains[i]) cout << num << " ";
        cout << endl;
    }
    */
    
    for (int i = 0; i < chains.size(); ++i) {
        for (int j = 0; j < chains[i].size(); ++j) {
            int qty = 1;
            int this_num = chains[i][j];
            int cur_chain = i;
            int cur_ind = j;
            while (true) {
                if (chains[cur_chain].size() - cur_ind > n - qty) {
                    min_required[chains[i][j]] = chains[cur_chain][cur_ind + (n - qty)];
                    break;
                }
                else {
                    int ell =chains[cur_chain][chains[cur_chain].size() - 1];
                    int nxt = next_ele[ell];
                    if (nxt == m) {
                        min_required[chains[i][j]] = m;
                        break;
                    }
                    else {
                        qty += (chains[cur_chain].size() - cur_ind);
                        cur_chain = chain_check[nxt].first;
                        cur_ind = chain_check[nxt].second;
                    }
                }
            }
        }
    }
    /*
    for (int i = 0; i < m; ++i) {
        cout << min_required[i] << " ";
    }
    cout << endl;
    */
    
    vector<int>abs_min(m);
    abs_min[m - 1] = min_required[m - 1];
    for (int i = m - 2; i >= 0; --i) {
        abs_min[i] = min(abs_min[i + 1], min_required[i]);
    }
    /*
    for (int i = 0; i < m; ++i) {
        cout << abs_min[i] << " ";
    }
    cout << endl;
     */
    
    
    for (int i = 0; i < q; ++i) {
        int q, r;
        cin >> q >> r;
        cout << (abs_min[q-1] <= r-1);
    }
    cout << endl;
}
