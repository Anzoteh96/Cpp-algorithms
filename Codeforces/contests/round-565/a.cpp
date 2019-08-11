#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        ll k;
        cin >> k;
        while (k != 1) {
            if (!(k % 2)) {
                k /= 2;
            } else if (!(k % 3)) {
                k *= 2;
                k /= 3;
            } else if (!(k % 5)) {
                k *= 4;
                k /= 5;
            } else {
                cnt = -1;
                break;
            }
            ++cnt;
        }
        cout << cnt << endl;
    }
}
