vector<sll>adj(100001);
vll used(100001,0);
vll ans;
void eu(ll u)
{
    while (!adj[u].empty())
    {
        auto v = *adj[u].begin();
        adj[u].erase(v);
        adj[v].erase(u);
        eu(v);
    }
    ans.pb(u);
}
void dfs(ll u)
{
    used[u]=1;
    for(auto v:adj[u]) if(!used[v]) dfs(v);
}
void solve()
{
    ll n,m;cin>>n>>m;
    while(m--)
    {
        ll x,y;cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    //check if euler cycle is possible from 1
    dfs(1);
    For(j,1,n)
    {
        if(!used[j] and !adj[j].empty())
        {
            p("IMPOSSIBLE");
            return;
        }
    }
    For(j,1,n)
    {
        if(sz(adj[j])%2)
        {
            p("IMPOSSIBLE");
            return;
        }
    }
    eu(1);
    printv(ans);

}