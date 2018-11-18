int hIndex(int* citations, int citationsSize) {
    int* map = (int*)calloc(citationsSize + 2, sizeof(int));
    int* buffer = (int*)malloc(citationsSize * sizeof(int));
    for (int i = 0; i < citationsSize; ++i)
    	map[citations[i] > citationsSize ? citationsSize + 1 : citations[i] + 1]++;
    for (int i = 1; i < citationsSize + 1; ++i)
	    map[i] += map[i - 1];
	for (int i = 0; i < citationsSize; ++i)
		buffer[map[citations[i] > citationsSize ? citationsSize : citations[i]] ++] = citations[i];

	for (int i = 0; i < citationsSize; ++i)
		citations[i] = buffer[i];

	free(map);
	free(buffer);

	int h = 0;
	while(h < citationsSize && citations[h] > h)
		h++;
	return h;
}

int hIndex(int* citations, int citationsSize) {
   
    int* map = (int*)calloc(citationsSize + 1, sizeof(int));

    for (int i = 0; i < citationsSize; ++i)
    	map[citations[i] > citationsSize ? citationsSize : citations[i]]++;
    
    int sum = 0;
    for(int i = citationsSize; i > 0; i--){
    	sum += map[i];
    	if(sum >= i){
    		free(map);
    		return i;
    	}
    }
    free(map);
    return 0;
}