package test;

import java.util.Stack;

public class testString {
	public static void main(String[] args) {
		Stack<String> resStack = new Stack<>();
		String s = "";
		resStack.push(s);
		
		s += "1";
		System.out.println(resStack.peek());
		System.out.println(s);
	}
}
