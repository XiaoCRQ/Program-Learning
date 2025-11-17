# 📒 C++ `ios` 格式化标志速查表

C++ 的 `cin` / `cout` 底层其实是 `iostream` 流对象，很多格式控制可以通过 `ios` 的标志来完成。  
使用方式一般有两种：

1. **流操纵符**（推荐）
    
    ```cpp
    cout << hex << showbase << uppercase << 255;  
    ```
    
2. **成员函数**
    
    ```cpp
    cout.setf(ios::hex, ios::basefield);  
    cout.setf(ios::showbase);  
    cout.setf(ios::uppercase);  
    ```
    

---

## 🔹 数字进制相关

|标志|作用|示例|
|---|---|---|
|`ios::dec`|十进制（默认）|`cout.setf(ios::dec, ios::basefield); cout << 255; // 255`|
|`ios::hex`|十六进制|`cout.setf(ios::hex, ios::basefield); cout << 255; // ff`|
|`ios::oct`|八进制|`cout.setf(ios::oct, ios::basefield); cout << 255; // 377`|
|`ios::showbase`|显示进制前缀（`0x`, `0`）|`cout << showbase << hex << 255; // 0xff`|
|`ios::uppercase`|十六进制大写|`cout << uppercase << hex << 255; // FF`|
|`ios::showpos`|正数显示 `+`|`cout << showpos << 123; // +123`|

> ⚡ 注意：`ios::dec/hex/oct` 需要和 `ios::basefield` 搭配使用，表示进制域。

---

## 🔹 布尔值相关

|标志|作用|示例|
|---|---|---|
|`ios::boolalpha`|用 `true/false` 代替 `1/0`|`cout << boolalpha << true; // true`|
|`ios::noboolalpha`|恢复 `1/0`|`cout << noboolalpha << true; // 1`|

---

## 🔹 浮点数相关

|标志|作用|示例|
|---|---|---|
|`ios::fixed`|固定小数点格式|`cout << fixed << setprecision(2) << 3.14159; // 3.14`|
|`ios::scientific`|科学计数法|`cout << scientific << 12345.6789; // 1.234568e+04`|
|`ios::showpoint`|总是显示小数点|`cout << showpoint << 5.0; // 5.00000`|
|`ios::uppercase`|科学计数法中的 `E` 大写|`cout << uppercase << scientific << 1234.5; // 1.234500E+03`|

> ⚡ 注意：`fixed` 和 `scientific` 需要和 `ios::floatfield` 搭配使用，表示浮点域。

---

## 🔹 对齐和填充

|标志|作用|示例|
|---|---|---|
|`ios::left`|左对齐|`cout << left << setw(5) << 42; // "42 "`|
|`ios::right`|右对齐（默认）|`cout << right << setw(5) << 42; // " 42"`|
|`ios::internal`|符号靠左，数字靠右|`cout << internal << setw(5) << -42; // "- 42"`|

---

## 🔹 组合方式

- `setf(flag)`：设置某个标志
    
- `setf(flag, mask)`：在某个域内设置标志，清除同类冲突的
    
    ```cpp
    cout.setf(ios::hex, ios::basefield);   // 设置为十六进制
    cout.setf(ios::fixed, ios::floatfield); // 设置为定点小数
    ```
    
- `unsetf(flag)`：取消标志
    
    ```cpp
    cout.unsetf(ios::showpos);
    ```
    

---

## 🔹 常见域分类

|域|对应的标志|
|---|---|
|`ios::basefield`|`ios::dec`, `ios::hex`, `ios::oct`|
|`ios::floatfield`|`ios::scientific`, `ios::fixed`|
|`ios::adjustfield`|`ios::left`, `ios::right`, `ios::internal`|

---

## 🔹 例子

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 255;
    double pi = 3.1415926;

    cout.setf(ios::hex, ios::basefield);   // 十六进制
    cout.setf(ios::showbase);              // 显示前缀
    cout.setf(ios::uppercase);             // 大写
    cout << n << endl;                     // 0XFF

    cout.setf(ios::fixed, ios::floatfield); // 定点小数
    cout.precision(3);                     // 保留3位小数
    cout << pi << endl;                    // 3.142
}
```

