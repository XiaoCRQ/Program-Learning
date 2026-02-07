#include "../t_head.h"
inline ll low_bit(ll x) { return x & -x; }
inline ll bitcnt(ll x) { return __builtin_popcountll(x); }  // bit 1 cnt
inline ll lsb(ll x) { return __builtin_ctzll(x); }          // 后导 0 cnt
inline ll msb(ll x) { return __builtin_clzll(x); }          // 前导 0 cnt
inline ll lg2(ll x) { return sizeof(ll) * 8 - 1 - msb(x); } // floor_lg2
inline bool is_pw2(ll x) { return x && !(x & (x - 1)); }
inline void erase_lb(ll &x) { x &= x - 1; }
