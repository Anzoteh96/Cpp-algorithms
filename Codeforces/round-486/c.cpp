#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<vector<int> >seq(k, vector<int>(0));
    for (int i = 0; i < k; ++i) {
        int s;
        cin >> s;
        vector<int>temp(s);
        for (int j = 0; j < s; ++j) {
            cin >> temp[j];
        }
        seq[i] = temp;
    }
    map<int, vector<pair<int, int> >> sum;
    for (int i = 0; i < k; ++i) {
        int count = 0;
        for (int j = 0; j < seq[i].size(); ++j) {
            count += seq[i][j];
        }
        for (int j = 0; j < seq[i].size(); ++j) {
            sum[count - seq[i][j]].push_back(make_pair(i + 1, j + 1));
        }
    }
    for (auto it = sum.begin(); it != sum.end(); ++it) {
        sort(it->second.begin(), it->second.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        });
        int sz = it->second.size();
        if (sz >= 2 && it->second[0].first != it->second[sz-1].first) {
            cout << "YES" << endl;
            cout << it->second[0].first << " " << it->second[0].second << endl;
            cout << it->second[sz-1].first << " " << it->second[sz-1].second << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
