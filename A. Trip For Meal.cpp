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
int main()
{
    ll n,a,b,c;
    scl(n);
    scl(a);
    scl(b);
    scl(c);
    ll sum=0;
    ll now=1;
    while(n)
    {
        n--;
        if(n==0)
        {
            break;
        }
        if(now==1)
        {
            if(a<=b)
            {
               sum+=a;
               now=2;
            }
            else
            {
                sum+=b;
                now=3;
            }
        }
        else if(now==2)
        {
            if(a<=c)
            {
                sum+=a;
                now=1;
            }
            else
            {
                sum+=c;
                now=3;
            }
        }
        else if(now==3)
        {
            if(b<=c)
            {
                sum+=b;
                now=1;
            }
            else
            {
                sum+=c;
                now=2;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
