# 查找 / 计数 / 比较

- `auto it = find(InputIt first, InputIt last, const T& value)`
    
    - 找到第一个等于 value 的元素，返回迭代器或 `last`。
        
- `auto it = find_if(InputIt first, InputIt last, UnaryPredicate p)`
    
    - 第一个满足谓词 p 的元素。
        
- `auto it = find_if_not(InputIt first, InputIt last, UnaryPredicate p)`
    
    - 第一个不满足 p 的元素。
        
- `bool b = binary_search(ForwardIt first, ForwardIt last, const T& value)`
    
    - 在有序区间中检查是否存在 value（需升序）。
        
- `auto it = lower_bound(ForwardIt first, ForwardIt last, const T& value)`
    
    - 第一个 `>= value` 的位置（有序）。
        
- `auto it = upper_bound(ForwardIt first, ForwardIt last, const T& value)`
    
    - 第一个 `> value` 的位置（有序）。
        
- `auto range = equal_range(ForwardIt first, ForwardIt last, const T& value)`
    
    - 返回 `{lower_bound, upper_bound}`。
        
- `size_t c = count(InputIt first, InputIt last, const T& value)`
    
    - 统计等于 value 的个数。
        
- `size_t c = count_if(InputIt first, InputIt last, UnaryPredicate p)`
    
    - 统计满足 p 的元素数。
        
- `bool all = all_of(InputIt first, InputIt last, UnaryPredicate p)` / `any_of` / `none_of`
    
    - 全/任意/无 元素满足 p。
        
- `auto it = adjacent_find(InputIt first, InputIt last)`
    
    - 找到相邻相等元素对的首个位置。
        

# 极值 / 元素位置

- `const T& m = min(const T& a, const T& b)` / `max(...)`
    
    - 两数最小/最大。
        
- `Iterator it = min_element(ForwardIt first, ForwardIt last)` / `max_element(...)`
    
    - 返回最小/最大值的迭代器。
        
- `auto pr = minmax(const T& a, const T& b)` / `auto pr = minmax_element(ForwardIt first, ForwardIt last)`
    
    - 返回 `{min, max}` 或 `{it_min, it_max}`。
        
- `T clamp(const T& v, const T& lo, const T& hi)` _(C++17)_
    
    - 将 v 限定在 [lo,hi]。
        

# 排序 / 重排 / 下一个排列

- `void sort(RandomIt first, RandomIt last)`
    
    - 升序排序（O(n log n)）。
        
- `void sort(RandomIt first, RandomIt last, Compare comp)`
    
    - 自定义比较器排序。
        
- `void stable_sort(RandomIt first, RandomIt last)`
    
    - 稳定排序（保持等价元素相对顺序）。
        
- `void partial_sort(RandomIt first, RandomIt middle, RandomIt last)`
    
    - 将 `[first,middle)` 排到已排序的最小区间。
        
- `void nth_element(RandomIt first, RandomIt nth, RandomIt last)`
    
    - 把第 n 小元素放到正确位置，左右无序。常用于第 k 小/大。
        
- `bool next_permutation(BidirIt first, BidirIt last)` / `prev_permutation(...)`
    
    - 生成下/上一个字典序排列，常用于枚举排列。
        
- `void reverse(BidirIt first, BidirIt last)`
    
    - 反转区间。
        
- `ForwardIt rotate(ForwardIt first, ForwardIt middle, ForwardIt last)`
    
    - 将 `[first,middle)` 移到末尾，相当于左旋。
        
- `void inplace_merge(BidirIt first, BidirIt middle, BidirIt last)`
    
    - 将两个已排序区间合并（原地）。
        

# 复制 / 变换 / 生成

- `OutIt copy(InputIt first, InputIt last, OutputIt d_first)`
    
    - 复制元素到另一个序列。
        
- `OutIt copy_if(InputIt first, InputIt last, OutputIt d_first, Predicate pred)`
    
    - 只复制满足 pred 的元素。
        
- `OutIt copy_n(InputIt first, Size n, OutputIt d_first)`
    
    - 复制前 n 个元素。
        
- `OutIt transform(InputIt first, InputIt last, OutputIt d_first, UnaryOp op)`
    
    - 对每个元素应用 op 并写入输出。
        
- `void generate(ForwardIt first, ForwardIt last, Generator g)`
    
    - 用 g() 填充区间。
        
- `void iota(ForwardIt first, ForwardIt last, T value)` _()_
    
    - 填充连续递增的序列（常用于编号）。
        

# 删除 / 替换 / 唯一化（常用“remove-erase”惯用法）

- `ForwardIt remove(ForwardIt first, ForwardIt last, const T& value)`
    
    - 将不等于 value 的元素前移，返回新尾迭代器（不改变容器大小）。常与 `v.erase(it, v.end())` 联用。
        
- `ForwardIt remove_if(ForwardIt first, ForwardIt last, Predicate p)`
    
    - 类似，只移除满足 p 的元素。
        
- `ForwardIt unique(ForwardIt first, ForwardIt last)`
    
    - 移除相邻重复元素（先排序再 unique 通常用来 dedup）。
        
- `OutIt unique_copy(InputIt first, InputIt last, OutputIt d_first)`
    
    - 将不重复的元素复制到输出。
        
- `void replace(ForwardIt first, ForwardIt last, const T& old_value, const T& new_value)`
    
    - 替换值。
        
- `void replace_if(ForwardIt first, ForwardIt last, Predicate p, const T& new_value)`
    
    - 满足 p 的元素替换。
        

# 合并 / 集合运算（有序序列）

- `OutIt merge(ForwardIt first1, ForwardIt last1, ForwardIt first2, ForwardIt last2, OutputIt d_first)`
    
    - 合并两个有序序列到输出（稳定）。
        
- `OutIt inplace_merge(BidirIt first, BidirIt middle, BidirIt last)`
    
    - 在原地合并两个相邻有序区间（见上）。
        
- `OutIt set_union(ForwardIt first1, ForwardIt last1, ForwardIt first2, ForwardIt last2, OutputIt d_first)`
    
    - 并集（输入需有序）。
        
- `OutIt set_intersection(...)`
    
    - 交集（有序）。
        
- `OutIt set_difference(...)`
    
    - 差集（有序）。
        
- `OutIt set_symmetric_difference(...)`
    
    - 对称差（有序）。
        
- `bool includes(ForwardIt first1, ForwardIt last1, ForwardIt first2, ForwardIt last2)`
    
    - 检查第一个有序序列是否包含第二个（多用于子集判断）。
        

# 堆（priority queue 基础操作）

- `void make_heap(RandomIt first, RandomIt last)`
    
    - 将区间构建为最大堆（默认）。
        
- `void push_heap(RandomIt first, RandomIt last)`
    
    - 假设 `[first,last-1)` 已是堆，插入 last-1 所指元素入堆。
        
- `void pop_heap(RandomIt first, RandomIt last)`
    
    - 将堆顶移到 `last-1`，并重排 `[first,last-1)` 为堆。常与 `v.pop_back()` 联用实现优先队列堆操作。
        
- `void sort_heap(RandomIt first, RandomIt last)`
    
    - 将堆排序为升序序列。
        
- `bool is_heap(RandomIt first, RandomIt last)` / `is_heap_until(...)`
    
    - 判断是否为堆，或返回最长堆前缀。
        

# 分区 / 分割

- `ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)`
    
    - 使满足 p 的元素在前，返回分界迭代器（不稳定）。
        
- `ForwardIt stable_partition(ForwardIt first, ForwardIt last, UnaryPredicate p)`
    
    - 稳定版本（保留相对顺序）。
        
- `ForwardIt partition_point(ForwardIt first, ForwardIt last, UnaryPredicate p)`
    
    - 在已按谓词分区的区间中找到分界点（用于二分查找分区点）。
        

# 比较 / 相等 / 字典序

- `bool eq = equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)`
    
    - 判断两个序列元素逐个相等（长度需保证）。
        
- `pair<It1,It2> mm = mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2)`
    
    - 找到第一个不匹配的位置。
        
- `bool lc = lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)`
    
    - 字典序比较（常用于序列比较）。
        

# 数值汇总 / 累加（需 `<numeric>`）

- `T sum = accumulate(InputIt first, InputIt last, T init)` _()_
    
    - 计算和（从 init 开始）。
        
- `T acc = inner_product(InputIt1 first1, InputIt1 last1, InputIt2 first2, T init)`
    
    - 内积累加。
        
- `T res = partial_sum(InputIt first, InputIt last, OutputIt d_first)`
    
    - 前缀和序列。
        
- `T res = adjacent_difference(InputIt first, InputIt last, OutputIt d_first)`
    
    - 相邻差序列。
        

# 其它常用工具

- `void swap(T& a, T& b)`
    
    - 交换。
        
- `void iter_swap(ForwardIt a, ForwardIt b)`
    
    - 交换两个迭代器指向的元素。
        
- `Iterator find_end(ForwardIt first, ForwardIt last, ForwardIt s_first, ForwardIt s_last)`
    
    - 查找最后一次出现子序列。
        
- `Iterator find_first_of(ForwardIt first, ForwardIt last, ForwardIt s_first, ForwardIt s_last)`
    
    - 在第一个序列中查找属于第二序列的任意元素。
        
- `template<class T> T sample(InputIt first, InputIt last, Size n, URNG&& g)` _(C++17)_
    
    - 从序列中随机抽样 n 个元素（常用概率/随机化技巧时用）。
        

---

# 常见竞赛“惯用组合”提示（速记）

- 去重：`sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());`
    
- 选第 k 小：`nth_element(v.begin(), v.begin()+k, v.end()); ans = v[k];`
    
- 维护堆（最大堆）：`make_heap(v.begin(), v.end()); pop_heap(v.begin(), v.end()); v.pop_back();`
    
- 二分在有序数组中找第一个大于 x：`auto it = upper_bound(a.begin(), a.end(), x); idx = it - a.begin();`
    
- 合并有序数组到新容器：`merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));`
    
- 生成 0..n-1：`iota(v.begin(), v.end(), 0);`
    
- 前缀和数组：`partial_sum(a.begin(), a.end(), pref.begin());`
    

---