#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat
{
	public:
		Bureaucrat( std::string const );
		Bureaucrat( std::string const, short);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string			getName( void ) const;
		short				getGrade( void ) const;

		void				checkGrade( void ) const;
		void				promotion( void );
		void				retrograde( void );
		void				signForm( Form & f );


		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Bureaucrate : Grade too high exception");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Bureaucrate : Grade too low exception");
				}
		};

	private:
		Bureaucrat( void );
		std::string const	_name;
		short				_grade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */