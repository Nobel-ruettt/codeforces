#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
using namespace std;
/***template***/
#define ll                   int
#define dd                   double
#define scl(n)               scanf("%d",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 1010
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  900000000000000000
#define mstt(a,b)            memset((a),(b),sizeof (a))
ll Set(ll n,ll pos)
{
    return n=n|(1<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1<<pos));
}
/***template***/
ll n,val;
vector<ll>num;
vector<ll>ans;
ll arr[1000005];
int main()
{
    scl(n);
    FOR(i,n)
    {
        scl(val);
        arr[val]=1;
        num.pb(val);
    }
    ll now_gcd=num[0];
    for(ll i=1; i<num.size(); i--)
    {
        now_gcd=__gcd(now_gcd,num[i]);
    }
    if(arr[now_gcd]==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(ll i=0;i<num.size();i++)
    {
        ans.pb(num[i]);
        ans.pb(now_gcd);
    }
    cout<<ans.size()<<endl;
    LOOP(i,ans.size())
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
