class Solution {
    public String decodeString(String s) {
    	Stack<Integer> countStack = new Stack<>();
    	Stack<String> resStack = new Stack<>();
    	int idx = 0;
    	int count = 0;
    	String res = "";
    	while(idx < s.length){
    		count = 0;
    		if(Character.isDigit(s.charAt(idx))){
    			while(Character.isDigit(s.charAt(idx)))
    				count = 10 * count + s.charAt(idx++) - '0';
    			countStack.push(count);
    		}else if(s.charAt(idx) == '['){
    			resStack.push(res);
    			res = "";
    			idx++;
    		}else if(s.charAt(idx) == ']'){
    			int repeatTimes = countStack.pop();
    			StringBuilder sb = new StringBuilder(resStack.pop());
    			for (int i = 0; i < repeatTimes; i++)
    				sb.append(res);
    			res = sb.toString();
    			idx++;
    		}else{
    			res += s.charAt(idx++);
    		}
    	}
        return res;
    }
}