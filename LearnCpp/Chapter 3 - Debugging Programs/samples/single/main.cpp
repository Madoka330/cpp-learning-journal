#include <iostream>

int cnt = 0;

int func(int n) {  
    if (n == 0) return 1;
    cnt++;
    return func(n - 1) * n;
}

int main() {

    std::cout << func(10) << '\n';
    return 0;
}