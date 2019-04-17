#include <iostream>
using namespace std;

short printers;
short drives;
short ram;
int sixteen = 16;

void displayPrinters()
{
	cout << "Number of printers connected to the computer: " << printers << endl;
}

void displayFloppyDrives()
{
	cout << "Number of floppy drives: " << drives << endl;
}

void displayRAMsize()
{
	cout << "The size of the RAM: " << ram << "GB" << endl;
}

int main()
{
	_asm
	{
		//printers
		mov ax, 1100111010011100b;
		mov bx, 1100000000000000b;
		and ax, bx;
		rol ax, 2;
		mov printers, ax;
		call displayPrinters;

		//floppy drives
		mov ax, 1100111010011100b;
		mov bx, 0000000011000000b;
		and ax, bx; //0000 0000 1000 0000
		rol ax, 10;
		add ax, 1;
		mov drives, ax;
		call displayFloppyDrives;

		//RAM size
		mov ax, 1100111010011100b;
		mov bx, 0000000000001100b;
		and ax, bx; //0000 0000 0000 1100
		shr ax, 2;
		add ax, 1; //4
		imul sixteen;
		mov ram, ax;
		call displayRAMsize;
	}

	system("pause");
	return 0;
}
