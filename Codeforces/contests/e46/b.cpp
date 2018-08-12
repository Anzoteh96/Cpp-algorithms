#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
    int n, m;
    cin >> n >> m;
    int prog[n + 2];
    prog[0] = 0;
    prog[n + 1] = m;
    for (int i = 1; i <= n; ++i) {
        cin >> prog[i];
    }
    int light = 0;
    int dim = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (i % 2 == 0) {
            dim += (prog[i] - prog[i - 1]);
        }
        else {
            light += (prog[i] - prog[i - 1]);
        }
    }
    int maxlight = light;
    int diff = light - dim;
    for (int i = 0; i <= n; ++i) {
        int d = prog[i + 1] - prog[i];
        if (i % 2 == 0) {
            diff -= d;
            if (d > 1) {
                int temp = light - 1 - diff;
                if (temp > maxlight) {
                    maxlight = temp;
                }
                //cout << diff << " " << temp << endl;
            }
        }
        else {
            diff += d;
            if (d > 1) {
                int temp = light + (prog[i + 1] - prog[i] - 1) - diff;
                if (temp > maxlight) {
                    maxlight = temp;
                }
                //cout << diff << " " << temp << endl;
            }
        }
    }
    cout << maxlight << endl;
}
