#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestFormTest", ROBOTOMY_SIGNE, ROBOTOMY_EXEC), _target("Test robot")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
			AForm("RobotomyRequestFormCopy-" + src.getTarget(), ROBOTOMY_SIGNE, ROBOTOMY_EXEC), _target(src.getTarget())
{
	*this = src;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
			AForm("RobotomyRequestForm-" + target, ROBOTOMY_SIGNE, ROBOTOMY_EXEC), _target(target)
{
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "RobotomyRequestForm : " << i.getTarget();
	return o;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string			RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->checkExecution(executor);
	}
	catch(const std::exception& e)
	{
		throw	e.what();
	}
	std::srand(time(NULL));
	std::cout << "[Drill noises]" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << "Robotomy on " << this->getTarget() << " worked !" << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " failed !" << std::endl;
}


/* ************************************************************************** */