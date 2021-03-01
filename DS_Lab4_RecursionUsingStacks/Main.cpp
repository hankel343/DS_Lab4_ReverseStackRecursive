/*	Hankel Haldin
*	ICCC Data Structures
*	LAB 4: Using Recursion to reverse the elements of a stack.
*	Description: This program has two functions. PushItems() recursively pushes items to a stack -
*	and ReverseStack() pops items from the stack and stores them in a queue that acts as a buffer.
*	Popping and enqueuing the elements occurs during the ascending phase of ReverseStack(). On the descending -
*	phase elements are deqeueued and pushed back to the original stack in the reverse order.
*/

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

void PushItems(Stack* PrimaryStack, int nData);
//Pre: A stack object has been dynamically allocated and PrimaryStack is a valid pointer to it.
//Post: A consecutive sequence of integers has been pushed to the stack.

void ReverseStack(Stack* PrimaryStack, Queue* AuxiliaryQueue);
//Pre: Both a stack and queue objects have been dynamically allocated and PrimaryStack and AuxiliaryQueue are pointers to them.
//Post: The stack object that PrimaryStack points to has been reversed.

int main()
{
	Stack* PrimaryStack = new Stack;
	Queue* AuxiliaryQueue = new Queue;
	int nData = 0;

	cout << "Recursive call to PushItems(): \n";
	PushItems(PrimaryStack, nData);
	cout << "\n### End of PushItems() ###\n";
	cout << "\nRecursive calls to ReverseStack(): \n";
	ReverseStack(PrimaryStack, AuxiliaryQueue);
	cout << "### End of ReverseStack() ###\n";

	return 0;
}

void PushItems(Stack* PrimaryStack, int nData)
{
	if (nData == 10) {
		cout << "--- End of ascending phase. ---\n";
		cout << "--- Entering returning phase. ---";
	} else {
		ItemType iNewItem;
		iNewItem.Set(nData);
		cout << "Current item being pushed to the stack: " << nData << endl;
		PrimaryStack->Push(iNewItem);

		PushItems(PrimaryStack, nData + 1);
	}
}

void ReverseStack(Stack* PrimaryStack, Queue* AuxiliaryQueue)
{
	ItemType iTempItem;
	try
	{
		int nTemp = PrimaryStack->Top().Get();
		cout << "Data popped from the top of the stack and enqueued: " << nTemp << endl;
		PrimaryStack->Pop();
		iTempItem.Set(nTemp);
		AuxiliaryQueue->Enqueue(iTempItem);
		
		/*Recursive call*/
		ReverseStack(PrimaryStack, AuxiliaryQueue);

		AuxiliaryQueue->Dequeue(iTempItem);
		cout << "Data being dequeued and pushed to original stack: " << iTempItem.Get() << endl;
		PrimaryStack->Push(iTempItem);
	} catch (EmptyStack exception) {
		cout << "--- End of ascending phase reached. ---\n";
		cout << "--- Entering returning phase. ---\n";
		cout << "Reversed stack: \n";
	}
}