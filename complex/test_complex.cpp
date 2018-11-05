#include<iostream>
#include <sstream>
#include"complex.h"


std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftseparator << re << separator << im << rightseparator;
	return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm) 
{

	char leftseparator = 0;
	double real = 0.0;
	char comma = 0;
	double imaganary = 0.0;
	char rightseparator = 0;

	istrm >> leftseparator >> real >> comma >> imaganary >> rightseparator;

	if (istrm.good())
	{
		if ((Complex::leftseparator == leftseparator) && (Complex::separator == comma) && (Complex::rightseparator == rightseparator))
		{
			re = real;
			im = imaganary;
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
	Complex z;
	istrm >> z;
	if (istrm.good())
	{
		std::cout << "Uspeshno ^^" << str << "-->" << z << std::endl;
	}
	else
	{
		std::cout << "Mistake!" << str << "-->" << z << std::endl;
	}

	return istrm.good();
}




int main(){
	testoparsirovanie("{8,8.9}");
	testoparsirovanie("{8,f}");
	Complex z,v;
	std::cin >> z.re >> z.im;
	std::cin >> v.re >>  v.im;
	double rez, imz, rev, imv;
	rez = z.re;
	imz = z.im;
	rev = v.re;
	imv = v.im;
	std::cout << "z + v =" << (z + v) << std::endl;
	std::cout << "z - v =" << (z - v) << std::endl;
	std::cout << "z * v =" << (z * v) << std::endl;
	 z.re= rez;
	 z.im=imz;
	 v.re = rev;
	 v.im = imv;
	std::cout << "z / v =" << (z / v) << std::endl;
	z.re = rez;
	z.im = imz;
	v.re = rev;
	v.im = imv;
	std::cout << "z += v" << (z += v) << std::endl;
	z.re = rez;
	z.im = imz;
	v.re = rev;
	v.im = imv;
	std::cout << "z -= v" << (z -= v) << std::endl;
	z.re = rez;
	z.im = imz;
	v.re = rev;
	v.im = imv;
	std::cout << "z *= v" << (z *= v) << std::endl;
	z.re = rez;
	z.im = imz;
	v.re = rev;
	v.im = imv;
	std::cout << "z /= v" << (z /= v) << std::endl;
	
	
	system("pause");
	return 0;






}