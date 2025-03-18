#include<stdio.h>
int bt[20], wt[20], tat[20], i, p;
float wtavg, tatavg;

void main(){
    printf("Enter number of processes: ");
    scanf("%d", &p);

    printf("Enter burst time for the following processes:\n");
    for (int i=0; i<p ; i++){
        printf( "p%d: ", i);
        scanf("%d", &bt[i]);
    }
   
    wt[0]= wtavg = 0;
    tat[0] = bt[0];
    tatavg =0;

    for (int i =1; i<p; i++){
        wt[i]= wt[i-1]+bt[i-1];
    }
    for (int i =0; i<p; i++){
        tat[i]= wt[i]+bt[i];
        wtavg += wt[i];
        tatavg += tat[i];

    }
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i=0; i<p; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
       
    }
    printf("\nAverage Turn Around time: %.2f", tatavg/p);
    printf("\nAverage Waiting time: %.2f", wtavg/p);
}

