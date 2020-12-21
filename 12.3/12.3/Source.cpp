#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};

void enq(Elem*& first, Elem*& last, Info value) {
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL) {
		last->next = tmp;
	}
	tmp->prev = last;
	last = tmp;
	if (first == NULL) {
		first = tmp;
	}
}

void deq(Elem*& first, Elem*& last) {
	Elem* tmp = first->next;
	delete first;
	first = tmp;
	if (first == NULL) {
		last = NULL;
	}
	else {
		first->prev = NULL;
	}
}

void ElemAmount(int& amount) {
	do {
		cout << " Введіть кількість елементів: "; cin >> amount;
		if (amount < 1) {
			cout << " Кількість має бути не меньше 1!" << endl;
		}
	} while (amount < 1);
}

void EnterValues(Elem*& first, Elem*& last, int amount, int*& ar) {
	int value;

	for (int i = 1; i <= amount; i++) {
		cout << " Введіть значення інформаційного поля в елементі №" << i << " : "; cin >> value;
		ar[i - 1] = value;
		enq(first, last, value);
	}
}

void Print(Elem* first) {
	while (first != NULL)
	{
		Info value = first->info;
		cout << value << " ";
		first = first->next;
	}
}

void PrintNewArray(int*& ar, int amount) {
	int answer;
	bool check = false;
	do {
		cout << " Введіть значення інформаційного поля елемента, після якого ви хочете видалити елемент: "; cin >> answer;

		for (int i = 0; i < amount; i++) {
			if (answer == ar[i]) {
				check = true;
			}
		}
		if (check != true) {
			cout << "Такого значення інформаційного поля не існує!" << endl;
		}
	} while (check != true);

	cout << " Нові значення: ";
	for (int i = 0; i < amount; i++) {
		cout << ar[i] << " ";
		if (ar[i] == answer) {
			i++;
		}
	}
	cout << endl;
}

void Delete(Elem*& first, Elem*& last) {
	while (first != NULL) {
		deq(first, last);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int amount = 0;

	Elem* first = NULL, * last = NULL;

	ElemAmount(amount);
	int* ar = new int[amount];
	EnterValues(first, last, amount, ar);
	cout << endl << endl << " Значення: ";
	Print(first);
	cout << endl << endl;
	PrintNewArray(ar, amount);
	cout << endl;
	Delete(first, last);

	delete[] ar;
	return 0;
}