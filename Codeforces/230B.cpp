#include <iostream>
#include <cmath>
using namespace std;

//objective: determine whether a number is T-prime
//T-prime means has exactly 3 positive divisors
//Equivalently, square of a prime number.

int main() {
	
	//prime sieve
	//store 'Y' for not prime and null for prime
	const int c=620000;
	char p[c]={};//representing 2c+1
	p[0]='Y';//1 is not prime
	for (int i=1; i<=sqrt(c/2)+1; i++)
	    {if (p[i]!='Y')//test prime first
	        {for (int j=2*i*(i+1);j<c;j+=(2*i+1))
	            {p[j]='Y';}
	        }
	    }
	
    int n;
	//n<= 10^5
    cin>>n;
    long long int a[n];
    for (int i=0; i<n; i++)
    {cin>>a[i];}
	//each number is <=10^12, so long long int needed
    for (int i=0; i<n; i++)
    {   //step 1: test if each number is a perfect square
        long long int d=sqrt(a[i]);
		//gives the floor funtion of sqrt(a[i]) as d is an integer
     if (d*d!=a[i])
        {cout<<"NO";}
	    //a[i] is a square if and only if floor sqrt (a[i])*floor sqrt (a[i]) is indeed a[i]
     else
		 //now that a[i] is a perfect square, test if its square root is a prime
        {if (d%2==0)
		 //even case: d is prime iff d is 2 (do it seperaely since it is not covered in prime sieve above)
            {if(d==2)
                {cout<<"YES";}
             else
                {cout<<"NO";}
            }
         else
            {int k=(d-1)/2;
	         //recall that p[k] corresponds to 2k+1
             if (p[k]=='Y')
                {cout<<"NO";}
             else
                {cout<<"YES";}
            } 
        }
        cout<<endl;
    }
	
	return 0;
}