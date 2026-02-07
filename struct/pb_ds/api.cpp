#include "pb_ds_head.h"
void set_api() { // map 同理
  pb_set<ll> set;
  ll x = 0, k = 0;
  set.erase(x);         // 删除单个 x
  set.find_by_order(k); // 返回第 k+1 小的迭代器
  set.order_of_key(x);  // 返回严格小于 x 的迭代器
}
void trie_api() {
  pb_trie<string, ll> t_map;
  pb_trie<string> t;
  t.insert("abc");
  t_map.insert({"abs", 0});
  auto range = t_map.prefix_range("a"); // 所有相同前缀的值
  for (auto it = range.first; it != range.second; it++)
    cout << it->first << ' ' << it->second << ' ';
}
void hash_api() {
  pb_hash<ll, ll> map;
  pb_hash<ll> set;
  set.insert(0);
  map[0] = 0;
  EACH(set) cout << it << ' '; // 迭代更快
  EACH(map) cout << it.first << ' ' << it.second << ' ';
}
void heap_api() {
  pb_heap<ll> heap, h1, h2;
  auto it = heap.push(0);
  heap.pop();
  heap.modify(it, 0); // 修改元素值
  h1.join(h2);        // 将 h2 合并到 h1
}
