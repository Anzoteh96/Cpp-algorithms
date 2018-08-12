#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<vector<int>>ball(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> ball[i][0];
        ball[i][1] = i + 1;
    }
    sort(ball.begin(), ball.end());
    if (n > 2) {
        cout << n - 1 << endl;
        for (int i = 1; i < n; ++i) {
            cout << ball[i][1] << " ";
        }
    }
    else if (n == 2 && ball[1][0] > ball[0][0]) {
        cout << 1 << endl;
        cout << ball[1][1] << endl;
    }
    else {
        cout << -1 << endl;
    }
}
