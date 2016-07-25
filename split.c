#include <stdio.h>
#include <string.h>

typedef char (*ARRAY)[16]; 
ARRAY ip_split(char *str, const char *split){
	static char iplist[16][16]={{0,},};
	char *p;
	int i=0;
	p = strtok(str, split);
	while(p != NULL){
		if(isspace(*p)){
			p++;
		}
		memcpy(iplist[i++], p, strlen(p));
		p = strtok(NULL,split);
	}
	return iplist;
}
int main(int argc, char *argv[]){
	char str[]="192.168.10.1 ,193.23.34.45,12.23.34.4";
	const char *split = ",";
    ARRAY p;
	p = ip_split(str, split);
	int i = 0; 
	while(p[i][0] != '\0'){
		printf("%saa",p[i]);
		i++;
	}
	return 0;
}
