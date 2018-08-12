#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (n == 1) {
        cout << b[0] << endl;
        return 0;
    }
    vector<ll>sum(n + 1, ll(0));
    for (int i = n - 1; i >= 0; --i) {
        sum[i] = sum[i + 1] + a[i] + b[i];
    }
    ll answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += (2 * i * a[i]) + (2 * i * b[i]);
        if (i % 2 == 0) {
            answer += b[i];
        }
        else {
            answer += a[i];
        }
    }
    ll weighted = 2 * (n - 1) * a[n - 1] + 2 * (n - 1) * b[n - 1];
    //cout << weighted << endl;
    if ((n - 1) % 2 == 0) {
        weighted += b[n - 1];
        weighted += a[n - 2] * (2 * n - 3);
    }
    else {
        weighted += a[n - 1];
        weighted += b[n - 2] * (2 * n - 3);
    }
    //cout << answer << " " << weighted << endl;
    ll temp_ans = answer;
    for (int i = 1; i < n; ++i) {
        ll myref = sum[n - i];
        if ((n - i) % 2 == 0) {
            myref += a[n - i - 1];
        }
        else {
            myref += b[n - i - 1];
        }
        //cout << "myref" << myref << endl;
        //cout << temp_ans << " " << myref << " " << (4 * n - 2 * i - 2) << " " << weighted << endl;
        temp_ans = temp_ans +  myref * (4 * n - 2 * i - 2) - 2 * weighted;
        if (temp_ans > answer) {
            answer = temp_ans;
        }
        weighted = myref * (4 * n - 2 * i - 2) - weighted;
        if (i != n - 1) {
            if ((n - i) % 2 == 0) {
                weighted += b[n - i - 1] * (2 * n - 2 * i - 2) + b[n - i - 2] * (2 * n - 2 * i - 3);
            }
            else {
                weighted += a[n - i - 1] * (2 * n - 2 * i - 2) + a[n - i - 2] * (2 * n - 2 * i - 3);
            }
        }
        //cout << temp_ans << " " << weighted << endl;
    }
    cout << answer << endl;
}
