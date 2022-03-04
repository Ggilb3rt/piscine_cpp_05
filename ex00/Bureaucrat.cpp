#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat( void ) : _name("Prrrrt", 150)
{
	return ;
}

Bureaucrat::Bureaucrat( std::string const name ) : _name(name), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( std::string const name, short grade ) : _name(name)
{
	try
	{
		if (grade > 150 || grade < 1)
		{
			if (grade > 150)
				throw Bureaucrat::GradeTooLowException();
			if (grade < 1)
				throw Bureaucrat::GradeTooHighException();
		}
		else
			this->_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		this->~Bureaucrat(); // marche pas...
	}
	
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName()), _grade(src.getGrade())
{
	// *this = src;
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
	{
		// this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	std::cout << this << " | " << &rhs << std::endl;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void					Bureaucrat::promotion( void )
{
	this->_grade -= 1;
	// ajouter try catch
}


void					Bureaucrat::retrograde( void )
{
	this->_grade += 1;
	// ajouter try catch
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

/* ************************************************************************** */