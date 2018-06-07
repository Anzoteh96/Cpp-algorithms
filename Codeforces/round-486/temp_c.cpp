#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int maxn=2e5+10;
int k;
struct pos
{
    int id;
    ll w;
    bool operator <(const pos &b) const
    {
        if(w<b.w)return true;
        else if(w==b.w)
        {
            return id<b.id;
        }
        else return false;
    }
};
int a[maxn];
ll sum[maxn];
set<pos>ans[maxn];
map<ll,int>mp;
int main()
{
    scanf("%d",&k);
    int n,temp;
    for(int i=0;i<k;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            sum[i]+=a[j];
        }
        for(int j=0;j<n;j++)
        {
            pos e;
            e.id=j,e.w=sum[i]-a[j];
            ans[i].insert(e);
        }
    }
    int flag=0;
    for(int i=0;i<k;i++)
    {
        set<pos>::iterator iter;
        for(iter = ans[i].begin() ; iter != ans[i].end() ; ++iter)
        {
            pos temp=*iter;
            int pos1=temp.id;
            temp.id=0;
            if(!mp[temp.w])
            {
                mp[temp.w]++;
                for(int j=i+1;j<k;j++)
                {
                    set<pos>::iterator iter1;
                    iter1=ans[j].lower_bound(temp);
                    if(iter1!=ans[j].end())
                    {
                        if((*iter1).w==temp.w)
                        {
                            cout<<"YES"<<endl;
                            cout<<j+1<<" "<<(*iter1).id+1<<endl;
                            cout<<i+1<<" "<<pos1+1;
                            flag=1;
                            exit(0);              }
                    }
                }
            }
        }
    }
    puts("NO");
    return 0;
}
