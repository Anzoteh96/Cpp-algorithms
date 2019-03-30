#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, q;
    cin >> n >> q;
    vector<int>vec(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
    vector<pair<int, int>>lookup(q + 1, make_pair(-1, -1));
    for (int i = 0; i < n; ++i) {
        int k = vec[i];
        if (lookup[k].first == -1) {
            lookup[k] = make_pair(i, i);
        }
        else {
            lookup[k].second = i;
        }
    }
    set<int>existing;
    for (int i = 0; i < n; ++i) {
        existing.insert(i);
    }
    vector<int>answer(n, 0);
    for (int i = q; i >= 1; --i) {
        if (lookup[i].first == -1) continue;
        auto it = existing.lower_bound(lookup[i].first);
        while (it != existing.end()) {
            int j = *it;
            if (j > lookup[i].second) break;
            answer[j] = i;
            auto temp = it;
            ++it;
            existing.erase(j);
        }
    }
    
    bool flag = true;
    //change at least one zero to q if there's none
    if (lookup[q].first == -1 && lookup[0].first == -1) {
        flag = false;
    }
    if (lookup[q].first == -1 && lookup[0].first != -1) {
        answer[lookup[0].first] = q;
    }
    for (int i = 0; flag && i < n; ++i) {
        if (vec[i] != answer[i] && vec[i] != 0) {
            flag = false;
        }
    }
    if (!flag) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int ind = 0;
    while (ind < n && answer[ind] == 0) {
        ++ind;
    }
    if (ind == n) {
        for (int i = 0; i < n; ++i) answer[i] = q;
    }
    else {
        for (int i = 0; i < ind; ++i) answer[i] = answer[ind];
        for (int i = 1; i < n; ++i) {
            if (answer[i] == 0) answer[i] = answer[i - 1];
        }
    }
    for (int i = 0; i < n; ++i) printf("%d ", answer[i]);
    cout << endl;
}
