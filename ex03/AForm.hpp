#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm( void );
		AForm( std::string, short, short);
		AForm( AForm const & src );
		virtual ~AForm( void );

		AForm &			operator=( AForm const & rhs );

		std::string		getName( void ) const;
		bool			getSigned( void ) const;
		short			getSignGrade( void ) const;
		short			getExecGrade( void ) const;

		void			checkSignGrade( void ) const;
		void			checkExecGrade( void ) const;
		void			checkExecution(  Bureaucrat const & executor ) const;
		void			beSigned( Bureaucrat & b );
		virtual void	execute( Bureaucrat const & executor ) const = 0;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm : Grade too high exception");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm : Grade too low exception");
				}
		};

		class	AlreadySignException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm : already signed exception");
				}
		};

		class	NotSignException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm : not signed exception");
				}
		};

	private:
		std::string const	_name;
		bool				_signed;
		short const			_signGrade;
		short const			_execGrade;
};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */