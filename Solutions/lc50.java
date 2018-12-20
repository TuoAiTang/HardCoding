class lc50 {
	//Solution 1: recursion
	//18ms beats 10.49%
	//Time: O(logn)
	//Space: O(logn)
    public double myPow(double x, int n) {
        if(n == 0) return 1.0;
        double d = myPow(x, n / 2);
        if(n % 2 == 0) return d * d;
        if(n < 0) return d * d / x;
        return d * d * x;
    }


    //11ms beats 59.43%
    public double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n < 0) return myPow(1 / x, - n);
        if(n % 2 == 0) return myPow(x * x, n / 2);
        return myPow(x * x, n / 2) * x;
    }
}