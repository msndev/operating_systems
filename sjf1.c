#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,n,temp;
 float aw=0,atat=0;
 printf("Enter the number of processes: ");
 scanf("%d",&n);
 int p[n],b[n],w[n],tat[n];
 printf("\nEnter the burst time values: \n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&b[i]);
 }
 printf("\nEnter the process number: \n");
 for(j=0;j<n;j++)
 {
 scanf("%d",&p[j]);
 }
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
    if(b[j]>b[j+1])
    {
     temp=b[j];
     b[j]=b[j+1];
     b[j+1]=temp;
     temp=p[j];
     p[j]=p[j+1];
     p[j+1]=temp;
    }
  }
}
printf("\nProcess number\tBursttime\tWaitingtime\tTurnaroundtime\t\t");
 for(i=0;i<n;i++)
 {
    w[i]=0;
    tat[i]=0;
    for(j=0;j<i;j++)
    {
     w[i]=w[i]+b[j];
    }
    tat[i]=w[i]+b[i];
    aw=aw+w[i];
    atat=atat+tat[i];
    printf("\n%d\t\t%d\t\t%d\t\t%d\t",p[i],b[i],w[i],tat[i]);
}
 aw=aw/n;
 printf("\nAverage waiting time: %f\n",aw);
 atat=atat/n;
 printf("\nAverage turn around time: %f\n",atat);
 printf("\n\n-------------------------------------18BCE0559-------------------------------------");
}
