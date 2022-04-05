#include <iostream>
#include <conio.h>
#include <string.h>
char bufRus[256];
using namespace std;


template<typename Type>
struct node
{
	int data; //информационное поле узла списка
	node* pNext;
	node(Type data = Type(), node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}

};


template<typename Type>
class List
{
public:

	List();
	List(List& Right);
	~List();
	void pop_front();
	void push_back(Type data);
	void clear();
	int GetSize() { return Size; }
	node<Type>* operator[](const int index);
	void operator=(List lst);
	void push_front(Type data);
	void insert(Type data, int index);
	void removeAt(int);
	void pop_back();
	void change_node(int index, Type data);
	void show_list();

	friend void choicesSort(List<Type>& arrayPtr);
	friend void bubbleSort(List<Type>& mas);
	friend void insertionSort(List<Type>& x);



	int Size;
	node<Type>* head;
};

template<typename Type>
void List<Type>::show_list() {
	node<Type>* to_show = (*this).head;
	for (int i = 0; i < Size; i++)
	{

		cout << to_show->data << "  ";
		to_show = to_show->pNext;
	}
	cout << endl;
}

template<typename Type>
void List<Type>::operator=(List lst) {
	(*this).clear();
	node<Type>* pTemp = lst.head;
	while (pTemp != 0)
	{
		this->push_back(pTemp->data);
		pTemp = pTemp->pNext;
	}

}

template<typename Type>
List<Type>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename Type>
List<Type>::List(List& Right) : head(0), Size(0)
{
	node<Type>* pTemp = Right.head;
	while (pTemp != 0)
	{
		this->push_back(pTemp->data);
		pTemp = pTemp->pNext;
	}

	//cout << "List Copied " << this << endl;
}

template<typename Type>
List<Type>::~List()  // определение деструктора
{
	clear();
}

template<typename Type>
void List<Type>::change_node(int index, Type data) {
	node<Type>* elem = this->head;
	for (int i = 0; i < index; i++)
	{
		elem = elem->pNext;
	}
	elem->data = data;
}

template<typename Type>
void List<Type>::pop_front()
{
	node<Type>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;

}

template<typename Type>
void List<Type>::push_back(Type data)
{
	if (head == nullptr)
	{
		head = new node<Type>(data);
	}
	else
	{
		node<Type>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new node<Type>(data);

	}

	Size++;
}

template<typename Type>
void List<Type>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename Type>
node<Type>* List<Type>::operator[](const int index)
{
	int counter = 0;
	node<Type>* current = this->head;
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

template<typename Type>
void List<Type>::push_front(Type data)  //вперед
{
	head = new node<Type>(data, head);
	Size++;
}

template<typename Type>
void List<Type>::insert(Type data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		node<Type>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		node<Type>* newNode = new node<Type>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<typename Type>
void List<Type>::removeAt(int index) {

	if (index == 0)
	{
		pop_front();
	}
	else
	{
		node<Type>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		node<Type>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}

}

template<typename Type>
void List<Type>::pop_back()
{
	removeAt(Size - 1);
}

template<typename Type>
void choicesSort(Type& arrayPtr) // сортировка выбором
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

template<typename Type>
void bubbleSort(Type& mas) {

	int flag = 1; int temp;    int i = 1;
	int arr_size = mas.Size;
	node<Type>* to_compare = nullptr;
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

template<typename Type>
void insertionSort(Type& x) {
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


	List<int> lst;

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
	List<int> lst1 = lst;
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
