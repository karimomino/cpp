#include "MutantStack.hpp"

int main() {
    MutantStack<int> mutantStack;
    MutantStack<int> emptyMutantStack;

    mutantStack.push(10);
    mutantStack.push(20);
    mutantStack.push(30);

    std::cout << "------------------------- Iterator test Begin -------------------------" << std::endl;;
    std::cout << "Elements in MutantStack using iterators: ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements in MutantStack using const iterators: ";
    for (MutantStack<int>::const_iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------- Iterator test End -------------------------" << std::endl;;

    std::cout << std::endl;

    std::cout << "------------------------- Functionality test Begin -------------------------" << std::endl;;
    std::cout << "Top element: " << mutantStack.top() << std::endl;
    mutantStack.pop();
    std::cout << "After pop(), top element: " << mutantStack.top() << std::endl;

    std::cout << "Is MutantStack empty: " << (mutantStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "MutantStack size: " << mutantStack.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Is EmptyMutantStack empty: " << (emptyMutantStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "EmptyMutantStack size: " << emptyMutantStack.size() << std::endl;

    mutantStack.push(40);
    mutantStack.push(50);

    std::cout << "Updated elements in MutantStack using iterators: ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------- Functionality test End -------------------------" << std::endl;;

    return 0;
}