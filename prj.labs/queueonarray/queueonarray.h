#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>

class Rational
{
public:
	int zn = 1;
	int ch = 0;
	char leftseparator = '{';
	char rightseparator = '}';
	char separator = '/';
	Rational() = default;
	Rational(const int chislitel, const int znamenatel);
	explicit Rational(const int real);
	Rational& operator+=  (Rational& lhs);
	Rational& operator-= ( Rational& lhs);
	Rational& operator*= ( Rational& lhs);
	Rational& operator/= ( Rational& lhs);

	bool operator== ( Rational& lhs);
	bool operator!= ( Rational& lhs);

	std::ostream& writeTo(std::ostream& str) const;
	std::istream& readFrom(std::istream& str);
	void Sokrachenie(int& ch, int& zn);
	//int nod(int a, int b);
};


Rational operator+ ( Rational& lhs,  Rational& rhs);
Rational operator- ( Rational& lhs,  Rational& rhs);
Rational operator* ( Rational& lhs,  Rational& rhs);
Rational operator/ ( Rational& lhs,  Rational& rhs);

std::ostream& operator<<(std::ostream& lhs, Rational& rhs);
std::istream& operator>>(std::istream& lhs, Rational& rhs);
#endif RATIONAL_H







