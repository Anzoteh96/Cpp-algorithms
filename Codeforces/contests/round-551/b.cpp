#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m, h;
    scanf("%d %d %d", &n, &m, &h);
    int a[m];
    int b[n];
    int t[n][m];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &t[i][j]);
        }
    }
    int answer[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[i][j]) {
                answer[i][j] = min(b[i], a[j]);
            }
            else {
                answer[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
}
