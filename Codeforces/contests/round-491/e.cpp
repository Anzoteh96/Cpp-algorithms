#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll comb(ll n, ll k) {
    ll start = 1;
    for (ll i = n; i >= n - k + 1; --i) {
        start *= i;
    }
    for (ll i = 1; i <= k; ++i) {
        start /= i;
    }
    return start;
}

int main () {
    string s;
    cin >> s;
    map<int, int>freq;
    for (int i = 0; i < s.length(); ++i) {
        ++freq[int(s[i]) - int('0')];
    }
    int k = freq[0];
    vector<ll>answer(25, 0);
    freq.erase(0);
    answer[0] = 1;
    for (auto it: freq) {
        int len = it.second;
        vector<ll>temp(25);
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < 25 - len; ++j) {
                temp[i + j] += answer[j] * comb(j + i, i);
            }
        }
        answer = temp;
        /*
        cout << it.first << endl;
        for (int i = 0; i < answer.size(); ++i) {
            cout << answer[i] << " ";
        }
        cout << endl;
        */
    }
    if (k > 0) {
        vector<ll>temp(25);
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < 25 - k; ++j) {
                temp[i + j] += answer[j] * (comb(j + i, i) - comb(j + i - 1, j));
            }
        }
        answer = temp;
    }
    ll count = 0;
    
    for (int i = 0; i < answer.size(); ++i) {
        //cout << answer[i] << " ";
        count += answer[i];
    }
    cout << count << endl;
}
