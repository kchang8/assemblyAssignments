#include <iostream>
using namespace std;

int main()
{
	int a, b, c, h;
	int two;
	int triArea, triPerimeter;
	int l, w;
	int rectArea, rectPerimeter;
	
	cout << "     /|\\                 ------------------   " << endl;
	cout << "    / | \\               |                  |  " << endl;
	cout << "   / h|  \\              |                  | w" << endl;
	cout << "a /   |   \\ b           |                  |  " << endl;
	cout << " /    |    \\            |                  |  " << endl;
	cout << " -----------              ------------------   " << endl;
	cout << "      c                          len           " << endl;

	cout << "Enter the values of a, b, c, and h: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the values of length and width of the rectangle: ";
	cin >> l >> w;
	cout << endl;

	_asm
	{
		//------TRIANGLE-------
		//calulates the area
		mov two, 2; //two 
		mov eax, c; //eax = c
		imul h; //edx: eax = hc
		idiv two; //eax = hc/2
		mov triArea, eax; //triangle area = hc/2

		//calulates the perimeter
		mov eax, a; //ebx = a
		add eax, b; //ebx = a+b
		add eax, c; //ebx = a+b+c
		mov triPerimeter, eax;

		
		//-----RECTANGLE-------
		//calulates the area
		mov eax, l; //eax = length
		imul eax, w; //eax = lw
		mov rectArea, eax;

		//calculates the perimeter
		mov eax, w; //eax = width
		add eax, l; //eax = l+w
		imul eax, two; //eax = 2(l+w)
		mov rectPerimeter, eax;
	}

	cout << "Triangle:\n";
	cout << "	Area......................." << triArea << "\n";
	cout << "	Perimeter.................." << triPerimeter << "\n";
	cout << "Rectangle:\n";
	cout << "	Area......................." << rectArea << "\n";
	cout << "	Perimeter.................." << rectPerimeter << "\n";

	system("pause");
	return 0;
}
