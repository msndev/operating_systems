#include <stdio.h>
int main()
{
      int a[10], b[10], temp[10];
      int i, s, count = 0, time, n;
      double w = 0, tat = 0, end;
      float awt, atat;
      printf("\nEnter the Total Number of Processes:");
      scanf("%d", &n);
      printf("\nEnter Details of %d Processes\n", n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter Arrival Time:");
            scanf("%d", &a[i]);
            printf("Enter Burst Time:");
            scanf("%d", &b[i]);
            temp[i] = b[i];
      }
      b[9] = 9999;
      for(time = 0; count != n; time++)
      {
            s = 9;
            for(i = 0; i < n; i++)
            {
                  if(a[i] <= time && b[i] < b[s] && b[i] > 0)
                  {
                        s = i;
                  }
            }
            b[s]--;
             if(b[s] == 0)
            {
                  count++;
                  end = time + 1;
                  w = w + end - a[s] - temp[s];
                  tat = tat + end - a[s];
            }
      }
      awt = w / n;
      atat = tat / n;
      printf("\n\nAverage Waiting Time:%f\n", awt);
      printf("Average Turnaround Time:%f\n", atat);
      return 0;
}
