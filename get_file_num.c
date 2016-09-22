#include <stdio.h>
#define CFG_NAME "abc.txt"
#define LINE_LENGTH (128)

int get_log_file(char filename[][64]){
    int i=0,  filenums=0;
    FILE *fp = fopen(CFG_NAME, "rb");
    if(NULL == fp){
        printf("Can't open %s\n", CFG_NAME);
        return -1; 
    }   
    
    while(1){
        if(feof(fp)==0){
            fgets(filename[i], LINE_LENGTH, fp);
            if(strlen(filename[i]) > 0){ 
                i++;  // filter blank line
            }   
        }else{
            break;
        }   
    }   
    
    fclose(fp);
    filenums = i;
    return filenums;
}

int main(){
	char filename[32][64]={0,};
    int num = get_log_file(filename);
	printf("%d\n", num);

}
