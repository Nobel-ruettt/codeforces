#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll Q[1000];
ll A[1000];
int main()
{
    cin>>s;
    ll count1=0;
    for(ll i=0;i<s.size();i++)
    {
        for(ll j=i+1;j<s.size();j++)
        {
            for(ll k=j+1;k<s.size();k++)
            {
                if(s[i]=='Q' && s[j]=='A' && s[k]=='Q')
                {
                    count1++;
                }
            }
        }
    }
    cout<<count1<<endl;
    return 0;
}
