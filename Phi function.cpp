#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//objective: to see if a number is prime
//we only consider odd numbers since the only even prime is 2
//below: ntp[i] stores whether 2i+1 is composite (value 1) or prime (value 0)
//prime[i] stores the i-th prime, where prime[0]=2

const int M=8000000;
bool ntp[M]={};//initialized as all zero
vector<int>prime(0);

//the procedure to produce all primes
void prodprime (){
	
	//to test odd primes, 2*i+1
	//algorithm: for each prime p we eliminate all old multiples >=p^2
	//p is stored at ntp[k] where p=2k+1
	//p^2=(2k+1)^2=4k^2+4k+1, stored at ntp[2k^2+2k]
	//since the interval between two odd multiples is 2p, the array interval is p=2k+1
	ntp[0]=1;
	for (int i = 1; i <= sqrt(M/2); i++)
	{if (ntp[i] == 0)//2i+1 prime
		{for (int j=2*i*(i+1); j<M; j+=(2*i+1))
			{ntp[j]=1;}//eliminate these
		}
	}

	prime.push_back(2);//2 is first prime
	for (int i = 0; i < M; i++)
		{if (ntp[i] == 0)
			{prime.push_back(2*i+1);}
		}//now we have all primes up to 2M-1
}

int phi (int n)
	{//to do so we need two accumulators, n1 and n2
	 //mechanism: let n=n1=n2=p_1^a_1 p_2^a_2...p_k^a_k, primes in ascending order
	 //we multiply n1 by (p1-1/p1) (p2-1/p2)... one prime at a time
	 //also reduce n2 to 1, one prime at a time
	 //To do so, we find the smallest prime divisor of n2 each time
	 //Method: test whether each prime in prime[i] divides n2
	 //Limit: prime[i]<=sqrt(n2) at each round since if n2>1 and no such prime in (1, sqrt(n2)) then n2 is now prime
	 //Then for each step, multiply n1 by (pi-1/pi) and divide n2 by p_i^ai (i.e. divide by p_i as long as p_i divides n_2)

	 int n1 = n;//keep dividing for phi
	 int n2 = n;//to be prime factorized
	 for (int i = 0; prime [i] <= sqrt (n2); i++)
	 {if (n2 % prime[i] == 0)
	 	{n1 *= (prime[i]-1);
	 	 n1 /= prime[i];
	 	 while (n2 % prime[i] == 0)
			{n2 /= prime[i];}
	 	}
	 }
	 if (n2 > 1)
	 {n1 *= (n2-1); n1 /= n2;}
	 return n1;
	}

int main() {
	// your code goes here
	prodprime();//prints phi(i) for first 10000 numbers
	for (int i = 2;i < 10000; i++)
	{cout<<i<<" "<<phi(i)<<endl;}



	return 0;
}