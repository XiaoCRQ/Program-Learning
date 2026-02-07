#include "inv.cpp"
// 对于组合数的模板计算
// c(n,k)
// == c(n,k-1)*(n-k+1)/k
// == c(n,k-1)*(n-k+1)/inv(k)mod

ll FT[N], CC[N]; // 阶乘数组
ll C(ll n, ll k) { return FT[n] * inv(FT[k]) % MOD * inv(FT[n - k]) % MOD; }
void init_FT() {
  FT[0] = 1;
  REP(i, N - 1) FT[i + 1] = FT[i] * (i + 1) % MOD;
}
void init_CC(ll n) {
  init_inv(n);
  CC[0] = 1;
  REP(i, n)
  CC[i + 1] = CC[i] * (n - i) % MOD * INV[i + 1] % MOD;
}
