#include "../t_head.h"
// ===================== 一维差分 ===================== //
// adjacent_difference(a.begin(),a.end(),b.begin());

// ===================== 二维差分 ===================== //
vvl diff2(vvl &a) {
  int n = a.size();
  int m = a[0].size();
  vvl d(n + 2, vl(m + 2, 0)); // 多开 1 维，边界安全
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      d[i][j] =
          a[i - 1][j - 1] - a[i - 1][j - 2] - a[i - 2][j - 1] + a[i - 2][j - 2];
  return d;
}

// 矩形区间加 [x1,y1]~[x2,y2] += val, 0-indexed
void add_rect(vvl &d, int x1, int y1, int x2, int y2, ll val) {
  x1++, y1++, x2++, y2++;
  d[x1][y1] += val;
  d[x2 + 1][y1] -= val;
  d[x1][y2 + 1] -= val;
  d[x2 + 1][y2 + 1] += val;
}

// ===================== 三维差分 ===================== //
vvvl diff3(vvvl &a) {
  int n = a.size();
  int m = a[0].size();
  int p = a[0][0].size();
  vvvl d(n + 2, vvl(m + 2, vl(p + 2, 0))); // 多开 1 维，边界安全
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      for (ll k = 1; k <= p; k++)
        d[i][j][k] =
            a[i - 1][j - 1][k - 1] - (i - 2 >= 0 ? a[i - 2][j - 1][k - 1] : 0) -
            (j - 2 >= 0 ? a[i - 1][j - 2][k - 1] : 0) -
            (k - 2 >= 0 ? a[i - 1][j - 1][k - 2] : 0) +
            (i - 2 >= 0 && j - 2 >= 0 ? a[i - 2][j - 2][k - 1] : 0) +
            (i - 2 >= 0 && k - 2 >= 0 ? a[i - 2][j - 1][k - 2] : 0) +
            (j - 2 >= 0 && k - 2 >= 0 ? a[i - 1][j - 2][k - 2] : 0) -
            (i - 2 >= 0 && j - 2 >= 0 && k - 2 >= 0 ? a[i - 2][j - 2][k - 2]
                                                    : 0);
  return d;
}

// 立方体区间加 [x1,y1,z1]~[x2,y2,z2] += val, 0-indexed
void add_cube(vvvl &d, int x1, int y1, int z1, int x2, int y2, int z2, ll val) {
  x1++, y1++, z1++, x2++, y2++, z2++;
  d[x1][y1][z1] += val;
  d[x2 + 1][y1][z1] -= val;
  d[x1][y2 + 1][z1] -= val;
  d[x1][y1][z2 + 1] -= val;
  d[x2 + 1][y2 + 1][z1] += val;
  d[x2 + 1][y1][z2 + 1] += val;
  d[x1][y2 + 1][z2 + 1] += val;
  d[x2 + 1][y2 + 1][z2 + 1] -= val;
}

// 恢复三维矩阵
vvvl recover3(vvvl &d) {
  int n = d.size() - 1, m = d[0].size() - 1, p = d[0][0].size() - 1;
  vvvl a(n, vvl(m, vl(p, 0)));
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      for (ll k = 1; k <= p; k++)
        a[i - 1][j - 1][k - 1] =
            d[i][j][k] + (i - 2 >= 0 ? a[i - 2][j - 1][k - 1] : 0) +
            (j - 2 >= 0 ? a[i - 1][j - 2][k - 1] : 0) +
            (k - 2 >= 0 ? a[i - 1][j - 1][k - 2] : 0) -
            (i - 2 >= 0 && j - 2 >= 0 ? a[i - 2][j - 2][k - 1] : 0) -
            (i - 2 >= 0 && k - 2 >= 0 ? a[i - 2][j - 1][k - 2] : 0) -
            (j - 2 >= 0 && k - 2 >= 0 ? a[i - 1][j - 2][k - 2] : 0) +
            (i - 2 >= 0 && j - 2 >= 0 && k - 2 >= 0 ? a[i - 2][j - 2][k - 2]
                                                    : 0);
  return a;
}
