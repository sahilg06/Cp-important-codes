//x<<y=x*2^y,x>>y=x/2^y
//1<<31 gives overflow
// while using ?: in add/subt use bracket
//use ll() for using an integer in self-built fn
//(x&-x) bitwise and of (x and its 2's complement) returns (last set bit)
//eg if x=1010 then it will return 0010 
// careful dont print empty container(run time error) 
//v.erase O(n)
//use ("\n") instead of endl as endl flushes the output buffer
//every time so takes more time than \n (TLE)
//stoll() and to_string()
//INT_MAX is approx 3e10
//iterate over multiples for(ll j=i;j<=n;j+=i)
#include<bits/stdc++.h>
typedef long long int ll;
#define ull unsigned long long int
#define lld long double
#define endl "\n"
#define fi first 
#define sec second 
#define setprecision sp
#define lb lower_bound
#define ub upper_bound
#define For(i, a, b) for(long long int i = (a); i <= (b); i++)
#define Forr(i, a, b) for(long long int i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define vlld vector<lld>
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
const ll MOD=1e9+7;
const ll dx[4]={-1, 0, 1, 0} , dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1} , dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

/**************************************************
//FENWICK TREE
ll bit[100005];
void update(ll idx, ll val, ll n) 
{ 
    for (; idx <= n; idx += idx&-idx) 
        bit[idx] += val; 
}
ll query(ll idx) 
{ 
    ll sum = 0; 
    for (; idx>0; idx-=idx&-idx) 
        sum += bit[idx]; 
    return sum; 
}
*****************************************************/

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
/******************************************
ll phi(ll n) 
{
    ll result = n;
    For(i,0,sqrt(n))
    {
        if (n % i == 0) 
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
************************************/

/***************************************
//to check whether a string is whole number(without leading 0s)
bool isNumber(string s) 
{
    if(s=="0") return true;
    if(s[0]=='0') return false;
    For(i,0,sz(s)-1) 
    {
        if (isdigit(s[i]) == false)  return false;
    } 
    return true; 
}
******************************/
/******************************
queue<ll> q;
//p:parent d:depth
vll used(200002),p(200002),d(200002);
vector<vll>adj(200002);
void bfs(ll s)
{
    q.push(s);
    p[s] = -1;
    used[s] = 1;
    while (!q.empty()) 
    {
        ll v = q.front();
        q.pop();
        for (ll u : adj[v]) 
        {
            if (!used[u]) 
            {
                used[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}
*****************************/
/***********************************

vector<vll >adj(100005);
vll subsz(100005);
void dfs(ll v,ll x) 
{
    subsz[v]=1;
    for(ll u : adj[v]) 
    {
        if (u!=x) dfs(u,v),subsz[v]+=subsz[u];
    }
}  
************************************/
/**********************************
ll used[1005][1005];
char s[1005][1005];
void dfs(ll x,ll y) 
{
    used[x][y]=1;
    For(i,0,3)
    {
       ll nx=x+dx[i],ny=y+dy[i];
       if(used[nx][ny]==0&&s[nx][ny]!='#') dfs(nx,ny);
    }
}
*********/
ll n,m;
map<pair<ll,ll>,ll>edge;
vll p(100005);vlld d(100005);
vector<vll >adj(100005);
vll used(100005);
void dfs(ll v,lld avg) 
{
    used[v]=1;
    for(ll u : adj[v]) 
    {
        if (!used[u]) dfs(u,avg);
        if(used[u]==2)
        {
            if(d[u]!=INT_MAX)
            {
                if (d[v] > edge[mp(v,u)] - avg + d[u]) 
                    d[v] = edge[mp(v,u)] - avg + d[u],
                    p[v] = u;
            }
        }
    }
    used[v]=2;
} 
bool check(lld avg)
{
    d.assign(n+1, INT_MAX);
    p.assign(n+1, -1);
    used.assign(n+1, 0);
    d[n] = 0;
    dfs(1, avg);
    return(d[1]<=0);
}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    ll T=1;//cin>>T;
    For(i,1,T)
    {
        cin>>n>>m;
        For(j,1,m)
        {
            ll a,b,c;cin>>a>>b>>c;
            adj[a].pb(b);edge[mp(a,b)]=c;
        }
        lld l=0,r=100;lld mid;
        For(j,1,20)
        {
            mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid;
        }
        check(mid);
        vll ans;
        ll x=1;
        while(x!=-1) ans.pb(x),x=p[x];
        cout<<sz(ans)-1<<endl;
        for(auto j:ans) cout<<j<<" ";
        
    }
}