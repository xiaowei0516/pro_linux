#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd[2];
    int ret=0;
    char str[100]="hello,comoputer";
    char buff[100]={0,};
    int *fdw = &fd[1];
    int *fdr = &fd[0];
    ret = pipe(fd);
    if(ret == -1){
        printf("failed created!\n");
        return -1;
    }

    pid_t  pid;
    pid = fork();
    if(pid<0){
        printf("fork  error\n");
        return -1;
    }
    if(pid == 0){
        sleep(2);
        close(*fdr);
        ret = write(*fdw, str, strlen(str));
        return 0;
    }else{
        close(*fdw);
        ret = read(*fdr, buff, sizeof(buff));
        printf("receive %d bytes data %s\n",ret,buff);
    }
    return 0;

}
