/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bFract = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const entier) : _entier(entier){
	std::cout << "Int constructor called" << std::endl;
	this->_entier = entier << this->_bFract;
}

Fixed::Fixed(float const flo){
	std::cout << "Float constructor called" << std::endl;
	this-> roundf(flo * (1 << this->_bFract));
}

Fixed::Fixed(Fixed const & copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_entier);
}

void    Fixed::setRawBits(int const raw){
    this->_entier = raw;
    return ;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_entier = rhs.getRawBits();
    return (*this);
}

int     Fixed::toInt(void) const{
	return (this->_entier >> this->_bFract);
}

float	Fixed::toFloat(void) const{

	return ((float)this->_entier / (float)(1 >> this->_bFract));
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs){
	float	flottant;

	flottant = rhs.toFloat();
	o << flottant;
	return (o);
}
