#include "../t_head.h"

struct dsu {
  vector<ll> pa, sz;
  void init(ll n) {
    pa.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(pa.begin(), pa.end(), 0);
  }
  ll find(ll u) { return pa[u] == u ? u : pa[u] = find(pa[u]); }
  void unite(ll u, ll v) {
    u = find(u), v = find(v);
    if (u != v) {
      if (sz[u] < sz[v])
        swap(u, v);
      pa[v] = u, sz[u] += sz[v];
    }
  }
};

struct dsu2 {
  queue<ll> recycle;
  vector<ll> pa, sz, sn;
  ll idx;
  void init(ll n) {
    recycle = {};
    sn.assign(n + 1, -1);
    pa.clear();
    sz.clear();
    idx = 0;
  }
  ll findv(ll u) { return pa[u] == u ? u : pa[u] = findv(pa[u]); }
  ll find(ll u) { return sn[u] == -1 ? -1 : findv(sn[u]); }
  void unite(ll u, ll v) {
    if (sn[u] != -1 && sn[v] != -1) {
      ll vu = find(u);
      ll vv = find(v);
      if (sz[vu] < sz[vv])
        swap(vu, vv);
      pa[vv] = vu;
      sz[vu] += sz[vv];
    } else if (sn[u] == -1 && sn[v] == -1) {
      pa.push_back(idx), sz.push_back(2);
      sn[u] = sn[v] = idx++;
    } else {
      ll t = sn[u] == -1 ? find(v) : find(u);
      sn[v] = sn[u] = t, sz[t]++;
    }
  }
  void erase(ll u) {
    if (sn[u] != -1)
      --sz[find(u)], sn[u] = -1;
  }
};
