#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n;
    cin >> n;
    vector<int>pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i];
    }
    sort(pts.begin(), pts.end());
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        freq[pts[i]] = 1;
    }
    vector<int>ptwo(1);
    ptwo[0] = 1;
    for (int i = 1; i <= 30; ++i) {
        ptwo.push_back(ptwo[i - 1] * 2);
    }
    //for (int i = 0; i < 33; ++i) cout << ptwo[i] << " ";
    
    vector<int>doubles;
    vector<int>triples;
    bool flag3 = false;
    bool flag2 = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 31; ++j) {
            if (freq.count(pts[i] - ptwo[j]) && freq.count(pts[i] + ptwo[j])) {
                flag3 = true;
                triples = vector<int>{pts[i] - ptwo[j], pts[i], pts[i] + ptwo[j]};
            }
            else if (freq.count(pts[i] + ptwo[j])) {
                flag2 = true;
                doubles = vector<int>{pts[i], pts[i] + ptwo[j]};
            }
        }
    }
    if (flag3) {
        cout << 3 << endl;
        cout << triples[0] << " " << triples[1] << " " << triples[2] << endl;
    }
    else if (flag2) {
        cout << 2 << endl;
        cout << doubles[0] << " " << doubles[1] << endl;
    }
    else {
        cout << 1 << endl;
        cout << pts[0] << endl;
    }
}
