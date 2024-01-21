#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

enum d_type {
LITERAL,
INT,
DOUBLE,
FLOAT,
CHAR
};

class ScalarConverter{
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& src );
	ScalarConverter& operator=( const ScalarConverter& rhs );
	~ScalarConverter( void );
public:
	static void convert(const std::string &);
private:
};
