vector<vll>adj(100005);
vll used(100005),p(100005);
ll st,en;
void dfs(ll v) 
{
    used[v]=1;
    for(ll u : adj[v]) 
    {
        if (!used[u]) p[u]=v,dfs(u);
        else if(used[u]==1) st=u,en=v;
    }
    used[v]=2;
}  
int main()
{
    
    fast_io;
    ll T=1;//cin>>T;
    For(i,1,T)
    {
        ll n,m;cin>>n>>m;
        For(j,1,m)
        {
            ll a,b;cin>>a>>b;
            adj[a].pb(b);
        }
        For(j,1,n)
        {
            if(!used[j]) dfs(j);
        }
        if(!st) cout<<"IMPOSSIBLE";
        else
        {
            vll ans;
            ll par=en;
            while(par!=st)
            {
                ans.pb(par);
                par=p[par];
            }
            ans.pb(st);
            ans.pb(en);
            cout<<sz(ans)<<endl;
            reverse(all(ans));
            for(auto j:ans) cout<<j<<" ";
        }
    }
}