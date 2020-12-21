//stores minimum prime factor O(n)
ll lp[1000000];
vll pr;

for (ll i=2; i<=1000000; ++i) 
{
    if (lp[i] == 0) 
    {
        lp[i] = i;
        pr.p_b(i);
    }
    for (ll j=0; j<sz(pr) && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
}

//checks whether a number is prime or not
//O(nloglogn)
vector<char> is_prime(100001, true);
void solve()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= 100000; i++) 
    {
        if (is_prime[i]) 
        {
            for (ll j = i * i; j <= 100000; j += i)
                is_prime[j] = false;
        }
    }
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
