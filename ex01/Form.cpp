/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:32:53 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/04 16:53:07 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(0), _sGrade(150), _xGrade(150) {
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _sGrade(src._sGrade), _xGrade(src._xGrade) {
	std::cout << "Form copy constructor" << std::endl;
}

Form &Form::operator=(const Form &src) {
	std::cout << "Form assignment operator" << std::endl;
	if (this != &src)
		_signed = src._signed;
	return *this;
}

Form::~Form() {
	std::cout << "Form " << _name << " destructor" << std::endl;
}

Form::Form(std::string name, unsigned int sGrade, unsigned int xGrade) : _name(name), _sGrade(sGrade), _xGrade(xGrade) {
	std::cout << "Form " << _name << " constructor" << std::endl;
	_signed = 0;
	if (_sGrade == 0 || _xGrade == 0)
		throw Form::GradeTooHighException();
	else if (_sGrade > 150 || _xGrade > 150)
		throw Form::GradeTooLowException();
}

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSigned() const {
	return _signed;
}

unsigned int	Form::getSGrade() const {
	return _sGrade;
}

unsigned int	Form::getXGrade() const {
	return _xGrade;
}

std::ostream	&operator<<(std::ostream &o, const Form &src) {
	o << src.getName() << ", Form sGrade " << src.getSGrade() << ", xGrade " << src.getXGrade() << ", signed: ";
	if (src.getSigned())
		o << "yes";
	else
		o << "no";
	return o;
}

void	Form::beSigned(const Bureaucrat &src) {
	if (src.getGrade() > _sGrade)
		throw Form::GradeTooLowException();
	else
		_signed = 1;
}
