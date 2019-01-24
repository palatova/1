#pragma once

#include <iostream>
#include <sstream>

struct Complex
{
	double re = 0.0;
	double im = 0.0;
	char leftseparator = '{';
	char separator = ',';
	char rightseparator = '}';
	Complex() {}
	explicit Complex(const double real);
	Complex(const double imaginary, const double real);
	Complex& operator+=  (const Complex& lhs);
	Complex& operator+= (const double lhs);
	Complex& operator-= (const Complex& lhs);
	Complex& operator-= (const double lhs);
	Complex& operator*= (const Complex& lhs);
	Complex& operator*= (const double lhs);
	Complex& operator/= (const Complex& lhs);
	Complex& operator/= (const double lhs);
	bool operator== (const Complex& lhs);
	bool operator!= (const Complex& lhs);
	
	std::ostream& writeTo(std::ostream& str) const;
	std::istream& readFrom (std::istream& str);
};



Complex operator+ (const Complex& lhs,const  Complex& rhs);
Complex operator+ (const double lhs, const Complex& rhs);
Complex operator+ (const Complex& lhs, const double rhs);
Complex operator- ( Complex& lhs,  Complex& rhs);
Complex operator- ( Complex& lhs,  double rhs);
Complex operator- ( double lhs,  Complex& rhs);
Complex operator* ( Complex& lhs,  Complex& rhs);
Complex operator* ( Complex& lhs, double rhs);
Complex operator* ( double lhs, Complex& rhs);
Complex operator/ ( Complex& lhs,  Complex& rhs);
Complex operator/ ( Complex& lhs,  double rhs);
Complex operator/ ( double lhs,  Complex& rhs);

std::ostream& operator<<(std::ostream& lhs, Complex& rhs);
std::istream& operator>>(std::istream& lhs, Complex& rhs);








