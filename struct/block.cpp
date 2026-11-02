#include "../t_head.h"

struct block { // 分块算法 [0, n-1]
  vector<ll> val, st, ed, bl, sz;
  ll n, bk;
  block(vector<ll> &v) : val(v), n(v.size()) {
    bk = max(1ll, (ll)sqrt((double)n));
    st.resize(bk);
    ed.resize(bk);
    sz.resize(bk);
    bl.resize(n);
    for (ll i = 0; i < bk; i++)
      st[i] = n / bk * i, ed[i] = n / bk * (i + 1) - 1;
    ed[bk - 1] = n - 1;
    for (ll i = 0; i < bk; i++) {
      for (ll j = st[i]; j <= ed[i]; j++)
        bl[j] = i;
      sz[i] = ed[i] - st[i] + 1;
    }
  }
};
