#include <bits/stdc++.h>

using namespace std;

int conv (string s) {
    if (s == "XX") return 0;
    if (s == "0X") return 1;
    if (s == "X0") return 2;
    if (s == "00") return 3;
}

int main () {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    vector<vector<int>>dp(n, vector<int>(4, 0));
    for (int i = 1; i < n; ++i) {
        string prev = "";
        prev += s[i - 1];
        prev += t[i - 1];
        string now  = "";
        now += s[i];
        now += t[i];
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = 0;
        }
        dp[i][conv(now)] = max(max(dp[i - 1][0], dp[i-1][1]), max(dp[i-1][2], dp[i-1][3]));
        if (conv(prev) == 0) continue;
        if (conv(prev) == 1 || conv(prev) == 2) {
            if (conv(now) == 3) {
                dp[i][0] = dp[i - 1][conv(prev)] + 1;
            }
        }
        if (conv(prev) == 3) {
            if (conv(now) == 0) continue;
            if (conv(now) == 3) {
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
                dp[i][1] = dp[i - 1][3] + 1;
                dp[i][2] = dp[i - 1][3] + 1;
            }
            if (conv(now)== 1 || conv(now) == 2) {
                dp[i][0] = dp[i - 1][3] + 1;
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    }*/
    cout << max(max(dp[n - 1][0], dp[n - 1][1]), max(dp[n - 1][2], dp[n - 1][3])) << endl;
}
