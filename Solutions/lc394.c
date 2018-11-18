#include <stdio.h>
#include <stdlib.h>

char* decodeString(char* s) {
    char** resStack = (char**)malloc(10000 * sizeof(char*));
    int* countStack = (int*)malloc(10000 * sizeof(int));
    int res_top = -1;
    int count_top = -1;
    int count = 0;
    int asc2num;
    int *res = NULL;
    while(*s != '\0'){
    	asc2num = *s - '0';
    	if(asc2num >= 0 && ascnum <= 9 ){
    		while(asc2num >= 0 && asc2num <= 9){   			
    			count = 10 * count + asc2num;
    			asc2num = *++s -'0';
    		}
    		countStack[++count_top] = count;
    	}else if(*s == '['){
    		resStack[++res_top] = res;
    	}
    }


}

int main(){

	char a[] = "3[a]2[bc]";

	printf("%s\n", decodeString(a));

	return 0;
}