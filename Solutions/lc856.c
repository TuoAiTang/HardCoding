#include <stdio.h>
#include <stdlib.h>



int scoreOfParentheses(char* S) {
    int stack[26] = {0};
    int top = 0;
    while(*S != '\0'){
    	if(*S == '('){
    		stack[++top] = 0;
    	}else{
    		stack[top - 1] += (stack[top]*2) > 1? stack[top]*2:1;
    		top--;
    	}
    	S ++;
    }

    return stack[0];
}

int main(){



	char a[] = "(()()(()()()))";

	printf("%d\n", scoreOfParentheses(a));


	return 0;
}