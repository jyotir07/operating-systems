//java program for SJF (Shortest Job First) process scheduling
//Author: jyotir07 @github
import java.util.Scanner;
class Process {
    int id;
    int burst;

    Process(int id, int burst) {
        this.id = id;
        this.burst = burst;
    }
}

public class SJFScheduling {
    public static void sjfScheduling(Process[] processes) {
        int n = processes.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (processes[j].burst > processes[j + 1].burst) {
                    Process temp = processes[j];
                    processes[j] = processes[j + 1];
                    processes[j + 1] = temp;
                }
            }
        }

        int[] wait = new int[n];
        int[] turnaround = new int[n];

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

        System.out.println("Process\tBurst\tWait\tTurnaround");
        for (int i = 0; i < n; i++) {
            System.out.println(processes[i].id + "\t" + processes[i].burst + "\t" + wait[i] + "\t" + turnaround[i]);
        }
        System.out.printf("Avg Wait: %.2f\n", avgWait);
        System.out.printf("Avg Turnaround: %.2f\n", avgTurnaround);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = scanner.nextInt();

        Process[] processes = new Process[n];

        for (int i = 0; i < n; i++) {
            int id = i + 1;
            System.out.print("Enter burst time for Process " + id + ": ");
            int burst = scanner.nextInt();
            processes[i] = new Process(id, burst);
        }

        sjfScheduling(processes);
    }
}
