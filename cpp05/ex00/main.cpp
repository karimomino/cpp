#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat("some politician", 33);

        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}