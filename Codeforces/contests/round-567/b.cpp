#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int l;
    cin >> l;
    string s;
    cin >> s;
    // see which ones we can split
    set<int>indices;
    int min_length = 1e9+7;
    for (int i = 1; i < l; ++i) {
        if (s[i] == '0') continue;
        indices.insert(i);
        int length_now = max(i, l - i);
        min_length = min(length_now, min_length);
    }
    vector<string>our_str;
    int min_digs = 1e9+7;
    for (int ind: indices) {
        int length_now = max(ind, l - ind);
        if (length_now > min_length + 1) continue;
        //cout << ind << endl;
        vector<int>digits;
        int carry = 0;
        for (int i = 0; i < length_now; ++i) {
            int d1 = (ind > i ? int(s[ind - i - 1]) - int('0') : 0);
            int d2 = (l - ind > i) ? int(s[l - i - 1]) - int('0') : 0;
            //cout << d1 << " " << d2 << endl;
            int res = (d1 + d2 + carry);
            digits.push_back(res % 10);
            carry = res / 10;
        }

        if (carry)digits.push_back(carry);
        string here = string(digits.size(), '0');
        for (int i = 0; i < digits.size(); ++i) {
            //cout << digits[digits.size() - i - 1] << " ";
            //here += char(digits[digits.size() - i - 1] + int('0'));
            here[i] = char(digits[digits.size() - i - 1] + int('0'));
        }
        our_str.push_back(here);
        min_digs = min(min_digs, (int)here.length());
        //cout << here << endl;
    }
    set<string>strs;
    for (string t: our_str) {
        if (t.length() == min_digs) {
            strs.insert(t);
            //cout << t << endl;
        }
    }
    cout << *strs.begin() << endl;
    
}
