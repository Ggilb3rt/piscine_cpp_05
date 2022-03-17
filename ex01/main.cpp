#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {

	Bureaucrat	hermes("Hermes", 52);
	Bureaucrat	dd("dd", 1234);
	Form		basic;

	std::cout << basic << std::endl;
	basic.beSigned(hermes);
	std::cout << basic << std::endl;


	std::cout << "------------------------" << std::endl << std::endl;


	Form		lp("Laissez passer A38", 100, 90);

	std::cout << lp << std::endl;
	try
	{
		lp.beSigned(dd);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "dd try to sign lp (erreur attendu)" << std::endl;
	dd.signForm(lp);
	std::cout << std::endl << lp << std::endl;
	
	std::cout << "Hermes try to sign lp" << std::endl;
	hermes.signForm(lp);
	std::cout << lp << std::endl;
	hermes.signForm(lp);
	return 0;
}