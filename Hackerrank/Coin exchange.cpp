#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Problem statement: given m coins with numerations a_0, a_1,...,a_{m-1}, how many ways are there to change n cents?
//Method: construct c[m][n+1], c[k][j] is the number of ways changing j cents with a_0, a_1, ..., a_k
//Observation: considering the number of a_k coins we have we know c[k][j]=:
//c[k-1][j] (no a_k coin) + c[k-1][j-a_k] (one a_k coin) +... +c[k-1][j-floor (ja_k) a_k]
//The final answer is then c[m-1][n]

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, m;
	cin >> n >> m;

	int a[m];
	for (int i = 0; i<m; i++)
	{
		cin >> a[i];
	}

	long long int c[m][n + 1] = { 0 };
	for (int i = 0; i <= n; i++)
	{
		if (i%a[0] == 0)
		{
			c[0][i] = 1;
		}
		else { c[0][i] = 0; }
	}

	if (m>1)
	{
		for (int i = 1; i<m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				for (int k = j; k >= 0; k -= a[i])
				{
					c[i][j] += c[i - 1][k];
				}
			}
		}
	}
	cout << c[m - 1][n];
	return 0;
}
