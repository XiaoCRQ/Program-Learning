#include "creat.cpp"
const ll N = 2e5;
vector<bool> vis;
G g;

void bfs(ll u) {
  vis.assign(vis.size(), false);
  queue<ll> que;
  que.push(u);
  while (!que.empty()) {
    u = que.front(), que.pop();
    for (ll i = g.head[u]; i != -1; i = g.nxt[i])
      if (!vis[g.to[i]]) {
        vis[g.to[i]] = true;
        que.push(g.to[i]);
      }
  }
}

void dfs(ll u) {
  vis[u] = true;
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (!vis[g.to[i]]) {
      dfs(g.to[i]);
    }
}

void dfs_st(ll u) {
  vis.assign(vis.size(), false);
  stack<ll> sk;
  sk.push(u);
  while (!sk.empty()) {
    u = sk.top(), sk.pop();
    for (ll i = g.head[u]; i != -1; i = g.nxt[i])
      if (!vis[g.to[i]]) {
        vis[u] = true;
        sk.push(g.to[i]);
      }
  }
}

namespace list {
ll n = g.head.size();
vector<ll> list, l(n), r(n);
void dfs_list(ll u) {
  l[u] = list.size(), list.push_back(u), vis[u] = true;
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (!vis[g.to[i]])
      dfs_list(g.to[i]);
  r[u] = list.size() - 1;
}
} // namespace list

namespace changeroot {
ll n = g.head.size();
vector<ll> d1(n + 1), d2(n + 1), dd(n + 1), up(n + 1);
void dfs1(ll u, ll pa) {
  d1[u] = d2[u] = 0, dd[u] = -1;
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (g.to[i] != pa) {
      ll v = g.to[i];
      dfs1(v, u);
      ll d = d1[v] + 1;
      if (d > d1[u]) {
        d2[u] = d1[u];
        d1[u] = d;
        dd[u] = v;
      } else if (d > d2[u])
        d2[u] = d;
    }
}
void dfs2(ll u, ll pa) {
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (g.to[i] != pa) {
      ll v = g.to[i];
      up[v] = max(up[u], dd[u] == v ? d2[u] : d1[u]) + 1;
      dfs2(v, u);
    }
}
} // namespace changeroot
