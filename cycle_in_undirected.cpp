vector<vll >adj(100005);
vll subsz(100005),used(100005),p(100005);
ll cycle;
void dfs(ll v,ll x) 
{
    p[v]=x;
    used[v]=1;
    for(ll u : adj[v]) 
    {
        if(used[u] && u!=x) cycle=u;
        if (!used[u]) dfs(u,v);
    }
}
map<pair<ll,ll>,ll>edge;
int main()
{
    
    fast_io;
    ll T=1;//cin>>T;
    For(i,1,T)
    {
        ll n,m;cin>>n>>m;
        ll a,b;
        For(j,1,m)
        {
            cin>>a>>b;
            adj[a].pb(b);adj[b].pb(a);
            edge[mp(a,b)]=1;edge[mp(b,a)]=1;
        }
        For(j,1,n)
        {
            if(!used[j]) dfs(j,0);
        }
        if(!cycle) cout<<"IMPOSSIBLE";
        else
        {
            ll par=cycle,c=0;
            vll ans;
            while(1)
            {
                ans.pb(par);
                if(c>1&&edge[mp(par,cycle)])
                {
                    ans.pb(cycle);break;
                }
                par=p[par];
                c++;
            }
            cout<<sz(ans)<<endl;
            for(auto j:ans) cout<<j<<" ";
        }
    }
}