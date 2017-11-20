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
#define ll                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
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
#define MAXN                 3000005
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
ll n,m;
ll nod,H;
ll par[MAXN];
bool vis[MAXN];
vector<ll>dis[MAXN];
vector<ll>cumsum[MAXN];
vector<pi>graph[MAXN];
vector<ll>visited_nodes;
void in_edges()
{
    ll u,v,c;
    FOR(i,n-1)
    {
        u=(i+1)/2;
        v=i+1;
        scl(c);
        graph[u].pb(mp(v,c));
        par[v]=u;
    }
}
void preprocess(ll pos)
{

    dis[pos].pb(0);
    for(ll i=0; i<graph[pos].size(); i++)
    {
        preprocess(graph[pos][i].uu);
    }
    if(graph[pos].size()==1)
    {
        ll adj=graph[pos][0].uu;
        ll adj_cost=graph[pos][0].vv;
        for(ll i=0; i<dis[adj].size(); i++)
        {
            dis[pos].pb(dis[adj][i]+adj_cost);
        }
    }
    else if(graph[pos].size()==2)
    {
        ll adj1=graph[pos][0].uu;
        ll adj2=graph[pos][1].uu;
        ll adj1_cost=graph[pos][0].vv;
        ll adj2_cost=graph[pos][1].vv;
        ll i=0;
        ll j=0;
        while(i<dis[adj1].size() && j<dis[adj2].size())
        {
            if(dis[adj1][i]+adj1_cost<=dis[adj2][j]+adj2_cost)
            {
                dis[pos].pb(dis[adj1][i]+adj1_cost);
                i++;
            }
            else
            {
                dis[pos].pb(dis[adj2][j]+adj2_cost);
                j++;
            }
        }
        while(i<dis[adj1].size())
        {
            dis[pos].pb(dis[adj1][i]+adj1_cost);
            i++;
        }
        while(j<dis[adj2].size())
        {
            dis[pos].pb(dis[adj2][j]+adj2_cost);
            j++;
        }
    }
}
void cumsum_make()
{
    FOR(i,n)
    {
        LOOP(j,dis[i].size())
        {
            if(j==0)
            {
                cumsum[i].pb(dis[i][j]);
            }
            else
            {
                cumsum[i].pb(cumsum[i][j-1]+dis[i][j]);
            }
        }
    }
}
ll binar(ll now_node,ll maxim)
{
    ll low=0;
    ll high=dis[now_node].size()-1;
    ll mid;
    ll ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(dis[now_node][mid]<=maxim)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
ll solve(ll now_node,ll dis_cover,ll ager_node)
{
    vis[now_node]=1;
    visited_nodes.pb(now_node);
    if(ager_node==-1)///pura subtree er answer e nite hobe
    {
        ll index=binar(now_node,H-dis_cover);
        ll ans=0;
        ans+=(((index+1)*H)-((index+1)*dis_cover+cumsum[now_node][index]));
        ll parent=par[now_node];
        if(vis[parent]==0 && parent!=0)
        {
            ll par_to_now_cost;
            LOOP(i,graph[parent].size())
            {
                ll adj=graph[parent][i].uu;
                if(adj==now_node)
                {
                    par_to_now_cost=graph[parent][i].vv;
                }
            }
            if(par_to_now_cost+dis_cover<=H)
            {
                return ans+solve(parent,par_to_now_cost+dis_cover,now_node);
            }
            else
            {
                return ans;
            }
        }
        else
        {
            return ans;
        }
    }
    else if(ager_node!=-1)
    {
        ll ans=0;
        ans+=(H-dis_cover);
        LOOP(i,graph[now_node].size())
        {
            if(graph[now_node][i].uu!=ager_node)
            {
                if((graph[now_node][i].vv+dis_cover)<=H)
                {
                    ans+=solve(graph[now_node][i].uu,dis_cover+graph[now_node][i].vv,-1);
                }
            }
        }
        ll parent=par[now_node];
        if(vis[parent]==0 && parent!=0)
        {
            ll par_to_now_cost;
            LOOP(i,graph[parent].size())
            {
                ll adj=graph[parent][i].uu;
                if(adj==now_node)
                {
                    par_to_now_cost=graph[parent][i].vv;
                }
            }
            if(par_to_now_cost+dis_cover<=H)
            {
                return ans+solve(parent,par_to_now_cost+dis_cover,now_node);
            }
            else
            {
                return ans;
            }
        }
        else
        {
            return ans;
        }
    }
}
int main()
{
    scl(n);
    scl(m);
    in_edges();
    preprocess(1);
    cumsum_make();
    FOR(i,m)
    {
        scl(nod);
        scl(H);
        ll ans=solve(nod,0,-1);
        printf("%lld\n",ans);
        LOOP(i,visited_nodes.size())
        {
            vis[visited_nodes[i]]=0;
        }
        visited_nodes.clear();
    }
    return 0;
}
