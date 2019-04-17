#include <iostream>
#include <string>
using namespace std;

int main()
{
	short numDrinks;
	short numSandwiches;
	short totalBill;

	cout << "-------------MENU--------------\n";
	cout << "Drinks.......................$4\n";
	cout << "Sandwiches...................$7\n";
	cout << "How many drinks? ";
	cin >> numDrinks;
	cout << "How many sandwiches? ";
	cin >> numSandwiches;
	
	_asm
	{
		//calculates the total amount for drinks
		mov ax, numDrinks; //ax = num of inputted drinks
		imul ax, 4; //dx: ax = numDrinks * 4

		//calculates the total amount for sandwiches
		mov bx, numSandwiches; //bx = num of inputted sandwiches
		imul bx, 7; //dx: bx = numSandwiches * 7

		//calculates the total bill 
		add ax, bx;
		mov totalBill, ax; 
	}

	cout << "Your total bill is " << totalBill << " dollars.\n";

	system("pause");
	return 0;
}
