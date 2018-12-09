//8ms beats 100%
int countPrimeSetBits(int L, int R) {
    int p[20] = {0};
    p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = p[19] = 1;
    int ans = 0;
    int l = L;
    while(L <= R){
    	if(p[countBits(L)]) ans++;
    	L++;
    }
    return ans;
}

int countBits(int n){
	int b = 0;
	while(n){
		n &= (n - 1);
		b++;
	}
	return b;
}