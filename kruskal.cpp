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
const ll mod=998244353;
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
ll modinv(ll n) 
{
    return binpow(n, mod - 2,mod);
}

/**************coding*********************/
ll parent[300005],siz[300005];
void make_set(ll v) 
{
    parent[v] = v;
    siz[v] = 1;
}

//find by path compression
ll find_set(ll v) 
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

//union by rank(size)
void union_sets(ll a, ll b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) 
    {
        if (siz[a] < siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

multiset<pair<ll,pll>>edge;
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
        For(j,1,n) make_set(j);
        For(j,1,m)
        {
            ll x,y,w;cin>>x>>y>>w;
            edge.insert({w,{x,y}});
        }
        ll cost=0;
        for(auto e:edge)
        {
            ll n1=e.sec.fi,n2=e.sec.sec;
            if(find_set(n1)!=find_set(n2)) cost+=e.fi,union_sets(n1,n2);
        }
        cout<<cost;
    }
}