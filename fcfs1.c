#include<stdio.h>

int main()
{
    int n;
    float awt=0,atat=0;
    int i,j;
    printf("Enter total number of processes:");
    scanf("%d",&n);
    int bt[n],wt[n],tat[n];

    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        awt+=wt[i];
        atat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    awt/=i;
    atat/=i;
    printf("\n\nAverage Waiting Time:%f",awt);
    printf("\n\nAverage Turnaround Time:%f",atat);
    printf("\n\n-------------------------------------18BCE0559-------------------------------------");
    return 0;
}
