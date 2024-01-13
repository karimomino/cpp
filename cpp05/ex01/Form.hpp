#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const short         _gradeToSign;
    const short         _gradeToExecute;


public:
    Form( void );
    Form( const std::string& name, short gradeToSign );
    Form( const std::string& name, short gradeToSign, short gradeToExecute );
    Form( const Form& src );
    ~Form();

    Form&   operator=( const Form& rhs );

    std::string getName() const;
    bool        getSigned() const;
    short         getGradeToSign() const;
    short         getGradeToExecute() const;

    void        beSigned( const Bureaucrat& bureaucrat );

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif