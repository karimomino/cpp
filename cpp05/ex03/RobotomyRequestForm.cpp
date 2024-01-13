#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=( RobotomyRequestForm& rhs ) {
    ( void )rhs;
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if ( this->getSigned() == false )
        throw AForm::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw AForm::GradeTooLowException();
    }
    else {
        
        int rand = 1 + std::rand() / ((RAND_MAX + 1u) / 2);
        if ( rand % 2 == 0 )
            std::cout << "*DRINGING NOISES* " << _target << " has been robotomized!" << std::endl;
        else
            std::cout << _target << " Robotomy failed! " << std::endl;
    }
}