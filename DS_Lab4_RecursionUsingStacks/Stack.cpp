#include "Stack.h"
#include <new> //This library is included to use bad_alloc exception.

Stack::Stack() {};

/*
IsEmpty(): Simply returns the condition of the top pointer of the stack being equal to nullptr.
*/
bool Stack::IsEmpty()
{
	return (pTop == nullptr);
}

/*
IsFull(): Method allocates memory for a new node.

Note: If allocation statement fails, bad_alloc exception is thrown and caught by catch clause.
Due to the linked list implementation, bad_alloc will be thrown in the even that dynamic memory has been depleted.
Exceptions are objects of type bad_alloc.
*/
bool Stack::IsFull()
{
	try
	{
		//Allocating mem. for test 
		Node* pTest = new Node; //If out of memory, throw bad_alloc exception.
		delete pTest; //If this statement is reached, memory was successfully allocated.
		return false;
	}
	catch (std::bad_alloc) {
		return true;
	}
}

/*
Push(): Method pushes a new element on to the stack.

Note: This method can throw an exception if the stack is full at calling time.
Accordingly, the client must wrap all calls to this method in a try-catch clause
Exception is an object of type FullStack();
*/
void Stack::Push(ItemType iNewItem)
{
	if (this->IsFull() == true)	throw FullStack();
	else
	{
		Node* pTemp = new Node;
		pTemp->iData = iNewItem;

		if (pTop == nullptr) { //If list was empty.
			pTemp->pNext = nullptr;
			pTop = pTemp; //Making top point to first node.
		}
		else {
			pTemp->pNext = pTop; //Making link to previous top node.
			pTop = pTemp; //Moving top to most recently inserted item.
		}
	}

}

/*
Pop(): Method removes the top most element from the stack.

Note: This method can throw an exception if the stack is empty at calling time.
All calls to this method should be included in a try-catch clause to handle potential exceptions.
Exception is an object of EmptyStack().
*/
void Stack::Pop()
{
	if (IsEmpty() == true)	throw EmptyStack();
	else
	{
		Node* pTemp = pTop;
		pTop = pTop->pNext; //Moves top to next item in the list.
		delete pTemp; //Deallocates memory for node to be deleted.
	}
}

/*
Top(): Displays the element sitting at the top of the stack.

Note: This method can throw an exception if the stack is empty at calling time.
All calls to this method should be in a try-catch clause to catch potential exceptions
Exceptions are objects of type EmptyStack().
*/
ItemType Stack::Top()
{
	if (this->IsEmpty())	throw EmptyStack();
	else					return pTop->iData;
}

Stack::~Stack()
{
	if (pTop != NULL) //If stack still has nodes with dynamically allocated memory.
	{
		Node* pTemp = pTop;
		Node* pTempTrailer = NULL;

		while (pTop != NULL)
		{
			pTempTrailer = pTop;
			pTop = pTop->pNext;
			delete pTempTrailer; //Deallocate memory from nodes in the list.
		}
	}
}