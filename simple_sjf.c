#include <stdio.h>

struct Process {
    int id;
    int burst;
};

void sjfScheduling(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst > processes[j + 1].burst) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int wait[n];
    int turnaround[n];

    wait[0] = 0;
    turnaround[0] = processes[0].burst;
    for (int i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + processes[i - 1].burst;
        turnaround[i] = wait[i] + processes[i].burst;
    }

    double avgWait = 0.0;
    double avgTurnaround = 0.0;
    for (int i = 0; i < n; i++) {
        avgWait += wait[i];
        avgTurnaround += turnaround[i];
    }
    avgWait /= n;
    avgTurnaround /= n;

    printf("Process\tBurst\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i].id, processes[i].burst, wait[i], turnaround[i]);
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
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst);
    }

    sjfScheduling(processes, n);

    return 0;
}
