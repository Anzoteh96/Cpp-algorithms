#include <bits/stdc++.h>

using namespace std;

int answer(int a, int b, int c, int n) {
    if (c > a || c > b) {
        return -1;
    }
    //so the union is a + b - c
    int uni = a + b - c;
    //cout << n - uni << "e";
    if (n <= uni) {
        return -1;
    }
    return n - uni;
}

int main () {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << answer(a,b,c,n) << endl;
}
