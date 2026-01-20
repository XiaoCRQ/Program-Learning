#include "t_head.h"
static inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

inline i128 i128_abs(i128 x) { return x < 0 ? -x : x; }

inline ll in() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}

inline void out(ll x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    out(x / 10);
  putchar(x % 10 + '0');
}

inline void out(pl x) {
  out(x.F);
  putchar(' ');
  out(x.S);
  putchar(' ');
}

// ===================== 函数模板 =====================
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// 快速加法防止溢出 (适合模数较大时)
inline ll qadd(ll a, ll b, ll mod = MOD) {
  a %= mod;
  b %= mod;
  ll r = a + b;
  return (r >= mod ? r - mod : r);
}

// 快速乘法防止溢出 (适合 a,b <= 1e18)
inline ll qmul(ll a, ll b, ll mod = MOD) {
  __int128 r = (__int128)a * b;
  return (ll)(r % mod);
}

// 快速幂防止溢出 (适合 a,b <= 1e18)
inline ll qpow(ll a, ll b, ll mod = MOD) {
  ll res = 1;
  a %= mod;
  while (b) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

// 二分查找
template <class F> ll bsearch_first(ll l, ll r, F f) {
  ll L = l, R = r;
  while (L < R) {
    ll m = L + (R - L) / 2;
    if (f(m))
      R = m;
    else
      L = m + 1;
  }
  return L;
}

vl ms(const vl &a) {
  ll size = a.size();
  vl ans(size);
  stack<ll> st;
  REP(i, size) {
    while (!st.empty() && a[i] < a[st.top()])
      ans[st.top()] = i, st.pop();
    st.push(i);
  }
  return ans;
}

void comperss(vl &a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}

// --- 前缀和/差分 ---
// 构建前缀和
template <typename T> vector<T> prefix_sum(const vector<T> &a) {
  ll n = a.size();
  vector<T> p(n + 1);
  FOR(i, 1, n) p[i] = p[i - 1] + a[i - 1];
  return p;
}

// O(1) 查询区间和 [l, r] (0-index)
template <typename T> inline T range_sum(const vector<T> &p, int l, int r) {
  return p[r + 1] - p[l];
}

// --- 快速最小值最大值 ---
template <typename T> inline T max3(T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> inline T min3(T a, T b, T c) { return min(a, min(b, c)); }
