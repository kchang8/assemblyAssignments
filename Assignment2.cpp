#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

float p = 3.25, sandwich = 2.10, s = 1.25, j = 1.75, b = 1.85, tax = 0.10;
float total;
string name;
char foodChoice, drinkChoice;
int numFood, numDrinks;

void getName()
{
	cout << "What is your name: ";
	cin >> name;
}

void custOrder()
{
	cout << "What kind of food in uppercase(P=Pizza, S=Sandwich)? ";
	cin >> foodChoice;
	cout << "  How many? ";
	cin >> numFood;
	cout << "What would you like to drink in uppercase(S=Soda, J=Juice, B=Beer)? ";
	cin >> drinkChoice;
	cout << "  How many? ";
	cin >> numDrinks;
}

void displayTotal()
{
	cout << name << ", your total bill including 10% tax is " << fixed << setprecision(2) << total << endl;
}

int main()
{
	cout << "------------Menu-----------\n";
	cout << "Food\n";
	cout << "  Pizza(P)............$3.25\n";
	cout << "  Sandwich(S).........$2.10\n";
	cout << "Drinks\n";
	cout << "  Soda(S).............$1.25\n";
	cout << "  Juice(J)............$1.75\n";
	cout << "  Beer(B).............$1.85\n";

	_asm
	{
		call getName;
		call custOrder;
		cmp foodChoice, 'P';
		Jne Sandwich;
		fld p;
		fld numFood;
		fmul; //eax = pizza price * num of food
		Jmp Soda;
	Sandwich:
		fld sandwich;
		fld numFood;
		fmul; //eax = sandwich price * num of food
	Soda:
		cmp drinkChoice, 'S';
		Jne Juice;
		fld s;
		fld numDrinks;
		fmul;
		fadd; //adds the food amount and the drink amount
		fstp total; //total = food amount + drink amount
		Jmp showTotal;
	Juice:
		cmp drinkChoice, 'J';
		Jne Beer;
		fld j;
		fld numDrinks;
		fmul;
		fadd;
		fstp total; //total = food amount + drink amount
		Jmp showTotal;
	Beer:
		cmp drinkChoice, 'B';
		Jne done;
		fld b;
		fld numDrinks;
		fmul;
		fadd;
		fstp total; //total = food amount + drink amount
	showTotal:
		fld total;
		fld total;
		fld tax;
		fmul; //eax = tax*total
		fadd; //eax = (tax*total) + total
		fstp total; 
		call displayTotal;
	done:

	}

	system("pause");
	return 0;
}