const ll MAXN=200005;
ll factorial[MAXN]={},inverse[MAXN]={};


// Function to find nCk 
ll nCk(ll n, ll k) 
{ 
    // Base case 
    if (k<0 || k>n) return 0; 
 
    // Apply formula to find nCk 
    ll ans = factorial[n]; 
    ans = (ans * inverse[n - k]) % mod; 
    ans = (ans * inverse[k]) % mod; 
    return ans; 
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

// Function to precompute 
// factorial and inverse 
void preCompute() 
{ 
    ll fact = 1; 
    factorial[0] = 1; 
    inverse[0] = 1; 
 
    // Pre-compute factorial and inverse 
    For(i,1,MAXN) 
    { 
        fact = (fact * i) % mod; 
        factorial[i] = fact; 
        inverse[i] = binpow(factorial[i], mod - 2,mod); 
    } 
} 

"O(n2) implementation: n choose k
Pascal formula"
cost ll maxn=1000;
ll C[maxn + 1][maxn + 1];
void solve()
{
    C[0][0] = 1;
    For(n,1,maxn) 
    {
        C[n][0] = C[n][n] = 1;
        For(k,1,n-1) C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}