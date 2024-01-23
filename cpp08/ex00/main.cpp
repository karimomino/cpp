#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    int valueToFind = 3;

    std::cout << "Testing with vector:" << std::endl;
    easyfind(vec, valueToFind);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    valueToFind = 25;

    std::cout << "Testing easyfind with list:" << std::endl;
    easyfind(lst, valueToFind);


    return 0;
}