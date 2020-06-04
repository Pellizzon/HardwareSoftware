#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void funcao_lenta()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Filho %d", i);
        sleep(2);
        printf(" -- Fim Filho %d\n", i);
    }
}

void funcao_lenta_pai()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Pai %d", i);
        sleep(1);
        printf(" -- Fim Pai %d\n", i);
    }
}

int main(int argc, char *argv[])
{
    pid_t filho;

    int fd = open("/tmp", O_RDWR | O_TMPFILE);
    // int fd = open(".temp", O_RDWR | O_CREAT);

    filho = fork();
    if (filho == 0)
    {
        dup2(fd, 1);
        funcao_lenta();
        return 0;
    }

    funcao_lenta_pai();
    lseek(fd, 0, SEEK_SET);

    int status;
    wait(&status);

    char buf[1];
    if (WIFEXITED(status))
    {
        while ((read(fd, buf, 1)) > 0)
        {
            printf("%c", buf[0]);
        }
    }

    close(fd);
    return 0;
}
