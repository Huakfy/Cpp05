/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:14:54 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 15:37:44 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("Default") {
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	std::cout << "PresidentialPardonForm assignment operator" << std::endl;
	(void)src;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm " << this->getName() << " destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("Presidential Pardon Form", 25, 5), _target(name) {
	std::cout << "PresidentialPardonForm " << this->getName() << " constructor" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & src) const {
	execCheck(src);
	std::cout << _target << " à été pardonné(e) par Zaphod Beeblebrox" << std::endl;
}