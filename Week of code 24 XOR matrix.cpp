//Hackerrank week of code 24, Problem 4

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//in this code we are going to see what happens we keeping doing operations for m-1 times:
//Given a_0, a_1, a_2, ..., a_(n-1). Then replace a_0 by a_0(x)a_1, a_1 by a_1(x)a_2,...,a_(n-1) by a_(n-1)(x)a_0
//(x) is the XOR operation
//scope: n<=10^5, m<=10^5, a_i<=2^64
//If we do XOR one step at a time, we need O(Nm) time which is good enough to get 40% on this problem
//To increase efficiency, we investigate the pattern of XOR-ing as m changes

//To model this, we assume that we have an infinite array insted of N elements
//If m=1, we have a_0, a_1, a_2, ...
//If m=2, we have a_0(x)a_1, a_1(x)a_2, a_2(x)a_3, ...
//If m=3, we have (a_0(x)a_1)(x)(a_1(x)a_2), (a_1(x)a_2)(x)(a_2(x)a_3),...
//Since (x) is associative, we can remove the brackets and have a_0(x)a_1^2(x)a_2, etc 
//(always denote ^ as exponent in comment, here means the number of (x) iterated in this case)
//Inductively, for any m in general, we have a_i changed to the following:
//a_i(x)a_{i+1}^(m-1C1)(x)a_{i+2}^((m-1)C2) (x)... a_{i+m-1}^((m-1)C(m-1))
//Also notice that y(x)y=0 and y(x)0=y
//Therefore we consider only those i with (m-1Ci) odd.
//Now by Lucas's theorem:
//(m-1Ci) is odd iff there is no binary position such that the digit of m-1 is 0 and that of i is 1
//in reality, we have only n elements in array. This can be resolved by taking each index mod n

typedef long long int ll;
int main() {
  
    int n;
    cin>>n;
    ll m;
    cin>>m;
    int M=64;//the maximum number of bits needed to represent m
    
    int a[n];
    for (int i=0; i<n; i++)
        {cin>>a[i];}//our arrays
    
    
    int bin[M];//records the binary digit of m-1;
    
    for (int i=0; i<M; i++)
        {bin[i]=((m-1)>>i)%2;}

	//Now we store c[n], the array we keep changing to fit the XOR requirement
	//Let m-1 be 2^c1+2^c2+...+2^c_k
	//Observe that for each p, a[p] will become (x) applied to a[p+c] where:
	//c has nonzero binary digits in subset {c1, c2,..., c_k}
	//Using step by step, we notice that:
	//c[0] c[1]... will become c[0](x)c[2^c1], c[1](x)c[1+2^c1]...
	//then the second step c[0](x)c[2^c1], c[1](x)c[1+2^c1]... will become:
	//Step 2: applying the above by c[i](x)c[i+2^c2} gives:
	//(c[0](x)c[2^c1])(x)(c[2^c2}(x)c[2^c1+2^c2]) etc
	//repeated the process for c_i (i=1,2,...,k) yields the result
	//relevance of temp: the process do not get interfered by the changing of c[i]s
    
    int c[n];
    for (int i=0; i<n; i++)
        {c[i]=a[i];}
    int temp[n];
    
    for (int i=0; i<M; i++)
        {if (bin[i]==1)//only when the i-th binary digit (counted from the least signiifcant) of m-1 is 1
            {
             ll g=1;
             g<<=i;//g is now 2^i
             g%=n;
             for (int j=0; j<n; j++)
                 {int k=g+j;
                  k%=n;
                  temp[j]=c[j]^c[k];//store the updated value at temp first
                 }
             
             for (int i=0; i<n; i++)
                 {c[i]=temp[i];}//after each round, change c to match temp
            }
        }
    
    
    
    
    for (int i=0; i<n; i++)
        {cout<<c[i]<<" ";}
   
    return 0;
}