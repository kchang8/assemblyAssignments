#include <iostream>
#include <ctime>
using namespace std;

char letterChoice, yesNo1, yesNo2;
int x, z, ans;
int correctCount, wrongCount;

void generateRand()
{
	srand(time(0));
	x = rand() % 100 + 1;
	z = rand() % 100 + 1;
}

void getAddition()
{
	cout << x << " + " << z << "? ";
	cin >> ans;
}

void getSubtraction()
{
	cout << x << " - " << z << "? ";
	cin >> ans;
}

void displayChoice()
{
	cout << "Enter your choice(a/b)? ";
	cin >> letterChoice;
}

void cont()
{
	cout << "Continue(y/n)? ";
	cin >> yesNo1;
}

void displayCorrect()
{
	cout << "CORRECT" << endl;
}

void displayWrong()
{
	cout << "WRONG" << endl;
}

void displayAnswers()
{
	cout << "No. of CORRECT answers = " << correctCount << endl;
	cout << "No. of WRONG answers = " << wrongCount << endl;
}

void doneQuestion()
{
	cout << "Are you done(y/n)? ";
	cin >> yesNo2;
}

void displayNice()
{
	cout << "Have a nice day" << endl;
}

int main()
{
	cout << "----------Practice Addition & Subtraction---------------\n";
	cout << "a.   Practice Addition\n";
	cout << "b.   Practice Subtraction\n";

	_asm
	{
	doloop:
		mov correctCount, 0;
		mov wrongCount, 0;
		call displayChoice;
		cmp letterChoice, 'a';
		Jne checkB;
	calculateAdd:
		call generateRand;
		call getAddition;
		mov eax, x; //eax = x(random num)
		add eax, z; //eax = x+z(random num)
		cmp ans, eax;
		Jne showWrongA;
		call displayCorrect;
		inc correctCount;
		Jmp contloopA;
	checkB:
		cmp letterChoice, 'b';
		Jne done;
	calculateSub:
		call generateRand;
		call getSubtraction;
		mov eax, x; //eax = x(random num)
		sub eax, z; //eax = x-z(random num)
		cmp ans, eax;
		Jne showWrongS;
		call displayCorrect;
		inc correctCount;
		Jmp contloopS;
	contloopA:
		call cont;
		cmp yesNo1, 'y';
		Jne choiceNo;
		Jmp calculateAdd;
	contloopS:
		call cont;
		cmp yesNo1, 'y';
		Jne choiceNo;
		Jmp calculateSub;
	showWrongA:
		call displayWrong;
		inc wrongCount;
		Jmp contloopA;
	showWrongS:
		call displayWrong;
		inc wrongCount;
		Jmp contloopS;
	choiceNo:
		cmp yesNo1, 'n';
		Jne done;
		call displayAnswers;
		call doneQuestion;
		cmp yesNo2, 'n';
		Je doloop;
		cmp yesNo2, 'y'; //if yesno2 does no equal n, check if it's y
		Je niceDay;
	niceDay:
		call displayNice;

	done:

	}

	system("pause");
	return 0;
}
