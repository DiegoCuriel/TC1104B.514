#include <stdio.h>

int main()
{
    FILE * lsOutput;
    FILE *tomayInput;
    char readBuffer[80];

    lsOutput = popen("ls *.c", "r"); //*.c filtra los archivos dejando los .c
    tomayInput = popen("wc -l", "w"); //wc -l cuenta las lineas

    while (fgets(readBuffer, 80, lsOutput))
    {
        fputs(readBuffer, tomayInput);
    }
    pclose(lsOutput);
    pclose(tomayInput);
    return 0;
}