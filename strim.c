#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   s :  a char array
*/
char* sdstrim(char *s, const char *cset) {
    char *start, *end, *sp, *ep;
    size_t len;

    sp = start = s;                   /*searched start pointer*/
    ep = end = s+strlen(s)-1;  /*searched end pointer*/
    while(sp <= end && strchr(cset, *sp)) sp++;
    while(ep > sp && strchr(cset, *ep)) ep--;
    len = (sp > ep) ? 0 : ((ep-sp)+1);
    if (s != sp) memmove(s, sp, len);
    s[len] = '\0';
    return s;
}

int main(int argc, char *argv[]){

	char s[128]="AAAA....  heallo ...aaa";
    char *p = sdstrim(s, "A. a");
    printf("strim:%s\n",p);
	return 0;
}
