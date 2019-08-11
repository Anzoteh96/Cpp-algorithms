#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        int mod[3] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            int u;
            cin >> u;
            ++mod[u % 3];
        }
        int m = min(mod[1], mod[2]);
        mod[0] += m;
        mod[1] -= m;
        mod[2] -= m;
        mod[0] += (mod[1] / 3);
        mod[0] += (mod[2] / 3);
        cout << mod[0] << endl;
    }
}
