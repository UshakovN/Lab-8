#pragma once
#include <cstdio>

class SETNUM //Класс множество чисел
{
private:
	int size;
	int* x;
	int Element(int z);
	void AddSort(int k, int& z);
	void DelSort(int k, int& z);

public:
	//Lab 8 Создание класса
	SETNUM(int z = 0); //Конструктор
	SETNUM(const SETNUM& set, int z = 1000); //Конструктор копирования
	void Output();
	bool Contains(int z);
	void AddElement(int z = 0);
	void DeleteElement(int z = 0);
	explicit operator int(); //Преобразующая функция
	~SETNUM(); //Деструктор
	SETNUM Union(const SETNUM& other);
	SETNUM Intersection(const SETNUM& other);
	SETNUM Difference(const SETNUM& other);

	//Lab 9 Перегрузка операций
	SETNUM& operator += (int z);
	SETNUM& operator -= (int z);
	SETNUM operator + (const SETNUM& other);
	SETNUM operator - (const SETNUM& other);
	SETNUM operator * (const SETNUM& other);
	SETNUM& operator = (const SETNUM& other);
	bool operator == (const SETNUM& other);
};