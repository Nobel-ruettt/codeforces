#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[2004];
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    if(n==1)
    {
        if(arr[1]!=1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
        return 0;
    }
    ll count1=0;
    for(ll i=1;i<=n;i++)
    {
        if(arr[i]==1)
        {
            count1++;
        }
    }
    if(count1>0)
    {
        cout<<n-count1<<endl;
        return 0;
    }
    ll minimum_mov=LLONG_MAX;
    for(ll i=1;i<=n;i++)
    {
        ll x=arr[i];
        for(ll j=i+1;j<=n;j++)
        {
            x=__gcd(x,arr[j]);
            if(x==1)
            {
                minimum_mov=min(minimum_mov,(j-i));
            }
        }
    }
    if(minimum_mov==LLONG_MAX)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    else
    {
        cout<<n-1+minimum_mov<<endl;
    }
    return 0;
}
