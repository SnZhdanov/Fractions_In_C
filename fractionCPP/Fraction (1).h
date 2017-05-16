#ifndef  FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

using namespace std;
class Fraction {

private:
	int *numerator;
	int *denominator;

public:

	// AUXILARY FUNCTIONS 

	int gcd(int m, int n)
	{
		// m = a, n = b
		if (m <  0)  m = -m;
		if (n < 0) n = -n;
		if (m < n) return gcd(n, m);
		if (n == 0) return m;
		return gcd(n, m%n);
	}//  determine the greatest common divisor between m nd n 


	void Fraction::reduce() {

		if (*numerator == 0) *denominator = 1;
		if (*denominator == 1) return;
		if (*denominator < 0) {
			*denominator = -*(denominator);
			*numerator = -(*(numerator));
		}
		int c = gcd(*numerator, *denominator);
		*numerator /= c;
		*denominator /= c;
	}   // simplify the fraction by removing the common factors between numerator and denominator, denominator always greater than 0.

					  /////////////////////////////////////////////////////////////////////////////////////////////
					  // constructors 

	Fraction()   // default construcotr   0/1
	{
		numerator = new int(0);
		denominator = new int(1);
	}


	Fraction(int n)  // Fraction  n/1
	{
		numerator = new int(n);
		denominator = new int(1);
	}


	Fraction(int n, int m)   // n/m  and must be simplified so that there is no common factor between numerator and denominator
	{
		numerator = new int(n);
		denominator = new int(m);
	}


	Fraction(Fraction & other) // copy constructor
	{
		numerator = new int(*(other.numerator));
		denominator = new int(*(other.denominator));
	}

							   // operators overloading 

	Fraction & operator = (Fraction & rhs)  // overload assignment operator
	{
		if (this != &rhs)
		{
			delete numerator;
			delete denominator;
			numerator = new int(*rhs.numerator);
			denominator = new int(*rhs.denominator);
		}
		return *this;
	}
	~Fraction()    // destructor
	{
		if (numerator) delete numerator;
		if (denominator) delete denominator;
	}
					 // relational operators < <= > >=   ==  !=

	bool operator < (Fraction & rhs);
	bool operator <= (Fraction & rhs);

	bool operator > (Fraction & rhs);

	bool operator >= (Fraction & rhs);

	bool operator == (Fraction & rhs);

	bool operator !=(Fraction &rhs);


	// overload arithmetic operators


	Fraction & operator +(Fraction & rhs) // addition
	{

		int num = (*numerator)*(*rhs.denominator) + (*denominator)*(*rhs.numerator);
		int denom = *denominator*(*rhs.denominator);
		Fraction *tmp = new Fraction(num, denom);

		
		return *tmp;
	}

	Fraction & operator -(Fraction & rhs)   // subtraction
	{
		int num = *numerator*(*rhs.denominator) - *denominator*(*rhs.numerator);
		int denom = *denominator*(*rhs.denominator);
		Fraction *tmp = new Fraction(num, denom);

		return *tmp;
	}

	Fraction & operator * (Fraction & rhs)  // multiplication
	{
		int num = *numerator*(*rhs.numerator);
		int denom = *denominator*(*rhs.denominator);
		Fraction *tmp = new Fraction(num, denom);
		return *tmp;
	}
	Fraction & operator / (Fraction & rhs)   // division
	{
		int num = *numerator/(*rhs.numerator);
		int denom = *denominator/(*rhs.denominator);
		Fraction *tmp = new Fraction(num, denom);
		return *tmp;
	}
											  ////////////////  increment and decrement
	Fraction & operator++()   // prefix increment
	{
		*numerator += *denominator;
		return *this;
	}
	Fraction & operator ++ (int) // postfix increment
	{
		Fraction *tmp = new Fraction(*this);
		*numerator += *denominator;
		return *this;
	}

	Fraction & operator--()     // prefix decrement
	{
		*numerator -= *denominator;
		return *this;
	}
	Fraction & operator -- (int)  // postfix decrement
	{
		Fraction *tmp = new Fraction(*this);
		*numerator -= *denominator;
		return *this;
	}
	Fraction & operator ^(int n)   //   exponentiation    : raise to the power n 
	{
		*numerator *= n;
		*denominator *= n;
		for (int i = 0; i < n; i++)
		{
			*numerator *= *numerator;
			*denominator *= *denominator;
		}
		Fraction *tmp = new Fraction(*numerator, *denominator);
		return *tmp;

	}

									 ////////////////////////////////////////////////////////////////////////////////////

	bool isZero() {
		return (*numerator == 0);
	}

	bool isNegative() {
		return  (*numerator < 0);
	}

	bool isPositive() {
		return (*numerator > 0);
	}

	bool isProper() {
		if (abs(*numerator) < *denominator) return true;
		else return false;
	}



	string toString() {
		string tmp;

		char buf[80];
		if (*denominator != 1)
			sprintf_s(buf, "%d/%d", *numerator, *denominator);
		else sprintf_s(buf, "%d", *numerator);
		tmp = string(buf);

		return tmp;
	}



	char *str();  //   C-string format of toString()



	friend ostream & operator<<(ostream & out, Fraction & rhs);

	friend istream & operator>>(istream & in, Fraction & f);

};


bool Fraction::operator > (Fraction & rhs)
{
	return(*numerator/(*denominator) > *rhs.numerator*(*rhs.denominator));
}

bool Fraction::operator < (Fraction & rhs)
{
	return(*numerator/(*denominator) < *rhs.numerator*(*rhs.denominator));
}

bool Fraction::operator <= (Fraction & rhs)
{
	return(*numerator*(*denominator) <= *rhs.numerator*(*rhs.denominator));
}

bool Fraction::operator >= (Fraction & rhs)
{
	return(*numerator*(*denominator) >= *rhs.numerator*(*rhs.denominator));
}

bool Fraction::operator == (Fraction & rhs)
{
	return(*numerator/(*denominator) == *rhs.numerator*(*rhs.denominator));
}

bool Fraction::operator != (Fraction &rhs)
{
	return (*numerator/(*denominator) != *rhs.numerator*(*rhs.denominator));
}



istream & operator>>(istream & in, Fraction & f) {

	char slash;
	int num;
	int denom;
	in >> num;
	in >> slash;
	in >> denom;

	(f.numerator) = new int(num);
	(f.denominator) = new int(denom);
	f.reduce();

	return in;

}

ostream & operator<<(ostream & out, Fraction & rhs)
{
	out << *rhs.numerator;
	if (*(rhs.denominator) != 1) 
	{
		out << " / " << *rhs.denominator;
	}
	return out;
}




#endif