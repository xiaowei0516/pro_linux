#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strip(char a[])
{
    char *p1,*p2;
    p1 = p2 = a;
    while(isspace(*p2))
    {
        p2++;
    }
    while((*p2)!='\0')
    {
        *p1++=*p2++;
    }
    while(isspace(*(p2-1)))
    {
        p2--;
    }
    *p2='\0';
    return strlen(a);
}


int main()
{
    char a[]="  welcome   ";
    strip(a);
    printf("==>%s<===\n",a);
    return 0;
}
