#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

#define PRESIDENTIAL_SIGN 25
#define PRESIDENTIAL_EXEC 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm();

		std::string		getTarget( void ) const;

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		void	execute( Bureaucrat const & executor) const;

	private:
		PresidentialPardonForm();
		std::string		_target;
};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ********************************************* PresidentialPardonForm_H */