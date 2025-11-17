# 📒 C++ `cin` / `cout` 备忘表
## 🔹 基础用法

- `cin >> var;`  
    从标准输入读取（以空格、换行、Tab 作为分隔符）。
    
- `cout << var;`  
    向标准输出写入内容。
    

---

## 🔹 常用流操纵符（需 `<iomanip>`）

|操纵符|用途|示例|
|---|---|---|
|`endl`|换行并刷新缓冲区|`cout << "Hi" << endl;`|
|`setw(n)`|设置字段宽度（右对齐）|`cout << setw(5) << 42;`|
|`setfill(c)`|指定填充字符|`cout << setfill('0') << setw(5) << 42; // 00042`|
|`setprecision(n)`|设置浮点数精度|`cout << setprecision(4) << 3.14159; // 3.142`|
|`fixed`|固定小数位|`cout << fixed << setprecision(2) << 3.14159; // 3.14`|
|`scientific`|科学计数法|`cout << scientific << 12345;`|
|`hex`|十六进制输出|`cout << hex << 255; // ff`|
|`oct`|八进制输出|`cout << oct << 255; // 377`|
|`dec`|十进制输出（默认）|`cout << dec << 255;`|
|`showbase`|显示进制前缀 (`0x`, `0`)|`cout << showbase << hex << 255; // 0xff`|
|`uppercase`|十六进制大写|`cout << uppercase << hex << 255; // FF`|
|`boolalpha`|输出 `true/false` 而不是 `1/0`|`cout << boolalpha << true; // true`|
|`noboolalpha`|恢复 `1/0`|`cout << noboolalpha << true; // 1`|

---

## 🔹 `cin` 控制

| 方法 / 操纵符                 | 用途                    | 示例                                 |
| ------------------------ | --------------------- | ---------------------------------- |
| `cin >> var`             | 读取一个值，遇空白停止           | `cin >> x;`                        |
| `getline(cin, str)`      | 读取整行（包括空格）            | `getline(cin, s);`                 |
| `cin.get()`              | 读取一个字符（包括空格、回车）       | `char c = cin.get();`              |
| `cin.getline(buf, size)` | 读一行到 `char[]`         | `cin.getline(arr, 100);`           |
| `cin.ignore(n, delim)`   | 忽略输入流前 n 个字符或直到 delim | `cin.ignore(100, '\n');`           |
| `cin.peek()`             | 查看下一个字符，但不提取          | `char c = cin.peek();`             |
| `cin.putback(c)`         | 将字符放回输入流              | `cin.putback('a');`                |
| `cin.eof()`              | 判断是否到达输入结束            | `while (!cin.eof()) ...`           |
| `cin.fail()`             | 检查输入是否失败              | `if (cin.fail()) { cin.clear(); }` |
| `cin.clear()`            | 清除错误状态                | `cin.clear();`                     |

---

## 🔹 流格式设置（成员函数）

（效果类似操纵符，可以链式调用）

| 方法                  | 用途     | 示例                           |
| ------------------- | ------ | ---------------------------- |
| `cout.width(n)`     | 设置宽度   | `cout.width(5); cout << 42;` |
| `cout.fill(c)`      | 设置填充字符 | `cout.fill('*');`            |
| `cout.setf(flag)`   | 设置格式   | `cout.setf(ios::hex);`       |
| `cout.unsetf(flag)` | 取消格式   | `cout.unsetf(ios::hex);`     |
| `cout.precision(n)` | 设置浮点精度 | `cout.precision(3);`         |

常见 `ios` 标志：

- `ios::hex`, `ios::oct`, `ios::dec`
    
- `ios::fixed`, `ios::scientific`
    
- `ios::showbase`, `ios::showpos`, `ios::uppercase`
    
- `ios::boolalpha`
    

---

## 🔹 快速示例

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 255;
    double pi = 3.1415926;

    cout << hex << showbase << n << endl;  // 0xff
    cout << dec << setw(5) << setfill('0') << n << endl;  // 00255
    cout << fixed << setprecision(2) << pi << endl;  // 3.14
}
```
