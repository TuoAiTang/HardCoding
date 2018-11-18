#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
	return a > b ? a : b;
}

struct Interval {
	int start;
	int end;
};

void radixSort(struct Interval* arr, int size){
	int maxStart = arr[0].start;
	for (int i = 1; i < size; ++i)
		maxStart = max(maxStart, arr[i].start);
	int rate = 1;
	struct Interval* buffer = (struct Interval*)malloc(size * sizeof(struct Interval));
	while(maxStart / rate){
		int count[11] = {0};
		for (int i = 0; i < size; ++i)
			++count[arr[i].start / rate % 10 + 1];
		for (int i = 1; i < 10; ++i)
			count[i] += count[i - 1];
		for (int i = 0; i < size; ++i)
			buffer[count[arr[i].start / rate % 10] ++] = arr[i];
		for (int i = 0; i < size; ++i)
			arr[i] = buffer[i];
		rate *= 10;
	}
	free(buffer);
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if(intervalsSize == 0) return NULL;

    *returnSize = 0;

    radixSort(intervals, intervalsSize);

    struct Interval* res = (struct Interval*)malloc(intervalsSize * sizeof(struct Interval));


    for (int i = 0; i < intervalsSize; ++i)
    {
    	if((*returnSize) != 0 && intervals[i].start <= res[*returnSize - 1].end)
    		res[*returnSize - 1].end = max(res[*returnSize - 1].end, intervals[i].end);
		else
    		res[(*returnSize) ++] = intervals[i];
    }

    return res;
}

int main(){
	struct Interval arr[4] = {{1, 3}, {6, 8}, {2, 4}, {4, 7}};

	int returnSize = 0;
	struct Interval* res = merge(arr, 4, &returnSize);

	printf("%d\n", returnSize);

	for (int i = 0; i < returnSize; ++i)
	{
		printf("start:%d \t end:%d\t\n", res[i].start, res[i].end);
	}

}