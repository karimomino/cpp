#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <list>
#include <iostream>


typedef int (*op_fn)(const int &, const int &);


class RPN {
public:
	static int calculate(const std::string &line);
private:
	RPN();
	~RPN();
	RPN(const RPN &rhs);
	RPN& operator=(const RPN &rhs);
	static std::pair<unsigned char , op_fn> _operations[4];
	static std::stack<int, std::list<int> > _stack;
	static void do_op(unsigned char symbol);

	static int sum(const int &lhs, const int &rhs);
	static int subtract(const int &lhs, const int &rhs);
	static int multiply(const int &lhs, const int &rhs);
	static int divide(const int &lhs, const int &rhs);
};

#endif
