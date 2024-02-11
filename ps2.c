#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int n,i,j,temp;
    float awt,ata;
    printf("Enter the number of process:");
    scanf("%d",&n);
    int p[n],st[n],ft[n],wt[n],ta[n],et[n],at[n];
    char pn[n][n],t[n];
    for(i=0; i<n; i++)
    {
        printf("Enter process no,arrivaltime,execution time & priority:");
        scanf("%s%d%d%d",pn[i],&at[i],&et[i],&p[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)

    {

        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        awt+=wt[i];
        ata+=ta[i];
    }
    awt=(float)awt/n;
    ata=(float)ata/n;
    printf("\nProcessno\tArrivaltime\tBursttime\tpriority\tWaitingtime\tTurnaroundtime");
    for(i=0; i<n; i++)
        printf("\n%s\t\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    getch();
}
