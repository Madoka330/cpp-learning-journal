# 7 - 作用域、生命周期和链接

---

## 7.1 - 复合语句（语句块）

---

## 7.2 - 用户定义命名空间和作用域解析运算符

---

### 自定义命名空间

```cpp
#include <iostream>
 
namespace foo { // define a namespace named foo

    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y) {
        return x + y;
    }
}
 
namespace goo {// define a namespace named goo

    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y) {
        return x - y;
    }
}
 
int main() {
    std::cout << foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace foo
    std::cout << goo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace goo
    return 0;
}
```

### 命名空间定义为多个块

将命名空间的声明分为多个部分放在不同的位置是合法的。所有这些申明都被认为是对应命名空间声明的一部分

`circle.h`

```cpp
#ifndef CIRCLE_H
#define CIRCLE_H

namespace basicMath {
    constexpr double pi{3.14};
}

#endif 
```

`growth.h`

```cpp
#ifndef GROWTH_H
#define GROWTH_H
 
namespace basicMath {
    constexpr double e{2.7};
}
 
#endif
```

`main.cpp`

