#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[]){
    char s[] ="ab-cd : ef;gh :i-jkl;mnop;qrs-tu: vwx-y;z";
    printf("%s\n",s);
    char *delim = "-: ";
    char *p;
    printf("%s\n", strtok(s, delim));
    while((p = strtok(NULL, delim)))
        printf("%s\n", p);
    printf("\n");
   // printf("%s\n",s);
    return 0;
} 
