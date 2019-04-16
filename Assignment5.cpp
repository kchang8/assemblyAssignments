#include <iostream>
using namespace std;

int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
int i, check, totalShirts, totalMedium, totalSS, totalRed;

void displayShirts()
{
	cout << "The total number of all shirts: " << totalShirts << endl;
}

void displayMedium()
{
	cout << "The total number of medium size shirts: " << totalMedium << endl;
}

void displaySS()
{
	cout << "The total number of short sleeved shirts: " << totalSS << endl;
}

void displayRed()
{
	cout << "The total number of red shirts: " << totalRed << endl;
}

int main()
{
	_asm
	{
		//computes the total number of shirts
		mov eax, 0;
		mov i, 0;
		lea esi, a;
	forloop:
		cmp i, 18;
		Jg showShirts;
		add eax, [esi]; //eax = 0 + number in first index
		add esi, 4; //goes to next index
		inc i;
		Jmp forloop;
	showShirts:
		mov totalShirts, eax;
		call displayShirts;

		//computes the total number of medium shirts
		mov eax, 0;
		mov i, 0;
		mov check, 0; //index for third dimension of a
		lea esi, a;
		add esi, 8; //makes the array go to the medium column a[0][1][0]
	forloop2:
		cmp i, 6;
		Jg showMedium;
		add eax, [esi];
		inc i;
		cmp check, 0;
		Je checkZero;
		add esi, 20;
		mov check, 0;
		Jmp forloop2;
	checkZero:
		add esi, 4;
		mov check, 1;
		Jmp forloop2;
	showMedium:
		mov totalMedium, eax;
		call displayMedium;

		//computes the total number of short sleeves shirts
		mov eax, 0;
		mov i, 0;
		lea esi, a;
	forloop3:
		cmp i, 9;
		Jg showSS;
		add eax, [esi];
		add esi, 8;
		inc i;
		Jmp forloop3;
	showSS:
		mov totalSS, eax;
		call displaySS;

		//computes the total number of red shirts
		mov eax, 0;
		mov i, 0;
		lea esi, a;
	forloop4:
		cmp i, 6;
		Jge showRed;
		add eax, [esi];
		add esi, 4;
		inc i;
		Jmp forloop4;
	showRed:
		mov totalRed, eax;
		call displayRed;
	}

	system("pause");
	return 0;
}