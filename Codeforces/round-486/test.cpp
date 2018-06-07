#include <iostream>

using namespace std;

int main() {
    int n = 200000;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << 3 * i;
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
