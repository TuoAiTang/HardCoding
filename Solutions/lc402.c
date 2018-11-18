#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// start 14:47
// end 17.13

char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    if(k >= n)
        return "0";
    char* ptr = num;
    for (int i = 0; i < n; ++i)
    {
        //ensure (ptr - 1) valid
        while(k > 0 && ptr > num && *(ptr-1) > num[i]){
            k--;
            ptr--;
        }
        *ptr++ = num[i];
    }
    //cut the tail
    ptr -= k;
    *ptr = '\0';
    //remove repeted '0' at the head
    while(*num == '0')
        num ++;
    //if all '0'
    if(*num == '\0')
        return "0";

    return num;
}


int main(){

    char a[] = "1321";
    int k = 2;

    printf("%s\n", removeKdigits(a, k));

    // removeAtIndex(a, k);

    // printf("%s\n", a);
    
	

	return 0;
}