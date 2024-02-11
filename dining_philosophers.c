#include <stdio.h>

void wf();
void bf();
void ff();

int main()
{
    int c;
    printf("")
    scanf("%d", &c);
    switch(c)
    {
        case 1: wf();
            break;
        case 2: bf();
            break;
        case 3: ff();
            break;
    }
}

void wf()
{
    int bn,pn,b[20],p[20],i,j,alloc[20],flag[20],temp;
    printf("Enter the no of blocks: ");
    scanf("%d",&bn);
    printf("Enter the no of processes: ");
    scanf("%d",&pn);
    for(i=0;i<bn;i++)
    {
        printf("Enter size of block %d: ",i+1);
        scanf("%d", &b[i]);
    }
    for(i=0;i<pn;i++)
    {
        printf("Enter size of process %d: ",i+1);
        scanf("%d", &p[i]);
    }
    for(i=0;i<bn;i++)
    {
        for(j=i+1;j<bn;j++)
        {
            if(b[i]>b[j])
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    printf("After sorting\n");
    for(i=0;i<bn;i++)
    {
        printf("%d\t",b[i]);
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<bn;j++)
        {
            if(p[i]<=b[j])
            {
                alloc[j]=p[i];
                printf("\n\nAlloc[%d]",alloc[j]);
                printf("\n\nProcess %d of size %d is allocated in block %d of size %d",j+1,p[j],i+1,b[i]);
                flag[j]=0;
                b[i]=0;
                break;
            }
            else
            {
                flag[j]=1;
            }
        }
    }
    for(j=0;j<pn;j++)
    {
        if(flag[j]!=0)
         printf("\n\nProcess %d of size %d is not allocated",j+1,p[j]);
    }


}

void bf()
{
   int bn,pn,b[20],p[20],i,j,alloc[20],flag[20],temp;
    printf("Enter the no of blocks: ");
    scanf("%d",&bn);
    printf("Enter the no of processes: ");
    scanf("%d",&pn);
    for(i=0;i<bn;i++)
    {
        printf("Enter size of block %d: ",i+1);
        scanf("%d", &b[i]);
    }
    for(i=0;i<pn;i++)
    {
        printf("Enter size of process %d: ",i+1);
        scanf("%d", &p[i]);
    }
    for(i=0;i<bn;i++)
    {
        for(j=0;j<bn;j++)
        {
            if(b[i]<b[j])
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    printf("After sorting\n");
    for(i=0;i<bn;i++)
    {
        printf("%d\t",b[i]);
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<bn;j++)
        {
            if(p[i]<=b[j])
            {
                alloc[j]=p[i];
                printf("\n\nAlloc[%d]",alloc[j]);
                printf("\n\nProcess %d of size %d is allocated in block %d of size %d",j+1,p[j],i+1,b[i]);
                flag[j]=0;
                b[i]=0;
                break;
            }
            else
            {
                flag[j]=1;
            }
        }
    }
    for(j=0;j<pn;j++)
    {
        if(flag[j]!=0)
         printf("\n\nProcess %d of size %d is not allocated",j+1,p[j]);
    }
}

void ff()
{
    int bn,pn,b[20],p[20],i,j,alloc[20],flag[20];
    printf("Enter the no of blocks: ");
    scanf("%d",&bn);
    printf("Enter the no of processes: ");
    scanf("%d",&pn);
    for(i=0;i<bn;i++)
    {
        printf("Enter size of block %d: ",i+1);
        scanf("%d", &b[i]);
    }
    for(i=0;i<pn;i++)
    {
        printf("Enter size of process %d: ",i+1);
        scanf("%d", &p[i]);
    }
    for(i=0;i<bn;i++)
    {
        for(j=0;j<pn;j++)
        {
            if(b[i]>=p[j])
            {
                alloc[i]=p[i];
                printf("\n\nProcess %d of size %d is allocated in block %d of size %d",j+1,p[j],i+1,b[i]);
                flag[j]=0;
                b[i]=0;
                break;
            }
            else
            {
                flag[j]=1;
            }
        }
    }
    for(j=0;j<pn;j++)
    {
        if(flag[j]!=0)
         printf("\n\nProcess %d of size %d is not allocated",j+1,p[j]);
    }
}
