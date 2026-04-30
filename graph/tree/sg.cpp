#include "creat.cpp"
inline ll mid(ll l, ll r) { return (l + r) >> 1; }
struct sg {
  vector<ll> lazy;
  tree t;
  ll n;

  sg(vector<ll> &val) : n(val.size()) {
    lazy.assign(1, 0);
    build(val, 0, n - 1, t.add());
  }

  void build(vector<ll> &val, ll l, ll r, ll p) {
    if (l == r) {
      t.data[p] = val[l];
      return;
    }
    ll m = mid(l, r);
    build(val, l, m, t.left[p] = t.add());
    build(val, m + 1, r, t.right[p] = t.add());
    t.data[p] = t.ld(p) + t.rd(p);
  }

  void push_down(ll l, ll r, ll p) {
    if (l == r || !lazy[p])
      return;
    ll m = mid(l, r);
    auto up = [&](ll sz, ll sp) {
      t.data[sp] += lazy[p] * sz;
      lazy[sp] += lazy[p];
    };
    up(m - l + 1, t.left[p]);
    up(r - m, t.right[p]);
    lazy[p] = 0;
  }

  void update(ll L, ll R, ll l, ll r, ll c, ll p = 0) {
    if (L <= l && r <= R) {
      t.data[p] += (r - l + 1) * c;
      lazy[p] += c;
      return;
    }
    push_down(l, r, p);
    ll m = mid(l, r);
    if (L <= m)
      update(L, R, l, m, c, t.left[p]);
    if (R > m)
      update(L, R, m + 1, r, c, t.right[p]);
    t.data[p] = t.ld(p) + t.rd(p);
  }

  ll query(ll L, ll R, ll l, ll r, ll p = 0) {
    if (L <= l && r <= R)
      return t.data[p];
    push_down(l, r, p);
    ll m = mid(l, r), res = 0;
    if (L <= m)
      res += query(L, R, l, m, t.left[p]);
    if (R > m)
      res += query(L, R, m + 1, r, t.right[p]);
    return res;
  }
};
