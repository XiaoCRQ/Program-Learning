#include "../t_head.h"
struct trie {
  vector<array<ll, 26>> t;
  vector<bool> exist;
  trie() { exist.assign(1, false), t.assign(1, {}); }
  void insert(string &s) {
    ll cur = 0;
    for (auto &ch : s) {
      ll c = ch - 'a';
      if (!t[cur][c]) {
        t[cur][c] = t.size();
        exist.emplace_back(false);
        t.emplace_back();
      }
      cur = t[cur][c];
    }
    exist[cur] = true;
  }
  bool find(string &s) {
    ll cur = 0;
    for (auto &ch : s) {
      ll c = ch - 'a';
      if (!t[cur][c])
        return false;
      cur = t[cur][c];
    }
    return exist[cur];
  }
};
