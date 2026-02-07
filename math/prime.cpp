#include "../t_head.h"
const ll N = 31622 + 5; // sqrt(1e9 + 5)
bool is_prime[N];
ll p[N], pcnt;
void init() {
  for (int i = 0; i <= N; ++i)
    is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  pcnt = 0;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      p[pcnt++] = i;
    }
  }
}
