/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:30:29 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/04 02:42:27 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iomanip>
# include <stdexcept>
# include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;

		Form();
	public:
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form& other);
		~Form();

		Form&	operator =(const Form& other);

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooLowException: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &o, const Form& form);

#endif
