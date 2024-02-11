#include <stdio.h>
#define HI 199
#define LO 0
void fcfs() {
int q[100],n,h,i,j,k,s=0,d;
    float a;
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    printf("Enter queue: \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&q[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d",&h);
    q[0]=h;
    printf("\n");
    for(j=0;j<=n-1;j++)
    {
d=abs(q[j+1]-q[j]);
s+=d;
printf("Move from %d to %d with seek %d\n",q[j],q[j+1],d);
    }
    printf("\nTotal seek is %d \t",s);
    a=s/(float)n;
    printf("\nAvg Seek Time is %f\n",a);
}
void scan()
{
    int i,j,s=0,n;
    int dis;
    int t,m;
    int dloc;
    printf("Enter no of location:\t");
    scanf("%d",&n);
    printf("Enter position of head:\t");
    scanf("%d",&dis);
    int d[n+1];
    printf("Enter elemets of disk queue:\n");
    for(i=0;i<n;i++)
    {
    scanf("%d",&d[i]);
    }
    d[n]=dis;
    n++;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(d[i]>d[j])
            {
                t=d[i];
                d[i]=d[j];
                d[j]=t;
} }
    }
    m=d[n-1];
    for(i=0;i<n;i++)
    {
        if(dis==d[i])
        {
dloc=i;
break; }
    }
    for(i=dloc;i>=0;i--)
    {
        printf("%d --> ",d[i]);
    }
    printf("0 --> ");
    for(i=dloc+1;i<n;i++)
    {
        printf("%d --> ",d[i]);
    }
s=abs(dis+m);
printf("\nMovement of total cylinders: %d",s);
}
void cscan()
{
int q[20],n=0,h=0,i,j,k,s=0,m=0,d=0,t=0,q1[20],q2[20],t1=0,t2=0; float a;
printf("Enter the initial head position: ");
scanf("%d",&h);
printf("Enter the size of queue request: "); scanf("%d",&n);
printf("Enter the queue of disk positons to be read: \n"); for(i=1;i<=n;i++)
{
        scanf("%d",&t);
        if(t>=h)
        {
            q1[t1]=t;
            t1++;
            } else {
q2[t2]=t;
t2++; }
}
for(i=0;i<t1;i++)
{
    for(j=i+1;j<t1;j++)
    {
        if(q1[i]>q1[j])
        {
            t=q1[i];
            q1[i]=q1[j];
            q1[j]=t;
} }
}
for(i=0;i<t2-1;i++)
{
    for(j=i+1;j<t2;j++)
    {
        if(q2[i]>q2[j])
        {
            t=q2[i];
            q2[i]=q2[j];
            q2[j]=t;
} }
}
if(abs(h-LO)>=abs(h-HI))
{
    for(i=1,j=0;j<t1;i++,j++)
    {
        q[i]=q1[j];
    }
    q[i]=HI;
    q[i+1]=0;
    for(i=t1+3,j=0;j<t2;i++,j++)
    {
        q[i]=q2[j];
    }
} else {
    for(i=1,j=t2-1; j>=0;i++,j--)
    {
        q[i]=q2[j];
    }
    q[i]=LO;
    q[i+1]=HI;
    for(i=t2+3,j=t1-1;j>=0;i++,j--)
    {
        q[i]=q1[j];
        }
    }
    q[0]=h;
    for(j=0;j<=n+1;j++)
    {
        d=abs(q[j+1]-q[j]);
        s+=d;
        printf("Disk head moves from %d to %d with seek
%d\n",q[j],q[j+1],d);
    }
    printf("Total seek time is %d\n",s);
    a=s/(float)n;
    printf("Average seek time is %f\n",a);
}
int main() {
    int c;
    printf("Enter choice: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1: fcfs();
            break;
        case 2: scan();
            break;
        case 3: cscan();
            break;
}
return 0; }