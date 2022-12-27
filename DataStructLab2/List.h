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
/// @brief ���������� �������� � ����� ������
/// @param list ������
/// @param data �������
void PushBack(List* list, int data);

/// @brief ���������� �������� � ������ ������
/// @param list ������
/// @param data �������
void PushForward(List* list, int data);

/// @brief ��������� ������ � ���������� ����������
/// @param list ������
/// @param count ���������� ���������
void GetFillRandomList(List* list, int count);

/// @brief �������� �������� �� �������
/// @param list ������
/// @param index ������ ���������� ��������
/// @return ������������ -1 ���� ���-�� �� ���
int Remove(List* list, int index);

/// @brief ��������� ������� ����� ���������� �������
/// @param list ������
/// @param index ������
/// @param value �������
/// @return ���������� -1 ��� ������
int InsertAfterIndex(List* list, int index, int value);

/// @brief ��������� ������� �� ��������� �������
/// @param list ������
/// @param index ������
/// @param value �������
/// @return ���������� -1 ��� ������
int InsertBeforeIndex(List* list, int index, int value);

/// @brief �������� � ���������� ������ ���������� ������� 
/// @param list ������
/// @param count ���������� ��������� �� ������� ����� �������� ������
void GetFillRandomList(List* list, int count);

/// @brief �������� �����
/// @param list ������
/// @param element �������
/// @return ��������� -1 ���� ������ �������� ����
int LinearSearch(List* list, int element);

/// @brief ���������� �������
/// @param list ������
void SortList(List* list);

/// @brief ������� ������
void RemoveList(List* list);