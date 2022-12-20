#include <iostream>
#include "List.h"
using namespace std;

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

int main()
{
    List* list = new List();
	while (true)
	{
		/*cout << "1. Create Dynamic Array\n"
				"2. Initializing an array with random numbers\n"
				"3. Show array\n4. Bubble sort\n"
				"5. Push back\n"
				"6. Push forward\n"
				"7. Insert element in some index\n"
				"8. Linear Search\n"
				"9. Binary Search\n"
				"10. Remove Element\n";*/
		int taskNumber = CheckingForDigit("Enter task number: ");
		cout << endl;
		if (taskNumber <= 10 && taskNumber >= 1)
		{
			switch (taskNumber)
			{
				case 1:
				{
					int data;
					cin >> data;
					PushBack(list, data);
					break;
				}
				case 2:
				{
					Show(list);
				}
			}
		}
	}
    delete list;
}
