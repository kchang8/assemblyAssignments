#include <iostream>
using namespace std;

short pin1 = 0xBEEF, pin2 = 0xFADE, pin3 = 0xCABE;
short total = 0, two = 2;

void displayBeefEven()
{
	cout << "BEEF is a valid ID for the family" << endl;
}
void displayBeefOdd()
{
	cout << "BEEF is not a valid ID for the family" << endl;
}

void displayFadeEven()
{
	cout << "FADE is a valid ID for the family" << endl;
}
void displayFadeOdd()
{
	cout << "FADE is not a valid ID for the family" << endl;
}

void displayCabeEven()
{
	cout << "CABE is a valid ID for the family" << endl;
}
void displayCabeOdd()
{
	cout << "CABE is not a valid ID for the family" << endl;
}

int main()
{
	_asm
	{
		//BEEF
		//checks B
		mov ax, pin1;
		mov bx, 1111000000000000b;
		and ax, bx;
		shr ax, 12;
		mov total, ax; //total = 11
		//checks E
		mov ax, pin1;
		mov bx, 0000111100000000b;
		and ax, bx;
		shr ax, 8;
		add ax, total; //total = 11 + 14
		mov total, ax;
		//checks E
		mov ax, pin1;
		mov bx, 0000000011110000b;
		and ax, bx;
		shr ax, 4;
		add ax, total;
		mov total, ax;
		//checks F
		mov ax, pin1;
		mov bx, 0000000000001111b;
		and ax, bx;
		add ax, total;
		mov total, ax;
		cwd;
		idiv two;
		cmp dx, 0;
		Jne showBeefOdd;
		call displayBeefEven;
		Jmp fade;
	showBeefOdd:
		call displayBeefOdd;

		//FADE
	fade:
		//checks F
		mov ax, pin2;
		mov bx, 1111000000000000b;
		and ax, bx;
		shr ax, 12;
		mov total, ax;
		//checks A
		mov ax, pin2;
		mov bx, 0000111100000000b;
		and ax, bx;
		shr ax, 8;
		add ax, total;
		mov total, ax;
		//checks D
		mov ax, pin2;
		mov bx, 0000000011110000b;
		and ax, bx;
		shr ax, 4;
		add ax, total;
		mov total, ax;
		//checks E
		mov ax, pin2;
		mov bx, 0000000000001111b;
		and ax, bx;
		add ax, total;
		mov total, ax;
		cwd;
		idiv two;
		cmp dx, 0;
		Jne showFadeOdd;
		call displayFadeEven;
		Jmp cabe;
	showFadeOdd:
		call displayFadeOdd;

		//CABE
	cabe:
		//checks C
		mov ax, pin3;
		mov bx, 1111000000000000b;
		and ax, bx;
		shr ax, 12;
		mov total, ax; 
		//checks A
		mov ax, pin3;
		mov bx, 0000111100000000b;
		and ax, bx;
		shr ax, 8;
		add ax, total;
		mov total, ax;
		//checks B
		mov ax, pin3;
		mov bx, 0000000011110000b;
		and ax, bx;
		shr ax, 4;
		add ax, total;
		mov total, ax;
		//checks E
		mov ax, pin3;
		mov bx, 0000000000001111b;
		and ax, bx;
		add ax, total;
		mov total, ax;
		cwd;
		idiv two;
		cmp dx, 0;
		Jne showCabeOdd;
		call displayCabeEven;
		Jmp done;
	showCabeOdd:
		call displayCabeOdd;
	done:

	}

	system("pause");
	return 0;
}
