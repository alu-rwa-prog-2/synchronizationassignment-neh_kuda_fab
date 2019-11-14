#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>

int Pizza=0;
pthread_mutex_t lock;

void *mySupplyingThread(void *vargp)
{
    pthread_mutex_lock(&lock);
   
    if(Pizza<=10)
    {
   
            Pizza= Pizza+1;
            printf("After Cooking 1 pizza we have %d pizza\n",Pizza);
           
           
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}


   void *myConsumingThread(void *vargp)
{
    pthread_mutex_lock(&lock);
   
    if(Pizza>0)
    {
            Pizza= Pizza-1;
            printf("After  the client eating one pizza, we have %d pizza\n",Pizza);
           
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}
   
int main()
{
    pthread_t supplyThread_id,  consumeThrea_id;
   
    while(1)
    {
       
   
    while(Pizza<10)
    {
        pthread_create(&supplyThread_id, NULL, mySupplyingThread,NULL);
       
         
    }
   
   
    while(Pizza>1)
    {
        pthread_create(&consumeThrea_id,NULL,myConsumingThread,NULL);
       
    }
    }
   
   
    pthread_join(supplyThread_id, NULL);
    pthread_join(consumeThrea_id, NULL);
   
    exit(0);
}