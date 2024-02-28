// Курсач Сабрина.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//дек последовательностей

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//------------------------------------------------------------------------Последовательность-----------------------------------------------------------------
struct Zven
{
	float simv;                   //Данные
	struct Zven* next;            //Указатель на след эл
};

struct Spisok
{
	Zven* head;                   //Указатель на начало
	Zven* current;                //Указатель (бегунок)
	Zven* current2;
	Zven* tail;					 //Указатель на конец
};
//------------------------------------------------------------------------Последовательность-----------------------------------------------------------------

//------------------------------------------------------------------------ДЕК-----------------------------------------------------------------
struct listElement
{
	Spisok value;
	listElement* nextElement = NULL;
	listElement* prevElement = NULL;
};
struct listCollection
{
	listElement* head;
	listElement* current;
	listElement* tail;
}list2;
//------------------------------------------------------------------------ДЕК-----------------------------------------------------------------



//------------------------------------------------------------------------ДЕК-Функции-----------------------------------------------------------------

int StartWork() {  //начать работу с ДЕКом

	list2.current = NULL;
	list2.head = NULL;
	list2.tail = NULL;
	return 0;

}

void DeleteAll()
{
	listElement* node = list2.head;
	listElement* badElement = node;
	while (node->nextElement != NULL)
	{
		badElement = node;
		node = node->nextElement;
		free(badElement);
	}
	list2.head = NULL;
	list2.current = NULL;
	list2.tail = NULL;
}
void Deletehead(listCollection* list2)
{
	list2->current = list2->head;
	if(list2->current->nextElement != NULL)
	{
		listElement* badNode = list2->current;
		list2->current = list2->current->nextElement;
		list2->head = list2->current;
		free(badNode);

	}
	else 
	{
		free(list2->current);
		list2->head = NULL;
		
	}
	
}
void Deletetail(listCollection* list2)
{
	list2->current = list2->tail;
	if (list2->current->prevElement != NULL) 
	{
		listElement* badNode = list2->current;
		list2->current = list2->current->prevElement;
		list2->tail = list2->current;
		list2->current->nextElement = NULL;
		free(badNode);
	}
	else 
	{
		free(list2->current);
		list2->tail = NULL;
		list2->current->nextElement = NULL;
		list2->head = NULL;
	}
}


void PrintList2(Spisok collection)                   //печать (Вспомогательная)
{
	Zven* node = collection.head;
	while (1)
	{
		printf("%f", node->simv);

		node = node->next;
		if (node == NULL)
		{
			printf("|");
			break;
		}
	}
}

void PrintList()              //печать ДЕКа
{
	listElement* node = list2.head;
	while (1) {
		PrintList2(node->value);
		if (node == list2.current)
			printf(" ");
		node = node->nextElement;
		if (node == NULL) {
			printf("\n");
			break;
		}
	}
}

void PrintList3(Spisok collection)                   //печать (Вспомогательная для Checkhead() и Checktail() )
{
	Zven* node = collection.head;
	while (1)
	{
		printf("%f", node->simv);

		node = node->next;
		if (node == NULL)
		{
			break;
		}
	}
}

void Checkhead() 
{
	printf("Первый элемент это: \n");
	PrintList3(list2.head->value);
	printf("\n\n");
}
void Checktail() {
	printf("Последний элемент это:\n");
	PrintList3(list2.tail->value);
	printf("\n\n");
}

int Shet()                             //Счет элементов в ДЕКе
{
	int t = 0;
	listElement* node = list2.head;
	while (1)
	{
		node = node->nextElement;
		t++;
		if (node == NULL)
		{
			return t;
			break;
		}
	}
}
int CheckEmpty(listCollection* list2)                 //проверка на пустату
{
	system("cls");
	printf("\n    Проверка: дек пуст?\n");
	if (list2->head == NULL)
	{
		printf("\n\n             |      ДА      | \n\n");
		return 1;
	}
	else
	{
		printf("\n\n           |      НЕТ      | \n\n");
		return 0;
	}
}

//------------------------------------------------------------------------ДЕК-Функции-----------------------------------------------------------------


//------------------------------------------------------------------------Последовательность-Функции-----------------------------------------------------------------

Spisok Start()                   //старт (создание пустого списка)
{
	Spisok list1;
	list1.current = NULL;
	list1.head = NULL;
	list1.tail = NULL;
	return list1;

}

void PrintList1(Spisok collection)         //печать (основное)
{
	Zven* node = collection.head;
	while (1)
	{
		printf("%f", node->simv);
		node = node->next;
		if (node == NULL)
		{
			printf("|");
			break;
		}
	}
}

void PrintList(Spisok collection)                   //печать
{
	Zven* node = collection.head;
	while (1)
	{
		printf("%f", node->simv);
		if (node == collection.current)
			printf("*");
		node = node->next;
		if (node == NULL)
		{
			printf("\n\n");
			break;
		}
	}
}

void DeleteAll(Spisok* list)   //очищение
{
	Zven* node = list->head;
	Zven* badElement = node;
	while (node->next != NULL)
	{
		badElement = node;
		node = node->next;
		free(badElement);
	}
	list->head = NULL;
	list->current = NULL;
}


int CheckEmpty2(Spisok* list)                 //проверка на пустоту
{
	system("cls");
	printf("\n    Проверка: последовательность пуста?\n");
	if (list->head == NULL)
	{
		printf("\n\n             |      ДА      | \n\n");
		return 1;
	}
	else
	{
		printf("\n\n           |      НЕТ      | \n\n");
		return 0;
	}
}

void CheckNext(Spisok* list)      //Показываем след элемент
{
	printf("\n|  Следующий символ:  %f   | \n\n", list->current->next->simv);
}

void MovePointerForvard(Spisok* list)    //Двигаем указатель
{
	list->current = list->current->next;
}

void MovePointerToStart(Spisok* list)     //Перенести указатель в начало
{
	list->current = list->head;
}

void ChangeNext(Spisok* list, float data)  //Изменение след элемент
{
	list->current->next->simv = data;
}



void Dobav(Spisok* collection, float data)            //добавление
{
	struct Zven* current;
	current = (struct Zven*)malloc(sizeof(struct Zven));
	//Zven* node = collection->head;

	if (current == NULL)
	{
		printf("...Ошибка! [память не выделена]\n");
		exit(1);
	}
	current->simv = data;
	current->next = NULL;
	
	if (collection->head == NULL)
	{
		collection->head = current;
		collection->tail = current;
		collection->current = current;
		collection->current2 = current;
	}
	else
	{
		collection->current2 = collection->tail;
		current->next = collection->current2->next;
		collection->current2->next = current;
		collection->tail = current;
	}
}

void Check(Spisok* list)      //Показываем след элемент
{
	if (list->current->next != NULL)
	{
		printf("\n\t|     ЕСТЬ     |\n");
	}
	else
	{
		printf("\n\t|     НЕТ     |\n");
	}
}

void AddElement(Spisok data, int directionFlag) 
{              
	struct listElement* current;
	current = (struct listElement*)malloc(sizeof(struct listElement));
	if (current == NULL) { printf("Error, NULL\n"); exit(1); }
	current->value = data;
	current->nextElement = NULL;
	current->prevElement = NULL;
	//Если выбран в начало
	if (directionFlag == 11)
	{
		if (list2.head == NULL)
		{
			list2.head = current;
			list2.current = current;
			list2.tail = current;
		}
		else
		{
			list2.current = list2.head;
			current->nextElement = list2.current;
			list2.current->prevElement = current;
			list2.head = current;
		}

	}
	//Если выбрано в конец
	else if (directionFlag == 12)
	{
		if (list2.head == NULL)
		{
			list2.head = current;
			list2.current = current;
			list2.tail = current;
		}
		else
		{
			list2.current = list2.tail;
			current->prevElement = list2.current;
			list2.current->nextElement = current;
			list2.tail = current;
		}

	}
}

//------------------------------------------------------------------------Последовательность-Функции-----------------------------------------------------------------


//------------------------------------------------------------------------Менюшки-----------------------------------------------------------------

void menu3(int e)  //меню последовательности
{
	system("cls");
	int men2 = 0;
	int buffer;
	int G = 0;
	Spisok list;
	if (e == 9)
	{
		list = list2.head->value;
	}
	else if (e == 10)
	{
		list = list2.tail->value;
	}
	else
	{
		list = Start();
	}

	while ((men2 == 0) && (G == 0))  //пока не был выбран и выполнен пункт 19 или 20
	{
		int menuPointer = 0;
		int directionFlag = 0;
		system("cls");
		printf("Меню (Последовательность)\n");

		printf("\n1. Очистить последовательность\n");
		printf("2. Проверка: последовательность пуста?\n");
		printf("3. Показать очередной элемент \n");
		printf("4. Пропустить элемент за указателем\n");
		printf("5. Прочитать элемент за указателем\n");
		printf("6. Изменить очередной элемент\n");
		printf("7. Добавить элемент в конец\n");
		printf("8. Установить указатель на начало\n");
		printf("9. Проверка: есть непрочитанный элемент?\n");
		printf("10. Распечатать\n");
		if ((e == 9) || (e == 10))
		{
			printf("12. Перейти в меню ДЕКа\n");
		}
		else
		{
			printf("11. Положить последовательность в ДЕК\n");
			printf("12. Перейти в меню ДЕКа\n");
		}
		printf("\nСписок: \n");
		if (list.head != NULL)  //если список не пуст
			PrintList(list);
		else printf("| Последовательность пуста! |\n\n");  //иначе
		printf("\nВыберите пункт:\n");
		scanf_s("%d", &menuPointer);
		buffer = getchar(); //мусор

		switch (menuPointer)
		{
		case 1:
			system("cls");
			if (list.head != NULL) 
			{
				DeleteAll(&list);
			}
			printf("... Выполнено успешно!\n\n");
			buffer = getchar();
			break;

		case 2:
			system("cls");
			CheckEmpty2(&list);
			printf("... Выполнено успешно!\n\n");
			buffer = getchar();
			break;

		case 3:
			system("cls");
			if (list.head != NULL) {
				if (list.current->next != NULL) {
					CheckNext(&list);
					printf("... Выполнено успешно!\n\n");
				}
				else printf("Конец списка\n");
			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;

		case 4:
			system("cls");
			if (list.head != NULL) {
				if (list.current->next != NULL) {
					MovePointerForvard(&list);
					printf("... Выполнено успешно!\n\n");
				}
				else printf("Конец списка\n");
			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;

		case 5:
			system("cls");
			if (list.head != NULL) {
				if (list.current->next != NULL)
				{
					CheckNext(&list);
					MovePointerForvard(&list);
					printf("... Выполнено успешно!\n\n");
				}
				else printf("Конец списка\n");
			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;


		case 6:
			system("cls");
			if (list.head != NULL) {
				if (list.current->next != NULL)
				{
					float inputChangeElement;
					printf("Введите новый элемент:\n");
					scanf_s("%f", &inputChangeElement);
					ChangeNext(&list, inputChangeElement);
					printf("... Выполнено успешно!\n\n");
				}
				else printf("Конец списка\n");
			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;


		case 7:
			system("cls");
			float inputElement;
			printf("Введите элемент:\n");
			scanf_s("%f", &inputElement);
			Dobav(&list, inputElement);
			printf("... Выполнено успешно!\n\n");
			buffer = getchar();
			break;


		case 8:
			system("cls");
			if (list.head != NULL)
			{
				MovePointerToStart(&list);
				printf("... Выполнено успешно!\n\n");

			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;

		case 9:
			system("cls");
			if (list.head != NULL)
			{
				Check(&list);
				printf("... Выполнено успешно!\n\n");

			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;


		case 10:
			system("cls");
			if (list.head != NULL)
			{
				PrintList1(list);
				printf("... Выполнено успешно!\n\n");

			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;

		case 11:
			system("cls");
			if (list.head != NULL)
			{
				if (e == 11)
				{
					AddElement(list, 11);
					printf("... Выполнено успешно!\n\n");
					men2 = 1;
				}

				if (e == 12)
				{
					AddElement(list, 12);
					printf("... Выполнено успешно!\n\n");
					men2 = 1;
				}

			}
			else printf("\n| Список пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;

		case 12:
			system("cls");
			if ((e == 9) || (e == 10))
			{
				if (list.head == NULL)
				{
					if (e == 9)
						Deletehead(&list2);
					if (e == 10)
						Deletetail(&list2);

				}
			}
			men2 = 1;
			buffer = getchar();
			break;

		default:
			system("cls");
			break;
		}

	}

}

void menu2()
{
	StartWork();
	int menuPointer = 0;
	int buffer;
	//int isExist = 0;
	system("cls");
	while (menuPointer != 14)
	{
		menuPointer = 0;
		//int directionFlag = 0;
		int t = 0;
		system("cls");
		printf("Меню (ДЕК  | максимальная длина: 5 элементов)\n");
		printf("\n1. Очистить ДЕК\n");
		printf("2. Проверка: ДЕК пуст?\n");
		printf("3. Показать первый элемент \n");
		printf("4. Показать последний элемент \n");
		printf("5. Удалить первый элемент \n");
		printf("6. Удалить последний элемент \n");
		printf("7. Взять первый элемент \n");
		printf("8. Взять последний элемент \n");
		printf("9. Изменить первый элемент \n");
		printf("10. Изменить последний элемент \n");
		printf("11. Добавить элемент в начало ДЕКа \n");
		printf("12. Добавить элемент в конец ДЕКа \n");
		printf("13. Распечатать ДЕК \n");
		printf("14. Закончить работу с ДЕКом \n");
		printf("\nДЕК: \n");
		if (list2.head != NULL)
		{
			PrintList();
		}
		else printf("ДЕК пуст\n");
		printf("\nВыберите пункт:\n");
		scanf_s("%d", &menuPointer);
		buffer = getchar();//мусор
		switch (menuPointer)
		{
		case 1:
			system("cls");
			if (list2.head != NULL)
			{
				DeleteAll();
			}
			printf("... Выполнено успешно!\n\n");
			buffer = getchar();
			break;
		case 2:
			system("cls");
			CheckEmpty(&list2);
			printf("... Выполнено успешно!\n\n");
			buffer = getchar();
			break;
		case 3:
			system("cls");
			if (list2.head != NULL) {
				if (list2.current->prevElement != NULL) {
					Checkhead();
					printf("... Выполнено успешно!\n\n");
				}
				else
					printf("\n| Ошибка: в деке один элемент! Добавьте элементы и выберите пункт повторно   |\n\n");
			}
			else
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;
		case 4:
			system("cls");
			if (list2.head != NULL) {
				if (list2.current->nextElement != NULL) {
					Checktail();
					printf("... Выполнено успешно!\n\n");
				}
				else
					printf("\n| Ошибка: в деке один элемент! Добавьте элементы и выберите пункт повторно |\n\n");
			}
			else
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;
		case 5:
			system("cls");
			if (list2.head != NULL)
			{
				if (list2.current != NULL)
				{
					Deletehead(&list2);
					printf("... Выполнено успешно!\n\n");
				}
				else
					printf("\n| Ошибка: в деке один элемент! Добавьте элементы и выберите пункт повторно   |\n\n");
			}
			else
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;
		case 6:
			system("cls");
			if (list2.head != NULL)
			{
				if (list2.current != NULL)
				{
					Deletetail(&list2);
					printf("... Выполнено успешно!\n\n");
				}
				else
					printf("\n| Ошибка: в деке один элемент! Добавьте элементы и выберите пункт повторно  |\n\n");
			}
			else
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;
		case 7:
			system("cls");
			if (list2.head != NULL) {
				if (list2.current->prevElement != NULL) {
					Checkhead();
					Deletehead(&list2);
					printf("... Выполнено успешно!\n\n");
				}
				else
					printf("\n| Ошибка: в деке один элемент! Добавьте элементы и выберите пункт повторно  |\n\n");
			}
			else
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;
		case 8:
			system("cls");
			if (list2.head != NULL) {
				if (list2.current->prevElement != NULL) {
					Checktail();
					Deletetail(&list2);
					printf("... Выполнено успешно!\n\n");
				}
				else
					printf("\n| Ошибка: в деке один элемент! Добавьте элементы и выберите пункт повторно  |\n\n");
			}
			else
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;

		case 9:
			system("cls");
			if (list2.head != NULL)
			{
				menu3(9);
			}
			else
			{
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			}

			buffer = getchar();
			break;


		case 10:
			system("cls");
			if (list2.head != NULL)
			{
				menu3(10);
			}
			else
			{
				printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			}
			buffer = getchar();
			break;


		case 11:
			system("cls");
			if (list2.head != NULL)
			{
				t = Shet();
				if (t < 5)
				{
					menu3(11);
					printf("... Выполнено успешно!\n\n");
				}
				else
				{
					printf("\n !Переполнение ДЕКа! \n\n");
				}
			}
			else
			{
				menu3(11);
			}

			buffer = getchar();
			break;

		case 12:
			system("cls");
			if (list2.head != NULL)
			{
				t = Shet();
				if (t < 5)
				{
					menu3(12);
					printf("... Выполнено успешно!\n\n");
				}
				else
				{
					printf("\n !Переполнение ДЕКа! \n\n");
				}
			}
			else
			{
				menu3(12);
			}

			buffer = getchar();
			break;
		case 13:
			system("cls");
			if (list2.head != NULL) {
				PrintList();
				printf("... Выполнено успешно!\n\n");
			}
			else printf("\n| ДЕК пуст! Добавьте элементы и выберите пункт повторно  |\n\n");
			buffer = getchar();
			break;

		default:
			system("cls");
			break;
		}
	}
}





//------------------------------------------------------------------------Менюшки-----------------------------------------------------------------


int main()
{
	setlocale(LC_ALL, "Russian");
	int menuPointer = 0;
	while (menuPointer != 2)
	{
		menuPointer = 0;
		printf("Меню\n");
		printf("Выберите пункт:\n");
		printf("1) Начать работу с кодом\n");
		printf("2) Выход\n");
		scanf_s("%d", &menuPointer);
		if (menuPointer == 1)
		{

			menu2();

		}
		else if (menuPointer == 2)
		{
			system("cls");
			printf("\n| Работа завершена! | \n");
			exit(0);
		}

		else printf("\n| Такого пункта нет! Выберите пунк повторно из предоставленного списка | \n");

		system("cls");
	}
}
