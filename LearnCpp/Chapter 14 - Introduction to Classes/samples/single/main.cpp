#include <iostream>
#include <string>

class Book {
public:
    std::string m_name;
    double m_price;

    void show_info() {
       std::cout << "书名：" << m_name << "，价格：" << m_price << "\n";
    }
};

int main() {
    Book book{"安达与岛村", 100};
    book.show_info();
    return 0;
}