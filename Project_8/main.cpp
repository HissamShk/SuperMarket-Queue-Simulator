//CSCI 301
//PROJECT 8
//Store Queue Simulation
//Hissamuddin Shaikh
//This program utilizes the class, Queue, to create a probabilistic simulation of a queueing system
//with several queues and several servers, one server for each queue, as in a grocery or discount store.
//A vareity of parameters are acquired from the User, such as the proabaility of a Customer showing up, and
//how many serevers to include in the simualtion.
//The Simulation runs for a specified amount of time, and the state of the queue at each tick (minute) is displayed.
//At the end of the Simulation a vareity of statistics are displayed regarding the result of the Simulation.
//It exercises most of the functions of the Queue class, and has error control present to allow the program to
//run smoothly.
#include <iostream>
#include "Queue.h"
#include <fstream>
#include <cstdlib>
using namespace std;
/*Function Prototypes*/
int shortest_trans(Queue q[],int trans_time[], int number);
//Pre-Condition: Takes in the object, through which the size of a particular Queue will be accessed.
//				 Takes in the array, containing the transaction times for the Queues, at that instance.
//				 Takes in the number of queues that have been created within the Simulation.
//Post-Condition: Returns the postion of the first queue that is empty and has no transaction currently occuring.
int shortest_queue(Queue q[], int number);
//Pre-Condition: Takes in the object, through which the size of a particular Queue will be accessed.
//               Takes in the number of queues that have been created within the Simulation.
//Post-Condition: Returns the postion of the shortest queue (1st Queue, 2nd Queue and so on..).
int main()
{

 /*Data Variables*/

 //Number of Tellers in the Simulation
 int servers;
 //The Probability of a Customer arriving to be serviced, in a single tick.
 //This will be a percentage between 1 and 100.
 int arrival_probability;
 //The longest time any Transaction can take.
 int Max_Duration_Transaction;
 //The Duration of the Simulation; has to be at least 1.
 int Simulation_Duration;
 //An Integer Seed Value for the Pseudo-Random Number Generator.
 int random_n_seed;

 //Prompt for the User to enter the, necessary information to run the Simulation.
 cout << endl;
 cout << "   |Queue Simulator|" << endl;
 cout << endl;
 cout << "   Enter these Parameters for the Simulation:-" << endl;
 cout << endl;
 cout << "        The Number of Queue/Server Pairs: "; cin >> servers;
 cout << endl;
 cout << "        The Probability that a Customer will Arrive in 1 Tick (%): "; cin >> arrival_probability;
 cout << endl;
 cout << "        The Maximum Duration of a Transaction (in Ticks): "; cin >> Max_Duration_Transaction;
 cout << endl;
 cout << "        The Duration of the Simulation (in Ticks): "; cin >> Simulation_Duration;
 cout << endl;
 cout << "        Enter a Random Number (for the Seed): "; cin >> random_n_seed;
 cout << endl;

 //Intialize the Number of Queues for the Simulation, and other essential variables.
  Queue Lines[servers];
  double avgtime;
  int entry_time;
  double wait_sum[servers];
  int count = 0;
  int wait_time[servers];
  int total_customers_left = 0;
  srand(random_n_seed);
  int Duration = Simulation_Duration + 1;
  double total_wait_sum;
  int longest_wait_time = 0;
 //Initialize Transition Time to 0, and Wait Time to 0 for each Queue.
 int trans_time[servers];
 for (int index = 0; index < servers; ++index )
 {
	 trans_time[index] = 0;
	 wait_time[index] = 0;
 }
 //Main for-loop for the Simulation Computation.
 for (int time = 1; time < Duration; ++time)
 {
  if (rand()%100 < arrival_probability)
  {
	  int checker = -2;
	  int prospect2 = shortest_trans(Lines, trans_time, servers);
	  int prospect = shortest_queue(Lines,servers);
	  //Places the Customer in the shortest queue possible
	  if (prospect2 == checker)
	  {
		  Lines[prospect].enqueue(time);
	  }
	  else
		  Lines[prospect2].enqueue(time);

  }
  //Checking the Queues for Statistical Infromation at each tick.
  for (int index3 = 0; index3 < servers; ++index3)
  {
   if (trans_time[index3] == 0)
   {
    if(!Lines[index3].empty())
    {
     entry_time = Lines[index3].dequeue();
	 wait_sum[index3] += (time - entry_time);
	 if (time - entry_time > wait_time[index3])
		wait_time[index3] = time - entry_time;
	 //wait_time = time - entry_time;
     ++count;
     trans_time[index3] = rand()% Max_Duration_Transaction + 1;
    }
   }
   else
    --trans_time[index3];
  }
		//Producing a snapshot of the Simulation for that particular tick.
		cout << "   ---------------------- " << endl;
		cout << "   Time on Clock: " << time << endl;
		cout << "   ---------------------- " << endl;
		for (int index4 = 0; index4 < servers; ++index4)
		{
			int increment = index4 + 1 ;
			/***********************************************************************************************************************************
			 * ANSWER TO QUESTION IS 4 | ANSWER TO QUESTION IS 4 | ANSWER TO QUESTION IS 4 | ANSWER TO QUESTION IS 4 | ANSWER TO QUESTION IS 4 *
			 ***********************************************************************************************************************************/
			cout << endl;
			cout << "   Queue: " << increment;
			cout << " | ";
			cout << "  " << trans_time[index4] << "	" << Lines[index4];
			cout << endl;
		}

	}
	//Loop to Calculate the Total Remaining Customers in all the Queues.
	for (int index5 = 0; index5 < servers; ++index5)
	{
		total_customers_left = total_customers_left + Lines[index5].size();
	}
	//Loop to Calculate Total Wait Timne
	for (int index5 = 0; index5 < servers; ++index5)
	{
		total_wait_sum = total_wait_sum + wait_sum[index5];
	}
	//Loop to Calculate Longest Time Waited
	for (int index5 = 0; index5 < servers; ++index5)
	{
		if (wait_time[index5] > longest_wait_time)
			longest_wait_time = wait_time[index5];
	}
	//Calculating Average Time of Transactions
	avgtime = total_wait_sum/count;
	cout << "   ---------------------------------------------------------------------------------------   " << endl;
	cout << "   Statistical Summary " << endl;
	cout << "   ---------------------------------------------------------------------------------------  " << endl;
	cout << endl;
	//Outputs the Total Number of Customers Served.
	cout << "      The Number of Customers served: " << count << endl;
	cout << endl;
	//Outputs the Average Time (Number of Ticks) the Customers who were served waited.
	cout << "      The Average Time (Number of Ticks) waited, by the " << count << " Customers who were served: " << avgtime << endl;
	cout << endl;
	//Outputs the Longest Time waited by any one Customer.
	cout << "      The Longest Time waited by a Customer: " << longest_wait_time << endl;
	cout << endl;
	//Outputs the Number of Customers remaining in all the Queues, when the simulation was terminated.
	cout << "      The Number of Customers left in the Queues, when the Simulation was terminated: " << total_customers_left << endl;
	cout << endl;
	cout << "   ---------------------------------------------------------------------------------------   " << endl;
	return 0;
};
//Function to determine, which Queue amongst all the Queues setup, is the shortest.
int shortest_queue(Queue q[], int number)
{
    int index2 = 0;
    //For loop to compare each Queue, with the other avaialble Queues.
	for(int i = 0 ; i < number ; i++)
    {
		if(q[i].size() < q[index2].size())
		{
			index2 = i;
		}
    }
    return index2;
}
//Function to determine, which Queue has no occuring transaction and no people waiting to go next.
int shortest_trans(Queue q[],int trans_time[], int number)
{
	int index2 = -2;
	int i = 0;
	while (i < number && index2 < 0)
    {
        if (q[i].empty() && trans_time[i] == 0)
			index2 = i;
		i++;

    }

    if (index2 == -2)
	{
		return -2;
	}
	else
		return index2;
}
