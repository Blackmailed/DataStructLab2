#include <iostream>
#include <chrono>
#include "TestOperations.h"
#include "List.h"

using namespace std;

void TestOperations(List* list)
{
	for (int step = 10000; step <= 500000; step += 10000)
	{
		RemoveList(list);
		int testValue = 10;
		GetFillRandomList(list, step);
		auto start = chrono::steady_clock::now();
		/*InsertBeforeIndex(list, list->Length / 2, testValue);*/
		/*PushForward(list, testValue);*/
		Remove(list, list->Length / 2);
		auto end = chrono::steady_clock::now();
		cout << chrono::duration_cast<std::chrono::microseconds>(end - start).count()
			<< ", " << step << endl;
	}
}