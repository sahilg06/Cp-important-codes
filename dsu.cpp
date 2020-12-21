ll parent[300005],siz[300005],mi[300005],mx[300005];
void make_set(ll v) 
{
    parent[v] = v;mi[v]=v;mx[v]=v;
    siz[v] = 1;
}

//find by path compression
ll find_set(ll v) 
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

//union by rank(size)
void union_sets(ll a, ll b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) 
    {
        if (siz[a] < siz[b]) swap(a, b);
        parent[b] = a;
        /*
        mi[a]=min(mi[a],mi[b]);
        mi[b]=min(mi[a],mi[b]);
        mx[a]=max(mx[a],mx[b]);
        mx[b]=max(mx[a],mx[b]);
        */
        siz[a] += siz[b];
    }
}



""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//union by height
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}