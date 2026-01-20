#include "t_head.h"
#include <bitset>
const ll M = 2e5;
const ll N = 5e5;
// ll w[M];  // 带权
bitset<M> vis;
ll parent[M];
ll head[M]; // 每个点的第一条边的下标
ll to[N];   // 第 i 条边指向的点
ll nxt[N];  // 下一条边的下标
ll idx = 0; // 当前边编号
void def_g() {
  RESET(parent, -1);
  RESET(head, -1);
  vis.reset();
  idx = 0;
}

inline void add(ll u, ll v, ll n = 0) { // 头插链表法
  // w[idx] = n; // 带权
  to[idx] = v;
  nxt[idx] = head[u];
  head[u] = idx++;
}

void bfs(ll u) {
  vis.reset();
  queue<ll> que;
  que.push(u);
  vis[u] = true;
  while (!que.empty()) {
    u = que.front(), que.pop();
    for (ll i = head[u]; i != -1; i = nxt[i])
      if (vis[to[i]] == false)
        parent[to[i]] = u, vis[to[i]] = true, que.push(to[i]);
  }
}

void dfs(ll u) { // 递归版本 —— 易爆栈
  vis[u] = true;
  for (ll i = head[u]; i != -1; i = nxt[i])
    if (vis[to[i]] == false)
      parent[to[i]] = u, vis[to[i]] = true, dfs(to[i]);
}

void dfs_st(ll u) { // 栈版本 —— 经典
  vis.reset();
  stack<ll> st;
  st.push(u);
  vis[u] = true;
  while (!st.empty()) {
    u = st.top(), st.pop();
    for (ll i = head[u]; i != -1; i = nxt[i])
      if (vis[to[i]] == false)
        parent[to[i]] = u, vis[to[i]] = true, st.push(to[i]);
  }
}

// vl dfs(ll start, bool over(ll &)) { // 显式栈 —— 回溯路径版本
//   vis.reset();
//   vl path[2] = {{start}, {head[start]}};
//   bool flag = true;
//   while (!path[0].empty()) {
//     flag = true;
//     ll i = path->size() - 1;
//     vis[path[0][i]] = true;
//     while (path[1][i] != -1) {
//       if (vis[to[path[1][i]]] == false) {
//         path[0].push_back(to[path[1][i]]);
//         path[1].push_back(head[to[path[1][i]]]);
//         // path[1][i] = nxt[path[1][i]];
//         // 特殊情况不可省
//         flag = false;
//         break;
//       }
//       path[1][i] = nxt[path[1][i]];
//     }
//     if (flag)
//       path[0].pop_back(), path[1].pop_back();
//   }
//   return path[0];
// }
