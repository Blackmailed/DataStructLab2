#include "List.h"
#include <xmemory>
#include <cstdlib>
#include <time.h>
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
		list->Tail = element;
		element->Next = nullptr;
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

Element* GetElement(List* list, int index)
{

	Element* element;

	if (index < list->Length / 2)
	{
		element = list->Head;

		for (int i = 0; i < index; ++i)
		{
			element = element->Next;
		}

		return element;
	}
	else
	{
		element = list->Tail;

		for (int i = list->Length - 1; i > index; i--)
		{
			element = element->Previous;
		}

		return element;
	}
}

int Remove(List* list, int index)
{
	if (list->Head == nullptr || list->Length - 1 < index || index < 0)
	{
		return -1;
	}

	Element* element = GetElement(list, index);

	if (element == list->Head)
	{
		list->Head = element->Next;
	}
	else
	{
		element->Previous->Next = element->Next;
	}

	if (element == list->Tail)
	{
		list->Tail = element->Previous;
	}
	else
	{
		element->Next->Previous = element->Previous;
	}

	list->Length--;
	delete element;
	return 0;
}

int InsertAfterIndex(List* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index || index < 0)
	{
		return -1;
	}

	Element* element = new Element();
	Element* indexElement = GetElement(list, index);

	element->Data = value;

	element->Next = indexElement->Next;
	element->Previous = indexElement;

	if (list->Length - 1 != index)
	{
		indexElement->Next->Previous = element;
	}

	indexElement->Next = element;

	if (list->Length - 1 == index)
	{
		list->Tail = element;
	}

	list->Length++;
	return 0;
}

int InsertBeforeIndex(List* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index || index < 0)
	{
		return -1;
	}

	Element* element = new Element();
	Element* indexElement = GetElement(list, index);

	element->Data = value;

	element->Next = indexElement;
	element->Previous = indexElement->Previous;

	if (indexElement->Previous != nullptr)
	{
		indexElement->Previous->Next = element;
	}

	indexElement->Previous = element;

	if (index == 0)
	{
		list->Head = element;
	}

	list->Length++;
	return 0;
}

void GetFillRandomList(List* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		PushBack(list, rand());
	}
}

int LinearSearch(List* list, int element)
{
	int index = 0;

	for (Element* iElement = list->Head; iElement != nullptr; iElement = iElement->Next, index++)
	{
		if (iElement->Data == element)
		{
			return index;
		}
	}
	return -1;
}

void SwapElements(List* list, Element* first, Element* second)
{
	if (first == list->Head)
	{
		list->Head = second;
	}
	else
	{
		first->Previous->Next = second;
	}

	if (second == list->Tail)
	{
		list->Tail = first;
	}
	else
	{
		second->Next->Previous = first;
	}

	first->Next = second->Next;
	second->Previous = first->Previous;
	first->Previous = second;
	second->Next = first;
}

void SortList(List* list)
{
	Element* first = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		for (int j = 0; j < list->Length - 1; j++)
		{
			if (first == nullptr)
			{
				break;
			}
			if (first->Next == nullptr)
			{
				break;
			}

			Element* second = first->Next;

			if (first->Data > second->Data)
			{
				SwapElements(list, first, second);
			}

			first = first->Next;
		}

		first = list->Head;
	}
}

void RemoveList(List* list)
{
	if (list->Head == nullptr)
	{
		return;
	}

	int index = 0;
	Element* temp = list->Head->Next;

	while (temp != nullptr)
	{
		delete temp->Previous;
		list->Length--;
		temp = temp->Next;
	}

	delete temp;
	list->Length--;
	list->Head = nullptr;
	list->Tail = nullptr;
}