/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:00:52 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/04 02:10:12 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

# define MIN_GRADE	150
# define MAX_GRADE	1

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

		Bureaucrat();
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat&	operator =(const Bureaucrat& other);

		const std::string&	getName() const;
		int					getGrade() const;

		void	incrementGrade(int change = 1);
		void	decrementGrade(int change = 1);

		class GradeTooLowException: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat);

#endif
