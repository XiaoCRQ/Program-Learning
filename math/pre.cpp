#include "../t_head.h"
// ===================== 一维前缀和 ===================== //
// partial_sum(a.begin(),a.end(),b.begin());
// get ==  b[r] - (l > 0 ? b[l - 1] : 0)
// O(1) 查询区间和 [l, r] ( 0 - size-1 )

// ===================== 二维前缀和 ===================== //
vector<vector<ll>> prefix_sum(vector<vector<ll>> &a) {
  ll n = a.size();
  ll m = a[0].size();
  vector<vector<ll>> b(n + 1, vector<ll>(m + 1, 0)); // b[0][*] b[*][0] 自动 0
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      b[i][j] = a[i - 1][j - 1] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
  return b;
}

// 查询二维区间 [x1,y1]~[x2,y2]，0-indexed
ll range_sum(vector<vector<ll>> &b, ll x1, ll y1, ll x2, ll y2) {
  x1++, y1++, x2++, y2++;
  return b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
}

// ===================== 三维前缀和 ===================== //
vector<vector<vector<ll>>> prefix_sum(vector<vector<vector<ll>>> &a) {
  ll n = a.size();
  ll m = a[0].size();
  ll p = a[0][0].size();
  vector<vector<vector<ll>>> b(
      n + 1,
      vector<vector<ll>>(m + 1, vector<ll>(p + 1, 0))); // b[0][*][*] 自动 0
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      for (ll k = 1; k <= p; k++)
        b[i][j][k] = a[i - 1][j - 1][k - 1] + b[i - 1][j][k] + b[i][j - 1][k] +
                     b[i][j][k - 1] - b[i - 1][j - 1][k] - b[i - 1][j][k - 1] -
                     b[i][j - 1][k - 1] + b[i - 1][j - 1][k - 1];
  return b;
}

// 查询三维区间 [x1,y1,z1] ~ [x2,y2,z2]，0-indexed
ll range_sum(
    vector<vector<vector<ll>>> &b, ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
  x1++, y1++, z1++, x2++, y2++, z2++;
  return b[x2][y2][z2] - b[x1 - 1][y2][z2] - b[x2][y1 - 1][z2] -
         b[x2][y2][z1 - 1] + b[x1 - 1][y1 - 1][z2] + b[x1 - 1][y2][z1 - 1] +
         b[x2][y1 - 1][z1 - 1] - b[x1 - 1][y1 - 1][z1 - 1];
}
