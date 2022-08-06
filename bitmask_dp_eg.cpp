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
const ll mod=1000000007;
const ll MOD=998244353;
const ll dx[4]={-1, 0, 1, 0} , dy[4]={0, 1, 0, -1};
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
ll gcdExtended(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}
ll modInverse(ll a, ll m){
    ll x, y;
    ll g = gcdExtended(a, m, x, y);
    ll res = (x%m + m) % m;
    return res;
}

ll modinv(ll n,ll mod) 
{
    return binpow(n, mod - 2,mod);
}


/**************coding****************************************/
ll edge[20][20]={};
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
        ll n,m;cin>>n>>m;
        For(j,1,m)
        {
            ll a,b;
            cin>>a>>b;a--;b--;
            edge[a][b]=1;edge[b][a]=1;
        }
        vll check(1<<n,1),dp(1<<n);
        For(j,0,(1<<n)-1)
        {
            dp[j]=1e15;
            vll temp;
            For(k,0,n-1) if(j&(1<<k)) temp.pb(k);
            For(x,0,sz(temp)-1)
            {
                For(y,x+1,sz(temp)-1)
                {
                    if(!edge[temp[x]][temp[y]]) check[j]=0;
                }
            }
            if(check[j]) dp[j]=1;
        }
        dp[0]=0;
        For(j,0,(1<<n)-1)
        {
            for(ll sub=j;sub;sub=(sub-1)&j) dp[j]=min(dp[j],dp[sub]+dp[sub^j]);
        }
        cout<<dp[(1<<n)-1];
    }
}