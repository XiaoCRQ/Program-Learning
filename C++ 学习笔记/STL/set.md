## `std::set` 常用总结（ACM竞赛向）

### 1. 定义与初始化

- `std::set<int> s;`  
    定义一个升序存储的集合。
    
- `std::set<int, std::greater<int>> s;`  
    定义一个降序集合。
    
- `std::set<int> s = {1,2,3};`  
    列表初始化。
    

---

### 2. 插入与删除

- `s.insert(x)`  
    插入元素 `x`，若已存在则无效。返回 `pair<iterator, bool>` 表示迭代器和是否成功。
    
- `s.erase(x)`  
    删除值为 `x` 的元素。复杂度 **O(log n)**。
    
- `s.erase(it)`  
    删除迭代器位置的元素。
    
- `s.clear()`  
    清空集合。
    

---

### 3. 查找与计数

- `s.find(x)`  
    返回指向 `x` 的迭代器，若不存在则返回 `s.end()`。
    
- `s.count(x)`  
    返回 `x` 的出现次数（`set` 只能是 `0` 或 `1`）。
    

---

### 4. 遍历与大小

- `s.begin()`, `s.end()`  
    迭代器遍历，升序输出。
    
- `s.rbegin()`, `s.rend()`  
    反向迭代器，降序输出。
    
- `s.size()`  
    集合大小。
    
- `s.empty()`  
    是否为空。
    

---

### 5. 区间操作（竞赛常用）

- `s.lower_bound(x)`  
    返回指向 **第一个 >= x** 的迭代器。
    
- `s.upper_bound(x)`  
    返回指向 **第一个 > x** 的迭代器。
    
- `s.equal_range(x)`  
    返回 `pair(lower_bound(x), upper_bound(x))`。
    

---

### 6. 交换与比较

- `s.swap(s2)`  
    交换两个集合。复杂度 **O(1)**。
    
- `s1 == s2`, `s1 < s2`  
    支持比较（字典序）。
    

---

## 🚀 ACM竞赛常用技巧

- **动态维护最小值/最大值**
    
    ```cpp
    int mn = *s.begin();      // 最小值
    int mx = *s.rbegin();     // 最大值
    ```
    
- **查找上下界（比如求最近的数）**
    
    ```cpp
    auto it = s.lower_bound(x);
    if (it != s.end()) cout << *it;  // >=x 的最小值
    ```
    
- **判重+排序合一**：用 `set` 存输入，自动去重+排序。
    
- **复杂度**：插入、删除、查找全是 `O(log n)`，适合大量动态操作。