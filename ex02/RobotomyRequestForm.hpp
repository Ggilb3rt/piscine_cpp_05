#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

#define ROBOTOMY_SIGNE 72
#define ROBOTOMY_EXEC 45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm();

		std::string		getTarget( void ) const;

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void	execute( Bureaucrat const & executor) const;

	private:
		std::string		_target;
};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */