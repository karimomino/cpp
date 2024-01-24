#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <sstream>



int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "Error: No arguments provided.\n";
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		int num;
		if (!(ss >> num) || !ss.eof()) {
			std::cout << "Error: Invalid sequence.\n";
			return 1;
		}
		if (num < 0) {
			std::cout << "Error: Negative numbers are not allowed.\n";
			return 1;
		}
		vec.push_back(num);
		deq.push_back(num);
	}

	std::cout << "Original vector: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
	std::cout << std::endl;

	double time_vector = PmergeMe::sort(vec);

	std::cout << "Sorted vector: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Original deque: ";
    for (size_t i = 0; i < deq.size(); ++i)
    {
        std::cout << deq[i] << " ";
    }
	std::cout << std::endl;

	double time_deque = PmergeMe::sort(deq);

	std::cout << "Sorted deque: ";
    for (size_t i = 0; i < deq.size(); ++i)
    {
        std::cout << deq[i] << " ";
    }
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Sorted vector[" << vec.size() << "] in: " << time_vector << " us" << std::endl;
	std::cout << "Sorted deque[" << deq.size() << "] in: " << time_deque << " us" << std::endl;
	return 0;
}