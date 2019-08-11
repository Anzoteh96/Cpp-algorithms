#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string>grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<vector<int>> col(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        col[n - 1][i] = 1;
        for (int j = n - 2; j >= 0; --j) {
            col[j][i] = (grid[j][i] == grid[j + 1][i]) ? col[j + 1][i] + 1 : 1;
        }
    }
    
    vector<vector<int>> conseq(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        conseq[i][m - 1] = 1;
        for (int j = m - 2; j >= 0; --j) {
            conseq[i][j] = (grid[i][j] == grid[i][j + 1]) ? conseq[i][j + 1] + 1 : 1;
        }
    }
    
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << col[i][j] << " "; cout << endl;
    }
    
    cout << endl;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << conseq[i][j]<< " ";cout << endl;
    }
    
    cout << endl;
     */
    
    
    ll answer = (ll)0;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int s_len = col[i][j];
            if (i + 3 * s_len > n) continue;
            int mid_start = i + s_len;
            int bot_start = i + 2 * s_len;
            if (col[mid_start][j] != s_len || col[bot_start][j] < s_len) continue;
            int freq = conseq[i][j];
            for (int st = i; st < i + 3 * s_len; ++st) {
                freq = min(freq, conseq[st][j]);
            }
            //int freq = min(min(conseq[i][j], conseq[mid_start][j]), conseq[bot_start][j]);
            answer += (ll)freq;
            i = mid_start - 1;
            //cout << answer << endl;
            //cout << i << " " << j << " " << freq << endl;
        }
    }
    cout << answer << endl;
    
}
