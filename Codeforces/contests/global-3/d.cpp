#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n;
    scanf("%d", &n);
    vector<pair<pair<int, int>, int>>small;
    vector<pair<pair<int, int>, int>>big;
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < v) small.push_back(make_pair(make_pair(u, v), i + 1));
        else big.push_back(make_pair(make_pair(u, v), i + 1));
    }
    vector<pair<pair<int, int>, int>>indices;
    if (small.size() >= big.size()) {
        sort(small.begin(), small.end());
        printf("%d\n", small.size());
        for (int i = small.size() - 1; i >= 0; --i) {
            printf("%d ", small[i].second);
        }
    } else {
        sort(big.begin(), big.end());
        printf("%d\n", big.size());
        for (int i = 0; i < big.size(); ++i) {
            printf("%d ", big[i].second);
        }
    }
    printf("\n");
}
