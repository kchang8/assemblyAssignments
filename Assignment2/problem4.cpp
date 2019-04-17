#include <iostream>
using namespace std;

int main()
{
	int d1, d2, d3, n;
	int ten = 10; int hundred = 100;
	int sum;

	cout << "Enter a 3 digit number: ";
	cin >> n;

	_asm
	{
		mov eax, n; //eax = n
		cdq; //n = edx:eax
		idiv hundred; //eax = n/100
		mov d1, eax; //d1 stores n/100
		mov eax, edx; //eax = remainder of n/100

		cdq;
		idiv ten; //eax = n/10
		mov d2, eax; //d2 stores n/10
		mov eax, edx; //eax = remainder of n/10

		mov d3, eax; //d3 stores eax which has the last number
		add eax, d2; //last number + d2
		add eax, d1; //last num + d2+d1
		mov sum, eax;
	}

	cout << "The total of digits in " << n << " is " << sum << endl;

	system("pause");
	return 0;
}
