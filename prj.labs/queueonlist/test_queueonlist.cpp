#include<iostream>
#include <sstream>
#include"rational.h"


std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm  << ch << "/" << zn ;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) 
{

	int chislitel = 0;
	char comma ='/';
	int znamenatel = 1;
	char leftseparator = 0;
	char rightseparator = 0;

	istrm >> leftseparator>>chislitel >> comma >>  znamenatel>>rightseparator;

	if (istrm.good())
	{
		//if (Rational::separator==comma)
		if ((Rational::leftseparator == leftseparator) && (Rational::separator == comma) && (Rational::rightseparator == rightseparator))
		{
			ch = chislitel;
			zn = znamenatel;
			Sokrachenie(ch,zn);
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;

}

bool testoparsirovanie(const std::string& str)
{
	std::istringstream istrm(str);
	Rational r;
	istrm >> r;
	if (istrm.good())
	{
	
	}
	else
	{
		std::cout << "Mistake!" << str << "-->" << r << std::endl;
	}

	return istrm.good();
}

int main(){
	//testoparsirovanie("{-2/0}");
	testoparsirovanie("{2/4}");
	testoparsirovanie("{-2/4}");
	testoparsirovanie("{-2/-4}");
	testoparsirovanie("{2/-4}");
   Rational z,v;
	std::cin >> z.ch >> z.zn;
	std::cin >> v.ch >>  v.zn;
double rez, imz, rev, imv;
	rez = z.ch;
	imz = z.zn;
	rev = v.ch;
	imv = v.zn;
	
 std::cout << "z + v =" << (z + v) << std::endl;
 z.ch = rez ;
 z.zn= imz ;
 v.ch = rev;
 v.zn=imv ;
std::cout << "z - v =" << (z - v) << std::endl;
z.ch = rez;
z.zn = imz;
v.ch = rev;
v.zn = imv;
std::cout << "z * v =" << (z * v) << std::endl;
z.ch = rez;
z.zn = imz;
v.ch = rev;
v.zn = imv;
std::cout << "z / v =" << (z / v) << std::endl;
z.ch = rez;
z.zn = imz;
v.ch = rev;
v.zn = imv;

std::cout << "(z += v) =" << (z += v) << std::endl;
z.ch = rez;
z.zn = imz;
v.ch = rev;
v.zn = imv;
std::cout << "(z -= v) =" << (z -= v) << std::endl;
z.ch = rez;
z.zn = imz;
v.ch = rev;
v.zn = imv;
std::cout << "(z *= v) =" << (z *= v) << std::endl;
z.ch = rez;
z.zn = imz;
v.ch = rev;
v.zn = imv;
std::cout << "(z /= v) =" << (z /= v) << std::endl;

	
	system("pause");
	return 0;






}