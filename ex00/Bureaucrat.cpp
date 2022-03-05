#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat( void ) : _name("Prrrrt"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( std::string const name ) : _name(name), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( std::string const name, short grade ) : _name(name), _grade(grade)
{
	try
	{
		this->checkGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName()), _grade(src.getGrade())
{
	try
	{
		this->checkGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat( void )
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string				Bureaucrat::getName( void ) const 
{
	return this->_name;
}

short					Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void					Bureaucrat::checkGrade( void )
{
	if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

void					Bureaucrat::promotion( void )
{
	try
	{
		this->_grade--;
		this->checkGrade();
		std::cout << this->getName() << " is promoted from grade " << (this->getGrade() + 1)
			<< " to grade " << this->getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		this->_grade++;
		std::cerr << this->getName() << " can't be promoted : " <<  e.what() << '\n';
	}
}


void					Bureaucrat::retrograde( void )
{
	try
	{
		this->_grade++;
		this->checkGrade();
		std::cout << this->getName() << " is retrograded from grade " << (this->getGrade() - 1)
			<< " to grade " << this->getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		this->_grade--;
		std::cerr << this->getName() << " can't be retrograded : " <<  e.what() << '\n';
	}
}

/* ************************************************************************** */