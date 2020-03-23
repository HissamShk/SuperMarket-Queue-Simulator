//CSCI 301
//Queue.h
//Queue Class: A Class to implement a Queue ADT (Abstract Data Type) of the
//Integer Type (Sequential (Array-based) Implementation).
//Hissamuddin Shaikh
//This class contains a variety of functions, that allows for the creation, manipulation and querying of a queue.
//The queue present in this class, has been implemented through an array-based approach.
#ifndef QUEUE_H
#define QUEUE_H
#include <fstream>
using namespace std;
//Class, containing functions that will implement a Sequential (Array-based) Queue.
class Queue
{
	public:
		//An Alias for the type assignment, to make it easier to change the type of Queue, if necessary.
		typedef int Item;
		//Declaration fo a Constant
		static const int CAPACITY = 10000;
		//Constructor
		Queue();
		/*Modificiation Member Functions*/
		void enqueue(Item entry);
		//Pre-Condition: Takes in an entry, of the type defined by "Item" .
        //Post-Condition: Places the Value at the end of the Queue(at the rear),
		//while also taking into account the increase in the lenght of the Queue.
		Item dequeue();
        //Post-Condition: Removes the Value at the front of the Queue(at the front), while
		//				  also taking into account the decrease in the lenght of the Queue.
		/*Constant Member Functions*/
		int size();
		//Post-Condition: Returns the size of the (at the time of being called).
		bool empty();
		//Post-Condition: Returns whether or not the Queue is empty.
		friend ostream& operator << (ostream& out_f, Queue q);
		//Post-Condition: Outputs all the values present in the Queue, in order.
		/*Private Member Functions*/
		int next_index(int i);
		//Post-Condition: Decides at which point in the Queue to insert a Value (assigns rear).
		//				  Also, recalibrates what value is at the front of the Queue (reassigns/assigns front)
	private:
		/*Data Members for the Class*/
		//Array to store the Values for the Queue.
		Item data[CAPACITY];
		//Variable to track the Value at the front of the Queue.
		int front;
		//Variable to track the Value at the rear of the Queue.
		int rear;
		//Variable to return the Number of Values stored in the Queue.
		int count;
};
#endif //QUEUE_H
