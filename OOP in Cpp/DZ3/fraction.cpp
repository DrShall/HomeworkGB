#include "fraction.h"
#include <iostream>

Fraction::Fraction(int numerator, int denomerator)
{
	try {
		numertor_ = numerator;
		denomerator_ = denomerator;
		if(denomerator == 0)
			throw 0;
	}  catch (int a) {
		std::cerr << "Denomerator cannot be zero!" << std::endl;
	}
}
void Fraction::print()
{
	try {
		if(denomerator_ == 0)
			throw 0;
		else
			std::cout << numertor_ << "/" << denomerator_ << std::endl;
	}  catch (int a) {
		std::cerr << "Denomerator cannot be zero!" << std::endl;
	}
}

Fraction Fraction::operator*(const Fraction& right)
{
	int n = numertor_ * right.numertor_;
	int d = denomerator_ * right.denomerator_;
	return Fraction(n, d);
}

Fraction Fraction::operator/(const Fraction& right)
{
	int n = numertor_ * right.denomerator_;
	int d = denomerator_ * right.numertor_;
	return Fraction(n, d);
}

Fraction Fraction::operator+(const Fraction& right)
{
	int n = numertor_ * right.denomerator_ + right.numertor_ * denomerator_;
	int d = denomerator_ * right.denomerator_;
	return Fraction(n, d);
}

Fraction Fraction::operator-(const Fraction& right)
{
	int n = numertor_ * right.denomerator_ - right.numertor_ * denomerator_;
	int d = denomerator_ * right.denomerator_;
	return Fraction(n, d);
}

Fraction Fraction::operator-()
{
	return Fraction(- numertor_, denomerator_);
}

bool Fraction::operator==(const Fraction& right)
{
	if( numertor_ == right.numertor_ && denomerator_ == right.denomerator_ )
		return true;
	if( ( numertor_ / right.numertor_ == denomerator_ / right.denomerator_ ) && ( numertor_ % right.numertor_ == denomerator_ % right.denomerator_ ) )
		return true;
	return false;
}

bool Fraction::operator!=(const Fraction& right)
{
	if( numertor_ == right.numertor_ && denomerator_ == right.denomerator_ )
		return false;
	if( ( numertor_ / right.numertor_ == denomerator_ / right.denomerator_ ) && ( numertor_ % right.numertor_ == denomerator_ % right.denomerator_ ) )
		return false;
	return true;
}

bool Fraction::operator<(const Fraction& right)
{
	if( ( numertor_ * right.denomerator_ ) < ( denomerator_ * right.numertor_ ) )
		return true;
	else
		return false;
}

bool Fraction::operator>(const Fraction& right)
{
	if( ( numertor_ * right.denomerator_ ) > ( denomerator_ * right.numertor_ ) )
		return true;
	else
		return false;
}

bool Fraction::operator<=(const Fraction& right)
{
	return ( (*this > right) ? false : true );
}

bool Fraction::operator>=(const Fraction& right)
{
	return ( ( *this < right) ? false : true );
}

