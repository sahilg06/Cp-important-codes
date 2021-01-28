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
const ll dx[4]={-1, 0, 1, 0} , dy[4]={0, 1, 0, -1};
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
ll level;
lld dp[100][100]={};
ll root[100][100]={};// considering key from i to j dp[i][j];
void print(ll l,ll r,ll level)
{
    if(l>r) return;
    ll rt=root[l][r];
    cout<<rt<<"   "<<level<<endl;
    print(l,rt-1,level+1),print(rt+1,r,level+1); 
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
        ll n;cin>>n;
        vll keys(n+1,0);
        vlld p(n+1,0),q(n+1,0),prob(n+1,0);
        For(j,1,n) cin>>keys[j];
        For(j,1,n) cin>>p[j]; 
        For(j,0,n) cin>>q[j];
        prob[0]=q[0];
        For(j,1,n) prob[j]+=(prob[j-1]+p[j]+q[j]);        
        For(len,1,n)
        {
            For(i,1,n-len+1)
            {
                ll j=i+len-1;
                dp[i][j]=INT_MAX;
                For(r,i,j)//treversing over root
                {
                    dp[i][j]=min(dp[i][j],dp[i][r-1]+dp[r+1][j]);
                    if(dp[i][j] == dp[i][r-1]+dp[r+1][j]) root[i][j]=r;
                }
                if(i==1) dp[i][j]+=prob[j];
                else dp[i][j]+=(prob[j]-prob[i-2]);
            }
        }
        cout<<dp[1][n]<<endl<<endl;
        For(j,1,n)
        {
            For(k,1,n) cout<<dp[j][k]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
        For(j,1,n)
        {
            For(k,1,n) cout<<root[j][k]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
        cout<<"OPTIMAL BST is"<<endl<<"key level"<<endl;
        print(1,n,1);
    }
}