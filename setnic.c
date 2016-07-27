#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NIC_OP 4

char *nicop[MAX_NIC_OP]={
     " sg off",
     " tso off",
     " gso off",
     " gro off"
};

const char *nicprefixcomm="ethtool -K ";
char nicfullcomm[MAX_NIC_OP][64]={0,};

int  exec_disable_nic(char nicfullcomm[][64], char *nicop[MAX_NIC_OP], const char *prefix, char *nicname)
{
    unsigned char tmplen=0;
    int i=0;
    for(i=0; i<MAX_NIC_OP; i++){
        memcpy(nicfullcomm[i], prefix,  strlen(prefix));
        tmplen = strlen(prefix);
        memcpy(nicfullcomm[i] + tmplen, nicname, strlen(nicname));
        tmplen = tmplen + strlen(nicname); 
        memcpy(nicfullcomm[i] + tmplen, nicop[i], strlen(nicop[i]));
	printf("%s\n", nicfullcomm[i]);
        system(nicfullcomm[i]);
    }
    return 0;
}

int main(int argc, char *argv[]){
    if(argc < 2){
	printf("setnic parameter error!\n");
	printf("USAGE:\n       setnic nicname\n");
	return 0;
    }
    exec_disable_nic(nicfullcomm, nicop, nicprefixcomm, argv[1]);
    return 0;
}
