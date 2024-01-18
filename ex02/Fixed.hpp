/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>


class Fixed {

	private:
		static const int		_bFract;
		int						_entier;

	public:
		Fixed();
		Fixed(int const entier);
		Fixed(float const flo);
		Fixed(Fixed const & copy);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
		Fixed &	operator=(Fixed const &rhs);
	
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;

		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		/*Pre-incr*/
		Fixed &	operator++(void);
		Fixed & operator--(void);
		/*Post-incr*/
		Fixed	operator++(int v);
		Fixed 	operator--(int v);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);


};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif