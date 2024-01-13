#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    try {
        Bureaucrat bureaucrat("Some Politician",11);
        Form form("Refund Form 1", 0);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("Some Politician",11);
        Form form("Refund Form 2", 10);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("Some Politician",11);
        Form form("Refund Form 3", 12);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}