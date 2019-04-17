#include <iostream>
using namespace std;

int main()
{
	short F;
	short C;
	short nine = 9, five = 5;

	cout << "Enter temperature in Fahrenheit: ";
	cin >> F;

	_asm
	{
		mov ax, F; //ax = F
		sub ax, 32; //ax = F-32
		imul five; //dx: ax = 5(F-32)
		idiv nine; //ax = 5(F-32)/9
		mov C, ax; // C = 5(F-32)/9
	}

	cout << F << "F is " << C << "C";
	cout << endl;

	system("pause");
	return 0;
}
