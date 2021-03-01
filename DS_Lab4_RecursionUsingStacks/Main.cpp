#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

void PushItems(Stack* PrimaryStack, int nData);
void ReverseStack(Stack* PrimaryStack, Queue* AuxiliaryQueue);

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
	if (nData == 5) {
		cout << "End of ascending phase.\n";
		cout << "Entering returning phase.";
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
		cout << "End of ascending phase reached.\n";
		cout << "Entering returning phase.\n";
	}
}