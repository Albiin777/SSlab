#include<stdio.h> 

int q[100], f = -1, r = -1; 
void insert(int n) 
{  if (f == -1) 
        f = 0; 
    r = r + 1; 
    q[r] = n; 
} 
int delete()  
{   int n; 
    n = q[f]; 
    f = f + 1; 
    return n; 
} 
void main() 
{ 
    int tq, n, i, t = 0, curr;  
    float twt = 0, ttat = 0; 
    printf("Round Robin CPU Scheduling Algorithm"); 
    printf("\nEnter how many processes: "); 
    scanf("%d", &n); 
    int p[100], at[100], bt[100], wt[100], tat[100], bt2[100], exist[100] = {0}; 
    for (i = 0; i < n; i++) 
    { 
        p[i] = i + 1; 
        printf("Enter the arrival time and burst time for process %d: ", i + 1); 
        scanf("%d %d", &at[i], &bt[i]); 
        bt2[i] = bt[i]; 
    } 
    printf("\nEnter time quantum: "); 
    scanf("%d", &tq); 
    insert(0); 
    exist[0] = 1;  
while (f <= r) 
    {   curr = delete();    
        if (bt[curr] >= tq) 
        {   bt[curr] -= tq; 
            t += tq; 
        } 
        else 
        {   t += bt[curr]; 
            bt[curr] = 0; 
        } 
        for (i = 0; i < n; i++) 
        {   if (exist[i] == 0 && at[i] <= t) 
            {   insert(i); 
                exist[i] = 1; } 
        } 
        if (bt[curr] == 0) 
        {   tat[curr] = t - at[curr]; 
            wt[curr] = tat[curr] - bt2[curr]; 
            ttat += tat[curr]; 
            twt += wt[curr]; 
        } 
        else 
        {   insert(curr); 
        } 
    } 
    printf("\nPNo.\tAT\tBT\tTAT\tWT\tCT"); 
    for (i = 0; i < n; i++) 
    {   printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt2[i], tat[i], wt[i], at[i] + tat[i]); 
    } 

    printf("\nAverage Turnaround time = %f", ttat / n); 
    printf("\nAverage Waiting time = %f", twt / n); 
}

 
