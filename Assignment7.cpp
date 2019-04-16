#include <iostream>
#include <iomanip>
using namespace std;

float numDrinks, numSandwiches, total;
int i, numCustomers, sandwichSize;
float s = 2.25, w = 1.75, j = 2.80, ten = 3.45, twelve = 5.25;
char drinkChoice;

void numCust()
{
	cout << "Enter the number of customers: ";
	cin >> numCustomers;
}

void custOrder()
{
	cout << "Customer " << i << ":" << endl;
	cout << "How many drinks? ";
	cin >> numDrinks;
	cout << "  What kind of drink(S=Soda, W=Water, J=Juice)? ";
	cin >> drinkChoice;
	cout << "How many sandwiches? ";
	cin >> numSandwiches;
	cout << "  What size of sandwich(10/12 inches)? ";
	cin >> sandwichSize;
}

void totalBill()
{
	cout << "Your total bill = $" << fixed << setprecision(2) << total << endl;
	cout << endl;
}

int main()
{
	cout << "------------7-11 Convenient Store--------------\n";
	cout << "Drinks\n";
	cout << "  Soda(S)................................$2.25\n";
	cout << "  Water(W)...............................$1.75\n";
	cout << "  Juice(J)...............................$2.80\n";
	cout << "Sandwiches\n";
	cout << "  10 inches..............................$3.45\n";
	cout << "  12 inches..............................$5.25\n";

	_asm
	{
		mov i, 1;
		call numCust;
	forloop:
		mov eax, numCustomers;
		cmp i, eax;
		Jg done;
		call custOrder;
		cmp drinkChoice, 'S';
		Jne Water;
		fld numDrinks;
		fld s;
		fmul;
		Jmp Sandwich;
	Water:
		cmp drinkChoice, 'W';
		Jne Juice;
		fld numDrinks;
		fld w;
		fmul;
		Jmp Sandwich;
	Juice:
		cmp drinkChoice, 'J';
		fld numDrinks;
		fld j;
		fmul;
		Jmp Sandwich;
	Sandwich:
		cmp sandwichSize, 10;
		Jne Twelve;
		fld numSandwiches;
		fld ten;
		fmul;
		fadd;
		fstp total;
		call totalBill;
		Jmp increment;
	Twelve:
		cmp sandwichSize, 12;
		Jne done;
		fld numSandwiches;
		fld twelve;
		fmul;
		fadd;
		fstp total;
		call totalBill;
	increment:
		inc i;
		Jmp forloop;
	done:

	}
	
	system("pause");
	return 0;
}