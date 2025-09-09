#include <stdio.h>

void main() {
    int n;
    printf("SJF CPU Scheduling Algorithm\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n], burstTime[n], arrivalTime[n], isCompleted[n];;
    int waitingTime[n], turnaroundTime[n], completionTime[n];
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;}
    
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter the arrival time and burst time for process %d:", i+1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }
    int currentTime = 0, completed = 0, totalWaitingTime = 0, totalTurnaroundTime = 0;
    
    while (completed != n) {
        int minBurstTime = __INT_MAX__;                              
        int selectedProcess = -1;
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && isCompleted[i] == 0) {
                if (burstTime[i] < minBurstTime) {
                    minBurstTime = burstTime[i];
                    selectedProcess = i;
                } } }
        
        if (selectedProcess == -1) {
            currentTime++;
        } else {
            completionTime[selectedProcess] = currentTime + burstTime[selectedProcess];
            turnaroundTime[selectedProcess] = completionTime[selectedProcess] - arrivalTime[selectedProcess];
            waitingTime[selectedProcess] = turnaroundTime[selectedProcess] - burstTime[selectedProcess];
            totalWaitingTime += waitingTime[selectedProcess];
            totalTurnaroundTime += turnaroundTime[selectedProcess];
            
            isCompleted[selectedProcess] = 1;
            currentTime = completionTime[selectedProcess];
            completed++;
        } }
    
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;
    
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               process[i], arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i], completionTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);   
}
