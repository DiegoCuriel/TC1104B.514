#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_THREADS 10

int saldo;
sem_t protectSaldo;

void *suma(void *arg)
{
    sem_wait(&protectSaldo); //decrementa
    printf("El saldo inicial es %d\n", saldo);
    saldo = saldo + 100;
    printf("El saldo despues es %d\n", saldo);
    sem_post(&protectSaldo); //incrementa
    pthread_exit(NULL); //avisar a main que el hilo terminó
}

int main()
{
    saldo = 0;
    pthread_t threadsInfo[NUM_THREADS];
    sem_init(&protectSaldo, 0, 1);
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threadsInfo[i], NULL, suma, NULL);
    }
    // Wait for the threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threadsInfo[i], NULL);
    }
    printf("El final es %d \n", saldo);
    pthread_exit(NULL); //acabar main si los hilos terminaron
    printf("Nunca llega aqui"); //el main ya habia terminado
}