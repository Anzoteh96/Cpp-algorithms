#include <bits/stdc++.h>

using namespace std;

const double pi = 4 * (atan(1));

typedef long long int ll;

int main() {
    int n1, r1;
    cin >> n1 >> r1;
    double n = n1;
    double r = r1;
    cout << fixed << setprecision(10) << r * sin(pi/n) / (1 - sin(pi/n)) << endl;
}
