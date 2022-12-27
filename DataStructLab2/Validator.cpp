#include "Validator.h"

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