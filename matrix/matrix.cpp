#include<iostream>
#include"rational.h"
#include<sstream>
int nod(int a, int b)
{
	a = abs(a);
	b = abs(b);
		while (a!=b)
		{
			if (a > b)
			{
				a = a-b;
			}
			else
			{
				b = b -a;
			}

		}
	
return a ;
}
void Rational::Sokrachenie(int& ch, int& zn) 
{
	if (nod(ch, zn) != 1)
	{
		if (((ch < 0) && (zn < 0)) || ((ch > 0) && (zn < 0)))
		{
			int y = zn;
			zn = zn /(- nod(ch, zn));
			ch = ch /(- nod(ch, y));
		}
		else
		{
			
				int y = zn;
				zn = zn / nod(ch, zn);
				ch = ch / nod(ch, y);
			
		}
		
	}


}

Rational::Rational(int chislitel,  int znamenatel) : ch(chislitel), zn(znamenatel)
{
	if (0 == zn)
	{
		std::cout << "znamenatel ne dolzen = 0";
	}
	Sokrachenie(ch, zn);
	
}
Rational::Rational(const int real)
{
	ch = real;
	zn = 1;
}

Rational& Rational::operator+= ( Rational& lhs) 
{
    ch = ch +lhs.ch* (zn / nod(zn, lhs.zn));
	zn *= (zn / nod(zn, lhs.zn));
	Sokrachenie(ch, zn);
	return *this;
	
}

Rational& Rational ::operator-= ( Rational& lhs)
{
	ch -= lhs.ch* (lhs.zn / nod(zn, lhs.zn));
	zn *= (lhs.zn / nod(zn, lhs.zn));
	Sokrachenie(ch, zn);
	return *this;
}

Rational& Rational::operator*= ( Rational& lhs)
{
	ch *=lhs.ch;
	zn *= lhs.zn;
	Sokrachenie(ch, zn);
	return *this;
}

Rational& Rational::operator/= ( Rational& lhs)
{
	ch *= lhs.zn;
	zn *= lhs.ch;
	Sokrachenie(ch, zn);
	return *this;
}

bool Rational::operator== ( Rational& lhs)
{
	return  (ch == lhs.ch) && (zn == lhs.zn);
	
}


bool Rational::operator!= ( Rational& lhs)
{
	return !(operator== (lhs));
}
 
std::ostream& operator<< (std::ostream& lhs, Rational& rhs)
{
	return rhs.writeTo(lhs);
}



std::istream& operator>> (std::istream& lhs, Rational& rhs)
{

	return rhs.readFrom(lhs);
}

Rational operator+ (Rational& lhs, Rational& rhs)
{
	lhs += rhs;
	return lhs;
}

Rational operator- (Rational& lhs, Rational& rhs)
{
	lhs -= rhs;
	return lhs;
}

Rational operator* (Rational& lhs, Rational& rhs)
{
	rhs *= lhs;
	return rhs;
}


Rational operator/(Rational& lhs, Rational& rhs)
{
	lhs /= rhs;
	return lhs;
}




