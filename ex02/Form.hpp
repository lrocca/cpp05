/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:30:29 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/08 02:50:16 by lrocca           ###   ########.fr       */
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
	protected:
		const std::string	name;
		const std::string	target;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;

		Form();
		virtual void	executeConcrete() const = 0;
	public:
		Form(const std::string& name, const std::string& target, \
			int gradeSign, int gradeExec);
		Form(const Form& other);
		virtual ~Form();

		Form&	operator =(const Form& other);

		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

		void			beSigned(const Bureaucrat& bureaucrat);
		void			execute(const Bureaucrat& executor) const;

		class GradeTooLowException: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char*	what() const throw();
		};

		class AlreadySignedException: public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &o, const Form& form);

#endif
