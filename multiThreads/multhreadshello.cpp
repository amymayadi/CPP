#include<stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
#include <unistd.h>  
  
void * fun1 (void *arg1)  
{  
    printf ("[pthread1]  -- start\n");  
    sleep (2);  
    printf ("[pthread1]  -- end\n");  
    pthread_exit ((void *) NULL);  
}  
  
void * fun2 (void *arg1)  
{  
    printf ("[pthread2]  -- start\n");  
    sleep (2);  
    printf ("[pthread2]  -- end\n");  
    pthread_exit ((void *) NULL);  
}  
  
int main(void)  
{  
  
    pthread_t pid1, pid2;  
    void *tmp;  
  
    printf ("[main] -- start\n");  
  
    if (pthread_create (&pid1, NULL, fun1, NULL)) {  
        perror ("create pthread1 error\n");  
        exit (1);  
    }  
    if (pthread_create (&pid2, NULL, fun2, NULL)) {  
        perror ("create pthread2 error\n");  
        exit (1);  
    }  
  
    if (pthread_join (pid1, &tmp)) {  
        perror ("join pthread1 error\n");  
        exit (1);  
    }  
  
    if (pthread_join (pid2, &tmp)) {  
        perror ("join pthread2 error\n");  
        exit (1);  
    }  
  
    sleep (2);  
    printf ("[main] -- end\n");  
    return 0;  
}  

