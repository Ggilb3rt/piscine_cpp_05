#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main () {
	Bureaucrat	hermes("Hermes", 52);
	Bureaucrat	dd("Dd", 150);
	Bureaucrat	boss("Boss", 1);

	std::cout << "------- Robotomy Requests | sign 72, exec 45-------" << std::endl;
	RobotomyRequestForm	basic;
	RobotomyRequestForm	alexa("Alexa");
	RobotomyRequestForm alexaCpy(alexa);

	dd.signForm(basic);
	boss.executeForm(alexa);
	hermes.signForm(alexa);
	hermes.executeForm(alexa);
	boss.executeForm(alexa);
	boss.signForm(basic);
	boss.executeForm(basic);
	boss.executeForm(alexaCpy);

	std::cout << std::endl << std::endl << "------- Presidential Pardon | sign 25, exec 5-------" << std::endl;
	Bureaucrat					philip("Philip", 25);
	PresidentialPardonForm		pouet("Pouet");

	hermes.signForm(pouet);
	boss.executeForm(pouet);
	philip.signForm(pouet);
	philip.executeForm(pouet);
	boss.executeForm(pouet);

	std::cout << std::endl << std::endl << "------- Shrubbery Creation | sign 145, exec 137-------" << std::endl;
	Bureaucrat					knightsWhoSayNi("Knights who say Ni !", 135);
	ShrubberyCreationForm		shrubbery("Shrubbery");
	ShrubberyCreationForm		forest("Forest");

	hermes.executeForm(shrubbery);
	dd.signForm(shrubbery);
	philip.signForm(shrubbery);
	hermes.signForm(shrubbery);
	knightsWhoSayNi.executeForm(shrubbery);
	boss.signForm(forest);
	boss.executeForm(forest);

	return 0;
}