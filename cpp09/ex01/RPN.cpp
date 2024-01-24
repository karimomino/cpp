#include "RPN.hpp"

std::stack<int , std::list<int> > RPN::_stack;
std::pair<unsigned char , op_fn> RPN::_operations[] = {
    std::make_pair('+', &RPN::sum),
    std::make_pair('-', &RPN::subtract),
    std::make_pair('*', &RPN::multiply),
    std::make_pair('/', &RPN::divide)
};

static int chartoi(const char & num) {
	return (num - '0');
}

int RPN::calculate(const std::string &line)
{
	if (line.empty()) {
		return 0;
	}
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it) {
		if (std::isspace(*it))
			continue;
		else if (std::isdigit(*it))
			_stack.push( chartoi( *it ) );
		else
			do_op(static_cast<unsigned char>(*it));
	}
	if (_stack.size() > 1)
		throw::std::runtime_error("Error: Invalid Number of opperands");
	int ret = _stack.top();
	while (!_stack.empty()) {
        _stack.pop();
    }
	return ret;
}

void RPN::do_op(unsigned char symbol)
{
	for (int i = 0; i < 4; ++i) {
		if (_operations[i].first == symbol) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Invalid Expression.");
			int rhs = _stack.top();
			_stack.pop();
			int lhs = _stack.top();
			_stack.pop();
			int res = (_operations[i].second)(lhs, rhs);
			_stack.push(res);
			return;
		}
	}
	throw std::runtime_error("Error: Usage of unsupported operation");
}

int RPN::sum(const int &lhs, const int &rhs)
{
	return lhs + rhs;
}
int RPN::subtract(const int &lhs, const int &rhs)
{
	return lhs - rhs;
}
int RPN::multiply(const int &lhs, const int &rhs)
{
	return lhs * rhs;
}
int RPN::divide(const int &lhs, const int &rhs)
{
	if (rhs == 0)
		throw std::runtime_error("Tried to divide by 0");
	return lhs / rhs;
}
