/*	Hankel Haldin
*	ICCC Data Structures
*	LAB 4: Using Recursion to reverse the elements of a stack.
*	Description: This program has two functions. PushItems() recursively pushes items to a stack -
*	and ReverseStack() pops items from the stack and stores them in a queue that acts as a buffer.
*	Popping and enqueuing the elements occurs during the ascending phase of ReverseStack(). On the descending -
*	phase elements are deqeueued and pushed back to the original stack in the reverse order.*/

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

/*	DESIGN NOTE ON PUSHITEMS():
*	I could have reversed the stack faster by popping items to the queue during the returning phase of PushItems(), 
*	but I felt that if I was going to stick with the design principle of each function doing one thing it wouldn't make sense for me to -
*	also pop items from the stack if the function's name is PushItems(). This is why I left the returning phase of PushItems() empty and -
*	performed that operation in ReverseStack(). It fits better there in the logical design of my program.*/

void PushItems(Stack* PrimaryStack, int nData, ItemType iTempItem);
//Pre: A stack object has been dynamically allocated and PrimaryStack is a valid pointer to it.
//Post: A consecutive sequence of integers has been pushed to the stack.

void ReverseStack(Stack* PrimaryStack, Queue* AuxiliaryQueue, ItemType iTempItem);
//Pre: Both a stack and queue objects have been dynamically allocated and PrimaryStack and AuxiliaryQueue are pointers to them.
//Post: The stack object that PrimaryStack points to has been reversed.

int main()
{
	Stack* PrimaryStack = new Stack;
	Queue* AuxiliaryQueue = new Queue;
	int nData = 0;
	ItemType iTempItem;

	cout << "Recursive call to PushItems(): \n";
	cout << "Original stack: \n";
	PushItems(PrimaryStack, nData, iTempItem);
	cout << "\n### End of PushItems() ###\n";
	cout << "\nRecursive calls to ReverseStack(): \n";
	ReverseStack(PrimaryStack, AuxiliaryQueue, iTempItem);
	cout << "### End of ReverseStack() ###\n";

	return 0;
}

void PushItems(Stack* PrimaryStack, int nData, ItemType iTempItem)
{
	if (nData == 10) {
		cout << "--- End of ascending phase. ---\n";
		cout << "--- Entering returning phase. ---";
	} else {
		/*This code will execute during the ascending phase:*/
		iTempItem.Set(nData);
		cout << "Current item being pushed to the stack: " << nData << endl;
		PrimaryStack->Push(iTempItem);

		/*Recursive Call*/
		PushItems(PrimaryStack, nData + 1, iTempItem);
		/*End of ascending phase code once base case is reached*/

		/*Returning phase of calls (nothing happens in this function)*/
	}
}

void ReverseStack(Stack* PrimaryStack, Queue* AuxiliaryQueue, ItemType iTempItem)
{
	try
	{
		/*This code is executed during the ascending phase of recursive calls:*/
		int nTemp = PrimaryStack->Top().Get();
		cout << "Data popped from the top of the stack and enqueued: " << nTemp << endl;
		PrimaryStack->Pop();
		iTempItem.Set(nTemp);
		AuxiliaryQueue->Enqueue(iTempItem);
		
		/*Recursive call*/
		ReverseStack(PrimaryStack, AuxiliaryQueue, iTempItem);
		/*End of ascending phase code once base case is reached*/

		/*These three statements will be executed during the returning phase:*/
		AuxiliaryQueue->Dequeue(iTempItem);
		cout << "Data being dequeued and pushed to original stack: " << iTempItem.Get() << endl;
		PrimaryStack->Push(iTempItem);

	} catch (EmptyStack exception) {
		cout << "--- End of ascending phase reached. ---\n";
		cout << "--- Entering returning phase. ---\n";
		cout << "Reversed stack: \n";
	}
}