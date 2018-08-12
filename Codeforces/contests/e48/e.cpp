#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

double threshold (double pt, map<ll, double>& total, int sum, int lo, int hi) {
    if (pt <= (double)lo) {
        return 0;
    }
    if (pt >= (double)hi) {
        return sum;
    }
    
    auto lower = total.upper_bound(floor(pt));
    --lower;
    auto upper = total.lower_bound(ceil(pt));
    
    if (lower == upper) {
        return lower->second;
    }
    //cout << lower->first << " check " << lower->second << endl;
    //cout << pt << endl;
    //cout << upper->first << " check " << upper->second << endl;
    //cout << (double)(lower->second) + (double)(upper->second - lower->second) * (double)(pt - lower->first) / (double)(upper->first - lower->first);
    return (double)(lower->second) + (double)(upper->second - lower->second) * (double)(pt - lower->first) / (double)(upper->first - lower->first);
}

typedef long long int ll;

int main () {
    cout << fixed << setprecision(10);
    ll s, a, b;
    scanf("%lld %lld %lld", &s, &a, &b);
    int n;
    cin >> n;
    vector<ll> l(n);
    vector<ll> r(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &l[i], &r[i]);
    }
    map<ll, double> total;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        total[l[i]] = (double)sum;
        sum += (r[i] - l[i]);
        total[r[i]] = (double)sum;
    }
    /*
    for (auto it: total) {
        cout << it.first << " " << it.second << endl;
    }
     */
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        double start = (double) (y * a - s * x) / (double) (y - s);
        double finish = (double) (y * b - s * x) / (double) (y - s);
        //cout << start << " " << finish << endl;
        double score = threshold(finish, total, sum, l[0], r[n-1]) - threshold (start, total, sum, l[0], r[n-1]);
        //cout << threshold(finish, total, sum, l[0], r[n-1]) << " score " <<  threshold (start, total, sum, l[0], r[n-1]) << endl;
        printf("%f\n", score * (double) (y-s) / (double) (y));
    }
}
