// Author: jyotir07 @github
#include <stdio.h>

// Structure to represent a process
struct Process
{
  int process_id;
  int arrival_time;
  int burst_time;
  int priority;
  int completion_time;
  int turnaround_time;
  int waiting_time;
};
// Function to calculate turnaround time and waiting time for each process
void calculateTimes(struct Process processes[], int n)
{
  int total_waiting_time = 0;
  int total_turnaround_time = 0;

  processes[0].completion_time = processes[0].burst_time;
  processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
  processes[0].waiting_time = processes[0].turnaround_time - processes[0].burst_time;

  total_waiting_time += processes[0].waiting_time;
  total_turnaround_time += processes[0].turnaround_time;

  for (int i = 1; i < n; i++)
  {
    processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

    total_waiting_time += processes[i].waiting_time;
    total_turnaround_time += processes[i].turnaround_time;
  }

  // Calculate average waiting time and turnaround time
  double avg_waiting_time = (double)total_waiting_time / n;
  double avg_turnaround_time = (double)total_turnaround_time / n;

  // Display results
  printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
           processes[i].burst_time, processes[i].priority, processes[i].completion_time,
           processes[i].turnaround_time, processes[i].waiting_time);
  }

  printf("\nAverage Waiting Time: %.2lf", avg_waiting_time);
  printf("\nAverage Turnaround Time: %.2lf\n", avg_turnaround_time);
}

// Function to perform FCFS Priority Scheduling
void fcfsPriorityScheduling(struct Process processes[], int n)
{
  // Sort the processes based on arrival time
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (processes[j].arrival_time > processes[j + 1].arrival_time)
      {
        // Swap the processes
        struct Process temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }

  // Calculate turnaround time and waiting time
  calculateTimes(processes, n);
}

int main()
{
  int n;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct Process processes[n];

  // Input process details
  for (int i = 0; i < n; i++)
  {
    printf("Enter details for Process %d:\n", i + 1);
    processes[i].process_id = i + 1;
    printf("Arrival Time: ");
    scanf("%d", &processes[i].arrival_time);
    printf("Burst Time: ");
    scanf("%d", &processes[i].burst_time);
    printf("Priority: ");
    scanf("%d", &processes[i].priority);
  }

  // Perform FCFS Priority Scheduling
  fcfsPriorityScheduling(processes, n);

  return 0;
}
