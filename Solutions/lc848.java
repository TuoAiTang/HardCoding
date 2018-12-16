//suffix sum
//Time: O(n)
//8ms beats 63%
class lc848 {
    public String shiftingLetters(String S, int[] shifts) {
        char [] s = S.toCharArray();
        int c = 0;
        for(int i = shifts.length; i >= 0; i--){
        	c += shifts[i] % 26;
        	s[i] = (char) ('a' + (s[i] - 'a' + c) % 26);
        }
        return String.valueOf(s);
    }
}
