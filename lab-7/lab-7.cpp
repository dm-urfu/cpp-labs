#include <iostream>
#include "SLList.h"

using namespace std;

void printSLList(const SLList* list) {
	while (list->hasNext())
	{
		cout << list->getData() << ", ";
		list = list->next();
	}

	cout << list->getData() << endl;
}

int findElementK(int k, SLList* list)
{
	auto next = list->next();
	int count = 1;
	while (next->hasNext())
	{
		next = next->next();
		count++;
	}

	next = list->next();

	for (int i = 0; i < count - 1; i++)
	{
		if (count - k == 0)
			return list->getData();
		else if (count - k == i + 1)
			return next->getData();
		next = next->next();
	}
}

void delDuplicates(SLList* list)
{
	SLList* temp = list;
	SLList* sllist = list;
	while (sllist != nullptr && sllist-> hasNext())
	{
		temp = sllist;
		while (temp->hasNext())
		{
			SLList* next = temp->next();
			if (next->getData() == sllist->getData())
				temp->removeNext();
			else
				temp = next;
		}
		sllist = sllist->next();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	SLList* list = SLList::beginList(rand() % 6);
	auto temp = list;
	for (int i = 0; i < 9; i++)
		temp = temp->addElement(rand() % 6);

	cout << "Исходный список: " << endl;
	printSLList(list);

	int k;
	cout << "k = ";
	cin >> k;
	cout << "Элемент k с конца: " << endl;
	cout << findElementK(k, list) << endl;

	delDuplicates(list);
	cout << "Список без дубликатов: " << endl;
	printSLList(list);
}
