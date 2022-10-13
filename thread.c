#include <stdio.h>
#include <pthread.h>

typedef struct thread_data
{
    int threadId;
    char name[20];
    //..
} ThreadData; //shortcut que será usado por ThreadData

void *holaMundo(void *arg)
{
    ThreadData *myData = (ThreadData *)arg;
    printf("Hola desde el hilo y mi id es %d \n", myData->threadId);
    pthread_exit(NULL); //avisar a main que el hilo terminó
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        ThreadData myData;
        pthread_t threadId;
        myData.threadId = i;
        pthread_create(&threadId, NULL, holaMundo, (void *) &myData);
    }
    pthread_exit(NULL); //acabar main si los hilos terminaron
    printf("Nunca llega aqui"); //el main ya habia terminado
}