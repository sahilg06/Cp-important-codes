class TreeAncestor {
public:
    int l;
    vector<int>d;
    vector<vector<int>> up;
    vector<vector<int>> adj;

    void dfs(int v, int p)
    {
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for(int u : adj[v]) if(u!=p) d[u]=d[v]+1, dfs(u,v);
    }

    TreeAncestor(int n, vector<int>& parent) {
        l = ceil(log2(n));
        d.assign(n,0);
        up.assign(n, vector<int>(l + 1));
        adj.assign(n+1,vector<int>());
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);
        dfs(0,0);
    }
    
    int getKthAncestor(int node, int k) {
        if(k>d[node]) return -1;
        int ans=node,c=0;
        while(k)
        {
            if(k&1) ans=up[ans][c];
            k/=2;
            c++;
        }
        return ans;
    }
};
