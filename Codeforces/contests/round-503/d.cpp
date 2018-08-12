#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n;
    cin >> n;
    if (n % 4 == 2) {
        printf("! %d", -1);
    }
    else {
        printf("? %d\n", 1);
        fflush(stdout);
        int resp1;
        cin >> resp1;
        printf("? %d\n", (n / 2) + 1);
        fflush(stdout);
        int resp2;
        cin >> resp2;
        if (resp1 == resp2) {
            printf("! %d", 1);
            return 0;
        }
        bool smaller = (resp1 > resp2);
        int lo = 1;
        int hi = n / 2;
        while (true) {
            int mid = (lo + hi) / 2;
            printf("? %d\n", mid);
            fflush(stdout);
            cin >> resp1;
            printf("? %d\n", (n / 2) + mid);
            fflush(stdout);
            cin >> resp2;
            if (resp1 == resp2) {
                printf("! %d", mid);
                break;
            }
            bool flag = (resp1 > resp2);
            if (smaller == flag) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
}
