#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int MAX = 5;
const int LEN = 20;
class Stack {

	int amount;
	char text[MAX][LEN];
public:
	Stack();

	int getamount();
	void show();
	void init(int n, char txt[LEN]) { strcpy_s(text[n], txt); }
	void inc_amount() { amount++; }
	char* pop() { amount--; return text[amount]; }
	void delete_odd();
	Stack operator+(char* txt);
	Stack operator-() { (*this).pop(); return *this; }
	friend void push(Stack& a, char* txt);

};
Stack::Stack()
{
	while (1) {
		cout << "Input amount of members:\n";
		cin >> amount;
		if (amount <= MAX) break;
		else { cout << "Error404\n"; }
	}
	cout << "Input " << amount << " members:\n";
	for (int i = 0; i < amount; i++) {
		cin >> text[i];
	}
	cout << "==============================" << endl;
}


void Stack::delete_odd() {
	//cout << amount << "   " << amount / 2;
	if (amount % 2) {
		for (int i = 0; i < amount / 2; i++) {

			strcpy_s(text[i], text[2 * i + 1]);

		}
	}
	else {
		for (int i = 0; i < amount / 2; i++) {

			strcpy_s(text[i], text[2 * i]);

		}
	}


	amount = amount / 2;
}



void Stack::show() {
	cout << endl;
	for (int i = 0; i < amount; i++) {
		cout << text[amount - i - 1] << endl;
	}
}


int Stack::getamount() { return amount; }


void push(Stack& a, char* txt) {
	if (a.getamount() + 1 > MAX) { cout << "Overloaded Stack" << endl; return; }
	a.inc_amount();
	a.init(a.amount - 1, txt);
	cout << "pushed succesfully--" << a.text[a.amount - 1] << endl;
}
Stack Stack::operator+(char* txt) {
	push(*this, txt);
	return *this;
}



int main() {
	Stack* spis;
	int n;
	cout << "Input a amount of stacks: \n"; cin >> n;
	cout << "==============================" << endl;
	spis = new Stack[n];
	cout << "==============================" << endl;
	for (int i = 0; i < n; i++) {
		cout << "==============================" << endl;
		spis[i].show();
	}
	cout << "write member to push: \n" << endl;
	char txt[LEN];
	cin >> txt;
	cout << endl;
	for (int i = 0; i < n; i++) {
		spis[i] + txt;
	}
	for (int i = 0; i < n; i++) {
		cout << "==============================" << endl;
		spis[i].show();
	}
	for (int i = 0; i < n; i++) {
		cout << "==============================" << endl;
		-(spis[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << "==============================" << endl;
		spis[i].show();
	}
	for (int i = 0; i < n; i++) {
		spis[i].delete_odd();
	}
	for (int i = 0; i < n; i++) {
		cout << "==============================" << endl;
		spis[i].show();
	}

	cout << "press any key!";
	while (!_kbhit());
}