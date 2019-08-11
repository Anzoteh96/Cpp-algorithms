#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<vector<int>>edges(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<int>distances(n + 1, -1);
        vector<vector<int>>indices(2);
        queue<int>qu;
        qu.push(1);
        distances[1] = 0;
        indices[0].push_back(1);
        while (!qu.empty()) {
            int k = qu.front();
            qu.pop();
            vector<int> &vec = edges[k];
            for (int i = 0; i < vec.size(); ++i) {
                int ell = vec[i];
                if (distances[ell] != -1) continue;
                distances[ell] = distances[k] + 1;
                indices[distances[ell] % 2].push_back(ell);
                qu.push(ell);
            }
        }
        vector<int> hello = (indices[0].size() >= indices[1].size()) ? indices[1] : indices[0];
        printf("%d\n", hello.size());
        for (int num: hello) {
            printf("%d ",num);
        }
        printf("\n");
    }
}
