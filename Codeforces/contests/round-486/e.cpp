#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>>ind(10, vector<int>(0));
    for (int i = 0; i < n; ++i) {
        int k = int(s[i])-int('0');
        ind[k].push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        sort(ind[i].begin(), ind[i].end());
    }
    bool flag[4];
    int ans[4];
    for (int i = 0; i < 4; ++i) {
        flag[i] = false;
    }
    //case 1: 00
    if (ind[0].size() >= 2) {
        int sz = ind[0].size();
        ans[1] = 2 * n - 3 - ind[0][sz-2] - ind[0][sz-1];
        flag[1] = true;
    }
    //case 2: 50
    if (ind[0].size() >= 1 && ind[5].size() >= 1) {
        int k = ind[0][ind[0].size() - 1];
        int l = ind[5][ind[5].size() - 1];
        //cout << k << " " << l << endl;
        if (k < l) {
            flag[2] = true;
            ans[2] = 2 * n - 2 - k - l;
        }
        if (l < k) {
            if (l != 0 || k == 1 || s[1] != '0') {
                ans[2] = 2 * n - 3 - k - l;
                flag[2] = true;
            }
        }
    }
    //case 3: 75
    if (ind[5].size() >= 1 && ind[7].size() >= 1) {
        int k = ind[5][ind[5].size() - 1];
        int l = ind[7][ind[7].size() - 1];
        if (k < l) {
            if (k != 0 || l == 1 || s[1] != '0') {
                ans[3] = 2 * n - 2 - k - l;
                flag[3] = true;
            }
        }
        if (l < k) {
            if (l != 0 || k == 1 || s[1] != '0') {
                ans[3] = 2 * n - 3 - k - l;
                flag[3] = true;
            }
        }
    }
    bool flag4 = false;
    int ans4;
    if (ind[5].size() >= 1 && ind[2].size() >= 1) {
        int k = ind[5][ind[5].size() - 1];
        int l = ind[2][ind[2].size() - 1];
        if (k < l) {
            if (k != 0 || l == 1 || s[1] != '0') {
                ans[0] = 2 * n - 2 - k - l;
                flag[0] = true;
            }
        }
        if (l < k) {
            if (l != 0 || k == 1 || s[1] != '0') {
                ans[0] = 2 * n - 3 - k - l;
                flag[0] = true;
            }
        }
    }
    if (!flag[1] && !flag[2] && !flag[3] && !flag[0]) {
        cout << -1 << endl;
        return 0;
    }
    vector<int>answer(0);
    for (int i = 0; i < 4; ++i) {
        if (flag[i]) answer.push_back(ans[i]);
    }
    sort(answer.begin(), answer.end());
    cout << answer[0];
}
