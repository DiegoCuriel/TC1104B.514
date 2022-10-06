#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void hola(int signalNumb)
{
    printf("Recibi la senal %d \n", signalNumb);
}

int cond = 1;

void terminarWhile(int sigNumber)
{
    printf("Terminando while \n");
    cond = 0;
}

int main()
{
    signal(12, terminarWhile);
    signal(2, hola);

    while (cond == 1)
    {
        printf("trabajando\n");
        sleep(1);
    }
    printf("Aqui nunca llega");
    return 0;
}