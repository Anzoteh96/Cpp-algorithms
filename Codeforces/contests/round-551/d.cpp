#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;
int answer[N];
int num_leafs[N];
int ismax[N];
int parent[N];

void solve(int n, int root, vector<vector<int>> &childs) {
    if (!childs[root].size()) {
        answer[root] = 1;
        num_leafs[root] = 1;
    }
    else {
        num_leafs[root] = 0;
        for (int i = 0; i < childs[root].size(); ++i) {
            solve(n, childs[root][i], childs);
            //cout << "counting leafs" << " " << num_leafs[childs[root][i]] << " " << num_leafs[
            num_leafs[root] += num_leafs[childs[root][i]];
        }
        if (ismax[root]) {
            int defeat = N;
            for (int i = 0; i < childs[root].size(); ++i) {
                defeat = min(defeat, num_leafs[childs[root][i]] - answer[childs[root][i]]);
            }
            answer[root] = num_leafs[root] - defeat;
        }
        else {
            int smaller = 0;
            for (int i = 0; i < childs[root].size(); ++i) {
                smaller += (answer[childs[root][i]] - 1);
            }
            answer[root] = smaller + 1;
        }
    }
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ismax[i]);
    }
    for (int i = 1; i < n; ++i) {
        scanf("%d", &parent[i]);
        --parent[i];
    }
    vector<vector<int>>childs(n);
    for (int i = 1; i < n; ++i) {
        childs[parent[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        answer[i] = -1;
        num_leafs[i] = -1;
    }
    solve(n, 0, childs);
    /*
    for (int i = 0; i < n; ++i) {
        cout << i << " " << num_leafs[i] << " " << answer[i] << endl;
    }
     */
    cout << answer[0] << endl;
}
