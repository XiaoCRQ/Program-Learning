# 构造 & 初始化

- `vector<T> v;` → 默认构造，空容器。
    
- `vector<T> v(n);` → 大小为 `n`，元素值为 `T()`。
    
- `vector<T> v(n, val);` → 大小为 `n`，元素全部为 `val`。
    
- `vector<T> v(begin, end);` → 用迭代器区间构造。
    
- `vector<T> v{a, b, c};` → 初始化列表。
## 二维数组
- `vector<vector<int>> arr(n, vector<int>(m))` → 创建n\*m的数组
---

# 基本属性

- `size_type size() const noexcept;` → 当前元素个数。
    
- `size_type capacity() const noexcept;` → 已分配的容量。
    
- `bool empty() const noexcept;` → 是否为空。
    
- `size_type max_size() const noexcept;` → 理论最大可容纳元素数。
    

---

# 元素访问

- `T& operator[](size_type pos);` / `const T& operator[](size_type pos) const;`  
    下标访问（不检查越界，最快）。
    
- `T& at(size_type pos);` / `const T& at(size_type pos) const;`  
    带边界检查（越界抛异常）。
    
- `T& front();` / `const T& front() const;` → 第一个元素。
    
- `T& back();` / `const T& back() const;` → 最后一个元素。
    
- `T* data() noexcept;` / `const T* data() const noexcept;` → 底层数组指针（常用于 C 接口）。
    

---

# 修改操作

- `void clear() noexcept;` → 清空所有元素。
    
- `void push_back(const T& val);` / `void push_back(T&& val);` → 末尾插入。
    
- `void pop_back();` → 删除末尾一个元素。
    
- `iterator insert(const_iterator pos, const T& val);`  
    在 `pos` 前插入元素，返回新迭代器。
    
- `iterator insert(const_iterator pos, size_type count, const T& val);` → 插入多个相同元素。
    
- `iterator erase(const_iterator pos);` → 删除单个元素。
    
- `iterator erase(const_iterator first, const_iterator last);` → 删除区间 `[first,last)`。
    
- `void resize(size_type n);` → 改变大小，多则填默认值，少则截断。
    
- `void resize(size_type n, const T& val);` → 改变大小，多则填 `val`。
    
- `void reserve(size_type new_cap);` → 预分配容量，避免反复扩容。
    
- `void shrink_to_fit();` → 回收多余容量（非强制）。
    
- `void assign(size_type n, const T& val);` → 重新赋值 n 个 `val`。
    
- `void swap(vector& other) noexcept;` → 与另一个 vector 交换。
    

---

# 迭代器

- `iterator begin() noexcept;` / `const_iterator begin() const noexcept;`
    
- `iterator end() noexcept;` / `const_iterator end() const noexcept;`
    
- `reverse_iterator rbegin() noexcept;` / `const_reverse_iterator rbegin() const noexcept;`
    
- `reverse_iterator rend() noexcept;` / `const_reverse_iterator rend() const noexcept;`
    

常用于：

```cpp
for (auto &x : v) cout << x << " ";
```

---

# 比较

- `bool operator==(const vector& rhs) const;`
    
- `bool operator!=(const vector& rhs) const;`
    
- `bool operator<(const vector& rhs) const;`（字典序比较）
    

---

# 常用 STL 组合

- **排序**：`sort(v.begin(), v.end());`
    
- **逆序**：`reverse(v.begin(), v.end());`
    
- **查找**：`auto it = find(v.begin(), v.end(), val);`
    
- **二分**：`lower_bound(v.begin(), v.end(), x);` / `upper_bound(...)`
    
- **去重**：
    
    ```
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ```
    

---

# 数组替代 & 常用技巧

- **二维数组（邻接表/DP 常用）**：  
    `vector<vector<int>> g(n, vector<int>(m, 0));`
    
- **预分配大空间**：  
    `vector<int> v; v.reserve(1e6);`
    
- **快速清空重用**：  
    `v.clear(); v.shrink_to_fit();`（一般只 `clear()` 即可）。
    

---

# ACM/竞赛高频推荐（核心函数）

1. **访问**：`v[i]`, `v.size()`, `v.back()`, `v.front()`
    
2. **修改**：`push_back`, `pop_back`, `resize`, `clear`, `erase`
    
3. **性能**：`reserve`（避免反复扩容）
    
4. **算法配合**：`sort`, `reverse`, `lower_bound`, `unique+erase`
    
5. **结构**：二维 vector 构造 `vector<vector<T>>`
    

