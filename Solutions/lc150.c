#include <stdio.h>
#include <stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;
    int ret = 0;
    for (int i = 0; i < tokensSize; ++i)
    {
    	//tokens[i] is an operand
        if((*tokens[i] - '0'>= 0 && *tokens[i] - '0' <= 9) || (*tokens[i] == '-' && tokens[i][1] != '\0')){
    		int num = 0;
    		int flag = 0;
    		char* p = tokens[i];
    		if(*p == '-'){
    			flag = 1;
    			p ++;
    		}
    		while(*p != '\0')
    			num = 10 * num + (*p++) - '0';
    		num = flag ? 0 - num : num;
    		stack[++top] = num;
    	}
        //tokens[i] is an operator
        else{
    		if(*tokens[i] == '+')
    			stack[top-1] += stack[top];
    		else if(*tokens[i] == '-')
    			stack[top-1] -= stack[top];
    		else if(*tokens[i] == '*')
    			stack[top-1] *= stack[top];
    		else if(*tokens[i] == '/')
    			stack[top-1] /= stack[top];
    		top--;
    	}
    }
    //avoid the cacse which tokensSize = 0 
    if(top == 0)
    	ret = stack[0];
    free(stack);
    return ret;
}

int main(){


	char* a[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

	printf("%d\n", evalRPN(a, 13));


	return 0;
}