#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	return ;
}

Intern::Intern( const Intern & src )
{
	*this = src;
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static AForm*	robotomy( std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	shrubbery( std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	presidential( std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*					Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm*		(*form[QT_FORMS])(std::string target) = {
		&presidential,
		&shrubbery,
		&robotomy
	};
	std::string	formsCmp[QT_FORMS] = {
		"presidential request",
		"shrubbery request",
		"robotomy request"
	};

	try
	{
		for (int i = 0; i < QT_FORMS; i++)
		{
			if (formName == formsCmp[i])
			{
				std::cout << "Intern create form : " << formName << std::endl;
				return form[i](formTarget);
			}
		}
		throw InternException();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return NULL;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */