#include<iostream>
#include"complex.h"
#include<sstream>

Complex::Complex(const double real) : Complex(real, 0.0)
{

}

Complex::Complex(const double real, const double imaginary) 
	: re(real)
	, im(imaginary)
{

}

Complex& Complex::operator+= (const Complex& lhs) 
{

    re = re + lhs.re;
	im = im + lhs.im;
	return *this;
	
}

Complex& Complex::operator+= (const double lhs)
{
	 re += Complex(lhs).re;
	 im += Complex(lhs).im;
	return *this;
}
Complex& Complex ::operator-= (const Complex& lhs)
{
	re -= lhs.re;
	im -= lhs.im;
	return *this;
}
Complex& Complex::operator-= (const double lhs)
{
	return operator -= (Complex(lhs));
}
Complex& Complex::operator*= (const Complex& lhs)
{
	double r = re;
	double m = im;
		re = re*lhs.re - (im * lhs.im);
		im = r * lhs.im + (m*lhs.re);
	return *this;
}
Complex& Complex::operator*= (double lhs)
{
	re *= lhs*re;
	im *= lhs*im;
	return *this;
}
Complex& Complex::operator/= (const Complex& lhs)
{
	double r = re;
	re = ((re *lhs.re + (im*lhs.im)) / (lhs.re*lhs.re - lhs.im *lhs.im));
	im=((-r *lhs.im + (im*lhs.re)) / (lhs.re*lhs.re - lhs.im *lhs.im));
	return *this;
}
Complex& Complex::operator/= (const double lhs)
{
	return operator/= (Complex(lhs));
}
bool Complex::operator== (const Complex& lhs) 
{
	return  (re == lhs.re) && (im == lhs.im);
	
}


bool Complex::operator!= (const Complex& lhs) 
{
	return !(operator== (lhs));
}
 
std::ostream& operator<< (std::ostream& lhs, Complex& rhs)
{
	return rhs.writeTo(lhs);
}


std::istream& operator>> (std::istream& lhs, Complex& rhs)
{

	return rhs.readFrom(lhs);
}

Complex operator+ (const Complex& rhs,const Complex& lhs)
{
	Complex sum;
	sum.re = rhs.re + lhs.re;
	sum.im = rhs.im + lhs.im;
	return sum;
}

Complex operator+ ( Complex& lhs,  double rhs) 
{
	lhs.re +=rhs;
	return lhs;
}
Complex operator+ ( double lhs, Complex& rhs)
{
	rhs.re += lhs;
	return rhs;
}
Complex operator- ( Complex& lhs, Complex& rhs)
{
	Complex vych;
	vych.re = lhs.re - rhs.re;
	vych.im = lhs.im - rhs.im;
	return vych;
}
Complex operator- (Complex& lhs, double rhs)
{
	lhs.re -= rhs;
	return lhs;
}
Complex operator- (double lhs, Complex& rhs)
{
	rhs.re -= lhs;
	return rhs;
}
Complex operator* (Complex& lhs, Complex& rhs)
{
	rhs *= lhs;
	return rhs;
}
Complex operator* (Complex& lhs, double rhs)
{
	lhs *= rhs;
	return lhs;
}
Complex operator* (double lhs, Complex& rhs)
{
	rhs *= lhs;
	return rhs;
}

Complex operator/(Complex& lhs, Complex& rhs)
{
	lhs /= rhs;
	return lhs;
}

Complex operator/ (Complex& lhs, double rhs)
{
	lhs /= rhs;
	return lhs;
}

Complex operator/ (double lhs, Complex& rhs)
{
	Complex lhs1;
	lhs1.re = lhs;
	lhs1.im = 0;
	lhs1 /= rhs;
	return lhs1;
}



