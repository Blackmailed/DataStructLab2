#include "Element.h"
#include "List.h"
#include <cstdlib>
#include <ctime>

void PushBack(List* list, int data)
{
	Element* element = new Element;
	element->Data = data;
	if (list->Tail == nullptr)
	{
		element->Next = nullptr;
		element->Previous = nullptr;
		list->Head = element;
		list->Tail = element;
	}
	else
	{
		list->Tail->Next = element;
		element->Previous = list->Tail;
		element->Next = nullptr;
		list->Tail = element;
	}

	list->Length++;
}

void PushForward(List* list, int data)
{
	Element* element = new Element;
	element->Data = data;

	if (list->Head == nullptr)
	{
		element->Next = nullptr;
		element->Previous = nullptr;
		list->Head = element;
		list->Tail = element;
	}
	else
	{
		list->Head->Previous = element;
		element->Next = list->Head;
		element->Previous = nullptr;
		list->Head = element;
	}

	list->Length++;
}

void GetFillRandomList(List* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		PushBack(list, rand());
	}
}