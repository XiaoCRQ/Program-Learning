#include "../t_head.h"
const ll N = 2e5 + 5;
const ll logN = 20; // 10^k 约为 2^(3.32k) + 0次幂层
ll st[N][logN];
ll lg[N];
ll st_size;
inline ll query(const ll l, const ll r) {
  ll m = lg[r - l + 1];
  return max(st[l][m], st[r - (1LL << m) + 1][m]);
}
void init(const vector<ll> &a) {
  st_size = a.size();
  for (ll i = 0; i < st_size; i++)
    st[i][0] = a[i];
  for (ll i = 2; i <= st_size; i++)
    lg[i] = lg[i / 2] + 1;
  for (ll j = 1; j < logN; j++)
    for (ll i = 0; i + (1LL << j) <= st_size; i++)
      st[i][j] = max(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
}
