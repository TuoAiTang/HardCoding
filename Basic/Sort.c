#include<stdio.h>
#include<stdlib.h>

//index start at 0, the index 1 is its left child for e.g
#define LeftChild(i)(2 * (i) + 1)


//CutOff min set to 1; or it will break down
#define CutOff 1


void randomFill(int* a, int size){
	for (int i = 0; i < size; ++i)
		a[i] = (int) rand() % 50 % 2;
}

void printArray(int* a, int size){
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int* a, int size){
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if(a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
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

/*param mi the MinIndex*/
int getMinIndex(int* a, int start, int end){
	int mi = start;
	for (int i = start + 1; i <= end; ++i)
	{
		if(a[mi] > a[i])
			mi = i;
	}
	return mi;
}
/*devide-and-conquer*/
int getMinIndexDC(int* a, int start, int end){
	if(start >= end)
		return end;
	int mid = (start + end) / 2;
	/*T(n/2)*/
	int left = getMinIndex(a, start, mid);
	/*T(n/2)*/
	int right = getMinIndex(a, mid + 1, end);

	return a[left] > a[right] ? right : left;
}

void SelectSort(int* a, int size){
	for (int i = 0; i < size; ++i)
	{
		int minIndex = getMinIndexDC(a, i, size - 1);
		swap(&a[i], &a[minIndex]);
	}
}

void ShellSort(int* a, int size){
	int i, j, inc;
	//inc becomes 1 finally, for the condition inc > 0, in the for loop
	//the diminishing increment sorting
	for (inc = size / 2; inc > 0; inc /= 2)
	{
		for (i = inc; i < size; i += inc)
		{
			int tmp = a[i];
			for (j = i; j > 0 && a[j-inc] > tmp; j -= inc)
				a[j] = a[j-inc];
			a[j] = tmp;
		}
	}
}

//@param n the heap size, also the array size which is ready to sort
//@param i the index that siftDown begin at, represents parent of child
void siftDown(int* a, int i, int n){
	int child;
	int tmp = a[i];
	while(LeftChild(i) < n){
		child = LeftChild(i);
		//select greater one betwen the two children, if it has right child
		//to build max heap
		if(child != n - 1 && a[child+1] > a[child])
			child++;
		if(tmp < a[child])
			a[i] = a[child];
		else
			break;
		i = child;
	}
	a[i] = tmp;
}

void HeapSort(int* a, int size){
	//build max heap, which is c++ default heap, probably for defalt sorting

	//TimeComplexity: one insert operation takes O(1) on avrg, so O(n) for total
	for(int i = size / 2; i >= 0; i--)
		siftDown(a, i, size);

	//TimeComplexity: 
	for (int i = size - 1; i >= 0; --i)
	{
		swap(&a[0], &a[i]);
		//DeleteMax
		//change the heap size to i
		siftDown(a, 0, i);
	}
}

void merge(int* a, int* tmpArray, int left, int right, int rightEnd){
	int numOfElements = rightEnd - left + 1;
	int leftEnd = right - 1;
	int tmpPos = left;

	while(left <= leftEnd && right <= rightEnd){
		if(a[left] <= a[right])
			tmpArray[tmpPos++] = a[left++];
		else
			tmpArray[tmpPos++] = a[right++];
	}

	while(left <= leftEnd)
		tmpArray[tmpPos++] = a[left++];
	while(right <= rightEnd)
		tmpArray[tmpPos++] = a[right++];

	for (int i = 0; i < numOfElements; ++i, rightEnd--)
		a[rightEnd] = tmpArray[rightEnd];
}

void merge1(int* a, int* tmpArray, int left, int right, int rightEnd){
	int leftEnd = right - 1;
	int tmpPos = left;

	while(left <= leftEnd && right <= rightEnd){
		if(a[left] <= a[right])
			tmpArray[tmpPos++] = a[left++];
		else
			tmpArray[tmpPos++] = a[right++];
	}

	while(left <= leftEnd)
		tmpArray[tmpPos++] = a[left++];
	while(right <= rightEnd)
		tmpArray[tmpPos++] = a[right++]; 
}

void MSort(int* a, int* tmpArray, int left, int right){
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		MSort(a, tmpArray, left, mid);
		MSort(a, tmpArray, mid + 1, right);
		merge(a, tmpArray, left, mid + 1, right);
	}
}
/*Recursive*/
void MergeSort(int* a, int size){
	int* tmpArray = (int*)malloc(size *  sizeof(int));
	MSort(a, tmpArray, 0, size - 1);
	free(tmpArray);
}

void MergePass(int* a, int* tmpArray, int size, int length){
	int i;
	for (i = 0; i <= size - 2 * length; i += 2 * length)
		merge1(a, tmpArray, i, i + length, i + 2 * length - 1);
	if(i + length < size)
		merge1(a, tmpArray, i, i + length, size - 1);
	else
		for(int j = i; j < size; j++){
			tmpArray[j] = a[j];
		}
}
/*Non-Recursive*/
void MergeSort1(int* a, int size){
	int* tmpArray = (int*)malloc(size * sizeof(int));
	int length = 1;
	while(length < size){
		MergePass(a, tmpArray, size, length);
		length *= 2;
		MergePass(tmpArray, a, size, length);
		length *= 2;
	}
	free(tmpArray);
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

void QSort(int* a, int left, int right){
	int i, j;
	int pivot;
	/*num of elements to sort*/
	if(right - left + 1 > CutOff){
		pivot = Median3(a, left, right);
		/*dead loop*/
		// i = left + 1; 
		// j = right - 2;
		// for(; ;){
		// 	while(a[i] < pivot) i++;	
		// 	while(a[j] > pivot) j--;
		// 	if(i < j)
		// 		swap(&a[i], &a[j]);
		// 	else
		// 		break;
		// }
		/*divide*/
		i = left; 
		j = right - 1;
		for(; ;){
			while(a[++i] < pivot);	
			while(a[--j] > pivot);
			if(i < j)
				swap(&a[i], &a[j]);
			else
				break;
		}
		swap(&a[i], &a[right-1]); 	/*pivot settled*/
		QSort(a, left, i - 1);
		QSort(a, i + 1, right);
	}	
	else
		InsertSort(a + left, right - left + 1);
}


void QuickSort(int* a, int size){
	QSort(a, 0, size - 1);
}

// int main(){

// 	int size = 10;
// 	int* a = (int*)malloc(sizeof(int) * size);
// 	randomFill(a, size);
// 	printf("Original:\n");
// 	printArray(a, size);
	
// 	//1
// 	// BubbleSort(a, size);
// 	// printf("BubbleSort: \n");
// 	// printArray(a, size);

// 	//2
// 	// InsertSort(a, size);
// 	// printf("InsertSort: \n");
// 	// printArray(a, size);

// 	//3
// 	// ShellSort(a, size);
// 	// printf("ShellSort:\n");
// 	// printArray(a, size);

// 	//4
// 	// HeapSort(a, size);
// 	// printf("HeapSort:\n");
// 	// printArray(a, size);

// 	//5
// 	// SelectSort(a, size);
// 	// printf("SelectSort:\n");
// 	// printArray(a, size);

// 	//6
// 	// MergeSort(a, size);
// 	// printf("MergeSort:\n");
// 	// printArray(a, size);

// 	//7
// 	// MergeSort1(a, size);
// 	// printf("MergeSort1:\n");
// 	// printArray(a, size);

// 	//8
// 	QuickSort(a, size);
// 	printf("QuickSort:\n");
// 	printArray(a, size);


// 	return 0;


// }