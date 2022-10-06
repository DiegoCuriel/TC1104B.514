#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    //hijo == 0
    int pid = fork();

    if (pid == 0)
    {
        printf("Soy el proceso hijo\n");
        execl("/workspace/TC1104B.514/hola", "hola.exe", NULL);
        sleep(5);
        printf("valio\n");
    }
    else
    {
        sleep(5);
        printf("Soy el proceso padre\n");
        wait(NULL);
    }
    return 0;
}