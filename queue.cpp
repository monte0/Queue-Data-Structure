using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
	front = 0;
	rear = -1;
	count = 0;
}
//destructor 
queue::~queue()
{
}
// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}
// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	if (count == MAX_SIZE)
		return true;
	else
		return false;
}
// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be enqueued
void queue::enqueue(el_t newElem)
{
	if (isFull() == true)
		throw Overflow();
	else
		rear = (rear + 1) % MAX_SIZE;
		el[rear] = newElem;
		count++;
}
// PURPOSE: if empty, throw Underflow
// if not empty, dequeues the front element to give it back
// PARAMETER: provide a holder (dequeuedElem) for the element dequeued (pass by ref)
void queue::dequeue(el_t& dequeuedElem)
{
	if (isEmpty() == true)
		throw Underflow();
	else
		dequeuedElem = el[front];
		front = (front + 1) % MAX_SIZE;
		count--;
}
// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not dequeue it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
	if (isEmpty() == true)
		throw Underflow();
	else
		theElem = el[front];
}
// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
	return count;
}
// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{
	int j = front;
	if (isEmpty() == true)
		cout << " [ EMPTY  ]" << endl;
	else
	{
		cout << "[" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << el[j] << endl;// " ";
			j = (j + 1) % MAX_SIZE;
		}
		cout << "]" << endl;
	}
}
// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling dequeue followed by enqueue.
void queue::goToBack()
{
	el_t tmp;					//tmp is the local variable
	if (count == 0)
		throw Underflow();
	if (count == 1)
		cout << "only 1 element" << endl;
	else
		dequeue(tmp);
		enqueue(tmp);
}