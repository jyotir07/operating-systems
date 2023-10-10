//in this code I have removed sorting and made it a little more opnimized     
#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int wait;
    int turnaround;
};

void sjfScheduling(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        int shortest = -1;
        for (int j = 0; j < n; j++) {
            if (processes[j].arrival <= currentTime && processes[j].burst > 0) {
                if (shortest == -1 || processes[j].burst < processes[shortest].burst) {
                    shortest = j;
                }
            }
        }

        if (shortest == -1) {
            currentTime++;
            continue;
        }

        processes[shortest].wait = currentTime - processes[shortest].arrival;
        processes[shortest].turnaround = processes[shortest].wait + processes[shortest].burst;
        currentTime += processes[shortest].burst;
        processes[shortest].burst = 0;
    }

    double avgWait = 0.0;
    double avgTurnaround = 0.0;
    for (int i = 0; i < n; i++) {
        avgWait += processes[i].wait;
        avgTurnaround += processes[i].turnaround;
    }
    avgWait /= n;
    avgTurnaround /= n;

    printf("Process\tArrival\tBurst\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival, processes[i].burst, processes[i].wait, processes[i].turnaround);
    }
    printf("Avg Wait: %.2lf\n", avgWait);
    printf("Avg Turnaround: %.2lf\n", avgTurnaround);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst);
    }

    sjfScheduling(processes, n);

    return 0;
}
