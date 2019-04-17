#include <iostream>
using namespace std;

int b[4][4] = { { 10, 20, 30, 40 }, { 20, 10, 40, 30 }, { 5, 15, 20, 25 }, { 30, 25, 20, 15 } };
int i, totalShirts, totalLarge, totalBlack;

void displayShirts()
{
	cout << "The total number of all shirts are: " << totalShirts << endl;
}

void displayLarge()
{
	cout << "The total number of large shirts are: " << totalLarge << endl;
}

void displayBlack()
{
	cout << "The total number of black shirts are: " << totalBlack << endl;
}

int main()
{
	_asm
	{
		//computes total number of shirts
		mov ebx, 0; //ebx = 0, ebx will store the computed value
		mov i, 0; //i = 0
		lea esi, b; //makes 2D array
	forloop:
		cmp i, 16;
		Jg showShirts;
		add ebx, [esi]; //makes ebx = 0 + (the first index number)
		add esi, 4; //adds 4 to index because the data type is int and it makes it go to next box
		inc i;
		Jmp forloop;
	showShirts:
		mov totalShirts, ebx;
		call displayShirts;

		//computes the total number of large shirts
		mov ecx, 0;
		mov i, 0;
		lea esi, b;
		add esi, 8; //goes to the column where the large shirts are, b[0][2]
	forloop2:
		cmp i, 4; //only compares the number of large shirts indexes
		Jg showLarge;
		add ecx, [esi]; //ecx = 0 + index at b+8(first value of large shirts)
		add esi, 16; //makes b array go to the next large shirts value at b+24
		inc i;
		Jmp forloop2;
	showLarge:
		mov totalLarge, ecx;
		call displayLarge;

		//computes the total number of black shirts
		mov ecx, 0;
		mov i, 0;
		lea esi, b;
		add esi, 48; //goes to the row where the black shirts are, b[3][0]
	forloop3:
		cmp i, 4; //compares the number of black shirts indexes
		Jg showBlack;
		add ecx, [esi]; //ecx = 0 + index at b+48(first value of black shirts)
		add esi, 4; //goes to next index of the row
		inc i;
		Jmp forloop3;
	showBlack:
		mov totalBlack, ecx;
		call displayBlack;
	}

	system("pause");
	return 0;
}
