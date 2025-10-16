```C++
/*====================================================================
 📘 C++ STL 常用算法模板注释 (按头文件分类)
    For ACM / Competitive Programming
====================================================================*/


//====================================================================
// <algorithm>
//====================================================================
#include <algorithm>

//===== 查找 / 计数 =====//
auto it = find(v.begin(), v.end(), value);                        // 找等于 value 的元素
auto it = find_if(v.begin(), v.end(), [](auto x){return x>0;});   // 找满足条件元素
int cnt = count(v.begin(), v.end(), value);                       // 统计等于 value 个数
int cnt2 = count_if(v.begin(), v.end(), [](auto x){return x%2;}); // 条件计数
bool all = all_of(v.begin(), v.end(), [](auto x){return x>0;});   // 全部满足
bool any = any_of(v.begin(), v.end(), [](auto x){return x<0;});   // 任意满足

//===== 二分查找 (需有序) =====//
auto it1 = lower_bound(v.begin(), v.end(), value);  // 第一个 >= value
auto it2 = upper_bound(v.begin(), v.end(), value);  // 第一个 > value
bool ok = binary_search(v.begin(), v.end(), value); // 是否存在 value
auto [L, R] = equal_range(v.begin(), v.end(), value); // 返回范围 [L,R)

//===== 极值 / 比较 =====//
auto mn = min(a, b);                                  // 返回较小值
auto mx = max(a, b);                                  // 返回较大值
auto [m1, m2] = minmax(a, b);                         // 同时求最小最大
auto itmin = min_element(v.begin(), v.end());         // 最小值迭代器
auto itmax = max_element(v.begin(), v.end());         // 最大值迭代器
auto [itA, itB] = minmax_element(v.begin(), v.end()); // 同时求最小最大迭代器
auto clp = clamp(x, lo, hi);                          // 限制区间内 (C++17)

//===== 排序 / 重排 =====//
sort(v.begin(), v.end());                                        // 升序
sort(v.begin(), v.end(), greater<int>());                        // 降序
sort(v.begin(), v.end(), [](auto &a, auto &b){return a<b;});     // 自定义比较
stable_sort(v.begin(), v.end());                                 // 稳定排序
partial_sort(v.begin(), v.begin()+k, v.end());                   // 前k最小
nth_element(v.begin(), v.begin()+k, v.end());                    // 第k小
next_permutation(v.begin(), v.end());                            // 下一个排列
prev_permutation(v.begin(), v.end());                            // 上一个排列
reverse(v.begin(), v.end());                                     // 翻转
rotate(v.begin(), v.begin()+k, v.end());                         // 左旋

//===== 删除 / 替换 =====//
v.erase(remove(v.begin(), v.end(), x), v.end());                 // 删除指定值
v.erase(remove_if(v.begin(), v.end(), [](auto x){return x<0;}), v.end()); // 删除条件
v.erase(unique(v.begin(), v.end()), v.end());                    // 去重(相邻)
replace(v.begin(), v.end(), a, b);                               // 替换值
replace_if(v.begin(), v.end(), [](auto x){return x<0;}, 0);      // 条件替换

//===== 拷贝 / 变换 =====//
copy(v.begin(), v.end(), back_inserter(u));                      // 复制
copy_if(v.begin(), v.end(), back_inserter(u), [](auto x){return x>0;}); // 条件复制
transform(v.begin(), v.end(), v.begin(), [](auto x){return x*x;});      // 元素映射
generate(v.begin(), v.end(), [](){return rand()%10;});           // 生成随机数列

//===== 合并 / 集合运算 (需有序) =====//
merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c)); // 合并
set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c)); // 并集
set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c)); // 交集
set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));   // 差集
set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c)); // 对称差
bool inc = includes(a.begin(), a.end(), b.begin(), b.end());     // 包含关系

//===== 堆操作 =====//
make_heap(v.begin(), v.end());    // 建最大堆
push_heap(v.begin(), v.end());    // 插入堆
pop_heap(v.begin(), v.end());     // 弹出堆顶(末尾为最大)
sort_heap(v.begin(), v.end());    // 堆排序
bool okh = is_heap(v.begin(), v.end()); // 判断是否为堆

//===== 分区 =====//
partition(v.begin(), v.end(), [](auto x){return x%2==0;});       // 分区(不稳定)
stable_partition(v.begin(), v.end(), [](auto x){return x%2==0;}); // 稳定分区

//===== 比较 / 相等 =====//
bool eq = equal(a.begin(), a.end(), b.begin());                   // 元素相等
auto [itx, ity] = mismatch(a.begin(), a.end(), b.begin());        // 第一个不同
bool lex = lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()); // 字典序


//====================================================================
// <numeric>
//====================================================================
#include <numeric>

// 累加和
int sum = accumulate(v.begin(), v.end(), 0);

// 内积 (sum of a[i]*b[i])
int prod = inner_product(a.begin(), a.end(), b.begin(), 0);

// 前缀和
partial_sum(v.begin(), v.end(), pref.begin());

// 相邻差
adjacent_difference(v.begin(), v.end(), diff.begin());

// 连续填充 (0,1,2,3...)
iota(v.begin(), v.end(), 0);

//====================================================================
// <functional>
//====================================================================
#include <functional>

// 常用比较仿函数
greater<int>()     // 降序排序或最大堆
less<int>()        // 升序 (默认)
equal_to<int>()    // 相等比较
not_equal_to<int>()// 不等比较

// 常用算术仿函数
plus<int>()        // 加法
minus<int>()       // 减法
multiplies<int>()  // 乘法
divides<int>()     // 除法
modulus<int>()     // 取模

//====================================================================
// <utility>
//====================================================================
#include <utility>

swap(a, b);                       // 交换两个变量
pair<int,int> p = {1, 2};         // 配对
auto [x, y] = p;                  // C++17结构化绑定
tie(x, y) = make_pair(3, 4);      // 拆解 pair
auto p2 = make_pair(a, b);        // 生成 pair
auto t = tuple(1,2,3);            // 多值元组 (需 <tuple>)
auto [a1,b1,c1] = t;              // 解构 tuple

//====================================================================
// <iterator>
//====================================================================
#include <iterator>

auto n = distance(v.begin(), v.end());      // 求区间长度
advance(it, k);                             // 迭代器前进 k 步
auto it = next(v.begin(), 2);               // 获取偏移迭代器
auto itp = prev(v.end(), 1);                // 获取前一迭代器
back_inserter(v);                           // 生成 push_back 输出迭代器
front_inserter(lst);                        // 生成 push_front 输出迭代器

//====================================================================
// <cmath>
//====================================================================
#include <cmath>

double r = sqrt(x);             // 平方根
double p = pow(x, y);           // x^y
double s = sin(theta);          // 正弦
double c = cos(theta);          // 余弦
double t = tan(theta);          // 正切
double e = exp(x);              // e^x
double l = log(x);              // ln(x)
double l10 = log10(x);          // log10(x)
double f = floor(x);            // 向下取整
double ce = ceil(x);            // 向上取整
double ab = fabs(x);            // 绝对值 (double)
int ab2 = abs(x);               // 绝对值 (int)

//====================================================================
// <cstdlib> / <ctime> (随机数常用)
//====================================================================
#include <cstdlib>
#include <ctime>

srand(time(0));          // 初始化随机数种子
int r1 = rand() % 100;   // 0~99 随机整数
double r2 = rand() / (double)RAND_MAX; // [0,1) 随机小数


//====================================================================
// ⚡ 常用竞赛惯用组合模板
//====================================================================

// 去重
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// 取第k小
nth_element(v.begin(), v.begin()+k, v.end());
int kth = v[k];

// 二分位置
auto it = lower_bound(v.begin(), v.end(), x);
int pos = it - v.begin();

// 堆维护
make_heap(v.begin(), v.end());
push_heap(v.begin(), v.end());
pop_heap(v.begin(), v.end());
v.pop_back();

// 生成编号
iota(v.begin(), v.end(), 0);
```

