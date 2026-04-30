#include "inv.cpp"
// 对于组合数的模板计算
// c(n,k)
// == c(n,k-1)*(n-k+1)/k
// == c(n,k-1)*(n-k+1)/inv(k)mod

ll FT[N], CC[N]; // 阶乘数组
ll C(ll n, ll k) { return FT[n] * inv(FT[k]) % MOD * inv(FT[n - k]) % MOD; }
void init_FT() {
  FT[0] = 1;
  for (ll i = 0; i < N - 1; i++)
    FT[i + 1] = FT[i] * (i + 1) % MOD;
}
void init_CC(ll n) {
  init_inv(n);
  CC[0] = 1;
  for (ll i = 0; i < n; i++)
    CC[i + 1] = CC[i] * (n - i) % MOD * INV[i + 1] % MOD;
}

// 多重集全排列
ll ccc(vector<ll> a, ll mod) {
  ll res, n = 0;
  for (auto &it : a)
    n += it;
  vector<ll> fact(n + 1, 1);
  for (ll i = 1; i <= N; i++)
    fact[i] = fact[i - 1] * i % mod;
  res = fact[n];
  for (auto &it : a)
    res *= inv_exgcd(fact[it], mod), res %= mod;
  return res;
}
