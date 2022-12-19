#pragma once
#include "Element.h"

struct List
{
	Element* Head;

	Element* Tail;

	int Length;

	List()
	{
		Head = nullptr;
		Tail = nullptr;
		Length = 0;
	}
};

void PushBack(List* list, int data);

void PushForward(List* list, int data);

void GetFillRandomList(List* list, int count);
