"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
considering [l,r)
l inclusive r exlusive
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

/******************************************************************************/
1.ONLY ONE ASSOCIATIVE OPERATION : Store the values of functions
QUERIES: pos->new value
calculate some function from [l,r]
/******************************************************************************/

vll t;
ll siz=1, neutral=0;
void init(ll n)
{
    siz=1;
    while(siz<n) siz*=2;
    t.assign(2*siz,0ll);
}

void op(ll a,ll b)
{
    return a+b;
}

void build(vll &a,ll cur,ll lx ,ll rx)
{
    if(rx-lx==1)
    {
        if(lx<sz(a)) t[cur] = a[lx];
        return;
    }
    ll m = (lx+rx)/2;
    build(a,2*cur+1,lx,m);
    build(a,2*cur+2,m,rx);
    t[cur]=op(t[2*cur+1], t[2*cur+2]);
}

void upd(ll cur, ll lx, ll rx, ll pos, ll new_v) 
{
    if (rx-lx==1) t[cur] = new_v;
    else 
    {
        ll m = (lx + rx) / 2;
        if(pos < m) upd(cur*2+1, lx, m, pos, new_v);
        else upd(cur*2+2, m, rx, pos, new_v);
        t[cur] = op(t[cur*2+1], t[cur*2+2]);
    }
}

ll calc(ll cur, ll lx, ll rx, ll l, ll r) 
{
    if (lx >= r || l >= rx) return neutral;
    if (lx >=l && rx <= r) return t[cur];

    ll m = (lx + rx) / 2;
    return op( calc(cur*2+1, lx, m, l, r) , calc(cur*2+2, m, rx, l, r) );
}



/***************************************************************************************/



/******************************************************************************/
2.ONLY ONE ASSOCIATIVE OPERATION : Store the values of operations
QUERIES: apply some function to a segment
calculate value at given pos
/******************************************************************************/

vll t;ll siz=1;
void init(ll n)
{
    while(siz<n) siz*=4;
    t.assign(2*siz,0ll);
}
void op(ll a,ll b)
{
    return a+b;
}
void modify(ll cur, ll lx, ll rx, ll l, ll r,ll v) 
{
    if (lx >= r || l >= rx) return;
    if (lx >=l && rx <= r)
    {
        t[cur]=op(t[cur],v);return;
    }
    ll m = (lx + rx) / 2;
    modify(2*cur+1,lx,m,l,r,v);
    modify(2*cur+2,m,rx,l,r,v);
}
ll calc(ll cur, ll lx, ll rx, ll pos)
{
    if (rx-lx==1) return t[cur];
    ll m = (lx + rx) / 2;
    if(pos<m) return op(calc(cur*2+1, lx, m, pos), t[cur]);
    else return op(calc(cur*2+2, m, rx, pos), t[cur]);
}

/**************************************************************************************/

/*****************************************************************************/
3. NON ASSOCIATIVE OPERATION , USING PROPAGATION :store operations
QUERIES: apply some function to a segment
calculate value at given pos
/******************************************************************************/

vll t;ll siz=1;
void init(ll n)
{
    while(siz<n) siz*=4;
    t.assign(2*siz,0);
}
ll operate(ll a,ll b)
{
    if(b==INT_MAX) return a;
    return b;
}
void propagate(ll cur,ll lx,ll rx)
{
    if(rx-lx==1) return;
    t[2*cur+1]=operate(t[2*cur+1],t[cur]);
    t[2*cur+2]=operate(t[2*cur+2],t[cur]);
    t[cur]=INT_MAX;
}
void modify(ll cur, ll lx, ll rx, ll l, ll r,ll v) 
{
    propagate(cur,lx,rx);
    if (lx >= r || l >= rx) return;
    if (lx >=l && rx <= r)
    {
        t[cur]=operate(t[cur],v);return;
    }
    ll m = (lx + rx) / 2;
    modify(2*cur+1,lx,m,l,r,v);
    modify(2*cur+2,m,rx,l,r,v);
}
ll calc(ll cur, ll lx, ll rx, ll pos)
{
    propagate(cur,lx,rx);
    if (rx-lx==1) return t[cur];
    ll m = (lx + rx) / 2;
    if(pos<m) return calc(cur*2+1, lx, m, pos);
    else return calc(cur*2+2, m, rx, pos);
}



/*************************************************************************************/

/********************************************************************/
4.MODIFY AND CALCULATE
TWO OPERATIONS "Change accordingly fn modify_op and calc_op"
Queries: modify the segment according to modify op
calc calc_op from l to r
/********************************************************************/

vpll t;ll siz=1,neutral=1e15;

void init(ll n)
{
    while(siz<n) siz*=4;
    t.assign(2*siz,{0,0});
    //change initialization accordingly

}

// fi:modify(l,r,v);sec:calc(l,r)
ll modify_op(ll a,ll b)
{
    return a+b;
}

ll calc_op(ll a,ll b)
{
    return min(a,b);
}

void build(vll &a,ll cur,ll lx ,ll rx)
{
    if(rx-lx==1)
    {
        if(lx<sz(a)) t[cur].sec=a[lx];return;
    }
    ll m=(lx+rx)/2;
    build(a,2*cur+1,lx,m);
    build(a,2*cur+2,m,rx);
    t[cur].sec = calc_op(t[2*cur+1].sec, t[2*cur+2].sec);
}

void modify(ll cur, ll lx, ll rx, ll l, ll r,ll v) 
{
    if (lx >= r || l >= rx) return;
    if (lx >=l && rx <= r)
    {
        t[cur].fi = modify_op(t[cur].fi,v);
        t[cur].sec = modify_op(t[cur].sec,v);
        return;
    }
    ll m = (lx + rx) / 2;
    modify(2*cur+1,lx,m,l,r,v);
    modify(2*cur+2,m,rx,l,r,v);
    t[cur].sec = calc_op(t[2*cur+1].sec, t[2*cur+2].sec);
    t[cur].sec = modify_op(t[cur].sec, t[cur].fi);
}

ll calc(ll cur, ll lx, ll rx, ll l,ll r)
{
    if (lx >= r || l >= rx) return neutral;
    if (lx >=l && rx <= r) return t[cur].sec;
    ll m = (lx + rx) / 2;
    ll m1 = calc(2*cur+1,lx,m,l,r);
    ll m2 = calc(2*cur+2,m,rx,l,r);
    ll res = calc_op(m1,m2);
    res = modify_op(res,t[cur].fi);
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    ll T=1;//cin>>T;
    For(i,1,T)
    {
        ll n,m;cin>>n>>m;
        init(n);
        For(j,1,m)
        {
            ll op;cin>>op;
            if(op==1)
            {
                ll l,r,v;cin>>l>>r>>v;modify(0,0,siz,l,r,v);
            }
            else
            {
                ll l,r;cin>>l>>r;cout<<calc(0,0,siz,l,r)<<endl;
            }
        }
    }
}


/************************************************************************************/
/************************************************************************/
5.MODIFY AND CALCULATE: With propagation
TWO OPERATIONS "Change accordingly fn modify_op and calc_op"
Queries: modify the segment according to modify op
calc calc_op from l to r
/************************************************************************/

vpll t;ll siz=1,neutral=0;
void init(ll n)
{
    while(siz<pow(2,n)) siz*=2;
    t.assign(2*siz,{INT_MAX,0});
    //change initialization accordingly
}

// fi:modify(l,r,v);sec:calc(l,r)
ll modify_op(ll a,ll b)
{
    if(b==INT_MAX) return a;
    else return b;
}

ll calc_op(ll a,ll b,ll lx, ll rx)
{
    if(ll(log2(rx-lx))&1) return(a|b);
    return (a^b);
}
void build(vll &a,ll cur,ll lx ,ll rx)
{
    if(rx-lx==1)
    {
        if(lx<sz(a)) t[cur].sec=a[lx];return;
    }
    ll m=(lx+rx)/2;
    build(a,2*cur+1,lx,m);
    build(a,2*cur+2,m,rx);
    t[cur].sec = calc_op(t[2*cur+1].sec, t[2*cur+2].sec);
}
 
void propagate(ll cur,ll lx,ll rx)
{
    if(rx-lx==1) return;
    t[2*cur+1].fi=modify_op(t[2*cur+1].fi,t[cur].fi);
    t[2*cur+2].fi=modify_op(t[2*cur+2].fi,t[cur].fi);
    t[2*cur+1].sec=modify_op(t[2*cur+1].sec,t[cur].fi);
    t[2*cur+2].sec=modify_op(t[2*cur+2].sec,t[cur].fi);
    t[cur].fi=INT_MAX;
}
 
void modify(ll cur, ll lx, ll rx, ll l, ll r,ll v) 
{
    propagate(cur,lx,rx);
    if (lx >= r || l >= rx) return;
    if (lx >=l && rx <= r)
    {
        t[cur].fi=modify_op(t[cur].fi,v);
        t[cur].sec=modify_op(t[cur].sec,v);
        return;
    }
    ll m = (lx + rx) / 2;
    modify(2*cur+1,lx,m,l,r,v);
    modify(2*cur+2,m,rx,l,r,v);
    t[cur].sec=calc_op(t[2*cur+1].sec, t[2*cur+2].sec,lx,rx);
}

ll calc(ll cur, ll lx, ll rx, ll l,ll r)
{
    propagate(cur,lx,rx);
    if (lx >= r || l >= rx) return neutral;
    if (lx >=l && rx <= r) return t[cur].sec;
    ll m = (lx + rx) / 2;
    ll m1=calc(2*cur+1,lx,m,l,r);
    ll m2=calc(2*cur+2,m,rx,l,r);
    ll res=calc_op(m1,m2,lx,rx);
    return res;
}