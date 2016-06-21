#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
static int count = 0;

void set_timer()
{
    struct itimerval itv;

    itv.it_value.tv_sec = 3;    //timer start after 3 seconds later
    itv.it_value.tv_usec = 0;

    itv.it_interval.tv_sec = 1;
    itv.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL,&itv,NULL);
}

void signal_handler(int m)
{
    count ++;
    printf("%d\n",count);
}

int main()
{
    signal(SIGALRM,signal_handler);
    set_timer();
    while(count < 10);
    return 0;
}
