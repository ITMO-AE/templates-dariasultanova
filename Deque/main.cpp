#include <iostream>
#include "deque.h"

int main()
{
    Deque<int> deque;

    deque.pushFront(50);
    deque.pushFront(33);
    deque.pushFront(14);
    deque.pushBack(25);
    deque.pushBack(47);
    deque.pushBack(61);

    try {
        std::cout << deque.at(0) << " " << deque.at(1) << " " << deque.at(2) << " "
                  << deque.at(3) << " " << deque.at(4) << " " << deque.at(5) << std::endl;
        std::cout << deque[1] << std::endl;
        std::cout << deque.front() << std::endl;
        std::cout << deque.back() << std::endl;
        std::cout << deque.empty() << std::endl;
        std::cout << deque.size() << std::endl;
        std::cout << deque[8] << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
