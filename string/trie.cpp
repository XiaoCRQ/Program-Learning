#include "../t_head.h"
const ll N = 2e5 + 5;
const ll M = 26;
// const ll M = 62; // 包含大小写字母和数字
ll trie[N][M] = {0}, cnt;
bitset<N> exist;
void init() {
  memset(trie, 0, sizeof trie);
  exist.reset();
  cnt = 0;
}
void insert(string &s) {
  ll idx = 0;
  for (auto &it : s) {
    ll c = it - 'a';
    if (!trie[idx][c])
      trie[idx][c] = ++cnt;
    idx = trie[idx][c];
  }
  exist[idx] = true;
}
bool find(string &s) {
  ll idx = 0;
  for (auto &it : s) {
    ll c = it - 'a';
    if (!trie[idx][c])
      return false;
    idx = trie[idx][c];
  }
  return exist[idx];
}
