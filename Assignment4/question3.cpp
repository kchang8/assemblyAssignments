#include <iostream>
using namespace std;

short counter, b = 0x6A2F, index;

void Base2()
{
	cout << "AX= ";
	short x = 1 << 15, t, n = 0x6A2F;
	for (int i = 1; i <= 16; i++)
	{
		t = n & x;
		if (t == 0)
		{
			cout << 0;
		}
		else { cout << 1; }
		if (i % 4 == 0)
		{
			cout << " ";
		}
		n = n << 1;
	}

	cout << endl;
}

void displayOnSprinklers()
{
	cout << counter << " sprinklers are ON" << endl;
}

void defectiveOutput()
{
	cout << "Defective Sprinklers: ";
}

void displayDefective()
{
	cout << index << " ";
}

int main()
{
	_asm
	{
		call Base2;
		mov counter, 0; //counter keeps track of num of 1s
		mov ax, b;
		mov cx, 1b; //comparing value 0000 0000 0000 0001
		mov index, 1;
	looper:
		cmp index, 16;
		Jg displayOn;
		and cx, ax;
		cmp cx, 1b;
		Je addCount;
		Jmp cont;
	addCount:
		inc counter; //counter++
	cont:
		inc index;
		shr ax, 1; //compares the second index when it shifts
		mov cx, 1b;
		Jmp looper;
	displayOn:
		call displayOnSprinklers;

		//defective sprinklers
		call defectiveOutput;
		mov index, 16; //loops through the bit from the last index
		mov ax, b;
	looper2:
		mov bx, ax;
		cmp index, 0; 
		Je done;
		mov cx, 1000000000000000b;
		and bx, cx;
		shr bx, 15;
		cmp bx, 1b;
		Jne defective;
		dec index;
		rol ax, 1;
		Jmp looper2;
	defective:
		mov b, ax;
		call displayDefective;
		dec index;
		mov ax, b;
		rol ax, 1;
		Jmp looper2;
	done:

	}
	cout << endl;

	system("pause");
	return 0;
}
