#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
sem_t mutex1;
sem_t full1;
sem_t empty1;
char buffer[100];
int mutex=1,full=0,empty=3,x=0;
void semaphores();
int main() {
int n;
void producer();
void consumer();
int wait(int);
int signal1(int);
printf("\n1.Producer\n2.Consumer\n3.Using semaphores\n4.Exit"); while(1)
{
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                if((mutex==1)&&(empty!=0))
                    producer();
                else
                    printf("Buffer is full!!");
                break;
            case 2:
                if((mutex==1)&&(full!=0))
                    consumer();
                else
                    printf("Buffer is empty!!");
                break;
case 3:
semaphores();
    break;
case 4:
                exit(0);
                break;
                }
}
return 0; }
int wait(int s)
{
    return (--s);
}
int signal1(int s)
{
    return(++s);
}
void producer()
{
mutex=wait(mutex);
full=wait(full);
empty=wait(empty);
x++;
printf("\nProducer produces the item %d",x); mutex=signal1(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal1(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal1(mutex);
}
void *producer1(void *arg)
{
    int i,index=0;
    for(i=0;i<26;i++)
    {
}
}
return 0; 
int wait(int s)
{
sem_wait(&empty1);
sem_wait(&mutex1);
buffer[index]=i+64;
printf("\nbuffer added %c to buffer\n", buffer[index]); sem_post(&full1);
sem_post(&mutex1);
if(++index==10)
index=0;
} 
void *consumer1(void *arg)
{
    int i,index=0;
    for(i=0;i<26;i++)
    {
        sem_wait(&full1);
sem_wait(&mutex1);
buffer[index]=i+64;
printf("\nconsumer consumed %c to buffer\n", buffer[index]); sem_post(&empty1);
sem_post(&mutex1);
if(++index==10)
index=0;
} }
void semaphores()
{
pthread_t tid1,tid2; sem_init(&mutex1,0,1); sem_init(&full1,0,0); sem_init(&empty1,0,10); pthread_create(&tid1,NULL,producer1,NULL); pthread_create(&tid2,NULL,consumer1,NULL); pthread_join(tid1,NULL); pthread_join(tid2,NULL); sem_destroy(&mutex1);
    sem_destroy(&full1);
    sem_destroy(&empty1);
}