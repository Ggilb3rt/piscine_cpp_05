#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

#define SHRUBBERY_SIGN 145
#define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm();

		std::string		getTarget( void ) const;

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		void	execute( Bureaucrat const & executor) const;

	private:
		ShrubberyCreationForm();
		std::string		_target;
};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ********************************************* ShrubberyCreationForm_H */