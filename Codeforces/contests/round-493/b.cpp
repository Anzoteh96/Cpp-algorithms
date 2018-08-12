#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, b;
    cin >> n >> b;
    vector<int>num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    vector<int>answer(n + 1, 9999999);
    answer[0] = 0;
    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        if (num[i] % 2) {
            ++odd;
        }
        else {
            ++even;
        }
        if (i < n - 1 && odd == even) {
            int diff = abs(num[i] - num[i + 1]);
            vector<int>temp(n + 1, 0);
            for (int j = 1; j <= n; ++j) {
                temp[j] = min(answer[j], answer[j - 1] + diff);
            }
            answer = temp;
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << endl;
    }*/
    int count = 0;
    while (count < n && answer[count + 1] <= b) {
        ++count;
    }
    cout << count << endl;
}
