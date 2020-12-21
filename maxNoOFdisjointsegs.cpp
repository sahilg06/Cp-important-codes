int main()
{
    
    fast_io;
    ll T=1;//cin>>T;
    For(i,1,T)
    {
        ll n;cin>>n;
        vpll time;
        For(j,1,n)
        {
            ll a,b;cin>>a>>b;
            time.pb(mp(b,a));
        }
        if(n==1)
        {
            cout<<1;return 0;
        }
        sort(all(time));
        ll l1=time[0].sec,r1=time[0].fi;
        ll cnt=1;
        For(j,1,n-1)
        {
            ll l2=time[j].sec,r2=time[j].fi;
            if(l2>=r1) cnt++,r1=r2;
        }
        cout<<cnt;
    }
}