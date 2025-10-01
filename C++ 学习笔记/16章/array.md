# 1. 构造与基本操作

- `std::array<T, N> arr;`  
    定义一个长度为 `N` 的固定数组，类型为 `T`。
    
- `arr[i]`  
    下标访问，时间复杂度 **O(1)**。无越界检查。
    
- `arr.at(i)`  
    带越界检查的访问，越界抛 `std::out_of_range`。复杂度 **O(1)**。
    
- `arr.fill(value)`  
    将所有元素赋值为 `value`。常用于初始化。
    

---

# 2. 大小与迭代器

- `arr.size()`  
    返回数组大小（固定值 `N`）。复杂度 **O(1)**。
    
- `arr.empty()`  
    是否为空（即 `N==0`）。复杂度 **O(1)**。
    
- `arr.begin()`, `arr.end()`  
    返回首尾迭代器，可用于 `for(auto x : arr)` 遍历。
    
- `arr.rbegin()`, `arr.rend()`  
    反向迭代器。
    

---

# 3. 元素访问

- `arr.front()`  
    返回首元素引用。
    
- `arr.back()`  
    返回尾元素引用。
    
- `arr.data()`  
    返回底层原生指针 `T*`，可与 `memset`、`scanf` 等C函数交互。
    

---

# 4. 赋值与交换

- `arr1 = arr2;`  
    支持整体赋值（逐元素拷贝）。
    
- `arr.swap(arr2)`  
    与另一个 `array` 交换。复杂度 **O(N)**。
    

---

# 5. 其他（算法竞赛常见搭配）

- `sort(arr.begin(), arr.end());`  
    排序，复杂度 **O(N log N)**。
    
- `reverse(arr.begin(), arr.end());`  
    翻转。
    
- `*min_element(arr.begin(), arr.end())`  
    最小值。
    
- `*max_element(arr.begin(), arr.end())`  
    最大值。
    
- `accumulate(arr.begin(), arr.end(), 0)`  
    求和。
    

---

# 🚀 ACM常用技巧

- **初始化**：`arr.fill(0);` 比 `for` 循环更快写。
    
- **和C数组兼容**：`arr.data()` 可直接传给 `scanf`、`memset`。
    
- **排序&搜索**：搭配 `sort`、`binary_search` 使用。
    
- **适合小固定数组**：如存储方向数组 `dx[4], dy[4]`，棋盘大小固定时比 `vector` 高效。
    
