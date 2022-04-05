/*Word: —лово, Ќомера страниц, на которых слово встречаетс€ (от 1 до 10), „исло страниц. —оздать массив объектов. ¬ывести:
а) слова, которые встречаютс€ более чем на N страницах;
б) слова в алфавитном пор€дке;
в) дл€ заданного слова номера страниц, на которых оно встреча-етс€.
*/

#include <conio.h>
#include <string.h>
#include <iostream>
#include<Windows.h>
#include "fstream"
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;


void myopen(ifstream& fin, string fname) {
	fin.open(fname);
	if (!fin.is_open()) {
		cout << "Error open file! " << fname << endl;
		system("pause");

	}

}
void myopen(ofstream& fout, string fname) {
	fout.open(fname);
	if (!fout.is_open()) {
		cout << "Error open file! " << fname << endl;
		system("pause");
		exit;
	}
}

//======= class Word =================
class Word {
	char word[30]; //private
	int amount;
	int* pages;
public:
	Word();
	Word(string, int, string);
	char* getword();
	int getamount();
	void show();
	void showPages();

};

Word::Word(string word_s, int tmp_amount, string pages_s) {
	int n = word_s.length();
	strcpy_s(word, word_s.c_str());  // переводим строку в массив букв
	cout << "word:" << word << endl;
	amount = tmp_amount;
	cout << "amount:" << amount << endl;
	const int camount = amount;
	pages = new int[camount];

	// парсим страницы
	size_t pos = 0;
	string delimiter = ",";
	int i = 0;
	cout << "pages:" << endl;


	while ((pos = pages_s.find(delimiter)) != string::npos) {
		string token;
		token = pages_s.substr(0, pos);
		pages[i] = stoi(token);
		cout << token << endl;
		pages_s.erase(0, pos + delimiter.length());

		i++;
	}
}
Word::Word()
{

}
void Word::show()
{
	cout << "Word :" << word << endl;
	while (true) {
		cout << "Amount :" << amount << endl;
		if (amount > 10) cout << "error404, try another" << endl;
		break;
	}
	cout << "Pages :";
	for (int i = 0; i < amount; i++) {
		cout << pages[i] << " ";
	}
	cout << endl;
	cout << "==============================" << endl;
}
void Word::showPages() {

	for (int i = 0; i < amount; i++) {
		cout << pages[i] << " ";
	}
}

char* Word::getword() { return word; }
int Word::getamount() { return amount; }
void showWordsAmountMoreN(Word spis[], int n)
{
	int amount;
	cout << "Input amount:"; cin >> amount;
	for (int i = 0; i < n; i++)
		if (spis[i].getamount() > amount)spis[i].show();
}
void findPages(Word spis[], int n)
{
	char word[30];
	cout << "Input word to find pages:"; cin >> word;
	cout << "Pages :";
	for (int i = 0; i < n; i++)
		if ((strcmp(spis[i].getword(), word) == 0))spis[i].showPages();
}



void sortWords(Word mas[], int n) {
	int flag = 1;     int i = 1;  Word x = mas[0];
	while (flag) {
		flag = 0;
		for (int j = 0; j < n - i; j++) {
			if (strcmp(mas[j].getword(), mas[j + 1].getword()) > 0) {
				x = mas[j];       mas[j] = mas[j + 1];        mas[j + 1] = x;
				flag = 1;
			}
		}
		i++;
	}
}
//========= main ================
int main() {
	try {
		string fname = "word.txt";

		ifstream fin(fname);


		if (!fin.is_open()) {

			throw 1;

		}
		fin.close();

		myopen(fin, fname);
		int count = 0;
		string line;
		while (getline(fin, line))
			count++;
		//system("pause");
		fin.close();

		myopen(fin, fname);

		string word_in, amount_in, pages_in;
		Word* w = new Word;
		for (int i = 0; i < count / 3; i++)
		{
			int amount;
			getline(fin, word_in);
			getline(fin, amount_in); amount = stoi(amount_in);
			getline(fin, pages_in);
			w[i] = Word(word_in, amount, pages_in);

		}
		fin.close();
		int n = count / 3;
		for (int j = 0; j < n; j++) {
			cout << "==============================" << endl;
			w[j].show();
		}

		sortWords(w, n);

		for (int j = 0; j < n; j++) {
			cout << "==============================" << endl;
			w[j].show();
		}
		cout << "SOS!" << endl;
		findPages(w, n);
		showWordsAmountMoreN(w, n);
		delete[] w;
		cout << "press any key!";

		while (!_kbhit());

	}

	catch (...)
	{
		cout << endl << "Error open file!ssss";
	}
}