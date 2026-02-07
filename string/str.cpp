#include "../t_head.h"
vl manachar(const string &str) {
  ll size = str.size() * 2 - 1;
  string ans(size, '#');
  vl d(size, 1);
  REP(i, str.size())
  ans[i * 2 + 1] = str[i];
  ll l = 0, r = -1;
  auto loop = [&](ll x) {
    ll mid = x;
    x = d[x];
    while (mid - x >= 0 && mid + x < size && str[mid + x] == str[mid - x])
      x++;
    return x;
  };
  REP(i, size) {
    if (i < r)
      d[i] = min(r - i, d[l + r - i]);
    d[i] = loop(i);
    l = i - d[i], r = i + d[i];
  }
  return d;
}
