#include <bits/stdc++.h>

// 高精度
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

// 有理数
#include <boost/rational.hpp>

// 位图
#include <boost/dynamic_bitset.hpp>

// 多维数组
#include <boost/multi_array.hpp>

// 哈希
#include <boost/functional/hash.hpp>

// 字符串算法
#include <boost/algorithm/string.hpp>

// 图论
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

// 堆
#include <boost/heap/fibonacci_heap.hpp>
#include <boost/heap/priority_queue.hpp>

// 双端队列
#include <boost/circular_buffer.hpp>

// 可选值
#include <boost/optional.hpp>

// 双向映射
#include <boost/bimap.hpp>

// 区间
#include <boost/icl/interval_set.hpp>

// 时间
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;

// ---------- multiprecision ----------
using boost::multiprecision::cpp_dec_float_50;
using boost::multiprecision::cpp_int;

// ---------- rational ----------
using boost::rational;

// ---------- graph ----------
using namespace boost;

// 常用图模板
using Graph = adjacency_list<vecS,
                             vecS,
                             directedS,
                             no_property,
                             property<edge_weight_t, int>>;

// ---------- heap ----------
template <class T> using FibHeap = boost::heap::fibonacci_heap<T>;

// ---------- hash pair ----------
struct PairHash {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    size_t seed = 0;
    boost::hash_combine(seed, p.first);
    boost::hash_combine(seed, p.second);
    return seed;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  // ===== cpp_int =====
  cpp_int big = 1;
  for (int i = 1; i <= 100; i++)
    big *= i;
  cout << big << '\n';

  // ===== 高精度浮点 =====
  cpp_dec_float_50 pi = acos(cpp_dec_float_50(-1));
  cout << fixed << setprecision(40) << pi << '\n';

  // ===== rational =====
  rational<int> a(1, 3), b(1, 6);
  auto c = a + b;
  cout << c.numerator() << '/' << c.denominator() << '\n';

  // ===== dynamic_bitset =====
  boost::dynamic_bitset<> bs(10);
  bs[3] = 1;
  bs[5] = 1;
  cout << bs << '\n';

  // ===== multi_array =====
  boost::multi_array<int, 2> arr(boost::extents[3][4]);
  arr[1][2] = 114;

  // ===== string algorithm =====
  string s = "a,b,c";
  vector<string> v;
  boost::split(v, s, boost::is_any_of(","));

  // ===== fibonacci heap =====
  FibHeap<int> heap;
  heap.push(3);
  heap.push(1);
  heap.push(2);
  cout << heap.top() << '\n';

  // ===== circular buffer =====
  boost::circular_buffer<int> cb(3);
  cb.push_back(1);
  cb.push_back(2);
  cb.push_back(3);
  cb.push_back(4);

  // ===== optional =====
  boost::optional<int> opt;
  opt = 114;

  // ===== bimap =====
  boost::bimap<int, string> bm;
  bm.insert({1, "one"});

  // ===== interval set =====
  boost::icl::interval_set<int> st;
  st.add(boost::icl::interval<int>::closed(1, 5));

  // ===== 时间 =====
  using namespace boost::posix_time;
  ptime now = second_clock::local_time();
  cout << to_simple_string(now) << '\n';

  return 0;
}
