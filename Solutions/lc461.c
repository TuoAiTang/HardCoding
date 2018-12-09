//both 0ms beats 100%
int hammingDistance(int x, int y) {
    int d = x ^ y;
    int ans = 0;
    while(d > 0){
    	ans += (d & 1);
    	d >>= 1;
    }
    return ans;
}

int hammingDistance(int x, int y) {
    int d = x ^ y;
    int ans = 0;
    // while(d > 0){	//4ms
    while(d){
    	ans ++;
    	d &= (d - 1);
    }
    return ans;
}