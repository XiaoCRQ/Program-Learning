# **ACM 常用 I/O 优化方法总结**

---

## 1. **C++ 标准 I/O 优化**

### (1) `ios::sync_with_stdio(false); cin.tie(nullptr);`

最常用的优化，禁用 `cin/cout` 与 `stdio` 的同步，并解绑 `cin/cout` 的绑定。

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    cout << n << "\n";
}
```

🔹 适合：大多数题目，能显著加快 `cin/cout`。  
🔹 注意：开启后不能混用 `scanf/printf`。

---

### (2) `endl` 替换为 `'\n'`

`endl` 会强制刷新缓冲区，比 `'\n'` 慢很多。

```cpp
cout << x << '\n'; // ✅
cout << x << endl; // ❌ 慢
```

---

## 2. **C 风格快速 I/O**

### (1) `scanf` / `printf`

比 `cin/cout` 快，常用格式：

```cpp
int x; scanf("%d", &x);
printf("%d\n", x);
```

---

### (2) `getchar` / `putchar`

读取/输出单字符，比 `scanf/printf` 更快。

```cpp
int readInt() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { x = x*10 + (c-'0'); c = getchar(); }
    return x*f;
}

void writeInt(int x) {
    if(x < 0) { putchar('-'); x = -x; }
    if(x > 9) writeInt(x/10);
    putchar(x%10 + '0');
}
```

---

## 3. **手写快读快写（推荐）**

在 **大输入大输出** 情况下（如 `10^6+` 数据），最常用：

```cpp
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { x = x*10 + (c - '0'); c = getchar(); }
    return x * f;
}

inline void write(int x) {
    if(x < 0) { putchar('-'); x = -x; }
    char buf[20]; int p = 0;
    do { buf[p++] = x%10 + '0'; x /= 10; } while(x);
    while(p) putchar(buf[--p]);
}
```

---

## 4. **块读写优化**

### (1) fread + fwrite 批量 I/O

直接操作缓冲区，**极致优化**（常见于极限卡常题）。

```cpp
const int SIZE = 1 << 20; // 缓冲区大小
char ibuf[SIZE], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
    if(p1 == p2) {
        p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin);
        if(p1 == p2) return EOF;
    }
    return *p1++;
}

inline int read() {
    int x = 0, f = 1; char c = gc();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = gc(); }
    while(c >= '0' && c <= '9') { x = x*10 + (c-'0'); c = gc(); }
    return x*f;
}

char obuf[SIZE]; int p3 = 0;
inline void pc(char c) {
    if(p3 == SIZE) fwrite(obuf, 1, p3, stdout), p3 = 0;
    obuf[p3++] = c;
}

inline void write(int x) {
    if(x < 0) { pc('-'); x = -x; }
    char buf[20]; int p = 0;
    do { buf[p++] = x%10 + '0'; x /= 10; } while(x);
    while(p) pc(buf[--p]);
}
inline void flush() { fwrite(obuf, 1, p3, stdout); }
```

🔹 注意：输出结束后要 `flush()`。

---

## 5. **字符串输入优化**

- **`getline`** 代替逐字符输入，适合读整行字符串。
    
- **批量读入**：用 `cin.read()` 或 `fread` 整块读入后自己切分。
    

```cpp
string s;
getline(cin, s);  // 读整行
```

---

## 6. **特殊场景优化**

- **输入全是数字（如矩阵）**  
    用 `memset` / `memcpy` + `fread` 批量读取。
    
- **只输出固定模式（YES/NO）**  
    建议存储到 `string` 数组，最后一次性输出：
    

```cpp
string out;
for(int i=0;i<n;i++) out += "YES\n";
cout << out;
```

---

# 🚀 ACM竞赛 I/O 优化常用选择

1. **普通题**：  
    `ios::sync_with_stdio(false); cin.tie(nullptr);`
    
2. **数据量大 (10^6)**：  
    手写 `getchar` 快读 + `putchar` 快写
    
3. **极限数据 (10^7+ ~ 10^8)**：  
    `fread/fwrite` 批量I/O
    

