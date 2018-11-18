int getIndex(char c){
	if(c >= 'a')
		return c - 'a' + 26;
	else
		return c - 'A';
}

int numJewelsInStones(char* J, char* S) {
    int ht[52] = {0};
    int lenJ = strlen(J);
    int lenS = strlen(S);
    int count = 0;
    for (int i = 0; i < lenJ; ++i)
    {
    	ht[getIndex(J[i])] = 1;
    }
    for (int i = 0; i < lenS; ++i)
    {
    	if(ht[getIndex(S[i])] == 1)
    		count ++;
    }

    return count;
}