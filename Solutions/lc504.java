//11ms beats 39.78%
class lc504 {
    public String convertToBase7(int num) {
        StringBuffer sb = new StringBuffer();
        Boolean is_negative = num < 0;
        num = Math.abs(num);

        do{
        	sb.append(num % 7);
        	num /= 7;
        } while(num > 0);

        if(is_negative)
        	sb.append("-");

        return sb.reverse().toString();
    }
}