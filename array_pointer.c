#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_IP_NUM 16
typedef char (*LISTARR)[16];
LISTARR ip_split(const char *str, const char *split){
    unsigned int len = strlen(str);
    char *tmp = (char*)malloc(len+1);
    if(NULL == tmp){
        printf("malloc error");
        exit(0);
    }
    memcpy(tmp, str, len);
    tmp[len]='\0';

    static char iplist[MAX_IP_NUM][16];
    int i,j;
    for(i=0; i<MAX_IP_NUM; i++)
        for(j=0; j<16; j++)
            iplist[i][j]='\0';
    char *p;
    i=0;
    p = strtok(tmp, split);
    while(p != NULL){
        if(isspace(*p)){
            p++;
        }
        memcpy(iplist[i++], p, strlen(p));
        p = strtok(NULL,split);
    }
    free(tmp);
    return iplist;
}


int main(int argc, char *argv[]){
	const char *ip = "192.168.10.1,192.168.10.2,192.168.10.3,";
    const char *delim = ",";
    LISTARR p = ip_split(ip, delim);
    int i=0;
    while( p[i][0] != '\0' ){
        printf("%s\n", *(p+i));
        i++;
    }
    return 0;
}
