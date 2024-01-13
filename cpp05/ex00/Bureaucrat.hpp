#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string   _name;
    short               _grade;

public:
    Bureaucrat( void );
    Bureaucrat( const std::string& name, short grade );
    Bureaucrat( const Bureaucrat& src );
    ~Bureaucrat();

    Bureaucrat& operator=( const Bureaucrat& rhs );

    std::string getName() const;
    short       getGrade() const;

    void        incrementGrade();
    void        decrementGrade();

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif