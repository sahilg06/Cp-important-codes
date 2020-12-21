int main()
{
    
    fast_io;
    ll T=1;cin>>T;
    For(i,1,T)
    {
        ll n;cin>>n;
        vpll time;
        For(j,0,n-1)
        {
            ll a,b;cin>>a>>b;
            time.pb(mp(a,b));
        }
        sort(all(time));
        multiset<ll>s;
        ll mx=0;
        For(j,0,n-1)
        {
            while(!s.empty()&&time[j].fi>(*s.begin()))
            {
                s.erase(s.begin());
            }
            mx=max(mx,sz(s)+1);
            s.insert(time[j].sec);
        }
        cout<<mx;
    }
}
