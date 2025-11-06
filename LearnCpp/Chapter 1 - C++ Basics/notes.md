- [1 - C++ 基础](#1---c-基础)
  - [1.1 - 程序结构和语法](#11---程序结构和语法)
  - [1.2 - 注释](#12---注释)
    - [单行注释](#单行注释)
    - [多行注释](#多行注释)
  - [1.3 - 对象和变量](#13---对象和变量)
    - [定义多个变量](#定义多个变量)
  - [1.4 - 变量赋值和初始化](#14---变量赋值和初始化)
    - [初始化](#初始化)
      - [默认初始化](#默认初始化)
      - [直接初始化](#直接初始化)
      - [括号初始化](#括号初始化)
      - [值初始化和零初始化](#值初始化和零初始化)
    - [初始化多个变量](#初始化多个变量)
  - [1.5 - iostream 简介：cout，cin 和 endl](#15---iostream-简介coutcin-和-endl)
    - [输入输出库](#输入输出库)
    - [std::cout](#stdcout)
    - [std::endl](#stdendl)
    - [std::cin](#stdcin)
  - [1.6 - 未初始化变量和未定义行为](#16---未初始化变量和未定义行为)
  - [1.7 - 关键字和标识符](#17---关键字和标识符)
  - [1.8 - 空白符和基本排版](#18---空白符和基本排版)
  - [1.9 - 字面量和操作符](#19---字面量和操作符)
  - [1.10 - 表达式简介](#110---表达式简介)
  - [1.11 - 开发你的第一个程序](#111---开发你的第一个程序)


# 1 - C++ 基础

## 1.1 - 程序结构和语法

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World" << '\n';
    return 0;
}
```

## 1.2 - 注释

### 单行注释

如果注释不长，就放在右边，否则单独放在所注释的行的上面

```cpp
#include <iostream>

int main() {
    std::cout << "Hello world!\n";                 // std::cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n"; // this is much easier to read
    std::cout << "Yeah!\n";                        // don't you think so?

    // std::cout lives in the iostream library
    std::cout << "Hello world!\n";
    
    // this is much easier to read
    std::cout << "It is very nice to meet you!\n";
    
    // don't you think so?
    std::cout << "Yeah!\n";
    
    return 0;                                
}
```

### 多行注释

可以通过增加 `*` 美化注释

```cpp
    /* This is a multi-line comment.
    * the matching asterisks to the left
    * can make this easier to read
    */
```

## 1.3 - 对象和变量

### 定义多个变量

```cpp
int a, int b; // wrong (compiler error)
 
int a, b;     // correct
```

```cpp
int a, double b; // wrong (compiler error)
 
int a; double b; // correct (but not recommended)
 
// correct and recommended (easier to read)
int a;
double b;
```

## 1.4 - 变量赋值和初始化

### 初始化

```cpp
int a;       // 无初始化值
int b = 5;   // 在等号后放置初始化值
int c(6);    // 在括号中放置初始化值
int d{7};    // 在花括号中放置初始化值
```

#### 默认初始化

`int a`：在大多数情况下默认初始化会导致变量存放一个不确定的值

#### 直接初始化

`int b = 5`: 对于复杂类型的数据，直接初始化相较于拷贝初始化更加高效

#### 括号初始化

括号初始化有三种形式

```cpp
int width{5};    // 直接括号初始化（推荐）
int height = {6}; // 拷贝括号初始化
int depth{};       // 值初始化
```

使用括号初始化的一个额外的优点是 `括号初始化不允许隐式缩窄转化` 的发生。例如：

```cpp
#include <iostream>

int main() {
    // narrowing conversion of '3.1400000000000001e+0' from 'double' to 'int' [-Wnarrowing]
    int a {3.14}; 
    return 0;                                
}
```

#### 值初始化和零初始化

```cpp
#include <iostream>

int main() {
    int sum{0};
    int n{}; 
    std::cin >> n;
    for (int i = 1; i <= n; ++i) sum += i;
    std::cout << sum << '\n';
    return 0;                                
}
```

### 初始化多个变量

```cpp
int a = 5, b = 6; // copy initialization
int c(7), d(8); // direct initialization
int e{9}, f{10}; // brace initialization (preferred)
```
## 1.5 - iostream 简介：cout，cin 和 endl

### 输入输出库

`iostream` 中的 io 指代的是输入输出 `input/output`

### std::cout

`cout` 代表的含义就是字符输出 `character output`

### std::endl

`endl` 表示的是结束该行 `end line`。它的执行效率稍微有点低，因为它通常需要完成两件事：将光标移动到下一行，然后确保输出结果马上显示在屏幕上（称为刷新输出）。但是使用 `\n` 一般而言是更好的选择。因为只会把光标移动到下一行而不会请求刷新  

### std::cin

`cin` 代表 `character input`

## 1.6 - 未初始化变量和未定义行为

## 1.7 - 关键字和标识符

## 1.8 - 空白符和基本排版

```cpp
#include <iostream>

int main() {
    // 两个相邻的字符串常量会在编译阶段自动拼接成一个完整的字符串
    std::cout << "Hello "
    "World" << '\n';
    return 0;                                
}
```

## 1.9 - 字面量和操作符

字面量的值是固定的，不能被修改

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World!";
    int x{5};
    return 0;                                
}
```

## 1.10 - 表达式简介

## 1.11 - 开发你的第一个程序

```cpp
#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;
    std::cout << "Double that number is: " << num * 2 << '\n';
    return 0;                                
}
```