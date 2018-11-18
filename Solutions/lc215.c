#include<stdio.h>
#include<stdlib.h>

#define CutOff 100

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int size){
	int i, j;
	for (i = 1; i < size; ++i)
	{
		int tmp = a[i];
		for (j = i; j > 0 && a[j-1] > tmp; j--)
			a[j] = a[j-1];
		a[j] = tmp;
	}
}

int Median3(int* a, int left, int right){
	int mid = (left + right) / 2;
	if(a[left] > a[right])
		swap(&a[left], &a[right]);
	if(a[left] > a[mid])
		swap(&a[left], &a[mid]);
	if(a[mid] > a[right])
		swap(&a[mid], &a[right]);
	swap(&a[mid], &a[right-1]); /*hide pivot*/
	return a[right-1];
}

void QuickSelect(int*a, int k, int left, int right){
	if(right - left > CutOff){
		int pivot = Median3(a, left, right);
		int i = left;
		int	j = right - 1;
		for (; ;)
		{						
			while(a[++i] < pivot);
			while(a[--j] > pivot);
			if(i < j)
				swap(&a[i], &a[j]);
			else
				break;
		}
		swap(&a[i], &a[right-1]);
		if(k <= i)
			QuickSelect(a, k, left, i - 1);
		else if(k > i + 1)
			QuickSelect(a, k, i + 1, right);
	}
	else
		InsertSort(a + left, right - left + 1);
}

int findKthLargest(int* nums, int numsSize, int k) {
    QuickSelect(nums, numsSize - k + 1, 0, numsSize - 1);
    return nums[numsSize - k];
}

