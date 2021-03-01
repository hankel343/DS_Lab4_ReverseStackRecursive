#ifndef QUEUE_H
#define QUEUE_H
#include "ItemType.h"
#include "Stack.h" //This header file is here because of the node struct that is commond to both classes.
#include <cstddef>
#include <new>

class FullQueue {};
class EmptyQueue {};

class Queue
{
private:
	Node* pFront;
	Node* pRear;

public:
	//Constructor:
	Queue();

	//Methods:
	void MakeEmpty();
	void Enqueue(ItemType iNewItem);
	void Dequeue(ItemType& iRemovedItem);
	bool IsEmpty() const;
	bool IsFull() const;

	//Destructor:
	~Queue();
};

#endif QUEUE_H