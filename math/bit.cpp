#include "../t_head.h"
inline ll low_bit(ll x) { return x & -x; }
inline ll bitcnt(ll x) { return __builtin_popcountll(x); }   // bit 1 cnt
inline ll lsb(ll x) { return __builtin_ctzll(x); }           // 后导 0 cnt
inline ll msb(ll x) { return __builtin_clzll(x); }           // 前导 0 cnt
inline ll lg2(ll x) { return sizeof(ll) * 8 - 1 - msb(x); }  // floor_lg2
inline ll clg2(ll x) { return sizeof(ll) * 8 - msb(x - 1); } // ceil_lg2
inline bool is_pw2(ll x) { return x && !(x & (x - 1)); }
inline void erase_lsb(ll &x) { x &= x - 1; }

// 枚举全集的所有子集（含空集）
inline void enum_subsets(ll mask, ll base, auto &&f) {
  for (ll sub = mask; sub; sub = (sub - 1) & mask) {
    f(base | sub);
  }
}

// 枚举大小恰好为 k 的子集（Gosper's Hack）
inline ll next_same_popcount(ll x) {
  ll c = x & -x, r = x + c;
  return (((r ^ x) >> 2) / c) | r;
}

// 提取第 k 个（0-indexed）置 1 位的位置
inline ll kth_set_bit(ll x, int k) {
  for (int i = 0; i < k; i++)
    x &= x - 1;
  return __builtin_ctzll(x);
}

// 将 x 的第 k 位置 1 / 清 0 / 翻转 / 查询
inline void set_bit(ll &x, int k) { x |= (1LL << k); }
inline void clr_bit(ll &x, int k) { x &= ~(1LL << k); }
inline void flip_bit(ll &x, int k) { x ^= (1LL << k); }
inline bool get_bit(ll x, int k) { return (x >> k) & 1; }

// 最低连续 0 段长度（从 LSB 起）：即 ctz，已有 lsb()，补最高连续 0 段
inline ll leading_zeros(ll x) { return msb(x); } // alias，语义更清晰

// 将最低的连续 1 段全部清 0，例如 0b10111 -> 0b10000
inline void clr_trailing_ones(ll &x) { x = (x + 1) & x; }

// 将最低的连续 0 段（非 LSB 处）全部置 1，例如 0b10100 -> 0b10111
inline void set_trailing_zeros_above_lsb(ll &x) { x = (x - 1) | x; }

// 判断 x 中 [l, r] 位是否全为 1（0-indexed，闭区间）
inline bool all_ones(ll x, int l, int r) {
  ll mask = ((1LL << (r - l + 1)) - 1) << l;
  return (x & mask) == mask;
}

// 取 x 的 [l, r] 位段（0-indexed，闭区间）
inline ll bit_range(ll x, int l, int r) {
  return (x >> l) & ((1LL << (r - l + 1)) - 1);
}
