#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int intmax = 200000;

vector<vector<int>>divisors(intmax+1);

int gcd(int a, int b) {
    if (a < 0 || b < 0) {
        return gcd(abs(a), abs(b));
    }
    if (a > b) {
        return gcd(b, a);
    }
    //so a <= b now
    if (a == 0) {
        return b;
    }
    //cout << a << b << endl;
    return gcd(b % a, a);
}

int main () {
    for (int i = 1; i <= intmax; ++i) {
        for (int j = 1; j * i <= intmax; ++j) {
            divisors[j * i].push_back(i);
        }
    }
    ll n;
    cin >> n;
    vector<int>a(n);
    //cout << "cp0" << endl;
    vector<vector<int>>vertices(intmax + 1);
    for (int i = 0 ; i < n; ++i) {
        scanf("%d", &a[i]);
        int k = a[i];
        for (int j = 0; j < divisors[k].size(); ++j) {
            vertices[divisors[k][j]].push_back(i);
            //cout << k << "div << "
        }
    }
    //cout << "cp1" << endl;
    vector<pair<int, int>>edges(n - 1);
    vector<vector<int>>all_edges(intmax + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d", &u);
        scanf("%d", &v);
        edges[i] = make_pair(u-1, v-1);
        int g = gcd(a[u-1], a[v-1]);
        for (int j = 0; j < divisors[g].size(); ++j) {
            all_edges[divisors[g][j]].push_back(i);
        }
    }
    //cout << "cp2" << endl;
    vector<ll>answer(intmax+1, 0);
    a.clear();
    
    for (int i = 1; i <= intmax; ++i) {
        //cerr << i << endl;
        if (!vertices[i].size()) continue;
        map<int, int>cc;
        map<int, vector<int>>cc_sets;
        for (int j = 0; j < vertices[i].size(); ++j) {
            cc[vertices[i][j]] = vertices[i][j];
            cc_sets[vertices[i][j]].push_back(vertices[i][j]);
        }
        if (true) {
            for (int j = 0; j < all_edges[i].size(); ++j) {
                int u = edges[all_edges[i][j]].first;
                int v = edges[all_edges[i][j]].second;
                if (cc[u] == cc[v]) continue;
                u = cc[u];
                v = cc[v];
                if (cc_sets[u].size() < cc_sets[v].size()) {
                    int temp = u;
                    u = v;
                    v = temp;
                }
                //self-reminder: cc_sets[u].size() >= cc_sets[v].size so move v to u
                for (int k = 0; k < cc_sets[v].size(); ++k) {
                    cc[cc_sets[v][k]] = u;
                    cc_sets[u].push_back(cc_sets[v][k]);
                }
                cc_sets[v].clear();
                cc_sets.erase(v);
            }
        }
        
        for (auto it:cc_sets) {
            ll sz = it.second.size();
            //cout << i << " " << sz << endl;
            answer[i] += (sz * (sz + 1)) / 2;
        }
    }
    
    for (int i = intmax; i >= 1; --i) {
        for (int j = 0; j < divisors[i].size() - 1; ++j) {
            answer[divisors[i][j]] -= answer[i];
        }
    }
    
    for (int i = 1; i <= intmax; ++i) {
        if (answer[i]) {
            cout << i << " " << answer[i] << endl;
        }
    }
    
}
