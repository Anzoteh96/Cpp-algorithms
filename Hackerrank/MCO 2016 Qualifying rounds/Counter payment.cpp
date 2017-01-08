#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Problem statement:
//There are n people and k counters.
//Counter i takes a_i minutes to count the total price and get the payment of one counter.
//Find the minimum time for all n customers to finish payment.
//Constraint: n<=10^9, k<=3*10^5.

//After time d, the number of customers processed by each counter is floor (d/a_i)
//So desired d is the minimum d with sum (floor (d/a_i))=n.
//(sum(d/a_i))-k = sum ((d/a_i)-1) <= sum (floor (d/a_i)) <= sum (d/a_i)

//Bounding on d: denote x=sum (1/a_i), then dx>=n, or d>=n/x.
//However dx-k<=n so d<=(n+k)/x.

int main() {

	int n, k;
	cin >> n >> k;
	int a[k];
	for (int i = 0;i<k;i++) { cin >> a[i]; }

	double sum = 0.0000;
	for (int i = 0;i<k;i++) { sum += (1.0000 / a[i]); }
	long long int x = floor(n / sum);
	long long int y = floor((n + k) / sum);
	//distane between x and y is k/sum. 
	//Since sum=sum(1/a[i])>=sum(1/(3*10^5))=k/(3*10^5) we have k/sum<=k/(k/(3*10^5))=(3*10^5).
	//We are doing binary search now so the number of such will not exceed log(3*10^5)+1=19.
	//Reason of using binary search: the function d/sum increases with d.
	//For each 'candidate' d we sum up floor (d/a_i) individually, resulting in k steps.
	//hence running time is klog k.

	long long int low = x;

	long long int high = y;

	long long int d = (low + high) / 2;

	while (true)
	{
		long long int d = (low + high) / 2;


		long long int total = 0;
		for (int i = 0;i<k;i++) { total += floor(d / a[i]); };
		//we want total >=n.

		long long int subtotal = 0;
		for (int i = 0;i<k;i++) { subtotal += floor((d - 1) / a[i]); };
		//we also want to check whether d is the minimum index fulfilling our requirement.
		//If subtotal < n, we know that we cannot decrease d any further.

		if (total<n&&subtotal<n) { low = d + 1; }
		if (subtotal >= n&&total >= n) { high = d - 1; }

		if (subtotal<n&&total >= n) { cout << d;break; }


	}


	return 0;
}
