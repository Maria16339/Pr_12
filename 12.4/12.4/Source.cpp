#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL) {
		Elem* T = L;
		while (T->link != L)
			T = T->link;
		T->link = tmp;
	}
	else {
		L = tmp;
	}
	tmp->link = L;
}

void remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link;
	if (T != L) {
		Elem* tmp = L->link;
		delete L;
		L = tmp;
		T->link = L;
	}
	else {
		delete L;
		L = NULL;
	}
}

void EnterAmount(int& amount) {
	do {
		cout << " ������ ������� �������� � �������: "; cin >> amount;
		if (amount < 1) {
			cout << " ʳ������ �� ���� ���� ������ 1!" << endl;
		}
	} while (amount < 1);
}

void EnterValues(Elem*& L, int amount) {
	int value;
	for (int i = 0; i < amount; i++) {
		cout << " ������ �������� �������������� ���� �������� �" << i + 1 << " : "; cin >> value;
		insert(L, value);
	}
}

void Print(Elem* L) {
	if (L == NULL) {
		return;
	}
	Elem* first = L;
	cout << " " << L->info;

	while (L->link != first) {
		L = L->link;
		cout << " " << L->info;
	}
	cout << endl;
}

void ToArray(Elem* L, int*& ar, int amount) {
	for (int i = 0; i < amount; i++) {
		ar[i] = L->info;
		if (L->link != L) {
			L = L->link;
		}
	}
}

void CheckMain(Elem* L1, Elem* L2, int amount) {
	bool finalanswer = true;
	bool* answer = new bool[amount];

	int* l1 = new int[amount];
	int* l2 = new int[amount];

	ToArray(L1, l1, amount);
	ToArray(L2, l2, amount);

	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++) {
			if (l1[i] == l2[j]) {
				answer[i] = true;
			}
		}
	}

	for (int i = 0; i < amount; i++) {
		if (answer[i] != true) {
			finalanswer = false;
		}
	}

	cout << endl;
	if (finalanswer == true) {
		cout << " �� �������� ������ 'L1' ������� � ������ 'L2'." << endl;
	}
	else if (finalanswer == false) {
		cout << " �� �� �������� ������ 'L1' ������� � ������ 'L2'!" << endl;
	}
	delete[] answer;
	delete[] l1;
	delete[] l2;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* L1 = NULL;
	Elem* L2 = NULL;

	int amount;

	EnterAmount(amount);

	cout << endl << " ������ 'L1':" << endl;
	EnterValues(L1, amount);
	cout << endl << " ������ 'L2':" << endl;
	EnterValues(L2, amount);

	cout << endl << " �������� ������ 'L1':";
	Print(L1);
	cout << endl << " �������� ������ 'L2':";
	Print(L2);

	CheckMain(L1, L2, amount);
	remove(L1);
	remove(L2);
	return 0;
}