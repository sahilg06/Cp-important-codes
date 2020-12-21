//x<<y=x*2^y,x>>y=x/2^y
// while using ?: in add/subt use bracket
//use ll() for using an integer in self-built fn
// careful dont print empty container(run time error) 
//v.erase O(n) 
#include<bits/stdc++.h>
typedef long long int ll;
#define lld long double
#define For(i, a, b) for(long long int i = (a); i <= (b); i++)
#define Forr(i, a, b) for(long long int i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define vi vector<int>
#define vch vector<char>
#define sll set<ll>
#define sch set<ch>
#define vpll vector< pair<ll,ll> >
#define vpii vector< pair<int,int> >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mll map<ll, ll>
#define mcll map<char,ll>
#define sz(container) ll((container).size())
#define fill(a,b) memset(a, b, sizeof(a))
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
lld pi=3.1415926535897932;
const ll inf=20000;

ll lcm(ll a, ll b)
{
    ll g=__gcd(a, b);
    return a/g*b;
}

ll binpow(ll a, ll b, ll m) 
{
    a %= m;
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}
vector<vll >adj(3000);
vll used(3000);
vch grid;ll cntG=0,cntB=0;
void dfs(ll v) 
{
    if(grid[v]=='#')
    {
        used[v]=1;return ;
    }
    else if(grid[v]=='G') cntG++;
    else if(grid[v]=='B') cntB++;
    used[v]=1;
    for(ll u : adj[v]) 
    {
        if (!used[u]) dfs(u);
    }
}
int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll T=1;cin>>T;
    For(i,1,T)
    {
        ll n,m;cin>>n>>m;
        adj.clear();adj.resize(3000);
        used.assign(3000,0);
        grid.clear();
        cntG=0;cntB=0;
        string s[n];
        For(j,0,n-1)
        {
            cin>>s[j];
        }
        For(j,0,n-1)
        {
            For(k,0,m-1)
            {
                if(j+1<n) adj[j*m+k].pb((j+1)*m+k),adj[(j+1)*m+k].pb(j*m+k);
                if(k+1<m) adj[j*m+k].pb(j*m+k+1),adj[j*m+k+1].pb(j*m+k);
                if(k-1>=0) adj[j*m+k].pb(j*m+k-1),adj[j*m+k-1].pb(j*m+k);
                if(j-1>=0) adj[j*m+k].pb((j-1)*m+k),adj[(j-1)*m+k].pb(j*m+k);
            }   
        }
        ll cnt1=0;
        For(j,0,n-1)
        {
            For(k,0,sz(s[j])-1)
            {
                grid.pb(s[j][k]);
                if(s[j][k]=='G') cnt1++;
            }
        }
        For(j,0,m*n-1)
        {
            if(grid[j]=='B')
            {
                for(ll k:adj[j])
                {
                    if(grid[k]=='.'&& k!=m*n-1) grid[k]='#';
                }
            }
        }
        dfs(m*n-1);
        if((!cntB||!cnt1)&& cntG==cnt1) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}