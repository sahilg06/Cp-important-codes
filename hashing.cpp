""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
We can just compute two different hashes for each string 
(by using two different p,different m, and compare these pairs instead
PREVENTING COLLISION
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



string s="*";
string t;
const ll p = 31;
const ll m = 1e9 + 9;
const ll N = 5005;
vll hashs(N,0),hashs_s(N,0),p_pow(N+1,0);
void presolve()
{
    p_pow[0]=1;
    For(j,1,N) p_pow[j]=(p_pow[j-1]*p)%m;
}



""""""""""""""""""""""HASHING DECREASING POWER""""""""""""""""""""
//hash:prefix-hash;hashs_s:suffix-hash
void compute_hash() 
{
    For(j,1,sz(s)-1)
    {
        hashs[j]=((hashs[j-1]*p)%m + (s[j]-'a'+1))%m;
    }
    string temp=t;reverse(all(temp));
    For(j,0,sz(temp)-1)
    {
        hashs_s[j+1]=((hashs_s[j]*p)%m + (temp[j]-'a'+1))%m;
    }
}
// interval hash prefix
ll ihashp(ll i,ll j)
{
    return ((hashs[j]-(hashs[i-1]*binpow(p,j-i+1,m))%m+10*m)%m);
}
// interval hash suffix
ll ihashs(ll i,ll j)
{
    return ((hashs_s[j]-(hashs_s[i-1]*binpow(p,j-i+1,m))%m+10*m)%m);
}
// palindrome using hash
bool isp(ll i,ll j,ll n)
{
    if(ihashp(i,j)==ihashs(n-j,n-i)) return true;
    return false;
}
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""




""""""""""""""""""""""""""""""HASHING INCREASING POWER""""""""""""""""""
void compute_hash() 
{
    ll pow=1;
    For(j,1,sz(s)-1)
    {
        hashs[j]= (hashs[j-1]+((s[j]-'a'+1)*pow)%m )%m;
        pow=(pow*p)%m;
    }
}
ll ihash(ll i,ll j)
{
    return ((hashs[j]-hashs[i-1]+m)%m)*modinv(binpow(p,i-1,m),m)%m;
}
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


""""""""""""""""""""""""""""NO of different SUBSTRINGS""""""""""""""""""""
ll cntdiff(string s)
{
    For(i,0,n-1)
    {
        hashes[i+1] = (hashes[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    ll cnt = 0;
    For(len,1,n) 
    {
        sll hs;
        For(i,0,n-len) 
        {
            ll cur_h = (hashes[i + len] + m - hashes[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += sz(hs);
    }
    return cnt;
}