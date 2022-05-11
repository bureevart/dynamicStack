﻿#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	//Нижняя и верхняя границы стека
	int EMPTY = -1, FULL = 5;
	//Массив для хранения данных
	char *st = new char[FULL + 1];

	//индекс определяющий вершину стека
	int top;

public:

	//Конструктор
	Stack();

	//Добавление элемента
	void Push(char c);

	//Извлечение элемента
	char Pop();

	//Очистка стека
	void Clear();

	//Проверка существования элементов в стеке
	bool IsEmpty();

	//Проверка на переполнение стека
	bool IsFull();

	//Количество элементов в стеке
	int GetCount();

    virtual ~Stack();

};

Stack::Stack()
{
	//Изначально стек пуст
	top = EMPTY;
}

void Stack::Clear()
{
	//Эффективная "очистка" стека
	//(данные в массиве все еще существуют,
	//но функции класса, ориентированные
	//на работу с вершиной стека,
	//будут их игнорировать)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	//Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	//Полон?
	return top == FULL;
}

int Stack::GetCount()
{
	//Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(char c)
{
	//Если в стеке есть место, то увеличиваем указатель
	//на вершину стека и вставляем новый элемент
	if (!IsFull())
	{
		st[++top] = c;
	} else {
        int temp[FULL + 1];
        for (int i = 0; i < FULL + 1; ++i) {
            temp[i] = st[i];
        }

        FULL++;

        st = new char[FULL + 1];
        for (int i = 0; i < FULL + 1; ++i) {
            st[i] = temp[i];
        }

        st[++top] = c;
    }
}


char Stack::Pop()
{
	//Если в стеке есть элементы, то возвращаем
	//верхний и уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[top--];
	else //Если в стеке элементов нет
		return 0;
}

Stack::~Stack() {
    delete[] st;
}

int main()
{
	srand(time(0));
	
	Stack ST;
	char c;
    int count = 200;
	//пока стек не заполнится
	while (count) {
		c = rand() % 4 + 2;
		ST.Push(c);
        count--;
	}

	ST.Push('a');
	//пока стек не освободится
	while (c = ST.Pop()) {
		cout << c << " ";
	}
	cout << "\n\n";

    return 0;
}


