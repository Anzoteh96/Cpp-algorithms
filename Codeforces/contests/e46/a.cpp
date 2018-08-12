#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n;
    cin >> n;
    map<string, int> a;
    map<string, int> b;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++a[s];
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++b[s];
    }
    int count = 0;
    count += abs(a["XXXL"] - b["XXXL"]);
    count += abs(a["XXL"] - b["XXL"]);
    count += abs(a["XL"] - b["XL"]);
    count += (abs(a["L"] - b["L"]) + abs(a["M"] - b["M"]) + abs(a["S"] - b["S"])) / 2;
    cout << count << endl;
}
