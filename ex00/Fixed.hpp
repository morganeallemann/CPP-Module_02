/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

class Fixed {

	private:
		int					_nb1;
		static const int	_nb2;

	public:
		Fixed();
		Fixed(Fixed & copy);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed &	operator=(Fixed const & rhs);
};

#endif 