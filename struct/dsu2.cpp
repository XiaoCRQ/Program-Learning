#include "../t_head.h"
const ll N = 2e5 + 5;
queue<ll> recycled;
vl pa, sz, sn;
ll idx;
void init(ll n) {
  while (!recycled.empty())
    recycled.pop();
  sn.assign(n + 1, -1);
  pa.clear();
  sz.clear();
  idx = 0;
}
ll findv(ll x) { return pa[x] == x ? x : pa[x] = findv(pa[x]); }
ll find(ll x) { return sn[x] == -1 ? -1 : findv(sn[x]); }
void unite(ll x, ll y) {
  if (sn[x] == -1 && sn[y] == -1) {
    if (!recycled.empty())
      sn[x] = sn[y] = recycled.front(), recycled.pop();
    else {
      pa.push_back(idx);
      sz.push_back(2);
      sn[x] = sn[y] = idx++;
    }
  } else if (sn[x] != -1 && sn[y] == -1)
    sn[y] = sn[x], sz[sn[y]]++;
  else if (sn[x] == -1 && sn[y] != -1)
    sn[x] = sn[y], sz[sn[x]]++;
  else {
    ll vx = find(x);
    ll vy = find(y);
    if (sz[vx] < sz[vy])
      swap(vx, vy);
    pa[vy] = vx;
    sz[vx] += sz[vy];
  }
}
void erase(ll x) {
  if (sn[x] == -1)
    return;
  if (--sz[sn[x]] == 0)
    recycled.push(sn[x]);
  sn[x] = -1;
}
