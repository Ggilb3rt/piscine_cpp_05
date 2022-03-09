#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("AForm from another dimension"), _signed(false),
				_signGrade(150), _execGrade(150)
{
	 return ;
}

AForm::AForm(std::string name, short signGrade, short execGrade) :
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

AForm::AForm( const AForm & src ) : _name(src.getName()), _signed(src.getSigned()),
				_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm : " << i.getName() << std::endl << "Status : ";
	i.getSigned() ? o << "Signed" : o << "Unsigned";
	o << std::endl << "Min grade to sign : " << i.getSignGrade() << std::endl
	<< "Min grade to execute : " << i.getExecGrade() << std::endl;
	return o;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string				AForm::getName( void ) const
{
	return this->_name;
}

bool					AForm::getSigned( void ) const
{
	return this->_signed;
}

short					AForm::getSignGrade( void ) const
{
	return this->_signGrade;
}

short					AForm::getExecGrade( void ) const
{
	return this->_execGrade;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					AForm::checkSignGrade( void ) const
{
	if (this->getSignGrade() > MIN_GRADE)
		throw AForm::GradeTooLowException();
	if (this->getSignGrade() < MAX_GRADE)
		throw AForm::GradeTooHighException();
	return ;
}

void					AForm::checkExecGrade( void ) const
{
	if (this->getExecGrade() > MIN_GRADE)
		throw AForm::GradeTooLowException();
	if (this->getExecGrade() < MAX_GRADE)
		throw AForm::GradeTooHighException();
	return ;
}

void					AForm::checkExecution( Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignException();
	if (executor.getGrade() >= this->getExecGrade())
		throw AForm::GradeTooLowException();
	return ;
}

void					AForm::beSigned( Bureaucrat & b)
{
	if (this->getSigned())
		throw AForm::AlreadySignException();
	else if (b.getGrade() <= this->getSignGrade())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
	return ;
}

/* ************************************************************************** */