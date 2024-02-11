#include<stdio.h>

int main()
{

  int c,j,n,time,remain,flag=0,tq;
  int wt=0,tat=0;
  printf("Enter total no of processes: ");
  scanf("%d",&n);
  int at[n],bt[n],rt[n];
  remain=n;
  for(c=0;c<n;c++)
  {
    printf("Enter Arrival Time for Process Process Number %d :",c+1);
    scanf("%d",&at[c]);
    printf("Enter Burst Time for Process Process Number %d :",c+1);
    scanf("%d",&bt[c]);
    rt[c]=bt[c];
  }
  printf("Enter Time Quantum:");
  scanf("%d",&tq);
  printf("\n\nProcess\t\tWaiting Time\t\tTurnaround Time\n");
  for(time=0,c=0;remain!=0;)
  {
    if(rt[c]<=tq && rt[c]>0)
    {
      time+=rt[c];
      rt[c]=0;
      flag=1;
    }
    else if(rt[c]>0)
    {
      rt[c]-=tq;
      time+=tq;
    }
    if(rt[c]==0 && flag==1)
    {
      remain--;
      printf("\nP[%d]\t\t%d\t\t%d",c+1,time-at[c]-bt[c],time-at[c]);
      wt+=time-at[c]-bt[c];
      tat+=time-at[c];
      flag=0;
    }
    if(c==n-1)
      c=0;
    else if(at[c+1]<=time)
      c++;
    else
      c=0;
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("\nAvg Turnaround Time = %f",tat*1.0/n);
  printf("\n\n-------------------------------------18BCE0559-------------------------------------");
  return 0;
}
