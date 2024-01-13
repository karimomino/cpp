#include "Form.hpp"

Form::Form( void ) : _name( "Default Form" ), _signed( false ), _gradeToSign( 150 ), _gradeToExecute( 150 ){
}

Form::Form( const std::string& name, short gradeToSign ) : _name( name ), _signed( false ), _gradeToSign( gradeToSign ), _gradeToExecute( 0 ) {
    if ( gradeToSign < 1 )
        throw Form::GradeTooHighException();
    if ( gradeToSign > 150 )
        throw Form::GradeTooLowException();
}

Form::Form( const Form& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

Form::~Form() {}

Form&   Form::operator=( const Form& rhs ) {
    if ( this != &rhs )
        _signed = rhs.getSigned();
    return *this;
}

std::string Form::getName() const {
    return _name;
}

bool   Form::getSigned() const {
    return _signed;
}

short   Form::getGradeToSign() const {
    return _gradeToSign;
}

short   Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign )
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *        Form::GradeTooLowException::what( void ) const throw() {
    return ( "Error: Grade Too Low" );
}

const char * Form::GradeTooHighException::what( void ) const throw() {
    return ( "Error: Grade Too High" );
}

std::ostream&   operator<<( std::ostream& o, const Form& rhs ) {
    o << "\n------------- Start of Form Info -------------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute();
    o << "\n------------- End of Form Info ---------------\n" << std::endl;
    return o;
}