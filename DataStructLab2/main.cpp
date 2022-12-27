#include <iostream>
#include "List.h"
#include "TestOperations.h"

using namespace std;

int CheckingForDigit(string outputString)
{
	if (outputString != "")
	{
		cout << outputString;
	}

	int value;

	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nError has been detected. Try again! \nEnter task number: ";
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1)
		{
			cout << "\nError has been detected. Try again! \nEnter task number: ";
			continue;
		}

		break;
	}

	return value;
}

void Show(List* list)
{
	Element* element = list->Head;

	cout << "Double Linked List: " << endl;

	while (element != nullptr)
	{
		cout << element->Data << " ";

		element = element->Next;
	}

	cout << endl << "Length: " << list->Length << endl;
}

int main()
{
    List* list = new List();
	while (true)
	{
		cout << "1. Get random list\n"
				"2. Show list\n"
				"3. Push back\n"
				"4. Push forward\n"
				"5. Insert element after index\n"
				"6. Insert element before index\n"
				"7. Removing element\n"
				"8. Linear Search\n"
				"9. Sort list\n"
				"10. Remove list\n"
				"11. Test\n";
		int taskNumber = CheckingForDigit("Enter task number: ");
		cout << endl;
		if (taskNumber <= 11 && taskNumber >= 1)
		{
			switch (taskNumber)
			{
				case 1:
				{
					int count = CheckingForDigit("Input count of number which u want random generate in List: ");
					GetFillRandomList(list, count);
					break;
				}
				case 2:
				{
					Show(list);
					break;
				}
				case 3:
				{
					int data;
					cout << "Input number which u want push back: ";
					cin >> data;
					PushBack(list, data);
					break;
				}
				case 4:
				{
					int data;
					cout << "Input number which u want push forward: ";
					cin >> data;
					PushForward(list, data);
					break;
				}
				case 5:
				{
					int index;
					int element;
					cout << "Input index of element after which u want add new element: ";
					cin >> index;
					cout << "Input element which u want add: ";
					cin >> element;
					InsertAfterIndex(list, index, element);
					break;
				}
				case 6:
				{
					int index;
					int element;
					cout << "Input index of element before which u want add new element: ";
					cin >> index;
					cout << "Input element which u want add: ";
					cin >> element;
					InsertBeforeIndex(list, index, element);
					break;
				}
				case 7:
				{
					int index;
					cout << "Input index of element which u want remove: ";
					cin >> index;
					Remove(list, index);
					break;
				}
				case 8:
				{
					int value;
					cout << "Input value which u want find with Linear Search: " << endl;
					cin >> value;
					int index = LinearSearch(list, value);

					if (index == -1)
					{
						cout << "There is no such number!" << endl;
					}
					else
					{
						cout << "Number " << value << " has an index of " << index << endl;
					}
					break;
				}
				case 9:
				{
					if (list->Length == 0)
					{
						cout << "There is no list!" << endl;
						return 0;
					}

					SortList(list);
					break;
				}
				case 10: 
				{
					RemoveList(list);
					Show(list);
					break;
				}
				case 11: 
				{
					TestOperations(list);
					break;
				}
				default:
				{
					cout << "Incorrect task, try enter number of task again !" << endl;
					break;
				}
			}
		}
	}
    delete list;
}
