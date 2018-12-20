class lc201 {
	//8ms beats 30.4% 8266 cases
    public int rangeBitwiseAnd(int m, int n) {
        return n == 0 ? 0 : rangeBitwiseAnd(m / 2, n / 2) << 1;
    }
}