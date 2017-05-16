#include <iostream>
#include <string>
#include "Fraction.h"
#include <ctime>

using namespace std;

int main()
{
	int x;
	Fraction f(1, 2);
	Fraction f2(1, 4);
	Fraction f3;

	cout << "\t\tWelcome to My Fraction Number System !!" << endl;
	cout << "\t\t0: Testing Big-Three" << endl;
	cout << "\t\t1: Testing arithmatic operators (+ - * .)" << endl;
	cout << "\t\t2: Testing prefix/postfix increment/decrement operators" << endl;
	cout << "\t\t3: Testing relation operators" << endl;
	cout << "\t\t4: Testing power function" << endl;
	cout << "\t\t5: To\t\t Quit"<< "\n\t\t Your choice: ";
	cin >> x;

	switch (x)
	{

	case 0:
		cout << "\t\t Please enter the first fraction : ";
		cin >> f;

		cout << "\t\t Please enter the second fraction : ";
		cin >> f2;

		cout << "\t\tTesting Big 3" << endl;
		cout << "\n\t\tInside a block:" << endl;
		f3 = (f);
		cout << "\t\t f1 = (" << f << ") and f2 = (" << f2 << ")" << endl;
		cout << "\t\t Fraction f3(f1) ; ==> f3 = (" << f3<<")" << endl;
		 f3 = (f2);
		cout << "\t\t After f3 = f2 : f1 = (" << f << "), f2 = (" << f2 << "), f3 = (" << f3 << ")" << endl;
		f = (f3);
		cout << "\t\t f1 = f3: f1 = (" << f << ")" << endl;
		cout << "\t\tOutside the block :" << endl;
		cout << "\t\tf1 = (" << f << ")" << endl;

	case 1:
		cout << "\t\tTesting Arithmetic operations : " << endl;
		cout << "(" << f << ") + (" << f2 << ") = " << (f + f2) << endl;
		cout << "(" << f << ") - (" << f2 << ") = " << (f - f2) << endl;
		cout << "(" << f << ") * (" << f2 << ") = " << (f * f2) << endl;
		cout << "(" << f << ") / (" << f2 << ") = " << (f / f2) << endl;
	case 2:
		cout << "\t\tTesting Increment/Derement :" << endl;
		cout << "++(" << f << ") + (" << f2 << ")  = " << ((f++) + f2) << endl;
		cout << "--(" << f << ") + (" << f2 << ")  = " << ((f--) + f2) << endl;
	case 3:
		cout << "\t\tTesting Relational operations :" << endl;
		cout << "\t\t (" << f << ")  >  (" << f2 << ") =    " << (f > f2) << endl;
		cout << "\t\t (" << f << ")  <  (" << f2 << ") =   " << (f < f2) << endl;
		cout << "\t\t (" << f << ")  ==  (" << f2 << ") =    " << (f == f2) << endl;
		cout << "\t\t (" << f << ")  <=  (" << f2 << ") =    " << (f <= f2) << endl;
		cout << "\t\t (" << f << ")  >=  (" << f2 << ") =    " << (f >= f2) << endl;
		cout << "\t\t (" << f << ")  !=  (" << f2 << ") =    " << (f != f2) << endl;
	case 4:
		cout << "\t\tTesting overload ^ :" << endl;
		cout << "\t\t (" << f << ") ^ (1) = (" << (f ^ 1) << endl;
		cout << "\t\t (" << f << ") ^ (-1) = (" << (f ^ -1) << endl;
	case 5: 
		cout << "\t\t Good Bye" << endl;
		exit(1);
	}

	system("pause");

}