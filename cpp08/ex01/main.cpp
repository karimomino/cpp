#include "Span.hpp"

void testBasicOperations() {
    Span span(10);

    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);

    std::cout << "Span: " << span << std::endl;

    std::cout << "Longest span: " << span.longestSpan() << std::endl;

    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
}

void testAddingNumbers() {
    Span span(10);

    std::cout << "Adding more numbers to the Span normally..." << std::endl;
    for (int i = 20; i < 30; i++) {
        span.addNumber(i);
    }
    std::cout << "Updated Span: " << span << std::endl;
}

void testAddingList() {
    Span span(10);

    std::list<int> additionalNumbers;
    additionalNumbers.push_back(25);
    additionalNumbers.push_back(30);
    additionalNumbers.push_back(35);

    span.addNumber(additionalNumbers.begin(), additionalNumbers.end());
    std::cout << "Updated Span after adding a list: " << span << std::endl;
}

void testFullSpanException() {
    Span span(0);

    std::cout << "Attempting to add a number when the Span is full..." << std::endl;
    span.addNumber(40);
}

void testShortListSpans() {
    Span span(5);

    std::cout << "Testing shortestSpan Exception..." << std::endl;
    try {
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "Testing longetSpan Exception..." << std::endl;
    try {
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    try {
        testBasicOperations();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        testAddingNumbers();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        testAddingList();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        testFullSpanException();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    testShortListSpans();

    return 0;
}