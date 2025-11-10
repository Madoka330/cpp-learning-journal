# 5 - 常量与字符串

## 4.14 - 编译时常量、常量表达式和 constexpr

> 本文章内容会被拆分至以下文章
> - 5.4
> - 5.5
> - 5.6

### 常量表达式

常量表达式是可以由编译器在编译时求值的表达式。要成为常量表达式，表达式中的所有值必须在编译时已知。例如，下面代码会被编译器优化

```cpp
#include <iostream>

int main() {
    std::cout << 3 + 4 << '\n';
    return 0;
}
```

```cpp
#include <iostream>

int main() {
    std::cout << 7 << '\n';
    return 0;
}
```

### 编译时常数

编译时常数是一个在编译时其值已知的常数。字面量（`1`、`2.3`、`Hello World`）是一种编译时常数

#### 编译时常量 - const

如果 `const` 变量的初始化表达值就是常量表达式，那么它就是编译时常量

```cpp
#include <iostream>
 
int main() {
    const int x {3};  // x 是编译时常量
    const int y {4};  // y 是编译时常量
 
    std::cout << x + y; // x + y 是编译时常量
 
    return 0;
}
```

#### 运行时常量 - const

任何用非常量表达式初始化的 `const` 变量都是运行时常量。运行时常量是在运行时才知道其初始化值的常量

```cpp
#include <iostream>
 
int getNumber() {
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;
 
    return y;
}
 
int main() {
    const int x{3};             // x is a compile time constant
    std::cout << "Enter a number: ";
    const int y{getNumber()};   // y is a runtime constant
    std::cout << x + y;         // x + y is a runtime expression
    return 0;
}
```

#### `constexpr` 关键字

当声明 `const` 变量时，编译器将隐式跟踪它是运行时常量还是编译时常量。我们可以使用 `constexpr`，如果 `constexpr` 变量的初始值不是常量表达式，编译器将会出错

```cpp
#include <iostream>
 
int main() {
    constexpr double gravity {9.8}; // ok: 9.8 is a constant expression
    constexpr int sum {4 + 5};      // ok: 4 + 5 is a constant expression
    constexpr int something {sum};  // ok: sum is a constant expression
 
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;
 
    constexpr int myAge {age};      // compile error: age is not a constant expression
 
    return 0;
}
```

## 5.1 - const 变量和符号常量

在编程中，常量（constant）指的是不会改变的值

### const 关键字

const 变量必须在定义时初始化，以后你也不能通过赋值来改变它

### const 函数形参

在按值传递的时候不要使用 `const`，因为它无论如何都会在函数结束的时候销毁

### const 类型返回值

由于返回值只是一个副本，所以不要使用 `const` 类型的返回值

## 5.2 - 字面量

## 5.3 - 数值系统（十进制、二进制、十六进制和八进制）

### 八进制和十六进制字面量

```cpp
#include <iostream>

int main() {
    // 八进制字面量，用 0 当作前缀
    std::cout << 012 << '\n';    // 10
    std::cout << 022 << '\n';    // 18
    std::cout << 0100 << '\n';   // 64
    return 0;
}
```

```cpp
#include <iostream>

int main() {
    // 十六进制字面量，用 0x 当作前缀
    std::cout << 0xff << '\n';     // 255
    std::cout << 0x100 << '\n';    // 256
    std::cout << 0x2b << '\n';     // 43
    return 0;
}
```

### 二进制字面量

可以使用 `'` 来当作分隔符

```cpp
#include <iostream>

int main() {
    // 二进制字面量，用 0b 当作前缀
    std::cout << 0b1111'1111 << '\n';  // 255
    std::cout << 0b1010 << '\n';       // 10
    std::cout << 0b0001 << '\n';       // 1
    return 0;
}
```

### 十进制、八进制、十六进制打印

```cpp
#include <iostream>
 
int main() {
    int x {12};
    std::cout << x << '\n';             // 12 decimal (by default) 
    std::cout << std::hex << x << '\n'; // c  hexadecimal
    std::cout << x << '\n';             // c  now hexadecimal
    std::cout << std::oct << x << '\n'; // 14 octal
    std::cout << std::dec << x << '\n'; // 12 return to decimal
    std::cout << x << '\n';             // 12 decimal
 
    return 0;
}
```

### 二进制打印

使用 `bitset`，传入的位数必须是一个编译时常量

```cpp
#include <bitset> // for std::bitset
#include <iostream>
 
int main() {
	// std::bitset<8> 表示要存储8个位
	std::bitset<8> bin1{0b1100'0101};            // binary literal for binary 1100 0101
	std::bitset<8> bin2{0xC5};                   // hexadecimal literal for binary 1100 0101
 
	std::cout << bin1 << ' ' << bin2 << '\n';    // 11000101 11000101
	std::cout << std::bitset<4>{0b1010} << '\n'; // 1010 create a temporary std::bitset and print it
 
	return 0;
}
```

## 5.7 - std::string 简介

### std::ws

运行下面代码，`getline()` 什么都读不到

```cpp
#include <string>
#include <iostream>
 
int main() {
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;
 
    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin, name); // 注意：没有使用 std::ws 
 
    std::cout << "Hello, " << name << ", you picked " << choice << '\n';
 
    return 0;
}
```

我们可以使用 `std::ws` 来修改该程序，这样 `std::getline()` 就会忽略任何前置的空白字符

```cpp
#include <string>
#include <iostream>
 
int main() {
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;
 
    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // note: added std::ws here
 
    std::cout << "Hello, " << name << ", you picked " << choice << '\n';
 
    return 0;
}
```

`std::ws` 只对当前输入起效

```cpp
#include <string>
#include <iostream>
 
int main() {
    std::string str, line1, line2;
    std::cin >> str;
    // ws 的修改只修改当前输入，不是全局修改
    std::getline(std::cin >> std::ws, line1);
    std::getline(std::cin, line2);

    std::cout << str << '\n';
    std::cout << line1 << '\n';
    std::cout << line2 << '\n';
    return 0;
}
```

### 字符串长度

在 `C++ 20` 中可以使用 `std::ssize()` 返回 `long long` 类型的字符串长度

```cpp
#include <string>
#include <iostream>
 
int main() {

    std::string str{"yuri"};
    std::cout << std::ssize(str) - 5 << '\n';  // -1
    std::cout << str.size() - 5 << '\n';       // 18446744073709551615

    return 0;
}
```

## 5.8 - std::string_view 简介

使用 `std::string_view` 替换 `std::string`。只读，无需创建副本

```cpp
#include <iostream>
#include <string>
#include <string_view>
 
// now a std::string_view 
void printSV(std::string_view str) {
    std::cout << str << '\n';
}
 
int main() {
    std::string_view s{"Hello, world!"}; // now a std::string_view
    printSV(s);
    return 0;
}
```

### constexpr

#include <iostream>
#include <string_view>

和` std::string` 不同的是，`std:: string_view` 完全支持 `constexpr`

```cpp
int main() {
    constexpr std::string_view s{ "Hello, world!" };
    std::cout << s << '\n'; // s 会在编译时被替换为 "Hello, world!" 
 
    return 0;
}
```

## 5.9 - std::string_view 第二部分

### `std::string_view`

`std::string_view` 不仅快，还有 `std::string` 的大部分功能

```cpp
#include <iostream>
#include <string_view>
 
int main() {
    std::string_view str{ "Trains are fast!" };
    
    std::cout << str.length() << '\n';                 // 16
    std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
    std::cout << (str == "Trains are fast!") << '\n';  // 1
    
    // Since C++20
    std::cout << str.starts_with("Boats") << '\n';     // 0
    std::cout << str.ends_with("fast!") << '\n';       // 1
    
    std::cout << str << '\n'; // Trains are fast!
    
    return 0;
}
```

`std::string_view` 并不会创建一个字符串的副本，当我们修改 `std::string_view` 的时候，被观察的字符串也会被修改

```cpp
#include <iostream>
#include <string_view>
 
int main() {
    char arr[]{"Gold"};
    std::string_view str{arr};
    
    std::cout << str << '\n'; // Gold
    
    // Change 'd' to 'f' in arr
    arr[3] = 'f';
    
    std::cout << str << '\n'; // Golf
    
    return 0;
}
```

### 视图修改函数

`remove_prefix`：从视图的左侧删除字符
`remove_suffix`：从视图的右侧删除字符

```cpp
#include <iostream>
#include <string_view>
 
int main() {
    std::string_view str{"Peach"};
    std::cout << str << '\n';
    
    // Ignore the first character.
    str.remove_prefix(1);      // each
    
    std::cout << str << '\n';
    
    // Ignore the last 2 characters.
    str.remove_suffix(2);      // ea
    
    std::cout << str << '\n';
    
    return 0;
}
```

### `std::string_view` 可以配合没有结束符的字符串

`C` 风格的字符串和 `std::string` 不同，`std::string_view` 不使用空结束符来标记字符串的结束。相反，它知道字符串在哪里结束，因为它会跟踪字符串的长度

```cpp
#include <iostream>
#include <iterator> // For std::size
#include <string_view>
 
int main() {
    // No null-terminator.
    char vowels[]{ 'a', 'e', 'i', 'o', 'u' };
    
    // vowels 并没有包含结束符，我们需要传递长度
    // 因为 vowels 是数组，我们可以使用 std::size 来获取长度
    std::string_view str{vowels, std::size(vowels)};
    
    std::cout << str << '\n'; // 这是安全的。std::cout 知道如何打印 std::string_view.
    
    return 0;
}
```

### 通过 `const std::string&` 还是 `std::string_view` 来传递字符串?

优先使用 `std::string_view`（按值传递）而不是 `const std::string&`，除非你需要调用其他要求使用 `C` 风格字符串或 `std::string` 的函数

### 生命周期

`std::string_view` 自身不能创建任何的字符串，它只是观察某个字符串的视图。下面就是一个例子

```cpp
#include <iostream>
#include <string>
#include <string_view>
 
std::string_view askForName() {
    std::cout << "What's your name?\n";
    
    // Use a std::string, because std::cin needs to modify it.
    std::string name{};
    std::cin >> name;
    
    // We're switching to std::string_view for demonstrative purposes only.
    // If you already have a std::string, there's no reason to switch to
    // a std::string_view.
    std::string_view view{ name };
    
    std::cout << "Hello " << view << '\n';
    
    return view;
} // name 变量被销毁，对应的字符串也销毁了
 
int main() {
    std::string_view view{ askForName() };
    
    // view 正在为一个不存在的字符串提供视图
    std::cout << "Your name is " << view << '\n'; // 未定义行为
    return 0;
}
```

确保 `std::string_view` 观察的字符串不会离开作用域，也不会被修改




