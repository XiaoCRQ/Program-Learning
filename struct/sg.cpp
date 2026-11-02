#include "../t_head.h"
inline ll mid(ll l, ll r) { return (l + r) >> 1; }
inline ll ls(ll p) { return p << 1; }
inline ll rs(ll p) { return p << 1; }
struct sg {
  vector<ll> val;
  ll size;

  sg(vector<ll> &a) : size(a.size()), val(a) { build(a, 0, size - 1, 0); }

  void build(vector<ll> &a, ll l, ll r, ll p) {
    if (l == r) {
      val[p] = a[l];
      return;
    }
    ll m = mid(l, r);
    build(a, l, m, )
  }
};
