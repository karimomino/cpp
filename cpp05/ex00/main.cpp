#include "Bureaucrat.hpp"
#include <exception>

int main( void )
{
    try {
        Bureaucrat bureaucrat("some politician", 33);

        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } 

    try {
        Bureaucrat bureaucrat("some politician", 151);

        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("some politician", 0);

        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}