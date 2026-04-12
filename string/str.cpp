#include "../t_head.h"
#include <functional>
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

vl string_prefix(const string &s) {
  ll n = s.size();
  vl res(n);
  for (ll i = 1, j = 0; i < n; j = res[++i - 1]) {
    while (j > 0 && s[i] != s[j])
      j = res[j - 1];
    res[i] = j + (s[i] == s[j]);
  }
  return res;
}

vl kmp(const string &text, const string &s) {
  vl res = string_prefix(s + "#" + text);
  return {res.begin() + s.size() + 1, res.end()};
}

vl exkmp(const string &s) {
  ll n = s.size();
  vl z(n);
  for (ll i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r && z[i - l] < r - i + 1)
      z[i] = z[i - 1];
    else {
      z[i] = max(0LL, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
    }
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

void sc(const string &text, const string &str) {
  { // boyer_moore_searcher O(n/m) 最坏O(nm)
    auto it = search(text.begin(), text.end(),
                     boyer_moore_searcher(str.begin(), str.end()));
    if (it != text.end())
      cout << distance(text.begin(), it);
  }
  { // boyer_moore_horspool_searcher O(n/m) 最坏O(nm) 内存更少
    auto it = search(text.begin(), text.end(),
                     boyer_moore_horspool_searcher(str.begin(), str.end()));
    if (it != text.end())
      cout << distance(text.begin(), it);
  }
}
