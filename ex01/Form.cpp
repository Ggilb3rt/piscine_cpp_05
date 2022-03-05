#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Form from another dimension"), _signed(false),
				_signGrade(150), _execGrade(150)
{
	 return ;
}

Form::Form(std::string name, short signGrade, short execGrade) :
			_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	try
	{
		this->checkSignGrade();
		this->checkExecGrade();
	}
	catch( std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

Form::Form( const Form & src ) : _name(src.getName()), _signed(src.getSigned()),
				_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form : " << i.getName() << std::endl << "Status : ";
	i.getSigned() ? o << "Signed" : o << "Unsigned";
	o << std::endl << "Min grade to sign : " << i.getSignGrade() << std::endl
	<< "Min grade to execute : " << i.getExecGrade() << std::endl;
	return o;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string				Form::getName( void ) const
{
	return this->_name;
}

bool					Form::getSigned( void ) const
{
	return this->_signed;
}

short					Form::getSignGrade( void ) const
{
	return this->_signGrade;
}

short					Form::getExecGrade( void ) const
{
	return this->_execGrade;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					Form::checkSignGrade( void ) const
{
	if (this->getSignGrade() > MIN_GRADE)
		throw Form::GradeTooLowException();
	if (this->getSignGrade() < MAX_GRADE)
		throw Form::GradeTooHighException();
	return ;
}

void					Form::checkExecGrade( void ) const
{
	if (this->getExecGrade() > MIN_GRADE)
		throw Form::GradeTooLowException();
	if (this->getExecGrade() < MAX_GRADE)
		throw Form::GradeTooHighException();
	return ;
}

void					Form::beSigned( Bureaucrat & b)
{
	if (this->getSigned())
		throw Form::AlreadySignException();
	else if (b.getGrade() <= this->getSignGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
	return ;
}

/* ************************************************************************** */