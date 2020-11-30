#include "SETNUM.h"

SETNUM::SETNUM(int z) {
	size = 1;
	x = new int[size];
	x[size - 1] = z;
}

SETNUM::SETNUM(const SETNUM& set, int z) {
	size = 0;
	x = new int[set.size];
	int j = 0;
	for (int i = 0; i < set.size; i++) {
		if (set.x[i] <= z) {
			x[j] = set.x[i];
			j++; size++;
		}
	}
}

SETNUM::operator int() {
	int sum = 0;
	for (int i = 0; i < size; i++) { sum += x[i]; }
	if (size != 0) sum /= size;
	else sum = 0;
	return sum;
}

void SETNUM::AddSort(int k, int& z) {
	int* y = new int[++size]; int i;
	for (i = 0; i < k; i++) { y[i] = x[i]; }
	y[i] = z;
	for (; i < size; i++) { y[i + 1] = x[i]; }
	delete[] x; x = y;
	return;
}

bool SETNUM::Contains(int z) {
	int i = 0; bool fl = false;
	while (!fl && i < size) {
		if (x[i] == z) fl = true;
		else i++;
	}
	return fl;
}

int SETNUM::Element(int z) {
	int i = 0; bool fl = false;
	while (!fl && i < size) {
		if (x[i] > z) fl = true;
		else i++;
	}
	return i;
}

void SETNUM::AddElement(int z) {
	if (!Contains(z)) {
		AddSort(Element(z), z);
	}
	return;
}

void SETNUM::DelSort(int k, int& z) {
	int* y = new int[--size]; int i;
	for (i = 0; i < k - 1; i++) { y[i] = x[i]; }
	for (; i < size; i++) { y[i] = x[i + 1]; }
	delete[] x; x = y;
	return;
}

void SETNUM::DeleteElement(int z) {
	if (Contains(z)) {
		DelSort(Element(z), z);
	}
	return;
}

void SETNUM::Output() {
	printf("Множество чисел: ");
	for (int i = 0; i < size; i++) { printf("%d ", x[i]); }
	printf("\n");
}

SETNUM::~SETNUM() {
	delete[] x; 
	size = 0;
}

/*
Операция присваивания; операции сравнения; операция «+» – объединение множеств;
Операция «*» – пересечение множеств; операция «-» – вычитание множеств;
Операция «+=» – добавление нового элемента в множество.
*/

SETNUM& SETNUM::operator = (const SETNUM& other) {
	size = other.size;
	for (int i = 0; i < other.size; i++) {
		x[i] = other.x[i];
	}
	return *this;
}

bool SETNUM::operator == (const SETNUM& other) {
	int i = 0; bool fl = true;
	while (i < size && fl) {
		if (x[i] != other.x[i]) fl = false;
		i++;
	}
	return fl;
}

SETNUM& SETNUM::operator += (int z) {
	AddElement(z);
	return *this;
}

SETNUM SETNUM::operator + (const SETNUM& other) {
	SETNUM s = *this;
	for (int i = 0; i < other.size; i++) {
		s.AddElement(other.x[i]);
	}
	return s;
}

SETNUM SETNUM::operator - (const SETNUM& other) {
	SETNUM s = *this;
	for (int i = 0; i < other.size; i++) {
		s.DeleteElement(other.x[i]);
	}
	return s;
}

SETNUM SETNUM::operator * (const SETNUM& other) {
	SETNUM s1; SETNUM s2 = other;
	for (int i = 0; i < size; i++) {
		if (this->Contains(x[i]) && s2.Contains(x[i])) {
			s1.AddSort(Element(x[i]), x[i]);
		}
	}
	s1.DeleteElement();
	return s1;
}

SETNUM& SETNUM::operator -= (int z) {
	DeleteElement(z);
	return *this;
}

/*Стандартные функции для множества в виде методов.*/

SETNUM SETNUM::Union(const SETNUM& other) {
	SETNUM s = *this;
	for (int i = 0; i < other.size; i++) {
		s.AddElement(other.x[i]);
	}
	return s;
}

SETNUM SETNUM::Intersection(const SETNUM& other) {
	SETNUM s1; SETNUM s2 = other;
	for (int i = 0; i < size; i++) {
		if (this->Contains(x[i]) && s2.Contains(x[i])) {
			s1.AddSort(Element(x[i]), x[i]);
		}
	}
	s1.DeleteElement();
	return s1;
}

SETNUM SETNUM::Difference(const SETNUM& other) {
	SETNUM s = *this;
	for (int i = 0; i < other.size; i++) {
		s.DeleteElement(other.x[i]);
	}
	return s;
}


/*
void SETNUM::Change(int z) {
	int i = 0; bool fl = false;
	while (!fl && i < size) {
		if (x[i] == z) fl = true;
		else if (x[i] > z) { x = AddSort(i, z); fl = true; }
		i++;
	}
	if (!fl) { x = AddSort(i, z); }
}
*/






