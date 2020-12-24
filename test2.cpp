#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

using namespace std;

//Purpose of the program: To print out all possible combinations of A B C
//Algorithm: Queue 
int main()
{
	string tmp;
	queue Q;
	Q.enqueue("A");		// "A", "B", "C" in the queue
	Q.enqueue("B");
	Q.enqueue("C");

	while (1)// while loop -- indefinitely
	{
		try
		{
			Q.dequeue(tmp);
			cout << tmp << endl;
			if (!Q.isFull())
				Q.enqueue(tmp + "A");
			else
				throw queue::Overflow();
			if (!Q.isFull())
				Q.enqueue(tmp + "B");
			else
				throw queue::Overflow();
			if (!Q.isFull())
				Q.enqueue(tmp + "C");
			else
				throw queue::Overflow();
		}
		catch (queue::Overflow)			//catches
		{
			Q.displayAll();
			cout << "CANNOT ADD" << endl;
			break;
		}
	}

	return 0;

}

