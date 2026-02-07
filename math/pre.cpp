#include "../t_head.h"
// ===================== 一维前缀和 ===================== //
// partial_sum(a.begin(),a.end(),b.begin());
// get ==  b[r] - (l > 0 ? b[l - 1] : 0)
// O(1) 查询区间和 [l, r] ( 0 - size-1 )

// ===================== 二维前缀和 ===================== //
vvl prefix_sum(vvl &a) {
  int n = a.size();
  int m = a[0].size();
  vvl b(n + 1, vl(m + 1, 0)); // b[0][*] b[*][0] 自动 0
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      b[i][j] = a[i - 1][j - 1] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
  return b;
}

// 查询二维区间 [x1,y1]~[x2,y2]，0-indexed
ll range_sum(vvl &b, int x1, int y1, int x2, int y2) {
  x1++, y1++, x2++, y2++;
  return b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
}

// ===================== 三维前缀和 ===================== //
vvvl prefix_sum(vvvl &a) {
  int n = a.size();
  int m = a[0].size();
  int p = a[0][0].size();
  vvvl b(n + 1, vvl(m + 1, vl(p + 1, 0))); // b[0][*][*] 自动 0
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      for (ll k = 1; k <= p; k++)
        b[i][j][k] = a[i - 1][j - 1][k - 1] + b[i - 1][j][k] + b[i][j - 1][k] +
                     b[i][j][k - 1] - b[i - 1][j - 1][k] - b[i - 1][j][k - 1] -
                     b[i][j - 1][k - 1] + b[i - 1][j - 1][k - 1];
  return b;
}

// 查询三维区间 [x1,y1,z1] ~ [x2,y2,z2]，0-indexed
ll range_sum(vvvl &b, int x1, int y1, int z1, int x2, int y2, int z2) {
  x1++, y1++, z1++, x2++, y2++, z2++;
  return b[x2][y2][z2] - b[x1 - 1][y2][z2] - b[x2][y1 - 1][z2] -
         b[x2][y2][z1 - 1] + b[x1 - 1][y1 - 1][z2] + b[x1 - 1][y2][z1 - 1] +
         b[x2][y1 - 1][z1 - 1] - b[x1 - 1][y1 - 1][z1 - 1];
}
