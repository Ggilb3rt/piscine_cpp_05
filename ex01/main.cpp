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
	//? Si j'utilise beSigned ici les throw ne sont pas catch ==> erreur
	//? mais si je catch dans beSigned, signForm ne catch plus rien...
	// std::cout << "lp se fait signer par dd (erreur attendu)" << std::endl;
	// lp.beSigned(dd);
	std::cout << std::endl << "dd sign lp (erreur attendu)" << std::endl;
	dd.signForm(lp);
	std::cout << std::endl << lp << std::endl;
	
	std::cout << "Hermes sign lp" << std::endl;
	hermes.signForm(lp);
	std::cout << lp << std::endl;
	hermes.signForm(lp);
	return 0;
}