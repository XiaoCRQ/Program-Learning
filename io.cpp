#include "t_head.h"
static inline void fast_io() { cin.tie(0)->sync_with_stdio(0); }

inline __int128_t i128_abs(__int128_t x) { return x < 0 ? -x : x; }

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

inline void out(pair<ll, ll> x) {
  out(x.first);
  putchar(' ');
  out(x.second);
  putchar(' ');
}

void io() {
  cout << oct << 255;       // 8进制
  cout << dec << 255;       // 10进制
  cout << hex << 255;       // 16进制
  cout << showbase << 255;  // 显示进制前缀
  cout << uppercase << 255; // 大写16进制 | 大写科学记数法E
  cout << showpos << 255;   // 正数显示

  cout << boolalpha << 0;   // true/false 替换 1/0
  cout << noboolalpha << 0; // 恢复 1/0

  cout << fixed << setprecision(10) << 0.00; // 固定小数位
  cout << scientific << 0.00;                // 科学计数法
  cout << showpoint << 0.00;                 // 总是显示小数点
  //...
}
