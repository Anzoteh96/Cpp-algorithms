#include<bits/stdc++.h>
using namespace std;
#define mx 200010
#define ll int
map<ll,ll>Mp;
ll arr[mx];
ll to[64];
vector<int>res,now;
int main()
{
    
    to[0] = 1;
    for(int i=1; i<=30; i++)
    {
        to[i] = to[i-1] * 2;
    }
    //    cout << to[4];
    ll n;
    cin >> n;
    for(int i=0 ;i<n; i++)
    {
        cin >> arr[i];
        Mp[arr[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        ll val = arr[i];
        vector<int>vec;
        for(int j=0; j<=30; j++)
        {
            vec.clear();
            vec.push_back(val);
            bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
            ll n1 = to[j];
            if(Mp.find(n1+val) != Mp.end()) f1 = 1,vec.push_back(n1+val);
            if(f1 && Mp.find(n1+n1+val) != Mp.end()) vec.push_back(n1+n1+val);
            if(Mp.find(val-n1) != Mp.end()) f2=1,vec.push_back(val-n1);
            if(f2 && Mp.find(-n1-n1+val) != Mp.end()) vec.push_back(val-n1-n1);
            if((int)res.size()<=(int)vec.size())
            {
                res.clear();
                res = vec;
            }
        }
        
    }
    int Min = min((int)res.size(),3);
    cout << Min << endl;
    Mp.clear();
    for(int i=0; i<Min; i++)
    {
        if(Mp.find(res[i])==Mp.end())cout <<res[i] << " ";
        Mp[res[i]]++;
    }
    cout << endl;
}
