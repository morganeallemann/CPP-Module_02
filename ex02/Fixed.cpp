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

Fixed::Fixed() : _entier(0){

}

Fixed::Fixed(int const entier) : _entier(entier << this->_bFract){

}

Fixed::Fixed(float const flo){
	this->_entier = roundf(flo * (1 << this->_bFract));
}

Fixed::Fixed(Fixed const & copy){
	*this = copy;
}

Fixed::~Fixed(){
}

int     Fixed::getRawBits(void) const{
    return (this->_entier);
}

void    Fixed::setRawBits(int const raw){
    this->_entier = raw;
    return ;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    this->_entier = rhs.getRawBits();
    return (*this);
}

int     Fixed::toInt(void) const{
	return (this->_entier >> this->_bFract);
}

float	Fixed::toFloat(void) const{

	return ((float)this->_entier / (float)(1 << this->_bFract));
}

bool	Fixed::operator==(Fixed const &rhs) const{
	return (this->_entier == rhs._entier);
}

bool	Fixed::operator!=(Fixed const &rhs) const{
	return not (this->_entier == rhs._entier);
}

bool	Fixed::operator<(Fixed const &rhs) const{
	return (this->_entier < rhs._entier);
}

bool	Fixed::operator>(Fixed const &rhs) const{
	return (this->_entier > rhs._entier);
}

bool	Fixed::operator<=(Fixed const &rhs) const{
	return (this->_entier <= rhs._entier);
}

bool	Fixed::operator>=(Fixed const &rhs) const{
	return (this->_entier >= rhs._entier);
}

float	Fixed::operator+(Fixed const &rhs) const{
	return (this->toFloat() + rhs.toFloat());
}

float	Fixed::operator-(Fixed const &rhs) const{
	return (this->toFloat() - rhs.toFloat());
}

float	Fixed::operator*(Fixed const &rhs) const{
	return (this->toFloat() * rhs.toFloat());
}

float	Fixed::operator/(Fixed const &rhs) const{
	return (this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++(void){
	++this->_entier;
	return (*this);
}

Fixed & Fixed::operator--(void){
	--this->_entier;
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed tmp = *this;

	this->_entier = _entier + 1;
	return (tmp);
}

Fixed	Fixed::operator--(int){
	Fixed	tmp = *this;

	this->_entier = _entier - 1;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b )
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b )
		return (a);
	else
		return (b);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs){
	return (o << rhs.toFloat());
}
