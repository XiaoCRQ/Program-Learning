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
  out(x.first);
  putchar(' ');
  out(x.second);
  putchar(' ');
}
