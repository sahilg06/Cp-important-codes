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
const ll MOD=1e9+7;
const ll dx[4]={-1, 0, 1, 0} , dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1} , dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

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
/******* 
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
********/

ll dp[1001][1001];
string lcs="";
void solve(string a,string b)
{
    ll n=sz(a),m=sz(b);
    For(i,1,n)
    {
        For(j,1,m)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    ll i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1]) lcs+=a[i-1],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    reverse(all(lcs));
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
        lcs="";
        string a,b;
        cin>>a>>b;
        solve(a,b);
        cout<<dp[sz(a)][sz(b)]<<" "<<lcs<<endl;
    }
}
