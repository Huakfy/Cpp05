/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:56:44 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 13:42:01 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
# define FORM

# include <string>
# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_sGrade;
		const unsigned int	_xGrade;
	public:
		//canon
		AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		AForm(std::string name, unsigned int sGrade, unsigned int xGrade);
		virtual std::string		getName() const;
		virtual bool			getSigned() const;
		virtual unsigned int	getSGrade() const;
		virtual unsigned int	getXGrade() const;
		virtual void			beSigned(const Bureaucrat &src);

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

		//ex02
		void execCheck(Bureaucrat const & executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class Unsigned : public std::exception {
			virtual const char *what() const throw() {
				return "Unsigned Form";
			}
		};
};

std::ostream	&operator<<(std::ostream &o, const AForm &src);

#endif