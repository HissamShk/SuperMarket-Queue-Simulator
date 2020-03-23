//CSCI 301
//Queue.cpp
//Queue Class: A Class to implement a Queue ADT (Abstract Data Type) of the
//Integer Type (Sequential (Array-based) Implementation).
//Hissamuddin Shaikh
#include <iostream>
#include <fstream>
#include "Queue.h"
using namespace std;
//Constructor
Queue::Queue()
{
	front = 0;
	rear = CAPACITY - 1;
	count = 0;
}
//Function to place a Value at the rear of the Queue.
void Queue:: enqueue(Item entry)
{
	rear = next_index(rear);
	data[rear] = entry;
	++count;
}
//Function to remove a Value from the front of the Queue.
Queue::Item Queue::dequeue()
{
	Item it;
	it = data[front];
	front = next_index(front);
	--count;
	return it;
}
//Function to return the number of Values (Size) in the Queue.
int Queue::size()
{
	return count;
}
//Function to inform whether or not the Queue is empty.
bool Queue::empty()
{
	return count == 0;
}
//Function to determine the position (determine rear) for the insertion of the Value into the Queue.
//Also recalibrates front when a value is removed from the queue.
int Queue::next_index(int i)
{
	return (i + 1) % CAPACITY;
}
//Freind function to print out the contents of the Queue, in order.
ostream& operator << (ostream& out_s, Queue q)
{
	int j = q.front;
	for (int i = 0; i < q.count; ++i)
	{
		out_s << "  " << q.data[j];
		j = q.next_index(j);
	}
	out_s << endl;
	out_s << endl;
	return out_s;
}
