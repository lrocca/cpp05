/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:30:03 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/04 03:08:28 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void	checkGrade(int grade, int min = MIN_GRADE, int max = MAX_GRADE) {
	if (grade > min)
		throw Form::GradeTooLowException();
	else if (grade < max)
		throw Form::GradeTooHighException();
}

Form::Form(): gradeSign(0), gradeExec(0) {}

Form::Form(const std::string& name, int gradeSign, int gradeExec)
	: name(name)
	, isSigned(false)
	, gradeSign(gradeSign)
	, gradeExec(gradeExec) {
	checkGrade(gradeSign);
	checkGrade(gradeExec);
}

Form::Form(const Form& other)
	: name(other.name)
	, isSigned(false)
	, gradeSign(other.gradeSign)
	, gradeExec(other.gradeExec) {}

Form::~Form() {}

Form&	Form::operator =(const Form& other) {
	if (this != &other) {}
	return *this;
}

const std::string&	Form::getName() const {
	return name;
}

bool	Form::getSigned() const {
	return isSigned;
}

int	Form::getGradeSign() const {
	return gradeSign;
}

int	Form::getGradeExec() const {
	return gradeExec;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (!isSigned) {
		if (gradeSign < bureaucrat.getGrade())
			throw GradeTooLowException();
		isSigned = true;
	}
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "<Form> grade too low!";
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "<Form> grade too high!";
}

std::ostream&	operator<<(std::ostream &o, const Form& form) {
	o	<< std::boolalpha << "Form " << form.getName() << ", signed: "
		<< form.getSigned() << ", grade to sign " << form.getGradeSign()
		<< ", grade to execute " << form.getGradeExec() << std::endl;
	return o;
}
