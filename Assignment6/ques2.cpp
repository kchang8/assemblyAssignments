#include <iostream>
using namespace std;

int a[5] = { 9, 3, 22, 8, 1 };
int i, j;

int main()
{
	cout << "Original array a: ";
	for (int x = 0; x < 5; x++)
	{
		cout << a[x] << " ";
	}
	cout << endl;

	_asm
	{
		lea esi, a; //makes array
		mov i, 0;
	forloop1:
		cmp i, 4;
		Jg done;
		Jmp forloop2;
	increment:
		inc i;
		mov j, 0;
		lea esi, a; //updates new array
		Jmp forloop1;
	forloop2:
		mov eax, 5;
		sub eax, i;
		sub eax, 1;
		cmp j, eax;
		Jge increment;
		inc j;
		mov ebx, [esi]; //ebx is first value of array
		add esi, 4; //goes to the next value, esi is the second value now
		mov ecx, [esi]; //makes ecx hold the second value
		cmp ebx, ecx;
		Jl forloop2;
		mov [esi], ebx; //ebx = second value(b+4)
		sub esi, 4;
		mov [esi], ecx;
		add esi, 4; //goes to the second position
		Jmp forloop2;
	done:
		
	}

	cout << "Sorted array a: ";
	for (int x = 0; x < 5; x++)
	{
		cout << a[x] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
