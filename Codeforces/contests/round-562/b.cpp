#include <bits/stdc++.h>
typedef complex<double> Comp;
vector<Comp>roots;

using namespace std;

typedef long long int ll;

template <class T> void fft(const T* in, Comp *out, int size, int step = 1) {
    if (size == 1) {
        *out = *in;
    } else {
        const int half = size >> 1;
        fft(in, out, half, step * 2);
        fft(in + step, out + half, half, step * 2);
        
        for (int i = 0, j = 0; i < half; i++, j += step) {
            const auto temp = out[i + half] * roots[j];
            out[i + half] = out[i] - temp;
            out[i] += temp;
        }
    }
}

vector<int>multiply(vector<int>a, vector<int> b) {
    int N = (int)(a.size() + b.size());
    while (N & (N - 1)) ++N; // make it a power of two
    a.resize(N);
    b.resize(N);
    roots.resize(N);
    
    for (int i = 0; i < N; ++i) {
        roots[i] = polar(1.0, 2 * i * M_PI / N);
    }
    vector<Comp> x(N), y(N);
    //cout << "hello" << endl;
    fft(a.data(), x.data(), N);
    fft(b.data(), y.data(), N);
    
    for (int i = 0; i < N; ++i) {
        x[i] *= y[i];
        roots[i] = conj(roots[i]);
    }
    
    fft(x.data(), y.data(), N);
    vector<int> res(N);
    
    for (int i = 0; i < N; ++i) {
        res[i] = (int) ((real(y[i]) + 0.5) / N);
    }
    
    while (res.size() > 1UL && res.back() == 0) {
        res.pop_back();
    }
    return res;
}

int main() {
    
}
