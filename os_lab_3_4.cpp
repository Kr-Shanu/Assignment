#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// Function to calculate a proper qantum for the round robin method.
double minimum_burst(vector<double> burst)
{
   double min = burst[0];
   for (int i = 1; i < burst.size(); i++)
   {
      if (min < burst[i])
         min = burst[i];
   }
   return min;
}

// Function to calculate the round robin scheduling.
void calculate_round_robin(vector<double> burst)
{
   vector<double> turnAround, copy_burst;
   for (int i = 0; i < burst.size(); i++)
   {
      turnAround.push_back(0);
      copy_burst.push_back(burst[i]);
   }

   double quantum = minimum_burst(burst) / 2.0;

   int i = 0, counter = 1, j = 0;
   while (burst[burst.size() - 1] >= 0)
   {
      if (burst[i] >= 0)
      {
         burst[i] = burst[i] - quantum;
         if (burst[i] <= 0)
         {
            turnAround[j] = counter * quantum;
            j++;
         }
         i++;
         if (i == burst.size())
            i = 0;
      }
      counter++;
   }

   double totalWait = 0, throuhput = 0;

   for (int i = 0; i < burst.size(); i++)
   {
      totalWait = totalWait + (turnAround[i] - copy_burst[i]);
      throuhput = throuhput + turnAround[i];
   }

   cout << "Round Robin avg wait time : " << totalWait / burst.size() << endl;
   cout << "Round Robin avg througput time: " << throuhput / burst.size() << endl;
}

void swap(double *xp, double *yp)
{
   double temp = *xp;
   *xp = *yp;
   *yp = temp;
}

// A function to implement bubble sort
vector<double> bubbleSort(vector<double> arr)
{
   int n = arr.size();
   int i, j;
   for (i = 0; i < n - 1; i++)

      // Last i elements are already in place
      for (j = 0; j < n - i - 1; j++)
         if (arr[j] > arr[j + 1])
            swap(&arr[j], &arr[j + 1]);

   return arr;
}

// Function to calculate sjf preemptive method.
void calculate_sjf_preemptive(vector<double> burst)
{
   burst = bubbleSort(burst);
   double waitingTime = 0, totalTime = 0;
   int i;
   for (i = 0; i < burst.size() - 1; i++)
   {
      totalTime = totalTime + burst[i];
      waitingTime = waitingTime + burst[i];
   }
   totalTime = totalTime + burst[i];

   cout << "The average throughput time for sjf :" << totalTime / burst.size() << endl;
   cout << "The average waiting time for sjf :" << waitingTime / burst.size() << endl;
}

// The function to calculate fcfs scheduling .
void calculate_fcfs(vector<double> burst)
{
   double waitingTime = 0, totalTime = 0;
   int i;
   for (i = 0; i < burst.size() - 1; i++)
   {
      totalTime = totalTime + burst[i];
      waitingTime = waitingTime + burst[i];
   }
   totalTime = totalTime + burst[i];

   cout << "FCFS avg. throughput time :" << totalTime / burst.size() << endl;
   cout << "FFCS avg. wait time :" << waitingTime / burst.size() << endl;
}

void calculate_sjf_non_preemptive(vector<double> burst)
{
   double waitingTime = 0, totalTime = 0;
   int i;
   for (i = 0; i < burst.size() - 1; i++)
   {
      totalTime = totalTime + burst[i];
      waitingTime = waitingTime + burst[i];
   }
   totalTime = totalTime + burst[i];

   cout << "SJF non thrtput time :" << totalTime / burst.size() << endl;
   cout << "SJF avg wait time :" << waitingTime / burst.size() << endl;
}

// Function to calculate whether the given burst time is taken in
// priority or not.
bool taken(vector<double> elements, double search)
{
   for (int i = 0; i < elements.size(); i++)
   {
      if (search == elements[i])
         return true;
   }
   return false;
}

// Function to calculate priority scheduling.
void calculate_priority(vector<double> burst)
{
   // To store burst time of all the process which are to be executed.
   vector<double> values;

   double input, totalTime = 0, waitingTime = 0;

   while (values.size() != burst.size())
   {
      cout << "Enter the priority number:" << endl;
      cin >> input;
      if (taken(values, input))
      {
         cout << "Input already taken";
         continue;
      }
      else
      {
         values.push_back(input);
         totalTime = totalTime + burst[input - 1];
      }
   }
   // loop to calculate waiting time.
   for (int i = 0; i < burst.size() - 1; i++)
   {
      waitingTime = waitingTime + burst[i];
   }
   cout << "Priority avg. thrtput time :" << totalTime / burst.size() << endl;
   cout << "Priority avg. wait time :" << waitingTime / burst.size() << endl;
}

int main()
{

   srand(time(0));
   int number_of_processes = 1 + (rand() % 25);

   vector<double> burst_times;

   for (int i = 0; i < number_of_processes; i++)
   {
      int time = 1 + (rand() % 15);
      burst_times.push_back(time);
   }

   while (true)
   {
      cout << "Enter 1 for fcfs:" << endl;
      cout << "Enter 2 for sjf_preemptive:" << endl;
      cout << "Enter 3 for sjf_nonpreemptive:" << endl;
      cout << "Enter 4 for priority:" << endl;
      cout << "Enter 5 for round_robin:" << endl;
      cout << "Enter 0 to exit" << endl;

      int take_value;
      cin >> take_value;

      switch (take_value)
      {
      case 1:
         calculate_fcfs(burst_times);
         break;
      case 2:
         calculate_sjf_preemptive(burst_times);
         break;
      case 3:
         calculate_sjf_non_preemptive(burst_times);
         break;
      case 4:
         calculate_priority(burst_times);
         break;
      case 5:
         calculate_round_robin(burst_times);
         break;
      case 0:
         cout << "Thankyou!" << endl;
         exit(0);
      default:
         cout << "Invalid input:" << endl;
         break;
      }
   }
   return 0;
}
