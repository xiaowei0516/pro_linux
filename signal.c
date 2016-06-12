#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void HandleSigint(int signo)
{
    printf("receive signal %d.\n", signo);
}

int main(void)
{
    if (signal(SIGQUIT, HandleSigint) == SIG_ERR)
    {   
        perror("signal");
        exit(0);
    }
    pause();

    return 0;
}
