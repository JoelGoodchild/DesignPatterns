#include <iostream>
#include "Stack.h"
#include "dynamicArray.h"

using namespace std;

void testDynamicArray()
{
	dynamicArray<int> data(10);
	cout << "Unit test for the dynamic array" << endl;
	cout << endl;

	dynamicArray<int> myArray(3);

	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Initial sizes-" << endl;
	cout << "Used: " << myArray.size() << endl;
	cout << "Capacity: " << myArray.capacity() << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;


	cout << "Adding 5 values to the array" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

	myArray.pushBack(9);
	myArray.pushBack(8);
	myArray.pushBack(7);
	myArray.pushBack(6);
	myArray.pushBack(5);

	cout << "The new sizes are:" << endl;
	cout << "Used: " << myArray.size() << endl;
	cout << "Capacity: " << myArray.capacity() << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Those values are:" << endl;

	for (int i = 0; i < myArray.size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

	// Clears array
	myArray.clear();

	cout << "Array has been cleared" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Adding 5 new values to the array" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

	myArray.pushFront(1);
	myArray.pushFront(2);
	myArray.pushFront(3);
	myArray.pushFront(4);
	myArray.pushFront(5);

	// Prints values
	cout << "Those Values are:" << endl;

	for (int i = 0; i < myArray.size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Adding the number 4 in slot number 1" << endl;

	// Inserts a 4 in slot 1
	myArray.Insert(1, 4);

	// Prints values
	cout << "Values are:" << endl;

	for (int i = 0; i < myArray.size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Removing the value from slot number 5" << endl;

	myArray.remove(5);

	// Prints values
	cout << "Values are:" << endl;

	for (int i = 0; i < myArray.size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	// Clear
	myArray.clear();
	// Shrink
	myArray.shrink();

	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "The array has been cleared and shrunk" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "The new sizes are:" << endl;
	cout << "Used: " << myArray.size() << endl;
	cout << "Capacity: " << myArray.capacity() << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}

void testStack()
{
	cout << endl;
	cout << "Unit test for Stack" << endl;
	cout << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

	Stack<int>* s1;
	s1 = new Stack<int>;

	cout << "Creating Stack and added 4 values 1 -> 4" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	s1->push(1);
	s1->push(2);
	s1->push(3);
	s1->push(4);

	cout << "Printing size of stack:" << endl;
	cout << s1->size() << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

	cout << "Popping top value:" << endl;
	cout << s1->pop() << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Printing top value:" << endl;
	cout << s1->top() << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

	cout << "Clearing stack" << endl;
	s1->Clear();
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Checking if stack is empty" << endl;
	if (s1->empty() == true)
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << endl;
}

void main()
{
	testDynamicArray();
	testStack();
	cout << "Testing complete" << endl;
	system("pause");
}