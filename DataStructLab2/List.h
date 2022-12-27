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
/// @brief Добавление элемента в конец списка
/// @param list Список
/// @param data Элемент
void PushBack(List* list, int data);

/// @brief Добавление элемента в начало списка
/// @param list Список
/// @param data Элемент
void PushForward(List* list, int data);

/// @brief Генерация списка с рандомными значениями
/// @param list Список
/// @param count Количество элементов
void GetFillRandomList(List* list, int count);

/// @brief Удаление элемента по индексу
/// @param list Список
/// @param index Индекс удаляемого элеманта
/// @return Возвращается -1 если что-то не так
int Remove(List* list, int index);

/// @brief Вставляет элемент после выбранного индекса
/// @param list Список
/// @param index Индекс
/// @param value Элемент
/// @return Возвращает -1 при ошибке
int InsertAfterIndex(List* list, int index, int value);

/// @brief Вставляет элемент до выбраного индекса
/// @param list Список
/// @param index Индекс
/// @param value Элемент
/// @return Возвращает -1 при ошибке
int InsertBeforeIndex(List* list, int index, int value);

/// @brief Создание и заполнение списка рандомными числами 
/// @param list Список
/// @param count Количество элементов из которых будет состоять список
void GetFillRandomList(List* list, int count);

/// @brief Линейный поиск
/// @param list Список
/// @param element Элемент
/// @return Возращает -1 если такого элемента нету
int LinearSearch(List* list, int element);

/// @brief Сортировка массива
/// @param list Список
void SortList(List* list);

/// @brief Очистка списка
void RemoveList(List* list);