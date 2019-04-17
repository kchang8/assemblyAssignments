#include <iostream>
#include <iomanip>
using namespace std;

float a, b, c;
float four = 4.0, two = 2.0, one = -1.0;
float x1, x2;

void display1()
{
	cout << "X1 = " << fixed << setprecision(2) << x1;
	cout << "    ";
}

void display2()
{
	cout << "X2 = " << fixed << setprecision(2) << x2 << endl;
}

int main()
{
	cout << "To see the two real roots of aX^2 + bX + c = 0," << endl;
	cout << "enter the a, b, c values: ";
	cin >> a >> b >> c;

	_asm
	{
		//computes x1
		fld b;
		fld b;
		fmul;
		fld four;
		fld a;
		fmul;
		fld c;
		fmul;
		fsub;
		fsqrt;
		fld b;
		fsub;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x1;
		call display1;

		//computes x2
		fld b;
		fld b;
		fmul;
		fld four;
		fld a;
		fmul;
		fld c;
		fmul;
		fsub;
		fsqrt;
		fld b;
		fadd;
		fld one;
		fmul;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x2;
		call display2;
	}
	
	system("pause");
	return 0;
}
