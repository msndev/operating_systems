#include <stdio.h>
#include <string.h>
void fifo() {
int rs[20],pf=0,i,j,k,fs=3,n=12;
rs[0]=2; rs[1]=3; rs[2]=2; rs[3]=1; rs[4]=5; rs[5]=2; rs[6]=4; rs[7]=5; rs[8]=3; rs[9]=2; rs[10]=5; rs[11]=2;
    printf("Given reference string is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",rs[i]);
    }
    printf("\nFrame size is 3\n");
    int t[fs];
    for(i=0;i<fs;i++)
    {
t[i]=-1; }
    for(i=0;i<n;i++)
    {
        k=0;
        for(j=0;j<fs;j++)
        {
            if(rs[i]==t[j])
            {
k++;
pf--; }
        }
        pf++;
        if((pf<=fs) && (k==0))
        {
            t[i]=rs[i];
        }
        else if(k==0)
        {
            t[(pf-1)%fs]=rs[i];
        }
        printf("\n");
        for(j=0;j<fs;j++)
        {
            printf("%d\t",t[j]);
        }
}
    printf("\nTotal Page fault: %d\n",pf);
}
void lru() {
int rs[20],t[20],f[20],m,n,p,k,l,a=0,b=0,pf=0,no=12,fs=3;
rs[0]=2; rs[1]=3; rs[2]=2; rs[3]=1; rs[4]=5; rs[5]=2; rs[6]=4; rs[7]=5; rs[8]=3; rs[9]=2; rs[10]=5; rs[11]=2;
    printf("Given reference string is: ");
    for(m=0;m<no;m++)
    {
        printf("%d ",rs[m]);
    }
    printf("\nFrame size is 3\n");
    for(m=0;m<fs;m++){
f[m]=-1; }
    for(n=0;n<no;n++)
    {
        a=0, b=0;
        for(m=0;m<fs;m++)
        {
            if(f[m]==rs[n])
            {
                a=1;
                b=1;
                break;
        if(a==0)
        {
        for(m=0;m<fs;m++)
        {
            if(f[m]==-1)
            {
} }
} }
} if(b==0)
f[m]=rs[n];
b=1;
break;
{
    for(m=0;m<fs;m++)
    {
t[m]=0; }
    for(k=n-1,l=1;l<=3-1;l++,k--)
    {
        for(m=0;m<fs;m++)
        {
            if(f[m]==rs[k])
            {
t[m]=1;
} }
        }
        for(m=0;m<fs;m++)
        {
if(t[m]==0)
p=m; }
f[p]=rs[n];
pf++; }
    printf("\n");
    for(m=0;m<fs;m++)
    {
        printf("%d\t",f[m]);
    }
}
    printf("\nTotal No of page fault: %d\n",pf);
}
void lfu() {
int tf=3,h=0;
int rs[20],f[20],a[25],t[25];
int m,n,p,flag,k,mt,temp,no=12;
rs[0]=2; rs[1]=3; rs[2]=2; rs[3]=1; rs[4]=5; rs[5]=2; rs[6]=4;
rs[7]=5; rs[8]=3; rs[9]=2; rs[10]=5; rs[11]=2; printf("Given reference string is: "); for(m=0;m<no;m++)
{
        printf("%d ",rs[m]);
    }
    printf("\nFrame size is 3\n");
    for(m=0;m<tf;m++)
    {
f[m]=-1; }
    for(m=0;m<25;m++)
    {
a[m]=0; }
    printf("\n");
    for(m=0;m<no;m++)
    {
        a[rs[m]]++;
        t[rs[m]]=m;
        flag=1;
        k=f[0];
        for(n=0;n<tf;n++)
        {
            if(f[n]==-1 || f[n]==rs[m])
            {
                if(f[n]!=-1)
                {
h++; }
flag=0;
f[n]=rs[m];
break; }
            if(a[k]>a[f[n]])
            {
k=f[n]; }
} if(flag) {
            mt=25;
            for(n=0;n<tf;n++)
            {
                if(a[f[n]]==a[k] && t[f[n]]<mt)
                {
temp=n;
                    mt=t[f[n]];
                }
            }
            a[f[temp]]=0;
            f[temp]=rs[m];
        }
        for(n=0;n<tf;n++)
        {
            printf("%d\t",f[n]);
}
        printf("\n");
    }
    printf("Page Fault: %d\n",h);
}
void optimal()
{
int rs[20],f[20],i[20],tf=3,no=12;
int pf=0,m,n,t,flag,fo;
int p,mi,p_f=-1;
rs[0]=2; rs[1]=3; rs[2]=2; rs[3]=1; rs[4]=5; rs[5]=2; rs[6]=4;
rs[7]=5; rs[8]=3; rs[9]=2; rs[10]=5; rs[11]=2; printf("Given reference string is: "); for(m=0;m<no;m++)
{
        printf("%d ",rs[m]);
    }
    printf("\nFrame size is 3\n");
    for(m=0;m<tf;m++)
    {
f[m]=-1; }
    for(m=0;m<no;m++)
    {
        flag=0;
        for(n=0;n<tf;n++)
        {
            if(f[n]==rs[m])
            {
flag=1;
        printf("\t");
break; }
}
if(flag==0)
{
    if(p_f==tf-1)
    {
        for(n=0;n<tf;n++)
        {
            for(t=m+1;t<no;t++)
            {
} }
        fo=0;
        for(n=0;n<tf;n++)
        {
            if(i[n]==0)
            {
                p=n;
                fo=1;
                break;
p=++p_f;
fo=1; }
if(fo==0) {
        mi=i[0];
        p=0;
        for(n=1;n<tf;n++)
        {
            if(mi<i[n])
            {
mi=i[n];
p=n; }
    f[p]=rs[m];
    printf("FAULT\t");
    pf++;
}
for(n=0;n<tf;n++)
{
            if(f[n]!=-1)
            {
                printf("%d\t", f[n]);
} }
        printf("\n");
    }
    printf("Total no of Page faults: %d \n",pf);
}
int main() {
int c;
printf("1.FIFO\n2.LRU\n3.LFU\n4.Optimal\nEnter choice: "); scanf("%d",&c);
switch(c)
{
} }