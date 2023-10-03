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
// const ll mod=1000000007;
const ll mod=998244353;
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

/**************coding****************************************/
// consider [l,r) : indices of the rightmost segment match 
//(i.e. among all detected segments we will keep the one that ends rightmost)
// see r as a boundary, beyond r we haven't scanned our string
// https://cp-algorithms.com/string/z-function.html

vector<int> getz(string s) 
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;

    // i: curr index
    for(int i = 1; i < n; i++) 
    {
        if(i < r)  z[i] = min(r - i, z[i - l]);

        while(i + z[i] < n && s[z[i]] == s[i + z[i]])  z[i]++;
        
        if(i + z[i] > r) l = i, r = i + z[i];
        
    }
    return z;
}
void solve()
{
    string s,p;cin>>s>>p;
    string concat=p+'$'+s;
    ll n=s.size(),m=p.size();
    ll siz=n+m+1;
    
    auto z=getz(concat);

    vll ans_idx;
    For(i,0,siz-1)
    {
        if(z[i]==m) ans_idx.pb(i-m-1);
    }
    debug(ans_idx);
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
        solve();
    }
}
