#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int solve(vector<int> &arr, int n, int m) {
    int lo = 0;
    int hi = m - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        bool succ = true;
        int threshold = 0;
        //cout << "mid is" << mid << endl;
        for (int i = 0; i < n && succ; ++i) {
            //cout << i << " old threshold " << threshold << endl;
            int lo_num = arr[i];
            int hi_num = arr[i] + mid;
            //cout << arr[i] << " " << hi_num << endl;
            //case 1: hi_num < m
            if (hi_num < m) {
                if (hi_num < threshold) succ = false;
                else threshold = max(threshold, arr[i]);
            } else {
                hi_num %= m;
                if (hi_num < threshold) threshold = max(threshold, arr[i]);
            }
            //cout << i << " new threshold " << threshold << endl << endl;
        }
        if (succ) {
            // mid is enough
            hi = mid;
        } else {
            //mid is not enough
            lo = mid + 1;
        }
    }
    return hi;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int answer = solve(arr, n, m);
    printf("%d\n", answer);
}
