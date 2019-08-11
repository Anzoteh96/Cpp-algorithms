#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int max_prime = 2750131;

int main() {
    vector<bool> is_prime(max_prime + 1);
    vector<int> prime_min(max_prime + 1);
    vector<int> prime_lookup(max_prime + 1, 0);
    vector<int>primes{2};
    is_prime[1] = false;
    is_prime[2] = true;
    prime_lookup[2] = 1;
    for (int i = 3; i <= max_prime; ++i) {
        //cout << i << endl;
        bool flag = true;
        for (auto num: primes) {
            if (num > sqrt(i)) break;
            if (!(i % num)) {
                prime_min[i] = num;
                flag = false;
                break;
            }
        }
        if (flag) {
            is_prime[i] = true;
            primes.push_back(i);
            prime_lookup[i] = primes.size();
        } else {
            is_prime[i] = false;
        }
    }
    /*
    for (int i = 0; i < 200; ++i) {
        if (prime_lookup[i]) cout << i << " " << prime_lookup[i] << endl;
    }
     */
    int n;
    scanf("%d", &n);
    vector<int>nums(max_prime + 1);
    for (int i = 0; i < 2 * n; ++i) {
        int k;
        scanf("%d", &k);
        ++nums[k];
        //cout << k << endl;
    }
    vector<int>answer;
    for (int i = max_prime; i >= 1; --i) {
        if (!nums[i]) continue;
        if (is_prime[i]) {
            int fact = prime_lookup[i];
            for (int j = 0; j < nums[i]; ++j) {
                answer.push_back(fact);
            }
            nums[fact] -= nums[i];
            nums[i] = 0;
        } else {
            int fact = i / prime_min[i];
            for (int j = 0; j < nums[i]; ++j) {
                answer.push_back(i);
            }
            nums[fact] -= nums[i];
            nums[i] = 0;
        }
    }
    for (int i = 0; i < answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}
