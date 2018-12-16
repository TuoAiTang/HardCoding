class lc754 {

	//O(sqrt(n))
	//6ms beats 38.92%
    public int reachNumber1(int target) {
    	target = Math.abs(target);
        int k = 0;
        int sum = 0;
        while(sum < target) sum += (++k);
        int d = sum - target;
        if(d % 2 == 0) return k;
        return k + 1 + (k % 2);
    }

    //O(1)
    //6ms beats 38.92%
    public int reachNumber2(int target) {
    	target = Math.abs(target);
        int k = (int) Math.sqrt(target * 2);
        int sum = k * (k + 1) / 2;
        if(sum < target) sum += (++k);
        int d = sum - target;
        if(d % 2 == 0) return k;
        return k + 1 + (k % 2);
    }
}