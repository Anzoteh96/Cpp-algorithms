#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n;
    scanf("%d", &n);
    int p[n + 1];
    int answer[n + 1];
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        bool temp[n + 1];
        for (int j = 0; j <= n; ++j) {
            temp[j] = false;
        }
        temp[i] = true;
        int now = i;
        while (true) {
            int check = p[now];
            if (temp[check]) {
                answer[i] = check;
                break;
            }
            temp[check] = true;
            now = check;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", answer[i]);
    }
}
