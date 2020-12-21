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
ll modinv(ll n) 
{
    return binpow(n, mod - 2,mod);
}




/*******************************************coding********/
ll n,m;
string txt,pattern;
vll lps(100005,0);//longest prefix which is also a suffix of pattern
void compute_lps()
{
    ll i=1,len=0;
    lps[0]=0;
    while(i<m)
    {
        if(pattern[i]==pattern[len]) len++,lps[i]=len,i++;
        else
        {
            if(len==0) lps[i]=0,i++;
            else len=lps[len-1];
        }
    }
}
void search()
{
    ll i=0,j=0;
    while(i<n)
    {
        if(pattern[j]==txt[i]) i++,j++;
        if(j==m)
        {
            cout<<"pattern found at index "<<(i-j)<<endl;
            j=lps[j-1];
        }
        // mismatch after j matches 
        else if (i < n && pattern[j] != txt[i]) 
        { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) j = lps[j - 1]; 
            else i++; 
        }
    }
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
        cin>>txt>>pattern;
        n=sz(txt);m=sz(pattern);//n>=m
        compute_lps();
        search();
    }
}