/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:32:53 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 13:38:54 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(0), _sGrade(150), _xGrade(150) {
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _sGrade(src._sGrade), _xGrade(src._xGrade) {
	std::cout << "AForm copy constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
	std::cout << "AForm assignment operator" << std::endl;
	if (this != &src)
		_signed = src._signed;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm " << _name << " destructor" << std::endl;
}

AForm::AForm(std::string name, unsigned int sGrade, unsigned int xGrade) : _name(name), _sGrade(sGrade), _xGrade(xGrade) {
	std::cout << "AForm " << _name << " constructor" << std::endl;
	_signed = 0;
	if (_sGrade == 0 || _xGrade == 0)
		throw AForm::GradeTooHighException();
	else if (_sGrade > 150 || _xGrade > 150)
		throw AForm::GradeTooLowException();
}

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getSigned() const {
	return _signed;
}

unsigned int	AForm::getSGrade() const {
	return _sGrade;
}

unsigned int	AForm::getXGrade() const {
	return _xGrade;
}

std::ostream	&operator<<(std::ostream &o, const AForm &src) {
	o << src.getName() << ", AForm sGrade " << src.getSGrade() << ", xGrade " << src.getXGrade() << ", signed: ";
	if (src.getSigned())
		o << "yes";
	else
		o << "no";
	return o;
}

void	AForm::beSigned(const Bureaucrat &src) {
	if (src.getGrade() > _sGrade)
		throw AForm::GradeTooLowException();
	else
		_signed = 1;
}

//ex02
void	AForm::execCheck(Bureaucrat const & executor) const {
	if (!(this->getSigned()))
		throw AForm::Unsigned();
	else if (executor.getGrade() > _xGrade)
		throw AForm::GradeTooLowException();
}
