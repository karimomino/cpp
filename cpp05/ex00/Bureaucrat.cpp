#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default Name"), _grade(150){
}

Bureaucrat::Bureaucrat( const std::string& name, short grade ) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name(src._name), _grade(src._grade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
    if ( this != &rhs )
        _grade = rhs.getGrade();

    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

short Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::incrementGrade() {
    if ( _grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( _grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char *        Bureaucrat::GradeTooLowException::what( void ) const throw() {
    return ( "Error: Grade Too Low" );
}

const char * Bureaucrat::GradeTooHighException::what( void ) const throw() {
    return ( "Error: Grade Too High" );
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
