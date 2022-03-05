#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form( void );
		Form( std::string, short, short);
		Form( Form const & src );
		~Form( void );

		Form &			operator=( Form const & rhs );

		std::string		getName( void ) const;
		bool			getSigned( void ) const;
		short			getSignGrade( void ) const;
		short			getExecGrade( void ) const;

		void			checkSignGrade( void ) const;
		void			checkExecGrade( void ) const;
		void			beSigned( Bureaucrat & b);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form : Grade too high exception");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form : Grade too low exception");
				}
		};

		class	AlreadySignException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form : already signed exception");
				}
		};

	private:
		std::string const	_name;
		bool				_signed;
		short const			_signGrade;
		short const			_execGrade;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */