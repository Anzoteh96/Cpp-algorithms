#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int row_one = 0;
    int row_two = 0;
    for (int i = 1; i < n; ++i) {
        printf("? %d %d %d %d\n", i, 1, i, n);
        fflush(stdout);
        int k;
        scanf("%d", &k);
        if (k == -1) return 0;
        if (k % 2) {
            if (row_one) row_two = i;
            else row_one = i;
        }
    }
    if (row_one && !row_two) row_two = n;
    pair<int, int> head;
    pair<int, int> tail;
    if (row_one) {
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            printf("? %d %d %d %d\n", row_one, lo, row_one, mid);
            fflush(stdout);
            int k;
            scanf("%d", &k);
            if (k == -1) return 0;
            if (k % 2) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        head = make_pair(row_one, hi);
        lo = 1;
        hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            printf("? %d %d %d %d\n", row_two, lo, row_two, mid);
            fflush(stdout);
            int k;
            scanf("%d", &k);
            if (k == -1) return 0;
            if (k % 2 == 0) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        tail = make_pair(row_two, hi);
    }
    else {
        int col_one = 0;
        int col_two = 0;
        for (int i = 1; i < n; ++i) {
            printf("? %d %d %d %d\n", 1, i, n, i);
            fflush(stdout);
            int k;
            scanf("%d", &k);
            if (k == -1) return 0;
            if (k % 2) {
                if (col_one) col_two = i;
                else col_one = i;
            }
        }
        if (col_one && !col_two) col_two = n;
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            //cout << lo << " " << hi << endl;
            int mid = (lo + hi) / 2;
            printf("? %d %d %d %d\n", lo, col_one, mid, col_one);
            fflush(stdout);
            int k;
            scanf("%d", &k);
            if (k == -1) return 0;
            if (k % 2 == 0) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        head = make_pair(hi, col_one);
        lo = 1;
        hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            printf("? %d %d %d %d\n", lo, col_two, mid, col_two);
            fflush(stdout);
            int k;
            scanf("%d", &k);
            if (k == -1) return 0;
            if (k % 2 == 0) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        tail = make_pair(hi, col_two);
    }
    printf("! %d %d %d %d\n", head.first, head.second, tail.first, tail.second);
    fflush(stdout);
}
