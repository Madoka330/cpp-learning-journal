#include <iostream>

int add(int x, int y);

int main() {
    int x{}, y{}; 
    std::cin >> x >> y;
    std::cout << x << " + " << y << " = " << add(x, y) << '\n';
    return 0;
}
