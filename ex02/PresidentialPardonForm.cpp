#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonFormTest", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), _target("Test robot")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
			AForm("PresidentialPardonFormCopy-" + src.getTarget(), PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), _target(src.getTarget())
{
	*this = src;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
			AForm("PresidentialPardonForm-" + target, PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), _target(target)
{
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "PresidentialPardonForm : " << i.getTarget();
	return o;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string			PresidentialPardonForm::getTarget( void ) const
{
	return this->_target;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->checkExecution(executor);
	}
	catch(const std::exception& e)
	{
		throw	e.what();
	}
	std::cout << this->getTarget() << " was forgiven by Zafod Beeblebrox." << std::endl;
}


/* ************************************************************************** */