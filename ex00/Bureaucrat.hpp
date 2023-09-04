/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:46:32 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/04 12:10:52 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		//canon
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat(std::string name, unsigned int grade);
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			increment();
		void			decrement();

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

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &src);

#endif