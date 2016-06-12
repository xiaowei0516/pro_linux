#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void HandleSigint(int signo, siginfo_t *info, void *none)
{
    printf("receive signal %d, addtional data is %d\n", signo,info->si_value.sival_int);
}

int main(void)
{
    struct sigaction act, oact;
    memset(&act, 0x00, sizeof(struct sigaction));
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = HandleSigint;
    act.sa_flags = SA_SIGINFO;
    if (sigaction(SIGINT, &act, &oact) == -1) 
    {   
        perror("sigaction");
        exit(0);
    }   
    pause();

    return 0;
}
