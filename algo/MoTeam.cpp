#include "../t_head.h"
void normal() { // 经典区间统计
  struct Query {
    ll l, r, idx;
  };
  ll n, q;
  cin >> n >> q;
  vector<Query> query(q);
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  for (ll i = 0; i < q; i++)
    cin >> query[i].l >> query[i].r, query[i].idx = i;
  ll block = max(1LL, (ll)sqrt(n));
  auto cmp = [&](Query &a, Query &b) {
    ll ba = a.l / block, bb = b.l / block;
    if (ba != bb)
      return ba < bb;
    return (ba & 1) ? (a.r > b.r) : (a.r < b.r);
  };
  sort(query.begin(), query.end(), cmp);
  vector<ll> cnt(n + 1, 0), freq(n + 2, 0), ans(q);
  ll cur_max = 0, l = 1, r = 0;
  auto add = [&](ll pos) {
    freq[cnt[a[pos]]]--;
    cnt[a[pos]]++;
    freq[cnt[a[pos]]]++;
    cur_max = max(cur_max, cnt[a[pos]]);
  };
  auto rem = [&](ll pos) {
    freq[cnt[a[pos]]]--;
    if (cnt[a[pos]] == cur_max && freq[cnt[a[pos]]] == 0)
      cur_max--;
    cnt[a[pos]]--;
    freq[cnt[a[pos]]]++;
  };
  for (auto &[ql, qr, idx] : query) {
    while (r < qr)
      add(++r);
    while (l > ql)
      add(--l);
    while (r > qr)
      rem(r--);
    while (l < ql)
      rem(l++);
    ans[idx] = cur_max;
  }

  for (ll i = 0; i < q; i++)
    cout << ans[i] << '\n';
}
