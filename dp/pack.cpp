#include "../t_head.h"

ll pack(ll t, ll n, vl &w, vl &v, vl &k) {
  vl dp(t + 1, 0);

  for (ll i = 0; i < n; i++) {
    // 01 背包
    if (k[i] == 1) {
      for (ll j = t; j >= w[i]; j--)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    // 完全背包
    else if (k[i] == 0) {
      for (ll j = w[i]; j <= t; j++)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    // 多重背包（二进制优化）
    else {
      ll cnt = k[i];
      for (ll c = 1; cnt > 0; c <<= 1) {
        ll use = min(c, cnt);
        cnt -= use;

        ll weight = use * w[i];
        ll value = use * v[i];

        for (ll j = t; j >= weight; j--)
          dp[j] = max(dp[j], dp[j - weight] + value);
      }
    }
  }

  return *max_element(dp.begin(), dp.end());
}
