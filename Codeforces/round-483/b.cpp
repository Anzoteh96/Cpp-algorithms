#include <bits/stdc++.h>

using namespace std;

bool isvalid(vector<vector<char> > mine) {
    int n = mine.size();
    int m = mine[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ( mine[i][j] == '*') continue;
            else if ( mine[i][j] == '.') {
                for (int k = max(0, i - 1); k <= min (n - 1, i + 1); ++k) {
                    for (int l = max (0, j - 1); l <= min (m - 1, j + 1); ++l) {
                        if (i == k && j == l) continue;
                        if (mine[k][l] == '*') return false;
                    }
                }
            }
            else {
                int promise = int(mine[i][j]) - int('0');
                int count = 0;
                for (int k = max(0, i - 1); k <= min (n - 1, i + 1); ++k) {
                    for (int l = max (0, j - 1); l <= min (m - 1, j + 1); ++l) {
                        if (i == k && j == l) continue;
                        if (mine[k][l] == '*') ++count;
                    }
                }
                //cout << i << " " << j << " " << promise << " " << count << endl;
                if (promise != count) return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> >mine(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mine[i][j];
        }
    }
    if (isvalid (mine)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
