```C++
/*====================================================================
  C++ STL 竞赛速查模板（按头文件分类）
  包含常用函数/容器的典型用法与注释
====================================================================*/

/* ------------------ 基本容器/算法相关头文件 ------------------ */
#include <bits/stdc++.h>
// 该头文件包含几乎所有常用头文件
// 可以省去包含其他文件的功夫
using namespace std;

/* ==================== <vector> ==================== */
// 动态数组，竞赛中最常用容器
vector<int> v;                           // 默认空
v.push_back(x);                          // 末尾插入
v.emplace_back(x);                       // 末尾原地构造
v.pop_back();                            // 弹出末尾
int n = v.size();                        // 大小
bool emp = v.empty();                    // 是否为空
v.reserve(100);                          // 预分配容量
v.resize(m);                             // 改变大小（会构造或删元素）
v.clear();                               // 删除全部元素（capacity不变）
v.shrink_to_fit();                       // 试图释放多余内存
v.insert(v.begin()+i, x);                // 在位置插入（线性）
v.erase(v.begin()+i);                    // 擦除位置（线性）
v.erase(unique(v.begin(), v.end()), v.end()); // 去重（先 sort）
sort(v.begin(), v.end());                // 排序
nth_element(v.begin(), v.begin()+k, v.end()); // 第 k 小到位
int *arr = v.data();                     // 指向连续内存（C 风格）
swap(v1, v2);                            // 交换两个 vector（常数）

/* ==================== <string> ==================== */
// 字符串基本操作（支持较大字符串）
string s = "hello";
int len = s.size();                      // 长度
s.empty();
s += " world";                           // 拼接
s.append("abc");
s.push_back('c');
s.pop_back();
string t = s.substr(pos, len);           // 子串
size_t p = s.find("abc");                // 查找，找不到返回 npos
size_t q = s.rfind("x");                 // 逆向查找
s.replace(pos, len, "new");              // 替换
s.insert(pos, "ins");                    // 插入
s.erase(pos, len);                       // 删除
int x = stoi("123");                     // 字符串转数（stoi, stol, stoll, stof...)
string u = to_string(123);               // 数转字符串
// C 风格快速访问
const char *c = s.c_str();

/* ==================== <map>（有序映射） ==================== */
// 基于红黑树，有序；查找、插入、删除均 O(log n)
map<int,int> mp;
mp[key] = val;                            // 插入或修改（会构造默认值）
mp.insert({k,v});                         // 插入（若已存在不覆盖）
mp.emplace(k, v);                         // 原地构造
auto it = mp.find(key);                   // 找到返回迭代器 or mp.end()
bool has = mp.count(key);                 // 0/1（ordered map 用法）
mp.erase(key);                            // 按 key 删除（或 mp.erase(it)）
auto itlow = mp.lower_bound(x);          // 第一个 >= x（map 特有）
auto itup = mp.upper_bound(x);           // 第一个 > x
for (auto &kv : mp) { /* kv.first, kv.second */ }

/* ==================== <unordered_map>（哈希映射） ==================== */
// 若需要更快的平均查找，使用哈希表（头 <unordered_map>）
// unordered_map<int,int> um; // 与 map 的接口类似，但无序，平均 O(1)

/* ==================== <set>（有序集合） ==================== */
// 红黑树实现的集合，元素唯一、有序
set<int> st;
st.insert(x);                             // 插入
st.emplace(x);
st.erase(x);                              // 删除值
auto sit = st.find(x);                    // 找到或 end()
st.count(x);                              // 0/1
auto s_itlow = st.lower_bound(x);         // >= x
auto s_itup = st.upper_bound(x);          // > x
st.clear();

// multiset：允许重复元素（插入/删除/查找类似）

/* ==================== <queue> / <deque> / <priority_queue> ==================== */
// queue：FIFO，deque：双端队列，priority_queue：优先队列（堆）
queue<int> q;
q.push(x); q.pop(); int f = q.front();    // 访问队头
deque<int> dq;
dq.push_front(x); dq.push_back(y);        // 双端插入
int bk = dq.back();
priority_queue<int> pq;                   // 默认最大堆
pq.push(x); pq.pop(); int top = pq.top();
// 最小堆：priority_queue<int, vector<int>, greater<int>> pqmin;

/* ==================== <stack> ==================== */
stack<int> stck;
stck.push(x);
stck.pop();
int ttop = stck.top();
bool emptyStack = stck.empty();

/* ==================== <pair> / <tuple> (<utility>, <tuple>) ==================== */
pair<int,int> pr = {1,2};
auto [a,b] = pr;                          // 结构化绑定（C++17）
tie(x,y) = make_pair(3,4);                // 拆包（可用于忽略项）
tuple<int,int,int> tup = {1,2,3};
auto [i1,i2,i3] = tup;

/* ==================== <algorithm>（常用摘录） ==================== */
// 前面已有很多算法示例：sort, lower_bound, upper_bound, unique, remove, 
// next_permutation, prev_permutation, reverse, rotate, merge, set_union 等
// 常见组合：去重 -> sort + unique + erase

/* ==================== <iterator> / 迭代器工具 ==================== */
// distance(begin, it) 返回距离
// advance(it, k) 将迭代器前进 k 步
// next(it, k), prev(it, k)
// back_inserter(v), front_inserter(list), inserter(set, it)

/* ==================== <utility> / 交换 ==================== */
swap(a,b);                                 // 交换
make_pair(a,b);

/* ==================== <numeric>（数值算法） ==================== */
// accumulate, partial_sum, inner_product, iota

/* ==================== <cmath>（数学函数） ==================== */
// sqrt, pow, sin, cos, tan, log, exp, floor, ceil, abs, fabs

/* ==================== I/O / 速写模板（竞赛常见） ==================== */
// 快速读写（若需要，放进模板）
ios::sync_with_stdio(false);
cin.tie(nullptr);

// 读 vector
int n; cin >> n;
vector<int> a(n);
for (int i = 0; i < n; ++i) cin >> a[i];

// 输出
for (auto x : a) cout << x << ' ';
cout << '\n';

/* ==================== 常用“捷径”/惯用写法（速记） ==================== */
// 1) 去重： sort(v), v.erase(unique(v.begin(), v.end()), v.end())
// 2) 第 k 小： nth_element(v.begin(), v.begin()+k, v.end()); int val = v[k];
// 3) 二分下标： auto it = lower_bound(v.begin(), v.end(), x); idx = it - v.begin();
// 4) 堆维护（top-k）： make_heap(v.begin(), v.end()); pop_heap(...); v.pop_back();
// 5) 并/交/差（有序）： set_union, set_intersection, set_difference
// 6) 哈希计数： unordered_map<int,int> cnt; cnt[x]++; // 统计频率
```
