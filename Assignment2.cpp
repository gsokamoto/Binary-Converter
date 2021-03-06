/**
Assignmet 2: A program to convert decimal values into binary, octal, or a hexadecimal value.
@author Grant Okamoto
@version 1.0
*/
#include <iostream>
#define MAX 100

using namespace std;

bool check_empty(int *p)
{
	return (*p == -1);	//returns true if empty, else returns false
}

bool check_full(int *p)
{
	return (*p == 99);	//returns true if full, else returns false
}

void push(int *p, int stack[], int entry)
{
	//if full, exits the program
	if (check_full(p) == true)
	{
		cout << "Stack Overflow";
		exit(0);
	}
	//pushes an entry to the top
	else
	{
		*p = *p + 1;
		stack[*p] = entry;
	}
}

int pop(int *p, int stack[])
{
	//if empty, does not pop
	if (check_empty(p) == true)
	{
		cout << "Stack Underflow";
		exit(0);
	}
	//pops an entry from the top
	else
	{
		int entry = stack[*p];
		*p = *p - 1;
		return entry;
	}
}

void Binary(int* p, int stack[], int entry) {
	//converts decimal to binary
	cout << "Binary: ";
	while (entry != 0)
	{
		push(p, stack, entry % 2);
		entry /= 2;
	}

	//prints out all of the values off the stack
	while (!check_empty(p))
	{
		cout << pop(p, stack);
	}
	cout << endl;
}

void Octal(int* p, int stack[], int entry) {
	//converts decimal to octal
	cout << "Octal: ";
	while (entry != 0)
	{
		push(p, stack, entry % 8);
		entry /= 8;
	}

	//prints out all of the values off the stack
	while (!check_empty(p))
	{
		cout << pop(p, stack);
	}
	cout << endl;
}

void Hexa(int* p, int stack[], int entry) {
	//converts decimal to octal
	cout << "Hexadecimal: ";
	while (entry != 0)
	{
		push(p, stack, entry % 16);
		entry /= 16;
	}

	//prints out all of the values off the stack
	while (!check_empty(p))
	{
		int temp = pop(p, stack);
		if (temp == 10)
		{
			cout << "A";
		}
		else if (temp == 11)
		{
			cout << "B";
		}
		else if (temp == 12)
		{
			cout << "C";
		}
		else if (temp == 13)
		{
			cout << "D";
		}
		else if (temp == 14)
		{
			cout << "E";
		}
		else if (temp == 15)
		{
			cout << "F";
		}
		else
		{
			cout << temp;
		}
	}
	cout << endl;
}

int main()
{
	//variables
	int* p = nullptr;
	int index;
	p = &index;
	*p = -1;
	int entry = 0;
	int stack[MAX];
	int input = -1;

	while (true)
	{
		//requesting user input
		cout << "Please enter the decimal value of the number you would like to convert:" << endl;
		cin >> entry;
		cout << "Select a new base number:" << endl;
		cout << "1. Base 2 (Binary)" << endl;
		cout << "2. Base 8 (Octal)" << endl;
		cout << "3. Base 16 (Hexadecimal)" << endl ;
		cin >> input;
		cout << endl;

		//does binary function
		if (input == 1)
		{
			cout << "Input (Decimal): " << entry << endl;
			Binary(p, stack, entry);
		}
		//does octal function
		else if (input == 2)
		{
			cout << "Input (Decimal): " << entry << endl;
			Octal(p, stack, entry);
		}
		//does hexidecimal function
		else if (input == 3)
		{
			cout << "Input (Decimal): " << entry << endl;
			Hexa(p, stack, entry);
		}
		cout << endl;
	}
}
