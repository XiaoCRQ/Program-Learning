#include "inv.cpp"
// ===== 组合数模板 =====
// c(n,k)
// == c(n,k-1)*(n-k+1)/k
// == c(n,k-1)*(n-k+1)/inv(k)mod
// 使用前提：MOD 为质数
// 使用前调用 comb_init()，之后 O(1) 查询 C(n,k)

const ll COMB_N = 1e6 + 5;
ll fac[COMB_N], inv_fac[COMB_N];

void comb_init(ll n = COMB_N - 1) {
  fac[0] = 1;
  for (ll i = 1; i <= n; i++)
    fac[i] = fac[i - 1] * i % MOD;
  inv_fac[n] = inv(fac[n]); // 费马小定理，一次
  for (ll i = n - 1; i >= 0; i--)
    inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
}

// C(n, k)：从 n 个中选 k 个，O(1)
// 越界自动返回 0
inline ll C(ll n, ll k) {
  if (k < 0 || k > n || n < 0)
    return 0;
  return fac[n] % MOD * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

// 固定 n，批量得到 C(n,0), C(n,1), ..., C(n,n)
// 存入 row[]，长度 n+1
// 用途：需要某一行所有组合数时比逐个调用 C() 更快（避免重复乘法）
void comb_row(ll n, vector<ll> &row) {
  row.resize(n + 1);
  row[0] = 1;
  for (ll i = 0; i < n; i++)
    row[i + 1] = row[i] % MOD * ((n - i) % MOD) % MOD * inv_fac[i + 1] % MOD *
                 fac[i] % MOD;
  // 等价：row[i+1] = row[i] * (n-i) % MOD * inv(i+1) % MOD
  // 此处复用 inv_fac[i+1]*fac[i] = inv(i+1)，避免额外求逆
}

// 多重集全排列：(a[0]+a[1]+...+a[m-1])! / (a[0]! * a[1]! * ... * a[m-1]!)
// mod 可为非质数（使用 exgcd 求逆）
// 注意：仅当所有 a[i]! 与 mod 互质时结果有意义
ll multiset_perm(vector<ll> a, ll mod) {
  ll n = 0;
  for (auto x : a)
    n += x;
  vector<ll> f(n + 1);
  f[0] = 1;
  for (ll i = 1; i <= n; i++)
    f[i] = f[i - 1] * i % mod;
  ll res = f[n];
  for (auto x : a)
    res = res % mod * inv_exgcd(f[x], mod) % mod;
  return res;
}

// Lucas 定理：n, k 很大，mod 为小质数 p 时使用
// 使用前需以 p 为模数重新调用 comb_init()
// 递归深度 O(log_p(n))
ll lucas(ll n, ll k, ll mod) {
  return k == 0 ? 1 : C(n % mod, k % mod) * lucas(n / mod, k / mod, mod) % mod;
}

// 预处理杨辉三角，pa[n][k] = C(n,k) % mod —— C(n,k) = C(n-1,k-1)+C(n-1,k)
// 适用：mod 任意（包括非质数），n <= PASCAL_N
// 限制：空间 O(n^2)，n 不能太大（建议 <= 5000）

const ll PASCAL_N = 5005;
ll pa[PASCAL_N][PASCAL_N];

void pascal_init(ll n, ll mod) {
  for (ll i = 0; i <= n; i++) {
    pa[i][0] = 1 % mod; // mod=1 时特判
    for (ll j = 1; j <= i; j++)
      pa[i][j] = (pa[i - 1][j - 1] + pa[i - 1][j]) % mod;
  }
}

inline ll C_pascal(ll n, ll k) {
  if (k < 0 || k > n)
    return 0;
  return pa[n][k];
}

// 返回第 n 行：C(n,0), C(n,1), ..., C(n,n)
vector<ll> pascal_row(ll n, ll mod) {
  vector<ll> cur(n + 1, 0);
  cur[0] = 1 % mod;
  for (ll i = 1; i <= n; i++)
    for (ll j = i; j >= 1; j--) // 从右向左，原地滚动
      cur[j] = (cur[j] + cur[j - 1]) % mod;
  return cur;
}
