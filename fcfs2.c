#include<stdio.h>
#include<string.h>
#include<conio.h>
main()
{
    int i,j,n,temp;
    float awt=0,atat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int a[n],b[n],star[n],finish[n],tat[n],wt[n],p[n];
    for(i=0; i<n; i++)
    {
        printf("\nEnter the Arrival Time of process %d:",i+1);
        scanf("%d",&a[i]);
        printf("Enter the Burst Time of process %d:",i+1);
        scanf("%d",&b[i]);
    }
     printf("\nEnter the process numbers:\n");
     for(j=0;j<n;j++)
     {
        scanf("%d",&p[j]);
     }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }

        }
    }
    for(i=0; i<n; i++)
    {
        if(i==0)
            star[i]=a[i];
        else
            star[i]=finish[i-1];
        wt[i]=star[i]-a[i];
        finish[i]=star[i]+b[i];
        tat[i]=finish[i]-a[i];
    }
    printf("\nProcessno\tArrivaltime\tBursttime\tWaitingTime\tTurnaroundtime");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t\t%3d\t\t%3d\t\t%3d\t\t%6d",p[i],a[i],b[i],wt[i],tat[i]);
        awt+=wt[i];
        atat+=tat[i];
    }
    printf("\nAverage Waiting time:%f",(float)awt/n);
    printf("\nAverage Turn Around Time:%f",(float)atat/n);
    printf("\n\n-------------------------------------18BCE0559-------------------------------------");
    return 0;
}
