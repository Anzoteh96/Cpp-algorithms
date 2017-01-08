#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Problem statement: given snakes and ladder, what's the least number of steps that allos us to reach 100 from 1?
//Method: breadth first search.
//Assumption: we have full control on the behaviour of the dice.
//We first construct a directed graph such that vertex from i to j exist if and only if we can reach from i to j
//If j is the mouth of snake or bottom of ladder, then there is no graph connecting j
//For each i, if i+k<=100, k<=6 and i+k is neither the mouth of snake nor bottom of ladder, then connect i to i+k.
//Otherwise, connect i to the the top of ladder/tail of snake determined by i+k

class node {
public:
	int data;
	node*next;
	node(int a, node*t)
	{
		data = a;
		next = t;
	}
};


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int t;
	cin >> t;
	for (int it = 0; it<t; it++)
	{
		int n;
		cin >> n;
		int L[n][2];
		for (int i = 0; i<n; i++)
		{
			cin >> L[i][0] >> L[i][1];
		}
		//L[i][0]=bottom of ladder
		//L[i][1]=top of ladder
		int m;
		cin >> m;
		int S[m][2];
		for (int i = 0; i<m; i++)
		{
			cin >> S[i][0] >> S[i][1];
		}
		//S[i][0]=mouth of snake
		//S[i][1]=botom of snake
		int acc[101];
		for (int i = 0; i <= 100; i++)
		{
			int ind = 0;
			while (ind<n&&L[ind][0] != i)
			{
				ind++;
			}
			if (ind<n) { acc[i] = L[ind][1]; }
			else
			{
				int indi = 0;
				while (indi<m&&S[indi][0] != i)
				{
					indi++;
				}
				if (indi<m) { acc[i] = S[indi][1]; }
				else acc[i] = i;
			}
		}
		//if i is neither the mouth of snake nor the bottom of ladder then acc[i]=i
		//otherwise if j is the bottom of snake or top of ladder corresponding to i then acc[i]=j

		//we store these info in adjacency list
		//adjacency list implementation
		node* adj[101] = { NULL };
		for (int i = 1; i <= 100; i++)
			if (acc[i] != i) { adj[i] = NULL; }//i is not reachable; assume that it doesn't exist
			else
			{
				adj[i] = new node(i, NULL);
				for (int k = 1; k <= 6; k++)
				{
					if (i + k>100) { break; }
					node* x = adj[i];
					while (x->next != NULL)
					{
						x = x->next;
					}
					x->next = new node(acc[i + k], NULL);
				}
			}

		int sac[101] = { 0 };//following: sac[i]=1 means it is possible to reach i in 'count' steps; 0 otherwise
		int temp[101] = { 0 };
		sac[1] = 1;
		temp[1] = 1;
		int count = 0;
		while (sac[100] == 0 && count <= 100)//once sac[100]=1 we can stop
			//only at most 99= (# vertices-1) steps needed to connect a vertex to another
		{
			for (int i = 1; i <= 100; i++)
			{
				if (sac[i] == 1)
				{
					node*x = adj[i];
					while (x->next != NULL)
					{
						temp[x->next->data] = 1;
						x = x->next;
					}
				}
			}
			for (int i = 1; i <= 100; i++)
			{
				sac[i] = temp[i];
			}
			count++;
		}

		if (sac[100] == 1) { cout << count; }
		else { cout << -1; }//if sac[100] is 0 after 100 steps, then there's no way to connect 1 to 100
		cout << endl;



	}

	return 0;
}
