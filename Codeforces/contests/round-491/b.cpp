#include <bits/stdc++.h>

using namespace std;

int threshold(int n) {
    if (n % 2) {
        return 4 * n + ((n + 1) / 2);
    }
    else {
        return (9 * n) / 2;
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int count = 0;
    int sum = 0;
    //cout << threshold(n) << endl;
    for (int i = 0; i < n; ++i) sum += vec[i];
    for (int i = 0; i < n; ++i) {
        if (sum >= threshold(n))break;
        ++count;
        sum += (5 - vec[i]);
    }
    cout << count << endl;
}
