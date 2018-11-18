#include <stdio.h>
#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {

    int* stack = (int*)malloc(10000 * sizeof(int));
    int top = -1;
    for (int i = 0; i < asteroidsSize; ++i)
    {
		if(top != -1 && asteroids[i] < 0 && stack[top] > 0){
			
			if(abs(asteroids[i]) > abs(stack[top])){
				while(abs(asteroids[i]) > abs(stack[top]) && top != -1){
					if(stack[top] < 0)
						break;
					top--;
				}
				if(top == -1 || stack[top] < 0){
					stack[++top] = asteroids[i];
					continue;
				}
			}

			if(abs(asteroids[i]) == abs(stack[top]))
				top --;	
		}
		else
			stack[++top] = asteroids[i];
    }
    *returnSize = top + 1;
    int* ret = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; ++i)
		ret[i] = stack[i];
	free(stack);
	return ret;
}


int main(){

	int size;
	int a[] = {-2, -2, 1, -2};
	int* ret = asteroidCollision(a, 4, &size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", ret[i]);
	}
	return 0;
}