#include "../../t_head.h"
const ll N = 2e5 + 5;
ll n, val[N];
ll sum[N << 2];
ll add[N << 2];
inline ll s_l(ll p) { return p * 2 + 1; }
inline ll s_r(ll p) { return p * 2 + 2; }
inline ll mid(ll l, ll r) { return l + (r - l) / 2; }
inline ll push_down(ll s, ll t, ll p) {
  ll m = mid(s, t);
  auto up = [&](ll idx, ll size) {
    sum[idx] += add[p] * size, add[idx] += add[p];
  };
  auto flag = [&]() -> bool { return add[p]; };
  if (flag() && s != t) {
    up(s_l(p), m - s + 1);
    up(s_r(p), t - m);
    add[p] = 0;
  }
  return m;
}
void update(ll l, ll r, ll c, ll s = 0, ll t = n - 1, ll p = 0) {
  if (l <= s && t <= r) {
    sum[p] += (t - s + 1) * c, add[p] += c;
    return;
  }
  ll m = push_down(s, t, p);
  if (l <= m)
    update(l, r, c, s, m, s_l(p));
  if (r > m)
    update(l, r, c, m + 1, t, s_r(p));
  sum[p] = sum[s_l(p)] + sum[s_r(p)];
}
ll get(ll l, ll r, ll s = 0, ll t = n - 1, ll p = 0) {
  if (l <= s && t <= r)
    return sum[p];
  ll m = push_down(s, t, p), ans = 0;
  ans += l <= m ? get(l, r, s, m, s_l(p)) : 0;
  ans += r > m ? get(l, r, m + 1, t, s_r(p)) : 0;
  return ans;
}
void init(ll s = 0, ll t = n - 1, ll p = 0) {
  add[p] = 0;
  if (s == t)
    sum[p] = val[s];
  else {
    ll m = mid(s, t);
    init(s, m, s_l(p)), init(m + 1, t, s_r(p));
    sum[p] = sum[s_l(p)] + sum[s_r(p)];
  }
}
