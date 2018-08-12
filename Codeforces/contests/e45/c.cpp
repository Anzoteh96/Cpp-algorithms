#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll n;
    cin >> n;
    vector<string>brackets(n);
    for (int i = 0; i < n; ++i) {
        cin >> brackets[i];
    }
    map<int, ll>left;
    map<int, ll>right;
    for (int i = 0; i < n; ++i) {
        int l = 0;
        int min_l = 0;
        for (int j = 0; j < brackets[i].length(); ++j) {
            if (brackets[i][j] == '(') {
                ++l;
            }
            else {
                --l;
            }
            if (l < min_l) {
                min_l = l;
            }
        }
        if (l >= 0 && min_l >= 0) {
            ++left[l];
        }
        if (l <= 0 && min_l == l) {
            ++right[l];
        }
    }
    ll count = 0;
    for (auto it:left) {
        int k = it.first;
        if (right.count(-k)) {
            ll the_count = it.second * right[-k];
            count += the_count;
        }
    }
    cout << count << endl;
}
