#include <iostream>

bool funcA() {
    std::cout << "funcA 被调用\n";
    return false;
}

bool funcB() {
    std::cout << "funcB 被调用\n";
    return true;
}

int main() {
    std::cout << "测试 &&（与）短路：\n";
    if (funcA() && funcB()) { // funcA 为 false，所以 funcB 不会被调用
        std::cout << "结果为真\n";
    } else {
        std::cout << "结果为假\n";
    }

    std::cout << "\n测试 ||（或）短路：\n";
    if (funcB() || funcA()) { // funcB 为 true，所以 funcA 不会被调用
        std::cout << "结果为真\n";
    } else {
        std::cout << "结果为假\n";
    }

    return 0;
}
