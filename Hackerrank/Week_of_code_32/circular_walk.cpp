#include <bits/stdc++.h>
//week of code 32, question 3
//score: 31.5/35 (AC-ed a day late)

/*
given 0, 1, ..., n-1 on a circle, a fellow starts from point s and aims to go point t.
at point i, the fellow can move clockwise or anticlockwise by at most a[i] steps,
where a[i] is given by (g*a[i-1] + seed)mod p, and given a[0]=r_0 or some r_0
how many steps is needed to go from s to t (or -1, if this is impossible)?
*/

using namespace std;

int circularWalk(int n, int s, int t, int r_0, int g, int seed, int p){
	//step 1: store a[0],..., a[n-1] first so that we can extract info easily later
	int* a = new int[n];//dynamic array needed since n goes up to 10 million
    a[0]=r_0;
    for (int i=1; i<n; ++i){
		long long int temp = a[i - 1];
		long long int temp1 = (temp*g + seed) % p;
		a[i] = temp1;
    }
    
	/*
	Step 2: flag[i] stores the steps needed to go from s to point i, so our target is flag[t]
	initialize all flag[i] as -1 (unreachable) first, then change flag[s] to 0
	*/
	int* flag = new int[n];
	for (int i = 0; i<n; ++i) { flag[i] = -1; }
	flag[s] = 0;
	/*
	2.1: initialize a queue containing only s, then for every element in the queue we 'update' flag[i]
	for all neighbour i of the element.
	We pop all elements in q after all its neighbours have been marked, and push all its 'just freshly marked'
	neughbours in.
	Keep going until the queue is empty or until t is marked
	*/
	/*
	2.2: notice something interesting: if we can go from s to j in k steps and i is between s and j,
	then we can go from s to i within <=k steps
	proof: if s=a_0->a_1->...->a_k=j and let x be the minimum index such that i is (not strictly, i.e. inclusive) between s and a_x
	then x<=k, and i between a_{x-1} and a_{x}.
	since a_{x-1} can go a_x, it can go to i too, and so x steps is needed, <=n.
	This means the set of numbers achievable from s in k steps is actually an interval.
	We take both of both the ends of interval, so that we only need to update the neighbours outside those intervals.
	Of course we gonna update those intervals as well.
	*/
	queue<int>q;
	q.push(s);
	int start = s;//the endpoint of the interval in the negative direction
	int end = s;//the endpoint of the interval in the positive direction
	//initially the interval is [s,s]; the interval can go <0 or >=n so need to wrap around
	while (!q.empty() && flag[t] == -1) {
		int k = q.front();//guaranteed to be in the interval.
		q.pop();
		//the positive direction
		//we check fist whether the distance between end and k is greater than a[k]
		//if not, then extend end
		int dist1 = end - k;
		if (dist1<0)dist1 += n;
		if (a[k]>dist1)end = (k + a[k]) % n;
		for (int i = dist1 + 1; i <= a[k]; ++i) {
			if (flag[(i + k) % n] != -1)continue;
			//only work on those previously unmarked, and mark it as flag[k]+1 (cz extra one step needed)
			q.push((i + k) % n);
			flag[(i + k) % n] = flag[k] + 1;
		}

		//now the negative direction, same thing except that we have to be extra careful about modulo operator involving negative numbers
		int dist2 = k - start;
		if (dist2<0)dist2 += n;
		if (a[k]>dist2)start = (k - a[k]) % n;
		if (start<0)start += n;
		for (int i = dist2 + 1; i <= a[k]; ++i) {
			int x = (k - i) % n;
			if (x<0)x += n;
			if (flag[x] != -1)continue;
			q.push(x);
			flag[x] = flag[k] + 1;
		}
	}

	return flag[t];
}

int main() {
    int n;
    int s;
    int t;
    cin >> n >> s >> t;
    
    int r_0;
    int g;
    int seed;
    int p;
    cin >> r_0 >> g >> seed >> p;
    int result = circularWalk(n, s, t, r_0, g, seed, p);
    cout << result << endl;
    return 0;
}