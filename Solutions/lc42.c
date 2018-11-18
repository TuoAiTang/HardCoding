#include <stdio.h>
#include <stdlib.h>
// start 20:00
// end 

int max(int a, int b){
	return a > b ? a : b;
}
int min(int a, int b){
	return a < b ? a : b;
}
// int trap(int* height, int heightSize) {
//     int* left_max = (int*)malloc(heightSize * sizeof(int));
//     int* right_max = (int*)malloc(heightSize * sizeof(int));

//     left_max[0] = height[0];
//     right_max[heightSize-1] = height[heightSize-1];

//     int ans = 0;


//     for (int i = 1; i < heightSize; ++i)
//     	left_max[i] = max(left_max[i-1], height[i]);

//     for (int i = heightSize-2; i >= 0; i--)
// 		right_max[i] = max(right_max[i+1], height[i]);

// 	for (int i = 0; i < heightSize; ++i)
// 		ans += min(left_max[i], right_max[i]) - height[i];

//     free(left_max);
//     free(right_max);

//     return ans;
// }
int trap(int* height, int heightSize) {
    int* stack = (int*)malloc(heightSize * sizeof(int));
    int top = -1;
    int ans = 0;
	for (int i = 0; i < heightSize; ++i){
		while(top != -1 && height[i] > height[stack[top]]){
			int bottom = stack[top--];
			//the very biginning can not trap rain
			if(top == -1)
				break;
			int bar = min(height[i], height[stack[top]]) - height[bottom];
			//if bar == 0, process forward, distance would increase
			int distance = i - stack[top] - 1;
			ans += distance * bar;
		}
		stack[++top] = i;
	}
	free(stack);
    return ans;
}


int main(){

	int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int heightSize = 12;
	printf("%d\n", trap(height, heightSize));

	printf("%d\n", max(3, 2));

	return 0;
}