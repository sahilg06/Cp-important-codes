"""""""""""""""""""""""""""""""""""""""""""""""""
https://codeforces.com/contest/1405/submission/92116068
To find distance between two nodes in a tree
To find diameter of a tree i.e. max distance between any two nodes
...Run dfs on any random node...Find node at max distance from it
...Run dfs on that node found in previous step
...Find node at max dis from that
"""""""""""""""""""""""""""""""""""""""""""""""""

""""""""""""""""""""""""""""""bfs""""
//dis:minimum no. of edges till that
queue<ll> q;
//p:parent d:depth
vll used(200002),p(200002),d(200002);
vector<vll>adj(200002);
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
""""""""""""""""""""""""""""""""""""""""

""""""""""""""""""""""""""""""bfs2d""""
struct node
{
    pll cd;
    ll d; //distance
};
map<pll,ll>used;
map<pll,ll>ar;

ll bfs2d(pll s,pll des)
{
    if(!ar[s]||!ar[des]) return -1;
    used[s]=1;
    queue<node>q;
    q.push({s,0});
    while(!q.empty())
    {
        node v=q.front();
        q.pop();
        if(v.cd==des) return v.d;
        For(i,0,7)
        {
            ll nx=v.cd.fi+dxx[i],ny=v.cd.sec+dyy[i];
            if(used[{nx,ny}]==0 && ar[{nx,ny}])
            {
                used[{nx,ny}]=1;
                q.push({{nx,ny},v.d+1});
            }
        }
    }
    return -1;
}
""""""""""""""""""""""""""""""""""""""""

DFS
/***********************************/

vector<vll >adj(100005);
vll subsz(100005),used(100005);
void dfs(ll v) 
{
    subsz[v]=1;
    used[v]=1;
    for(ll u : adj[v]) 
    {
        if (!used[u]) dfs(u),subsz[v]+=subsz[u];
    }
}  
/************************************/

DFS-2d
/**********************************/
ll used[1005][1005];
char s[1005][1005];
void dfs(ll x,ll y) 
{
    used[x][y]=1;
    For(i,0,3)
    {
       ll nx=x+dx[i],ny=y+dy[i];
       if(used[nx][ny]==0&&s[nx][ny]!='#') dfs(nx,ny);
    }
}
/*********/



/*********BRIDGES*********/
//trying to find deepest back edge
vector<vll >adj(500005);
vll visited(500005),low(500005),
tin(500005);
ll timer=0;
vpll bridge;
void dfs(ll v, ll p = -1) 
{
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    for (ll to : adj[v]) 
    {
        if (to == p) continue;
        if (visited[to])
        low[v] = min(low[v], tin[to]);
        else 
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) bridge.pb(mp(min(v,to),max(v,to)));
        }
    }
}


/*********ARTICUALTION POINTS*********/
vector<vll >adj(500005);
vll visited(500005),low(500005),
tin(500005);
ll timer=0;set<ll>cnt;
void dfs(ll v, ll p = -1) 
{
    visited[v] = 1;
    ll child=0;
    tin[v] = low[v] = timer++;
    for (ll to : adj[v]) 
    {
        if (to == p) continue;
        if (visited[to])
        low[v] = min(low[v], tin[to]);
        else 
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v]&&p!=-1) cnt.insert(v);
            child++;
        }
        if(p==-1&&child>1) cnt.insert(v);
    }
}


"Djikstra O(n^2 + m) implementation
First operation O(n) : Time of finding the unmarked vertex with the smallest distance d[v]
2nd operation O(1): relaxation
we perform the first operation O(n) times and the second one O(m) times.
OPTIMAL for dense graphs(where n^2 approx equal to m) "
ll n,m;
vll p(100005);vll d(100005);
vector<vpll>adj(100005);
vll used(100005);
void sss() 
{
    For(i,1,n)
    {
        ll v = -1;
        For(j,1,n)
        {
            if(!used[j] && (v==-1 || d[j]<d[v]))
                v = j;
        }
        //cout<<v<<" "<<d[v]<<endl;
        if(d[v] == INT_MAX)  break;
        used[v]=1;
        for(auto edge : adj[v]) 
        {
            ll to = edge.fi;
            ll len = edge.sec;
            if (d[v] + len < d[to]) 
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"SPARSE GRAPHS : we can use data structures that perform both types of operations 
(extracting a minimum and updating an item) in O(logn). 
Then the complexity of Dijkstra's algorithm is O(nlogn+mlogn)=O(mlogn)."

"PRIORITY QUEUE"
priority_queue<pll,vpll,greater<pll>> q;
vll d(100005),p(100005);
vector<vpll>adj(100005);
vll used(100005);
void sss()
{
    q.push({0, 1});
    while (!q.empty()) 
    {
        ll v = q.top().sec;
        ll d_v = q.top().fi;
        q.pop();
        if(d_v != d[v]) continue; 
        for (auto edge : adj[v]) 
        {
            ll to = edge.fi;
            ll len = edge.sec;
            if (d[v] + len < d[to]) 
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"SET of pairs"

set<pll>q;
vll d(100005),p(100005);
vector<vpll>adj(100005);
vll used(100005);
void sss()
{
    q.insert({0, 1});
    while (!q.empty()) 
    {
        ll v = q.begin()->sec;
        q.erase(q.begin());
        for (auto edge : adj[v]) 
        {
            ll to = edge.fi;
            ll len = edge.sec;
            if (d[v] + len < d[to]) 
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
'FLOYD WARSHALL ALGO--TO find the shortest path of all vertices 
from each vertex in O(n^3)'


ll n,m,q;cin>>n>>m>>q;
ll d[n+1][n+1];
For(j,1,n) 
{
    For(k,1,n)
    {
        d[j][k]=1e17;
    }
    d[j][j]=0;
} 
ll a,b,c;
For(j,1,m)
{
    cin>>a>>b>>c;
    d[a][b]=min(d[a][b],c);
    d[b][a]=min(d[b][a],c);
}
For(k,1,n)
{
    For(i,1,n)
    {
        For(j,1,n)
        {
            if (d[i][k] + d[k][j] < d[i][j])  
            d[i][j] = d[i][k] + d[k][j];  
        }
    }
}
For(j,1,q)
{
    ll x,y;cin>>x>>y;
    if(d[x][y]>=1e17) cout<<-1<<endl;
    else cout<<d[x][y]<<endl;
}

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
    
    
STRONGLY CONNECTED COMPONENTS AND :::TOPOLOGICAL SORTING:::

vector<vll >adj(100005),adjr(100005);
//adjr:reverse graph
vll used(100005),cost(100005),order,comp;
void dfs1(ll v) 
{
    used[v]=1;
    for(ll u : adj[v]) 
    {
        if (!used[u]) dfs1(u);
    }
    order.pb(v);
}
//ord will contain the reverse of topological sorting order
//clear comp after every call of dfs2
void dfs2(ll v) 
{
    used[v]=1;comp.pb(v);
    for(ll u : adjr[v]) 
    {
        if (!used[u]) dfs2(u);
    }
} 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
