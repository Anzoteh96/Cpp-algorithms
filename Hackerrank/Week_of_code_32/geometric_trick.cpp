#include <bits/stdc++.h>
//week of code 32, Question 4
//score: 50/50
/*Problem statement: given a string s with length n,
with s[0], s[1], ..., s[n-1] all in the set {a, b, c},
find the number of unordered triples {i,j,k} such that (i+1)(k+1)=(j+1)^2,
and: either (s[j]='b', s[i]='a', s[k]='c') or (s[j]='b', s[i]='c' or s[k]='a')
*/

using namespace std;

int main() {
	int n;
	cin >> n;//length of string
	string s;
	cin >> s;//the actual string
	//

	/*step 1: prime sieve from 0 to n
	we have p as an boolean array such that p[i] contains the info whether 2i+1 is prime
	(there's only one even prime, i.e. 2. So eliminate all even numbers).
	*/
	bool* p = new bool[(n + 1) / 2];
	//step 1.1: initialize everything as yes (i.e. it is a prime number first), then change p[0] (representing 1) as false
	for (int i = 0; i<(n + 1) / 2; ++i) {
		p[i] = true;
	}
	p[0] = false;

	/*Step 1.2:
	we know that every composite number x has a prime divisor at most sqrt(x)
	so for each prime p it suffices to 'filter out' all multiples of at least p^2
	Which means we only consider all primes q<=sqrt(n), so q lives in index at most sqrt(n)/2
	(we place sqrt(n/2)+1 as upper bound for safety)
	then for each i with 2i+1 prime, we 'falsify' the index of p[k] where 2k+1>=(2i+1)^2 and 2i+1|2k+1
	that is, k=2i(i+1), 2i(i+1)+(2i+1), 2i(i+1)+2(2i+1), ...
	*/
	for (int i = 1; i <= sqrt(n / 2) + 1; ++i) {
		if (p[i] == false)continue;
		for (int j = 2 * i*(i + 1); j<(n + 1) / 2; j += (2 * i + 1)) {
			p[j] = false;
		}
	}
	//step 1.3: extract all primes
	vector<int>prime;
	prime.push_back(2);
	for (int i = 0; i<(n + 1) / 2; ++i) {
		if (p[i])prime.push_back(2 * i + 1);
	}

	/*Step 2: ans[x] is the number of such triples for substring of first x+1 characaters
	so what we need is ans[n-1]
	also ans[0]=0
	notice also that ans[i]-ans[i-1] is the number of such triples involving i (but not anything greater than i)
	(in other words we are sort of doing dynamic programming)
	this means that if s[i]='b' there's no use
	otherwise, we locate all j and k< i such that (j+1)(i+1)=(k+1)^2, which means (j+1)(i+1) is a perfect square
	fun fact: we search for the least such j (j_min) first, then the subsequent ones are just j+1=x^2(j_min +1) for some x
	also (j_min +1) is square free: prime p divides j_min+1 if and only if the exponent of p in i+1 is odd
	*/

	int* ans = new int[n];
	ans[0] = 0;
	for (int i = 1; i<n; ++i) {
		ans[i] = ans[i - 1];//initialize first, then add
		if (s[i] == 'b')continue;//ans[i]=ans[i-1] in this case
		int acc = i + 1;
		int min = i + 1;//it will be j_min later
		int sq = 1;
		for (int j = 0; prime[j] <= sqrt(acc); ++j) {
			//determines the parity of power of prime[j] in i+1
			int tempsqr = prime[j] * prime[j];
			while (acc%prime[j] == 0) {
				if (acc%tempsqr == 0) {
					acc /= tempsqr;
					min /= tempsqr;
					sq *= prime[j];//the corresponding minimum square
				}
				else {//where we deal with the case with odd exponent of prime[j]
					sq *= prime[j];
					acc /= prime[j];
				}

			}
		}
		if (acc>1) {//only case is when acc is prime
			sq *= acc;
			acc = 1;
		}
		int x = (i + 1) / sq;
		for (int j = 1; j<x; ++j) {
			int c = sq*j - 1;
			int d = min*j*j - 1;
			if (s[i] == 'a'&&s[c] == 'b'&&s[d] == 'c')++ans[i];
			else if (s[i] == 'c'&&s[c] == 'b'&&s[d] == 'a')++ans[i];
		}
	}
	//for (int i=0; i<n; ++i)cout<<i<<" "<<ans[i]<<" "<<endl;
	cout << ans[n - 1];
	return 0;
}
