#include <stdio.h>
#include <stdlib.h>

int calPoints(char** ops, int opsSize) {
    int sum = 0, score = 0;
    int* stack = (int*)malloc(1001 * sizeof(int));
    int top = 0;
    for (int i = 0; i < opsSize; ++i)
    {
    	switch(*ops[i]){
    		case 'C':
    			sum -= stack[top--];
    			break;
    		case 'D':
    			score = 2 * stack[top];
    			stack[++top] = score;
    			sum += score;
    			break;
    		case '+':
    			score = stack[top] + stack[top - 1];
    			stack[++top] = score;
    			sum += score;
    			break;
    		default:
    			score = atoi(ops[i]);
    			stack[++top] = score;
    			sum += score;
    			break;
    	}
    }

    return sum;
}

int main(){

	char *a[6] = {"12","3","C","2","D","+"}; //12 + 2 + 4 + 6 = 24


	printf("Score:%d\n", calPoints(a, 6));


	return 0;
}
