/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:34:56 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 15:37:53 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("Default") {
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	std::cout << "ShrubberyCreationForm assignment operator" << std::endl;
	(void)src;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << this->getName() << " destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("Shrubbery Creation Form", 145, 137), _target(name) {
	std::cout << "ShrubberyCreationForm " << this->getName() << " constructor" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & src) const {
	execCheck(src);
	std::ofstream outfile ((_target + "_shrubbery").c_str(), std::ios::app);
	outfile <<"\
     ccee88oo                  ccee88oo\n\
  C8O8O8Q8PoOb o8oo         C8O8O8Q8PoOb o8oo\n\
 dOB69QO8PdUOpugoO9bD      dOB69QO8PdUOpugoO9bD\n\
CgggbU8OU qOp qOdoUOdcb   CgggbU8OU qOp qOdoUOdcb\n\
    6OuU  /p u gcoUodpP       6OuU  /p u gcoUodpP\n\
      \\\\\\//  /douUP             \\\\\\//  /douUP\n\
        \\\\\\////                   \\\\\\////\n\
         |||/\\                    |||/\\\n\
         |||\\/                    |||\\/\n\
         |||||                    |||||\n\
........//||||\\..................//||||\\"<< std::endl;
	outfile.close();
}