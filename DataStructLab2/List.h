#pragma once

/// @brief Представляет реализацию по представлению элемента списка.
struct Element
{
	/// @brief Указатель на следующий элемент списка.
	Element* Next;
	/// @brief Указатель на предыдущий элемент списка.
	Element* Previous;
	/// @brief Значение элемента списка.
	int Data;
};

/// @brief Представляет реализацию двусвязного линейного списка
struct List
{
	/// @brief Указатель на первый элемент списка
	Element* Head;
	/// @brief Указатель на последний элемент списка
	Element* Tail;
	/// @brief Длина списка
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
