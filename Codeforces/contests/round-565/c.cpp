#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    map<int, int>lookup{{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};
    vector<set<int>>nums(6);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        nums[lookup[u]].insert(i);
    }
    int cnt = 0;
    for (int k: nums[0]) {
        int ind[6];
        ind[0] = k;
        bool flag = true;
        for (int i = 1; i < 6 && flag; ++i) {
            auto it = nums[i].lower_bound(ind[i - 1]);
            if (it == nums[i].end()) flag = false;
            else {
                ind[i] = *it;
            }
        }
        if (flag) {
            cnt += 6;
            for (int i = 1; i < 6; ++i) {
                nums[i].erase(ind[i]);
            }
        }
    }
    cout << n - cnt << endl;
}
