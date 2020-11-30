/*Вариант 2. Разработать класс для представления объекта множество чисел. 
Определить конструктор с одним параметром-числом, который задаёт элемент множества,
который можно использовать как конструктор умолчания. 
Определить конструктор, которые копирует в новое множество элементы другого множества, 
не превышающие заданное значение, который можно использовать как конструктор копирования. 
Определить преобразования из переменной типа int в множество и из множества в переменную типа int.
Определить деструктор. */

#include <cstdio>
#include <locale.h>
#include "SETNUM.h"
#pragma warning (disable:6064)

int main() {
	setlocale(LC_ALL, "RUS");
	int z = 0; char end = NULL;
	printf("Ввод множества.\n");
	printf("Проинициализируйте множество числом [Set].\n");
	scanf_s("%d", &z);
	SETNUM Set(z);
	Set.Output();

	printf("Нажмите z чтобы завершить.\n");
	while (end != 'z') {
		printf("Введите число, которое следует добавить в множество [Set].\n");
		scanf_s("%d", &z);
		Set.AddElement(z);
		Set.Output();
		scanf_s("%c", &end); }
	printf("Числа добавлены.\n"); end = NULL;

	printf("Введите заданное значение:\n");
	scanf_s("%d", &z);
	printf("Множество, элементы которого не превышают заданное значение [Copy].\n");
	SETNUM Copy(Set, z);
	Copy.Output();
	printf("Множество скопировано.\n");

	while (end != 'z') {
		printf("Введите число, которое следует удалить из множества [Set].\n");
		scanf_s("%d", &z);
		Set.DeleteElement(z);
		Set.Output();
		scanf_s("%c", &end);}
	printf("Числа удалены.\n"); end = NULL;

	printf("Преобразование из переменной типа int в множество [ConvertInt].\n");
	printf("Введите переменную типа int:\n");
	scanf_s("%d", &z);
	SETNUM ConvertInt(z);
	ConvertInt.Output();

	z = (int)Set;
	printf("Преобразование из множества [Set] в переменную типа int: %d \n", z);
	

	/*Операция присваивания; операции сравнения; операция «+» – объединение множеств; 
	Операция «*» – пересечение множеств; операция «-» – вычитание множеств; 
	Операция «+=» – добавление нового элемента в множество. */

	printf("Тесты перегрузок операторов. \n");

	while (end != 'z') {
		printf("Введите число, которое следует добавить в множество [Set]: ");
		scanf_s("%d", &z);
		Set += z;
		Set.Output();
		scanf_s("%c", &end);}
	printf("Числа добавлены.\n"); end = NULL;

	printf("[Set] "); Set.Output();
	printf("[Copy] "); Copy.Output();
	printf("Равенство множеств = %d.\n", Set == Copy);

	printf("Перегрузка + :\n");
	SETNUM Temp1 = (Set + Copy);
	Temp1.Output();

	printf("Перегрузка - :\n");
	SETNUM Temp2 = (Set - Copy);
	Temp2.Output();

	printf("Перегрузка * :\n");
	SETNUM Temp3 = (Set * Copy);
	Temp3.Output();

	/*
	while (end != 'z') {
		printf("Введите число, которое следует удалить из множества [Set]: ");
		scanf_s("%d", &z);
		Set -= z;
		Set.Output();
		scanf_s("%c", &end);
	}
	printf("Числа удалены.\n"); end = NULL;
	*/

	printf("Присваивание Set = Copy. \n");
	Set = Copy;
	printf("[Set] "); Set.Output();
	printf("[Copy] "); Copy.Output();
	printf("Равенство множеств = %d. \n", Set == Copy);

	/*
	printf("Тесты стандартных методов. \n");

	printf("Объединение множеств. \n");
	SETNUM UnionS = Set.Union(Copy); 
	UnionS.Output();
	printf("Пересечение множеств. \n");
	SETNUM IntersectionS = Set.Intersection(Copy); 
	IntersectionS.Output();
	*/

	return 0;
}
