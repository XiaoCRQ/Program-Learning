#include "../../t_head.h"
#define REPGG(u, head, nxt) for (ll i = head[u]; i != -1; i = nxt[i])
#define REPG(u) REPGG(u, head, nxt)
const ll NODE = 2e5 + 5; // 数据范围
const ll EDGE = 5e5;     // 无向图存储2倍的边
bitset<NODE> vis;
ll w[NODE], e[EDGE];
ll pa[NODE], h[NODE];
ll head[NODE], to[EDGE], nxt[EDGE];
ll idx, root;
void init() {
  memset(head, -1, sizeof head);
  memset(pa, -1, sizeof pa);
  memset(h, 0, sizeof h);
  vis.reset();
  idx = 0, root = 1;
}
inline void add(ll u, ll v) {
  to[idx] = v, nxt[idx] = head[u], head[u] = idx++;
}
inline void add_pot(ll u, ll v, ll val) { w[u] = val, add(u, v); }
inline void add_edge(ll u, ll v, ll val) { e[idx] = val, add(u, v); }
