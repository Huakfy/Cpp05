/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:57:48 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 16:28:38 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN
# define INTERN

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		//canon
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm	*makeShrub(std::string target);
		AForm	*makeRobot(std::string target);
		AForm	*makePres(std::string target);
		AForm	*makeForm(std::string nameForm, std::string target);

		class FormNotExistException : public std::exception {
			virtual const char *what() const throw() {
				return "Form does not exist";
			}
		};
};

#endif