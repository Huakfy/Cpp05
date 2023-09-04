/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:32:56 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/04 16:52:55 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
# define FORM

# include <string>
# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_sGrade;
		const unsigned int	_xGrade;
	public:
		//canon
		Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		Form(std::string name, unsigned int sGrade, unsigned int xGrade);
		std::string		getName() const;
		bool			getSigned() const;
		unsigned int	getSGrade() const;
		unsigned int	getXGrade() const;
		void			beSigned(const Bureaucrat &src);

		class GradeTooHighException : public std::exception {
			virtual const char *what() const throw() {
				return "Grade too high";
			}
		};

		class GradeTooLowException : public std::exception {
			virtual const char *what() const throw() {
				return "Grade too low";
			}
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &src);

#endif