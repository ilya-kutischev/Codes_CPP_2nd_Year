#include <iostream>
#include <conio.h>
#include <string.h>
char bufRus[256];
using namespace std;


struct node
{
	int data; //информационное поле узла списка
	node* pNext;
	node(int data = NULL, node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}

};

class List
{
public:
	List();
	List(List& Right);
	~List();
	void pop_front();
	void push_back(int data);
	void clear();
	int GetSize() { return Size; }
	node* operator[](const int index);

	void operator=(List lst);
	void push_front(int data);
	void insert(int data, int index);
	void removeAt(int);
	void pop_back();
	void change_node(int index, int data);
	void show_list();

	friend void choicesSort(List& arrayPtr);
	friend void bubbleSort(List& mas);
	friend void insertionSort(List& x);
	int Size;
	node* head;
};

void List::show_list() {
	node* to_show = (*this).head;
	for (int i = 0; i < Size; i++)
	{

		cout << to_show->data << "  ";
		to_show = to_show->pNext;
	}
	cout << endl;
}

void List::operator=(List lst) {
	(*this).clear();
	node* pTemp = lst.head;
	while (pTemp != 0)
	{
		this->push_back(pTemp->data);
		pTemp = pTemp->pNext;
	}

}

List::List()
{
	Size = 0;
	head = nullptr;
}

List::List(List& Right) : head(0), Size(0)
{
	node* pTemp = Right.head;
	while (pTemp != 0)
	{
		this->push_back(pTemp->data);
		pTemp = pTemp->pNext;
	}

	//cout << "List Copied " << this << endl;
}

List::~List()  // определение деструктора
{
	clear();
}

void List::change_node(int index, int data) {
	node* elem = this->head;
	for (int i = 0; i < index; i++)
	{
		elem = elem->pNext;
	}
	elem->data = data;
}

void List::pop_front()
{
	node* temp = head;
	head = head->pNext;
	delete temp;
	Size--;

}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new node(data);
	}
	else
	{
		node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new node(data);

	}

	Size++;
}

void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}


node* List::operator[](const int index)
{
	int counter = 0;
	node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current;
		}
		current = current->pNext;
		counter++;
	}
}


void List::push_front(int data)  //вперед
{
	head = new node(data, head);
	Size++;
}


void List::insert(int data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		node* newNode = new node(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

void List::removeAt(int index) {

	if (index == 0)
	{
		pop_front();
	}
	else
	{
		node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}

}


void List::pop_back()
{
	removeAt(Size - 1);
}


void choicesSort(List& arrayPtr) // сортировка выбором
{
	int arr_size = arrayPtr.Size;
	for (int repeat_counter = 0; repeat_counter < arr_size; repeat_counter++)
	{
		int temp = arrayPtr[0]->data; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < arr_size; element_counter++)
		{
			if (arrayPtr[repeat_counter]->data < arrayPtr[element_counter]->data)
			{
				//cout << "remove " << arrayPtr[repeat_counter] << " and " << arrayPtr[element_counter] << endl;
				temp = arrayPtr[repeat_counter]->data;
				arrayPtr.change_node(repeat_counter, arrayPtr[element_counter]->data);
				arrayPtr.change_node(element_counter, temp);

			}
		}
	}
}

void bubbleSort(List& mas) {

	int flag = 1; int temp;    int i = 1;
	int arr_size = mas.Size;
	node* to_compare = nullptr;
	while (flag) {

		flag = 0;

		for (int j = 0; j < arr_size - i; j++) {
			if (!j) to_compare = mas[j];
			else to_compare = to_compare->pNext;
			if ((to_compare->data) > ((to_compare->pNext)->data))
			{
				//cout << "remove " << mas[j] << " and " << mas[j + 1] << endl;
				temp = (to_compare->pNext)->data;
				((to_compare->pNext)->data) = (to_compare->data);
				(to_compare->data) = temp;
				//cout << temp << "temp" << endl;
				//mas.change_node(j + 1, mas[j]);
				//mas.change_node(j, temp);

				flag = 1;
			}
		}
		i++;
	}
}

void insertionSort(List& x) {
	int temp = 0;
	int arr_size = x.Size;
	for (int i = 1; i < arr_size; i++)

		for (int j = i; j > 0 && (x[j - 1]->data) < (x[j]->data); j--) {// пока j>0 и элемент j-1 > j, x-массив int
			temp = x[j - 1]->data;
			(x[j - 1]->data) = (x[j]->data);
			(x[j]->data) = temp;
			//x.change_node(j - 1, x[j]->data);
			//x.change_node(j, temp);      // меняем местами элементы j и j-1
		}
}

int main()
{
	setlocale(LC_ALL, "ru");


	List lst;

	cout << "Creating a list:" << endl;

	cout << "How many elemets are we pushing?" << endl;
	int num;
	cin >> num;
	cout << "Write elements to push:" << endl;
	int tmp;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		lst.push_front(tmp);
	}
	while (true) {
		cout << "#####################################" << endl;
		cout << "\nWhat to do?\n0 - exit and sort\n1 - pop_front" << endl <<
			"2 - push_back" << endl <<
			"3 - clear" << endl <<
			"4 - GetSize" << endl <<
			"5 - push_front" << endl <<
			"6 - insert" << endl <<
			"7 - remove elem" << endl <<
			"8 - pop_back" << endl <<
			"9 - change_node" << endl <<
			"10 - show_list " << endl;
		int ch, num, num1, fl = 0;
		cout << endl << ">>";
		cin >> ch;
		cout << endl;
		if (!ch)break;
		if (ch == 1) { lst.pop_front(); fl = 1; }
		if (ch == 2) { cout << "Num: "; cin >> num; lst.push_back(num); fl = 1; }
		if (ch == 3) { lst.clear();  cout << "cleared"; fl = 1; }
		if (ch == 4) { num = lst.GetSize();  cout << "size: " << num << endl; fl = 1; }
		if (ch == 5) { cout << "Num: "; cin >> num; lst.push_front(num); fl = 1; }
		if (ch == 6) { cout << "Index: "; cin >> num; cout << endl << "Data: "; cin >> num1; lst.insert(num, num1); fl = 1; }
		if (ch == 7) { cout << "Index: "; cin >> num; lst.removeAt(num); fl = 1; }
		if (ch == 8) { lst.pop_back();  cout << "popped back"; fl = 1; }
		if (ch == 9) { cout << "Index: "; cin >> num; cout << endl << "Data: "; cin >> num1; lst.change_node(num, num1); fl = 1; }
		if (ch == 10) { lst.show_list(); cout << endl; fl = 1; }
		if (fl)continue;
		else cout << ">>there was found an Error, please check your choice!" << endl <<
			"if this error is unexpected, please contact me on kutischev10@gmail.com" << endl;
	}
	List lst1 = lst;
	cout << endl;
	cout << "#####################################" << endl;
	cout << "Your list:" << endl;
	lst.show_list();
	cout << endl;
	cout << "ChoicesSort";
	cout << endl;
	choicesSort(lst);

	lst.show_list();

	lst = lst1;
	cout << endl;
	cout << "#####################################" << endl;
	lst.show_list();
	cout << endl;
	cout << "BubbleSort" << endl;
	bubbleSort(lst);

	cout << endl;

	lst.show_list();


	lst = lst1;
	cout << endl;
	cout << "#####################################" << endl;
	lst.show_list();
	cout << endl;
	cout << "InsertionSort" << endl;
	insertionSort(lst);
	cout << endl;

	lst.show_list();

	return 0;
}
