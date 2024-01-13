#include "AForm.hpp"

AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if ( gradeToSign < 1 || gradeToExecute < 1 )
        throw AForm::GradeTooHighException();
    if ( gradeToSign > 150 || gradeToExecute > 150 )
        throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

AForm::~AForm() {}

AForm&   AForm::operator=( const AForm& rhs ) {
    if ( this != &rhs )
        _signed = rhs.getSigned();
    return *this;
}

std::string AForm::getName() const {
    return _name;
}

bool   AForm::getSigned() const {
    return _signed;
}

int   AForm::getGradeToSign() const {
    return _gradeToSign;
}

int   AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign ) {
        throw AForm::GradeTooLowException();
    }
    _signed = true;
}

const char *        AForm::GradeTooLowException::what( void ) const throw() {
    return ( "Error: Grade Too Low" );
}

const char * AForm::GradeTooHighException::what( void ) const throw() {
    return ( "Error: Grade Too High" );
}

const char * AForm::NotSignedException::what( void ) const throw() {
    return ( "Error: AForm not signed" );
}

std::ostream&   operator<<( std::ostream &o, const AForm& rhs ) {
    o << "------------- AForm Info -------------" << std::endl;
    o << "AForm name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;;
    return o;
}