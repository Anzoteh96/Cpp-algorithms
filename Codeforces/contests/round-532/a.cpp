#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int absmax = 0;
    for (int b = 0; b < k; ++b) {
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (i % k == b) continue;
            diff += a[i];
        }
        //cout << b << " " << diff << endl;
        if (abs(diff) > absmax) absmax = abs(diff);
    }
    cout << absmax << endl;
}
