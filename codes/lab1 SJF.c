#include <stdio.h>

void main(){
    int n,i,j,temp,bt[20],p[20],wt[20],tat[20];

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    printf("Enter burst time for the following processes:\n");
    for (int i=0; i<n ; i++){
        printf( "p%d: ", i);
        scanf("%d", &bt[i]);
    }

    for(i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    float wtavg=0,tatavg=bt[0];
    wt[0]=0;
    tat[0]=bt[0];
    for (int i =1; i<n; i++){
        wt[i]= wt[i-1]+bt[i-1];
    }
    for (int i =0; i<n; i++){
        tat[i]= wt[i]+bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
  
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i=0; i<n; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
       
    }
    printf("\nAverage Turn Around time: %.2f", tatavg/n);
    printf("\nAverage Waiting time: %.2f", wtavg/n);
}