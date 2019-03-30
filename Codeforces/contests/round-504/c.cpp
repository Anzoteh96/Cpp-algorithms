#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>open(n / 2);
    vector<int>closed(n / 2);
    int op = 0;
    int cl = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            open[op] = i;
            ++op;
        }
        else {
            closed[cl] = i;
            ++cl;
        }
    }
    vector<vector<int>>vec(k, vector<int>(2));
    for (int i = 0; i < k / 2; ++i) {
        vec[2 * i][0] = open[i];
        vec[2 * i][1] = 1;
        vec[2 * i + 1][0] = closed[i];
        vec[2 * i + 1][1] = 2;
    }
    sort(vec.begin(), vec.end());
    string ans;
    for (int i = 0; i < k; ++i) {
        if (vec[i][1] == 1) {
            ans += "(";
        }
        else {
            ans += ")";
        }
    }
    cout << ans << endl;
}
