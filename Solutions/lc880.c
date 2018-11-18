#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// start 21:36
// end 22.00

int isDigit(char c){
    int dis = c - '0';
    return (dis >= 0 &&  dis <= 9) ? 1 : 0;
}

char* decodeAtIndex(char* S, int K) {
    int n = strlen(S);
    //long 和 int 都是4个字节
    //long 是8个字节
    long long size = 0;
    char* res = (char*)malloc(2 * sizeof(char));
    for (int i = 0; i < n; ++i)
    {
        if(isDigit(S[i]))
            size *= S[i] - '0';
        else
            size ++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        K %= size;

        if(K == 0 && !isDigit(S[i])){
            *res = S[i];
            res[1] = '\0';
            return res;
        }

        if(isDigit(S[i]))
            size /= S[i] - '0';
        else
            size--;
    }
    return NULL;
}

int main(){


	char a[] = "a2345678999999999999999";

	printf("%c\n", *decodeAtIndex(a, 1));

    printf("sizeof int:%d\n", sizeof(int));
    printf("sizeof long:%d\n", sizeof(long long));
    printf("%ld\n", LONG_LONG_MAX);

	return 0;
}