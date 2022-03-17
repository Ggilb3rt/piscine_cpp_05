#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target("Test")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
			AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(src.getTarget())
{
	*this = src;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
			AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(target)
{
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "ShrubberyCreationForm : " << i.getTarget();
	return o;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string			ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->checkExecution(executor);
	}
	catch(const std::exception& e)
	{
		throw	e.what();
	}
	std::string		output_name = this->getTarget() + "_shrubbery";
	std::ifstream	input("seedFile");
	std::ofstream	output(output_name.c_str());

	if (input.is_open() && output.is_open())
	{
		output << input.rdbuf() << "   "
			<< this->getTarget() << " Created by " << executor.getName();
		input.close();
		output.close();
		std::cout << output_name << " created" << std::endl;
	}
	else
		std::cerr << "Error while openning file." << std::endl;
}


/* ************************************************************************** */