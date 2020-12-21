/******************************************
ll phi(ll n) 
{
    ll result = n;
    For(i,0,sqrt(n))
    {
        if (n % i == 0) 
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
************************************/