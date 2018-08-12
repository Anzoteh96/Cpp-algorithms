#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }
    vector<int>answer(n);
    int remainder = 0;
    for (int i = 0; i < n; ++i) {
        remainder += names[i];
        answer[i] = remainder / m;
        remainder %= m;
    }
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;
}
