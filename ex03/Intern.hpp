#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

#define QT_FORMS 3

class Intern
{
	public:
		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm*			makeForm(std::string formName, std::string formTarget);
	
		class	InternException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Intern makes an error...");
				}
		};

};

#endif /* ********************************************************** INTERN_H */