#include "../t_head.h"
vl manacher(const string &str) {
  string t(2 * str.size() + 1, '#');
  for (ll i = 0; i < str.size(); i++)
    t[i * 2 + 1] = str[i];
  ll n = t.size();
  vl d(n, 0);
  ll l = 0, r = -1;
  for (ll i = 0; i < n; i++) {
    if (i <= r)
      d[i] = min(d[l + r - i], r - i);
    while (i - d[i] - 1 >= 0 && i + d[i] + 1 < n &&
           t[i - d[i] - 1] == t[i + d[i] + 1])
      d[i]++;
    if (i + d[i] > r)
      l = i - d[i], r = i + d[i];
  }
  return d;
}
