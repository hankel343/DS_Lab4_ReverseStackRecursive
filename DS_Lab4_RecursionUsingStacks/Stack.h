#ifndef STACK_H
#define STACK_H

#include "ItemType.h"

struct Node
{
	ItemType iData;
	Node* pNext;
};

//FullStack and EmptyStack are used for exception handling.
class FullStack {};
class EmptyStack {};

class Stack
{
private:
	Node* pTop = nullptr; //Pointer to top of stack
	const int nMAX_ITEMS = 5;

public:
	//Constructor:
	Stack();

	//Getters:
	bool IsEmpty();
	//Pre: Stack object exists
	//Post: Returns true or false based on whether the stack is empty.

	bool IsFull();
	//Pre: Stack object exists
	//Post: Returns true or false based on whether the stack is contains the maximum number of elements.
	//***Note*** This method can throw exceptions of type bad_alloc. Handles own exceptions.

	//Setters:
	void Push(ItemType iNewItem);
	//Pre: Stack object exists and the stack is not full.
	//Post: A new item is pushed on to the stack
	//***Note*** This method can throw exceptions of type FullStack. Client must have try-catch clause.

	void Pop();
	//Pre: Stack object exists and the stack is not empty.
	//Post: The top most item is removed from the stack (and not returned).
	//***Note*** This method can throw exceptions of type EmptyStack. Client must have try-catch clause.

	ItemType Top();
	//Pre: A stack object exists and client has verified stack is not empty.
	//Post: A copy of the item on the top of the stack is returned (and not removed).
	//***Note*** This method can throw exceptions of type EmptyStack. Client must have try-catch clause.

	//Destructor:
	~Stack();
	//Pre: A stack object exists.
	//Post all memory allocated for the stack object will be deallocated.
};

#endif STACK_H