#pragma once

/// @brief ������������ ���������� �� ������������� �������� ������.
struct Element
{
	/// @brief ��������� �� ��������� ������� ������.
	Element* Next;
	/// @brief ��������� �� ���������� ������� ������.
	Element* Previous;
	/// @brief �������� �������� ������.
	int Data;
};

/// @brief ������������ ���������� ����������� ��������� ������
struct List
{
	/// @brief ��������� �� ������ ������� ������
	Element* Head;
	/// @brief ��������� �� ��������� ������� ������
	Element* Tail;
	/// @brief ����� ������
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
