#include <stdio.h>
#include <stdlib.h>

// start 14.26
// end 14.50

int max(int a, int b){
	return a>b?a:b;
}

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc(heightsSize * sizeof(int));
    int top = -1;
    int maxArea = 0;
    int count = 0;
    for (int i = 0; i < heightsSize; ++i)
    {
    	count = 0;
    	//ensure ascending sequence in the stack
    	while(top != -1 && heights[i] < stack[top]){
    		int t = stack[top--];
    		count++;
    		maxArea = max(t * count, maxArea);
    	}
    	//push the element replaced by heights[i] popped just before
    	while(count--)
    		stack[++top] = heights[i];
    	//push the current element
    	stack[++top] = heights[i];
    }
    //calculate the rest in the stack
    count = 0;
    while(top != -1){
    	int t = stack[top--];
    	count++;
    	maxArea = max(t * count, maxArea);
    }
    return maxArea;
}

int main(){

	int heights[] = {2,1,5,3,2,3};
	int size = 6;
	printf("%d\n", largestRectangleArea(heights, size));

	return 0;
}