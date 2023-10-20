//x<<y=x*2^y,x>>y=x/2^y
//1e5+3 is prime
// in a matrix, all elements of a primary diagonal have constant diff of coordinates
// and a secondary diagonal has constant sum of coordinates
//use ll() for using an integer in self-built fn
//(x&-x) bitwise and of (x and its 2's complement) returns (last set bit)
//eg if x=1010 then it will return 0010 
// careful dont print empty container(run time error) 
//use ("\n") instead of endl as endl flushes the output buffer
//every time so takes more time than \n (TLE)
//stoll() and to_string((less than 1e19))
//INT_MAX is approx 3e10
//For sets use set_name.lower_bound(x)(strictly O(logn)) 
//NOT lb(all(s),x)(O(logn) for random access (eg vector) but for sets it is O(n));
//int 2e9, long long int 91e18
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
#define p(a) cout<<a<<endl
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
#define vplld vector< pair<lld,lld> >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mll map<ll, ll>
#define umll unordered_map<ll, ll>
#define mcll map<char,ll>
#define sz(container) ll((container).size())
#define fill(a,b) memset(a, b, sizeof(a))
#define jai_shree_ram ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
lld pi=3.1415926535897932;
const ll INF = 1LL<<62;
const ll mod=1000000007;
// const ll mod=998244353;
const ll dx[4]={-1, 0, 1, 0} , dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1} , dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
string ds="RLDU";
 
template <typename T, size_t size> void printa(const T (&array)[size])
{
    for(size_t i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    cout<<endl;
 
}
template<typename T> void printv(const T& t) 
{
    std::copy(t.cbegin(),t.cend(),std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout<<endl;
}
 
 
////////////////////////////////////////////////////////////////
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x)
 {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) 
{int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/////////////////////////////////////////////////////////////////
 
/***************************************/
// struct cmp 
// {
//     bool operator() (const pll &a, const pll &b)  const 
//     {
//         ll lena = a.sec - a.fi + 1;
//         ll lenb = b.sec - b.fi + 1;
//         if (lena == lenb) return a.fi < b.fi;
//         return lena > lenb;
//     }
// };
/********************************/
 
 
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
 
ll lcm(ll a, ll b)
{
    ll g=__gcd(a, b);
    return a/g*b;
}
ll Pow(ll a, ll b) 
{
    //a %= m;
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a ;//% m;
        a = a * a ;//% m;
        b >>= 1;
    }
    return res;
}
 
ll modinv(ll n,ll mod) 
{
    return binpow(n, mod - 2,mod);
}
 
 
/**************coding****************************************/
ll k,d;
vll num;
ll dp[2000][2000][2][3]={};
ll rec(ll i, ll m, ll small, ll ch) //0,1,2
{
    if(i==sz(num))
    {
        if(!m) return 1;
        return 0;
    }

    if(dp[i][m][small][ch]!=-1) return dp[i][m][small][ch];

    ll ans=0;
    ll lim=num[i];
    if(small) lim=9;

    ll rem=1; //even se start
    if(ch==1) rem=0; //odd se start hua h
    ll st=0;

    if(!ch) // start nhi hua h abhi tk
    {
        st=1, 
        ans=(ans+rec(i+1,m,1,0))%mod; // next mein bhi start nhi hoga
    }

    // ya to pehle se start h ya fir next mein start ho jayega
    For(j,st,lim)
    {
        if(ch!=0 and (i%2==rem) and j!=d) continue; // even pr sirf d aayega
        if(ch!=0 and (i%2!=rem) and j==d) continue; // odd pr d nhi aayega
        if(ch==0 and j==d) continue;
        ll flag=small;
        if(j<lim)  flag=1;

        ll nch=ch;

        // yha pr start hoga 
        if(ch==0)
        {
            if(i%2) nch=1; //odd se start
            else nch=2; //even se start
        }

        ans=(ans+rec(i+1,(m*10+j)%k,flag,nch))%mod;
    }

    return dp[i][m][small][ch]=ans;

}
void solve(ll t)
{
    memset(dp,-1,sizeof(dp));
    cin>>k>>d;
    string a,b; cin>>a>>b;
    ll n=sz(a), m=sz(b);

    num.clear();
    For(i,0,m-1) num.pb((b[i]-'0'));

    ll ans1=rec(0,0,0,0);
    debug(ans1);

    memset(dp,-1,sizeof(dp));
    num.clear();
    For(i,0,n-1) num.pb((a[i]-'0'));
    ll i=n-1;
    while(num[i]==0) num[i]=9,i--;
    num[i]--;
    if(num[0]==0) num.erase(num.begin());

    ll ans2=rec(0,0,0,0);
    debug(ans2);

    ll fans=(ans1-ans2+mod)%mod;
    p(fans);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    jai_shree_ram;
    ll T=1;//cin>>T;
    For(i,0,T-1)
    {
        solve(i+1);
    }
}