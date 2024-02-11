#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
void zombie();
void orphan();
int main() {
int c;
printf("\n1.Zombie Process \n2.Orphan process\nEnter your choice: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            zombie();
            break;
        case 2:
orphan();
            break;
        default:
            printf("Invalid Choice");
            break;
}
return 0; }
void zombie()
{
    pid_t fork_return=fork();
    if(fork_return>0)
    {
printf("I am the parent\n");
sleep(10);
printf("parent--My fork value is %d\n",fork_return); printf("parent--My getpaid value is %d\n",getpid()); printf("parent--My parent's id is
getpaid()=%d\n",getppid());
        wait(NULL);
}
else if(fork_return==0)
    {
printf("I am the child\n");
printf("child----My fork return value is %d\n",fork_return); printf("child----My getpid value is %d\n",getpid()); printf("child----My parent's id is getppid() =
%d\n",getppid());
        exit(0);
}
printf("This is the main function\n my getpaid()=%d",getpid()); }
void orphan()
{
    int id;
    printf("Before fork()\n");
    id=fork();
if(id==0) {
printf("Child has started: %d\n ",getpid()); printf("Parent of this child : %d\n",getppid()); printf("child prints 1 item :\n ");
sleep(10);
        printf("child prints 2 item :\n");
    }
else {
        printf("Parent has started : %d\n",getpid());
printf("Parent of the parent proc: %d\n",getppid()); }
    printf("\nAfter fork()\n");
}