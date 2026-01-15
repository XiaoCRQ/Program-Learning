```C++
// ========================
// Ultimate Boost ACM/ICPC CPP 模板
// Author: XiaoCRQ
// Date: 2025-10-30
// ========================

#include <bits/stdc++.h>
using namespace std;

// ------------------------[ACM【库函数】速查C++模板](ACM【库函数】速查C++模板.md)
// 类型定义
// ------------------------
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;

// ------------------------
// 宏定义
// ------------------------
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define RESET(a,b) memset(a,b,sizeof(a))

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

// ------------------------
// 常量
// ------------------------
const int INF = 1e9;
const ll LINF = 1e18;
const double PI = acos(-1.0);
const int MOD = 1e9+7;
const int MAXN = 1e6+5;  // 可根据题目修改

// ------------------------
// 快速幂 / 模运算
// ------------------------
ll qpow(ll a, ll b, ll mod=MOD){
    ll res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

// ------------------------
// gcd / lcm
// ------------------------
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

// ------------------------
// 组合数预处理 (阶乘 + 逆元)
// ------------------------
ll fac[MAXN],inv[MAXN];
void initComb(int n, ll mod=MOD){
    fac[0]=1;
    FOR(i,1,n) fac[i]=fac[i-1]*i%mod;
    inv[n]=qpow(fac[n],mod-2,mod);
    FORD(i,n-1,0) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int k,ll mod=MOD){
    if(k<0||k>n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}

// ------------------------
// 并查集
// ------------------------
struct DSU{
    vi parent,rank;
    DSU(int n){ parent.resize(n); rank.resize(n,0); iota(ALL(parent),0);}
    int find(int x){ return parent[x]==x?x:parent[x]=find(parent[x]); }
    void unite(int x,int y){
        x=find(x); y=find(y);
        if(x==y) return;
        if(rank[x]<rank[y]) parent[x]=y;
        else { parent[y]=x; if(rank[x]==rank[y]) rank[x]++; }
    }
    bool same(int x,int y){ return find(x)==find(y); }
};

// ------------------------
// 快速输入输出
// ------------------------
inline int readInt(){
    int x=0; char c=getchar(); bool f=false;
    while(!isdigit(c)){ if(c=='-') f=true; c=getchar();}
    while(isdigit(c)){ x=x*10+c-'0'; c=getchar();}
    return f?-x:x;
}
inline ll readLL(){
    ll x=0; char c=getchar(); bool f=false;
    while(!isdigit(c)){ if(c=='-') f=true; c=getchar();}
    while(isdigit(c)){ x=x*10+c-'0'; c=getchar();}
    return f?-x:x;
}

// ------------------------
// 图相关
// ------------------------
struct Graph{
    int n;
    vector<vi> adj;
    Graph(int _n){ n=_n; adj.resize(n);}
    void addEdge(int u,int v,bool directed=false){
        adj[u].PB(v);
        if(!directed) adj[v].PB(u);
    }

    // DFS
    vector<bool> visited;
    void dfs(int u){
        visited[u]=true;
        for(auto v:adj[u]) if(!visited[v]) dfs(v);
    }

    // BFS
    vector<int> bfs(int start){
        vector<int> dist(n,-1);
        queue<int> q;
        dist[start]=0; q.push(start);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:adj[u]) if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
        return dist;
    }

    // Dijkstra
    vector<ll> dijkstra(int s, vector<vector<pll>>& w){
        vector<ll> dist(n,LINF);
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        dist[s]=0; pq.push({0,s});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            if(d>dist[u]) continue;
            for(auto [v,c]:w[u]){
                if(dist[v]>dist[u]+c){
                    dist[v]=dist[u]+c;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};

// ------------------------
// 树状数组 (Fenwick Tree)
// ------------------------
struct BIT{
    vi bit; int n;
    BIT(int _n){ n=_n; bit.assign(n+1,0);}
    void update(int i,int x){ for(;i<=n;i+=i&-i) bit[i]+=x; }
    int query(int i){ int res=0; for(;i>0;i-=i&-i) res+=bit[i]; return res;}
    int query(int l,int r){ return query(r)-query(l-1);}
};

// ------------------------
// 线段树
// ------------------------
struct SegmentTree{
    int n;
    vl tree;
    SegmentTree(int _n){ n=_n; tree.assign(4*n,0);}
    void build(vl &a,int v,int tl,int tr){
        if(tl==tr) tree[v]=a[tl];
        else{
            int tm=(tl+tr)/2;
            build(a,v*2,tl,tm);
            build(a,v*2+1,tm+1,tr);
            tree[v]=tree[v*2]+tree[v*2+1];
        }
    }
    void update(int v,int tl,int tr,int pos,ll val){
        if(tl==tr) tree[v]=val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm) update(v*2,tl,tm,pos,val);
            else update(v*2+1,tm+1,tr,pos,val);
            tree[v]=tree[v*2]+tree[v*2+1];
        }
    }
    ll query(int v,int tl,int tr,int l,int r){
        if(l>r) return 0;
        if(l==tl && r==tr) return tree[v];
        int tm=(tl+tr)/2;
        return query(v*2,tl,tm,l,min(r,tm)) + query(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
};

// ------------------------
// 主函数
// ------------------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int t=1;
    cin >> t;
    while(t--){
        // ------------------------
        // 写每组测试用例逻辑
        // ------------------------
        int n;
        cin >> n;
        vi a(n);
        REP(i,n) cin >> a[i];
        sort(ALL(a));
        REP(i,n) cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}
```