#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main () {

	Bureaucrat	boss("Boss", 1);
	Intern		random;
	AForm*		oneJob = NULL;

	oneJob = random.makeForm("poeut", "roger");
	// boss.signForm(*oneJob); //! make segfault because NULL pointer is pass to reference
	
	std::cout << std::endl << std::endl << "------- Presidential Pardon -------" << std::endl;
	oneJob = random.makeForm("presidential request", "Roger");
	boss.signForm(*oneJob);
	boss.executeForm(*oneJob);
	delete oneJob;

	std::cout << std::endl << std::endl << "------- Robotomy request -------" << std::endl;
	oneJob = random.makeForm("robotomy request", "Roger");
	boss.signForm(*oneJob);
	boss.executeForm(*oneJob);
	delete oneJob;

	std::cout << std::endl << std::endl << "------- Shrubbery request -------" << std::endl;
	oneJob = random.makeForm("shrubbery request", "Roger");
	boss.signForm(*oneJob);
	boss.executeForm(*oneJob);
	


	return 0;
}