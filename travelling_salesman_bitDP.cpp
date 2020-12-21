//x<<y=x*2^y,x>>y=x/2^y
//1e5+3 is prime
// in a matrix, all elements of a primary diagonal have constant diff of coordinates
// and a secondary diagonal has constant sum of coordinates
//use ll() for using an integer in self-built fn
//(x&-x) bitwise and of (x and its 2's complement) returns (last set bit)
//eg if x=1010 then it will return 0010 
// careful dont print empty container(run time error) 
//v.erase O(n)
//use ("\n") instead of endl as endl flushes the output buffer
//every time so takes more time than \n (TLE)
//stoll() and to_string((less than 1e19))
//INT_MAX is approx 3e10
//For sets use set_name.lower_bound(x)(strictly O(logn)) 
//NOT lb(all(s),x)(O(logn) for random access (eg vector) but for sets it is O(n));
#include<bits/stdc++.h>
typedef long long int ll;
#define ull unsigned long long int
#define lld long double
#define endl "\n"
#define fi first 
#define sec second 
#define sp setprecision 
#define lb lower_bound
#define ub upper_bound
#define For(i, a, b) for(long long int i = (a); i <= (b); i++)
#define Forr(i, a, b) for(long long int i = (a); i >= (b); i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define pll pair<ll,ll>
#define plld pair<lld,lld>
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
#define PI 3.1415926535897932384626 
const ll mod=1000000007;
//const ll dx[4]={-1, 0, 1, 0} , dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1} , dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
string ds="RLDU";

/***************************************
struct cmp 
{
    bool operator() (const pll &a, const pll &b)  const 
    {
        ll lena = a.sec - a.fi + 1;
        ll lenb = b.sec - b.fi + 1;
        if (lena == lenb) return a.fi < b.fi;
        return lena > lenb;
    }
};
********************************/

ll lcm(ll a, ll b)
{
    ll g=__gcd(a, b);
    return a/g*b;
}

ll binpow(ll a, ll b,ll m) 
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
ll Pow(ll a, ll b) 
{
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a;
        a = a * a ;
        b >>= 1;
    }
    return res;
}
ll modinv(ll n,ll m) 
{
    return binpow(n, m - 2,m);
}




/*******************************************coding********/
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
        ll n;cin>>n;
        vector<tuple<ll,ll,ll>>v;
        For(j,1,n)
        {
            ll x,y,z;cin>>x>>y>>z;
            v.pb({x,y,z});
        }
        ll dis[n][n];
        ll N=1ll<<n;
        ll cost[n][N]={};
        //currently at nth vertex,
        //already visited set of vertices represented by N
        For(j,0,N-1) For(k,0,n-1) cost[k][j]=1e15;
        cost[0][1]=0;
        For(j,0,n-1)
        {
            For(k,0,n-1)
            {
                auto [x1,y1,z1]=v[j];
                auto [x2,y2,z2]=v[k];
                dis[j][k]=abs(x1-x2)+abs(y1-y2)+max(0ll,z2-z1);        
            }
        }
        for(ll j=1;j<N;j+=2)
        {
            For(i,1,n-1)
            {
                if(j&(1ll<<i)) continue;
                For(k,0,n-1)
                {
                    if(j&(1ll<<k))
                    cost[i][j|(1ll<<i)]=min(cost[i][j|(1ll<<i)],cost[k][j]+dis[k][i]);
                }
            }
        }
        ll ans=1e15;
        For(j,1,n-1) ans=min(ans,cost[j][N-1]+dis[j][0]);
        cout<<ans;
    }
}