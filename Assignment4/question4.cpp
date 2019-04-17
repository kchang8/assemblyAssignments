#include <iostream>
#include <ctime>
using namespace std;

short floors, index, a = 0x0000;

void generateRand()
{
	floors = rand() % 14 + 2; //random nums 2-16
}

void Base2()
{
	cout << "AX= ";
	short x = 1 << 15, t, n = a;
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

void elevatorOutput()
{
	cout << "Elevator will stop at floors no. ";
}

void displayFloors()
{
	cout << index << " ";
}

int main()
{
	srand(time(0));
	_asm
	{
		mov index, 1;
	forloop:
		cmp index, 10;
		Jg displayAx;
		call generateRand;
		mov cx, a;
		mov bx, 1b;
	check2:
		cmp floors, 2;
		Jne check3;
		shl bx, 1;
		or cx, bx; //compares the all 0 register with bx that stores 2 position
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check3:
		cmp floors, 3;
		Jne check4;
		shl bx, 2;
		or cx, bx;
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check4:
		cmp floors, 4;
		Jne check5;
		shl bx, 3;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check5:
		cmp floors, 5;
		Jne check6;
		shl bx, 4;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check6:
		cmp floors, 6;
		Jne check7;
		shl bx, 5;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check7:
		cmp floors, 7;
		Jne check8;
		shl bx, 6;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check8:
		cmp floors, 8;
		Jne check9;
		shl bx, 7;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check9:
		cmp floors, 9;
		Jne check10;
		shl bx, 8;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check10:
		cmp floors, 10;
		Jne check11;
		shl bx, 9;
		or cx, bx;
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check11:
		cmp floors, 11;
		Jne check12;
		shl bx, 10;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
		Jmp forloop;
	check12:
		cmp floors, 12;
		Jne check13;
		shl bx, 11;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check13:
		cmp floors, 13;
		Jne check14;
		shl bx, 12;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check14:
		cmp floors, 14;
		Jne check15;
		shl bx, 13;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check15:
		cmp floors, 15;
		Jne check16;
		shl bx, 14;
		or cx, bx; 
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	check16:
		cmp floors, 16;
		Jne done;
		shl bx, 15;
		or cx, bx;
		mov ax, a;
		or ax, bx;
		mov a, ax;
		inc index;
		Jmp forloop;
	displayAx:
		call Base2;

		//floors stopped
		call elevatorOutput;
		mov index, 1;
		mov ax, a;
	looper2:
		mov cx, ax;
		cmp index, 16;
		Jg done;
		mov bx, 1b;
		and cx, bx;
		cmp cx, 1b;
		Je showStop;
		inc index;
		ror ax, 1;
		Jmp looper2;
	showStop:
		mov a, ax;
		call displayFloors;
		inc index;
		mov ax, a;
		ror ax, 1;
		Jmp looper2;
	done:

	}
	cout << endl;

	system("pause");
	return 0;
}
