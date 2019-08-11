#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void myswap(vector<int> &vec, vector<int> &lookup, vector<pair<int, int>> &answer, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
    lookup[vec[i]] = i;
    lookup[vec[j]] = j;
    answer.push_back(make_pair(i, j));
}

void solve(int n, vector<int> &vec, vector<int> &lookup, vector<pair<int, int>> &answer) {
    for (int trgt = 1; trgt <= n; ++trgt) {
        if (vec[trgt] == trgt) continue;
        int ind = lookup[trgt];
        if (abs(ind - trgt) >= n / 2) {
            myswap(vec, lookup, answer, ind, trgt);
            continue;
        }
        if (trgt <= n / 2) {
            if (ind <= n / 2) {
                myswap(vec, lookup, answer, ind, n);
                myswap(vec, lookup, answer, n, trgt);
            } else if (trgt == 1) {
                myswap(vec, lookup, answer, 1, ind);
            } else {
                myswap(vec, lookup, answer, 1, ind);
                myswap(vec, lookup, answer, 1, n);
                myswap(vec, lookup, answer, 1, ind);
                myswap(vec, lookup, answer, trgt, n);
            }
        } else {
            myswap(vec, lookup, answer, 1, ind);
            myswap(vec, lookup, answer, 1, trgt);
            myswap(vec, lookup, answer, 1, ind);
        }
        // for (int i = 1; i <= n; ++i) cout << vec[i] << " "; cout << endl;
    }
}

int main () {
    int n;
    scanf("%d", &n);
    vector<int>vec(n + 1, 0);
    vector<int>lookup(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &vec[i]);
        lookup[vec[i]] = i;
    }
    vector<pair<int, int>>answer;
    solve(n, vec, lookup, answer);
    printf("%d\n", answer.size());
    for (int i = 0; i < answer.size(); ++i) {
        printf("%d %d\n", answer[i].first, answer[i].second);
    }
}
