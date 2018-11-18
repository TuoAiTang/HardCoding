#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char c){
    int dis = c - '0';
    return (dis >= 0 &&  dis <= 9) ? 1 : 0;
}

int calculate(char* s) {
	int n = strlen(s);
	int result = 0;
	int number = 0;
	int sign = 1;
	int top = -1;
	// we don't need to push if no '(' contained
	//else we push n / 2 times without pop at most
	//so set the size to half of the length
	//here stack push non-negetive operand and -1/+1 for sign
	int* stack = (int*)malloc(n / 2 * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
    	char c = s[i];
    	if(isDigit(c))
    		number = 10 * number + c - '0';
    	else{
    		switch(c){
	    		case '+':
	    			result += sign * number;
	    			sign = 1;
	    			number = 0;
	    			break;
	    		case '-':
	    			result += sign * number;
	    			sign = -1;
	    			number = 0;
	    			break;
	    		case '(':
	    			stack[++top] = result;
	    			stack[++top] = sign;
	    			//reset
	    			result = 0;
	    			sign = 1;
	    			break;
	    		case ')':
	    			result += sign * number;
	    			//firt-sign, second-result before
	    			result *= stack[top--];
	    			result += stack[top--];
	    			number = 0;
	    			break;

	    		default:
	    			break;
    		}
    	}
	}
	if(number != 0)
		result += sign * number;
	free(stack);
    return result;
}



int main(){


	char a[] = "1 + 1"; //1

	printf("%d\n", calculate(a));

	//int i = 1;
	//test switch
	// switch(i){
	// 	case 1:
	// 		printf("is 1\n");

	// 	case 2:
	// 		printf("is 2\n");
	// 	case 3:
	// 		printf("is 3\n");

	// 	default:
	// 		printf("123\n");	
	// 		break;
	// }


	return 0;
}