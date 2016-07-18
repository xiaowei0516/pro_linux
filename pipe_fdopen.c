#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
	int fd[2];
	int ret=0;
	int readnum = 0;
	char rechari,recharj,rechark;
	char str[100]="hello,comoputer";
	char buff[100]={0,};
	int *fdw = &fd[1];
	int *fdr = &fd[0];
	FILE *fp = NULL;
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
		close(*fdr);
        sleep(4);
		fp = fdopen(fd[1],"w");
		fprintf(fp,"abc");
  		fclose(fp);
  		return 0;
 	}else{
		close(*fdw);
  		fp = fdopen(fd[0],"r");
  		setvbuf(fp,NULL,_IONBF,0);
  		while(1){
            printf("aabb");
   			readnum=fscanf(fp,"%c%c%c",&rechari,&recharj,&rechark);
            printf("ccdd");
   			if(readnum < 1){
    			printf("no char read !!\n");
    			break;
   			}
   			printf("%d --- %c %c %c\n",readnum,rechari,recharj,rechark);
   			break;  /*(read  one time)*/
  		}
  	   fclose(fp);
 	}
	return 0;
}
