#include <iostream>
#include <iomanip>
using namespace std;

float a, b, c, h;
float two = 2.0, half = 0.5;
float triArea, triPerimeter;
float l, w;
float rectArea, rectPerimeter;

void displayTriangle()
{
	cout << "Triangle" << endl;
	cout << "   Area......................" << fixed << setprecision(2) << triArea << endl;
	cout << "   Perimeter................." << fixed << setprecision(2) << triPerimeter << endl;
}

void displayRectangle()
{
	cout << "Rectangle" << endl;
	cout << "   Area......................" << fixed << setprecision(2) << rectArea << endl;
	cout << "   Perimeter................." << fixed << setprecision(2) << rectPerimeter << endl;
}

int main()
{
	cout << "     /|\\                 ------------------       " << endl;
	cout << "    / | \\               |                  |      " << endl;
	cout << "   / h|  \\              |                  | width" << endl;
	cout << "a /   |   \\ b           |                  |      " << endl;
	cout << " /    |    \\            |                  |      " << endl;
	cout << " -----------              ------------------       " << endl;
	cout << "      c                         length             " << endl;

	cout << "Enter the values of a, b, c, and h: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the values of length and width of the rectangle: ";
	cin >> l >> w;
	cout << endl;

	_asm
	{
		//TRIANGLE
		//computes area
		fld half;
		fld c;
		fmul;
		fld h;
		fmul;
		fstp triArea;
		//computes perimeter
		fld a;
		fld b;
		fadd;
		fld c;
		fadd;
		fstp triPerimeter;
		call displayTriangle;

		//RECTANGLE
		//computes area
		fld l;
		fld w;
		fmul;
		fstp rectArea;
		//computes perimeter
		fld two;
		fld l;
		fmul;
		fld two;
		fld w;
		fmul;
		fadd;
		fstp rectPerimeter;
		call displayRectangle;
	}

	system("pause");
	return 0;
}
