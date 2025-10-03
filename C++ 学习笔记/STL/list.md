
## 🚀 STL 常用数据结构一览

### 1. 链表类

- **`std::list<T>`**
    
    - **双向链表**
        
    - 随机访问不方便，但在 **任意位置插入/删除 O(1)**（前提是已知迭代器）。
        
    - 常用函数：
        
        - `list.push_back(x)` / `list.push_front(x)`
            
        - `list.pop_back()` / `list.pop_front()`
            
        - `list.insert(it, x)` 在迭代器位置前插入
            
        - `list.erase(it)` 删除迭代器位置元素
            
        - `list.remove(x)` 删除所有等于 `x` 的元素
            
        - `list.sort()` 内置排序（归并排序）
            
        - `list.reverse()` 反转
            
- **`std::forward_list<T>`**
    
    - **单向链表**，比 `list` 更轻量，但功能较少。
        

---

### 2. 队列类

- **`std::queue<T>`**
    
    - 普通队列（FIFO，先进先出）。
        
    - 基于 `deque` 或 `list`。
        
    - 常用函数：
        
        - `q.push(x)` 入队
            
        - `q.pop()` 出队（删除队首）
            
        - `q.front()` 队首元素
            
        - `q.back()` 队尾元素
            
        - `q.empty()`, `q.size()`
            
- **`std::priority_queue<T>`**
    
    - **优先队列（堆实现）**，默认最大堆。
        
    - 常用于维护最大值/最小值。
        
    - 定义方式：
        
        - `priority_queue<int> pq;` 最大堆
            
        - `priority_queue<int, vector<int>, greater<int>> pq;` 最小堆
            
    - 常用函数：
        
        - `pq.push(x)` 插入
            
        - `pq.pop()` 删除堆顶
            
        - `pq.top()` 访问堆顶（最大/最小值）
            
- **`std::deque<T>`**
    
    - **双端队列**，两端都能插入删除，效率比 `vector` 高。
        
    - 常用函数和 `vector` 类似：
        
        - `dq.push_back(x)` / `dq.push_front(x)`
            
        - `dq.pop_back()` / `dq.pop_front()`
            
        - 随机访问支持 `dq[i]`
            

---

### 3. 栈类

- **`std::stack<T>`**
    
    - 栈（LIFO，先进后出）。
        
    - 基于 `deque` 或 `list`。
        
    - 常用函数：
        
        - `st.push(x)` 入栈
            
        - `st.pop()` 出栈（删除栈顶）
            
        - `st.top()` 栈顶元素
            
        - `st.empty()`, `st.size()`
            

---

### 4. 其他常用

- **`std::bitset<N>`**
    
    - 固定大小的二进制位集合，常用于位运算优化。
        
- **`std::map<K, V>`**
    
    - 平衡树映射，支持 `O(log n)` 查找/插入/删除。
        
- **`std::unordered_set / unordered_map`**
    
    - 基于哈希表，查找平均 `O(1)`，但无序。
        

---

## 🚩 ACM/竞赛常用场景

- **`queue`**：BFS 图遍历
    
- **`priority_queue`**：Dijkstra、贪心算法
    
- **`stack`**：括号匹配、单调栈
    
- **`deque`**：单调队列优化 DP / 滑动窗口最值
    
- **`list`**：少用（除非题目强制链表操作）
    
- **`set/map`**：动态有序集合、维护上下界
    
- **`unordered_set/map`**：哈希判重、快速查找
    

