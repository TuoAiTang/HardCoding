#include <stdio.h>
#include <stdlib.h>


int* dailyTemperatures(int* T, int TSize, int* returnSize) {  
    *returnSize = TSize;

    int* stack = (int*)malloc(TSize * sizeof(int));

    int* ret = (int*)malloc(TSize * sizeof(int));

    int top = -1;

    for (int i = 0; i < TSize; ++i)
    {
    	while(top != -1 && T[stack[top]] < T[i]){
    		ret[stack[top]] = i - stack[top];
    		top--;
    	}
    	stack[++top] = i;
    }
    while(top > -1)
    	ret[stack[top--]] = 0;

    return ret;
}

int main()
{
	int T[] = {73, 74, 75, 71, 69, 72, 76, 73};
	int size;
	int* ret = dailyTemperatures(T, 8, &size);
	for (int i = 0; i < size; ++i)
		printf("%d\n", ret[i]);
	return 0;
}