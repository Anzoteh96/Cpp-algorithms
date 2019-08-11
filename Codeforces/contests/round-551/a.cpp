#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, t;
    cin >> n >> t;
    int s[n];
    int d[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> d[i];
    }
    int ans[n];
    for (int i = 0; i < n; ++i) {
        //ans[i] is the minimum number that is >= t, >= s[i] and congruent to s[i] mod d[i]
        if (t < s[i]) ans[i] = s[i];
        else {
            int diff = t - s[i];
            int quo = (diff + d[i] - 1) / d[i];
            ans[i] = s[i] + quo * d[i];
        }
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        //cout << i << " " << ans[i] << endl;
        if (ans[i] < ans[answer]) answer = i;
    }
    cout << answer + 1 << endl;
}
