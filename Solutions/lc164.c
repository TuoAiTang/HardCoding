int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

//radix sort
int maximumGap(int* nums, int numsSize) {
    if(numsSize < 2) return 0;
    int radix = 10;
    int maxVal = nums[0];
    for(int i = 1; i < numsSize; ++i)
    	maxVal = max(maxVal, nums[i]);
    int rate = 1;
    int* buffer = (int*)malloc(numsSize * sizeof(int));
    while(maxVal / rate){

	    int count[11] = {0};

	    for (int i = 0; i < numsSize; ++i)
	    	++count[nums[i] / rate % radix + 1];

	    for (int i = 1; i < radix; ++i)
	    	count[i] += count[i - 1];

	    for (int i = 0; i < numsSize; ++i)
	    	buffer[count[nums[i] / rate % radix] ++] = nums[i];

	    for (int i = 0; i < numsSize; ++i)
		    nums[i] = buffer[i];

    	rate *= radix;
    }
    free(buffer);

    int gap = 0;
    for (int i = 1; i < numsSize; ++i)
    	gap = max(gap, nums[i] - nums[i - 1]);
    return gap;
}


int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

//bucket sort
int maximumGap(int* nums, int numsSize) {
    if(numsSize < 2) return 0;
    int minVal = nums[0];
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
    }

    //divide to n - 1 intervals whith length bsize
    int bsize = max(1, (maxVal-minVal)/(numsSize-1));

    //bucket numbers 
    int bn = (maxVal - minVal) / bsize + 1;

    struct b{
        int min;
        int max;
    } bucket[bn];

    for (int i = 0; i < bn; ++i)
    {
       bucket[i].min = INT_MAX;
       bucket[i].max = -1;  //non-negative range numbers
    }

    //fill the buckets
    for (int i = 0; i < numsSize; ++i)
    {
        int index = (nums[i] - minVal) / bsize;
        bucket[index].min = min(bucket[index].min, nums[i]);
        bucket[index].max = max(bucket[index].max, nums[i]);
    }

    int last_max = bucket[0].max;
    int max_diff = 0;
    for (int i = 0; i < bn; ++i)
    {   
        //empty bucket
        if(bucket[i].max == -1) continue;

        max_diff = max(max_diff, bucket[i].min - last_max);

        last_max = bucket[i].max;
    }
    return max_diff;
}