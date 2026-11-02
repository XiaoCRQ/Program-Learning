#include "creat.cpp"
vector<ll> pa, dp;
G g;
ll d;

void dfs(ll u) {
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (g.to[i] != pa[u]) {
      pa[g.to[i]] = u, dfs(g.to[i]);
      d = max(d, dp[u] + dp[g.to[i]] + 1);
      dp[u] = max(dp[u], dp[g.to[i]] + 1);
    }
}

void tree_dia() {
  ll n = g.head.size();
  pa.assign(n, -1);
  dp.assign(n, 0);
  dfs(1);
  cout << d;
}
