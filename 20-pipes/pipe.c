#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void func1()
{
    sleep(1);
    printf("print(\"Este e um comando python!\", 1, 2, 4//3, 4/3)\n");
}

void func2()
{
    // complete aqui com exec
}

int main()
{
    // crie o pipe e redireciona a saída do processo pai para
    // a entrada do filho ;)
    int fds[2];
    pipe(fds);

    pid_t f = fork();
    if (f == 0)
    {
        char c = 'a';
        int x = 1;
        write(fds[1], &x, sizeof(int));
    }
    else
    {
        int x;
        read(fds[0], &x, sizeof(int));
        printf("%d \n", x);
    }
}