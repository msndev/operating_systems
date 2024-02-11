#include <stdio.h>

int main()
{
      int c = 0, m, n, p, t, r,at[10],a[10], cu[10][10], mc[10][10],mr[10], ru[10], s = 0;
      for(m=0;m<10;m++)
      {
         at[m]=0;
      }
      printf("\nEnter The Total Number Of Processes:\t");
      scanf("%d", &p);
      for(m = 0; m < p; m++)
      {
            ru[m] = 1;
            c++;
      }
      printf("\nEnter The Total Number Of Resources To Allocate:\t");
      scanf("%d", &r);
      printf("\nEnter The Claim Vector:\t");
      for(m = 0; m < r; m++)
      {
            scanf("%d", &mr[m]);
      }
      printf("\nEnter Allocated Resource Table:\n");
      for(m = 0; m < p; m++)
      {
            for(n = 0; n < r; n++)
            {
                  scanf("%d", &cu[m][n]);
            }
      }
      printf("\nEnter The Maximum Claim Table:\n");
      for(m = 0; m < p; m++)
      {
            for(n = 0; n < r; n++)
            {
                  scanf("%d", &mc[m][n]);
            }
      }
      for(m = 0; m < p; m++)
      {
            for(n = 0; n < r; n++)
            {
                  at[n] = at[n] + cu[m][n];
            }
      }
      for(m = 0; m < r; m++)
      {
            a[m] = mr[m] - at[m];
      }
      printf("\n");
      while(c != 0)
      {
            s = 0;
            for(m = 0; m < p; m++)
            {
                  if(ru[m])
                  {
                        t = 1;
                        for(n = 0; n < r; n++)
                        {
                              if(mc[m][n] - cu[m][n] > a[n])
                              {
                                    t = 0;
                                    break;
                              }
                        }
                        if(t)
                        {
                               ru[m] = 0;
                               c--;
                               s = 1;
                               for(n = 0; n < r; n++)
                               {
                                     a[n] = a[n] + cu[m][n];
                               }
                               break;
                        }
                  }
            }
            if(!s)
            {
                  printf("unsafe\n");
                  break;
            }
            else
            {
                  printf("\nsafe\n");
            }
      }
      return 0;
}
