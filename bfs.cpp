
queue<ll> q;
//p:parent d:depth
vll used(200002),p(200002),d(200002);
vector<vll>adj(200002);
ll ans=0;
void bfs(ll s)
{
    q.push(s);
    p[s] = -1;
    used[s] = 1;
    while (!q.empty()) 
    {
        ll v = q.front();
        q.pop();
        for (ll u : adj[v]) 
        {
            if (!used[u]) 
            {
                used[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

"To find minimum no. of edges between two nodes in a graph take one 
as source, do bfs(source) find depth[destination]"