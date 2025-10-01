# 输入/输出

- `std::istream& operator>>(std::istream& is, std::string& s)`  
    以空白分隔读入一个词（遇空格/换行停止）。  
    示例：`cin >> s;` — 读单词或 token。
    
- `std::getline(std::istream& is, std::string& s)`  
    读整行（包含空格），不包含行尾 `\n`。  
    示例：`getline(cin, s);` — 读整行输入。
    

---

# 构造与赋值（简短）

- `string s;` / `string s(const char* s)` / `string s(size_type n, char ch)`  
    常用于初始化空串、字面量或重复字符构造。  
    示例：`string s(10, '0');` — 产生 `"0000000000"`。
    
- `s = "abc";` / `s = other;`  
    直接赋值。
    

---

# 长度与访问

- `size_type size() const noexcept` / `size_type length() const noexcept`  
    返回长度（常用于循环边界）。  
    示例：`for (size_t i=0;i<s.size();++i)`。
    
- `bool empty() const noexcept`  
    判断是否为空（比 `s.size()==0` 更语义化）。
    
- `char& operator[](size_type pos)` / `const char& operator[](size_type pos) const`  
    下标访问（**不检查越界**，最快）。  
    示例：`if (s[i] == '0') ...`
    
- `char& at(size_type pos)` / `const char& at(size_type pos) const`  
    带范围检查（比赛中较少用于性能敏感处）。
    
- `char& front()` / `char& back()`  
    访问首尾字符。示例：`s.back() = '\0';`（注意合法性）。
    
- `const char* c_str() const noexcept`  
    获取 C 字符串指针（只读），用于 `printf` 或 `strcmp`（若需要 C API）。  
    示例：`printf("%s\n", s.c_str());`
    

---

# 拼接与构造结果串

- `string& operator+=(const string& str)` / `string& operator+=(const char* s)` / `string& operator+=(char c)`  
    快速追加。示例：`s += '+';` / `s += t;`
    
- `string operator+(const string& a, const string& b)`（及其重载）  
    拼接生成新字符串（注意临时开销）。示例：`t = a + ":" + b;`
    
- `string& append(const string& str)` / `append(const char* s, size_type n)` / `append(size_type n, char ch)`  
    多重载追加，常用于构造大字符串。
    
- `void push_back(char ch)`  
    在尾部追加单字符（常用，效率高）。
    

---

# 截取 / 子串处理

- `string substr(size_type pos = 0, size_type n = npos) const`  
    从 `pos` 截取长度 `n` 的子串（返回新字符串）。比赛中常用于解析 token。  
    示例：`t = s.substr(i, j-i);`
    
- `size_type copy(char* s, size_type n, size_type pos = 0) const`  
    将字符拷到目标缓冲（**不自动添加 `\0`**），偶用于与 C 接口交互。
    

---

# 查找与定位（非常常用）

- `size_type find(const string& str, size_type pos = 0) const noexcept`  
    查找子串首次出现位置或返回 `npos`。常用于循环查找或判断是否包含。  
    示例：`pos = s.find("01"); if (pos != string::npos) ...`
    
- `size_type find(const char* s, size_type pos, size_type n) const` / `find(char ch, size_type pos = 0) const noexcept`  
    查单字符或 C 字符串（多重载）。
    
- `size_type rfind(const string& str, size_type pos = npos) const noexcept`  
    反向查找（从右侧找第一个匹配）。
    
- `size_type find_first_of(const string& s, size_type pos = 0) const noexcept`  
    找出第一个属于给定字符集合的位置（常用于寻找任一分隔符）。  
    示例：`p = s.find_first_of(" ,;");`
    
- `size_type find_first_not_of(const string& s, size_type pos = 0) const noexcept`  
    找出第一个不属于给定字符集合的位置（常用于跳过空白或分隔符）。  
    组合示例（split）：
    
    ```
    p = s.find_first_not_of(" ,");
    q = s.find_first_of(" ,", p);
    token = s.substr(p, q-p);
    ```
    
- `size_type find_last_of(...)` / `find_last_not_of(...)`  
    类似上面但从右侧搜索。
    

---

# 删除 / 替换（常用于文本处理）

- `string& erase(size_type pos = 0, size_type len = npos)`  
    从 `pos` 删除 `len` 个字符。常用于局部删去。示例：`s.erase(i, 1);`
    
- `iterator erase(const_iterator first, const_iterator last)`  
    基于迭代器删除一段。
    
- `string& replace(size_type pos, size_type len, const string& str)`  
    替换指定区间为新串，常用于模式替换。
    

---

# 比较与排序相关

- `int compare(const string& str) const noexcept`  
    三值比较（<0,0,>0），用于按字典序比较（也有 `compare(pos,len,...)` 重载）。  
    示例：`if (a.compare(b) < 0) ...`（通常直接用 `<` 更简洁）。
    
- `bool operator<(const string& rhs) const` / `==` / `!=` ...  
    字典序比较，常用于 `std::sort(vector<string>)` 或 `map` 键。
    

---

# 数字/字符串相互转换（常用于解析/输出）

- `int stoi(const string& str, size_t* idx = 0, int base = 10)`  
    将 `str` 转为 `int`（抛 `invalid_argument` / `out_of_range`）。比赛中常用于快速解析数字片段（注意异常或使用 `strtol` 更稳健）。  
    示例：`int x = stoi(token);`
    
- `long long stoll(const string& str, size_t* idx = 0, int base = 10)`  
    转为 `long long`（常用）。
    
- `string to_string(int val)` / `string to_string(long long val)`  
    将数字转为字符串，常用于输出构造或拼接。
    

---

# 迭代器（用于遍历/修改）

- `iterator begin()` / `iterator end()` / `const_iterator cbegin() const` / `cend()`  
    范围循环或 STL 算法可直接使用：`for (char &ch : s)`。
    
- `reverse_iterator rbegin()` / `rend()`  
    反向遍历（常用于从末尾向前处理）。
    

---

# 性能/内存控制（比赛中有时需要）

- `void reserve(size_type new_cap = 0)`  
    预分配容量以避免多次 realloc，提高拼接性能。比赛构造大字符串时常用：`s.reserve(100000);`
    
- `void shrink_to_fit()`  
    尝试释放多余容量（较少用在比赛中）。
    

---

# 常用组合技巧（速查）

- **按分隔符分割字符串（常见模板）**：
    
    ```
    size_t i = s.find_first_not_of(delim, 0);
    while (i != string::npos) {
      size_t j = s.find_first_of(delim, i);
      tokens.push_back(s.substr(i, j-i));
      i = s.find_first_not_of(delim, j);
    }
    ```
    
- **在字符串中查找所有出现位置**：
    
    ```
    for (size_t p = s.find(t); p != string::npos; p = s.find(t, p+1)) { /* p 为每个位置 */ }
    ```
    
- **字符串转整型并处理索引**：`int x = stoi(s.substr(l, r-l));`
    

---

# 小结（比赛优先级）

高频且推荐：

- 输入：`cin >> s`, `getline`
    
- 长度/访问：`s.size()`, `s[i]`
    
- 查找：`find`, `rfind`, `find_first_of`, `find_first_not_of`
    
- 截取：`substr`
    
- 拼接：`+=`, `append`, `push_back`（配合 `reserve`）
    
- 删除/替换：`erase`, `replace`
    
- 转换：`stoi/stoll`, `to_string`
    
- 比较/排序：`<`, `==`, `compare`
