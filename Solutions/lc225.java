import java.util.*;
class lc225{
	public static void main(String[] args) {
		MyStack3 ms = new MyStack3();
		ms.push(1);
		ms.push(2);
		System.out.println("top" + ms.top());
		ms.pop();
		System.out.println("top" + ms.top());
	}
}
//55ms beats 86.88%
//Time: push(O(1)) pop(O(n))
//Space: two queue O(n) n -> the total element in q1 and q2
class MyStack {

	private Queue<Integer> q1;
	private Queue<Integer> q2;
	private int top;
    /** Initialize your data structure here. */
    public MyStack() {
       	q1 = new LinkedList<>();
       	q2 = new LinkedList<>();  
       	top = -1;     
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q1.add(x);
        top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
    	while(q1.size() > 1){
    		top = q1.remove();
    		q2.add(top);
    	}
    	int pop_num = q1.remove();
    	Queue<Integer> tmp = q1;
    	q1 = q2;
    	q2 = tmp;
    	return pop_num;
    }
    
    /** Get the top element. */
    public int top() {
        return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty() && q2.isEmpty();
    }
    	
}

//56ms beats 80.04%
//Time: push(O(n)) pop(O(1))
//Space: two queue O(n) n -> the total element in q1 and q2
class MyStack2 {

	private Queue<Integer> q1;
	private Queue<Integer> q2;
	private int top;
    /** Initialize your data structure here. */
    public MyStack2() {
       	q1 = new LinkedList<>();
       	q2 = new LinkedList<>();  
       	top = -1;     
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
    	q2.add(x);
    	top = x;
        while(!q1.isEmpty())
    		q2.add(q1.remove());
    	Queue<Integer> tmp = q1;
    	q1 = q2;
    	q2 = tmp;

    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
    	if(empty()) return -1;
    	int pop_num = q1.remove();
    	return pop_num;
    }
    
    /** Get the top element. */
    public int top() {
    	if(empty()) return -1;
        return q1.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty();
    }
    	
}


//63ms beats 47.46%
//Time: push(O(n)) pop(O(1))
//Space: only one queue O(n) n -> the total element in q1 and q2
class MyStack3 {

	private Queue<Integer> q;
    /** Initialize your data structure here. */
    public MyStack3() {
       	q = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
    	int size = q.size();
    	q.add(x);
    	while(size-- > 0)
    		q.add(q.remove());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
    	if(empty()) return -1;
    	return q.remove();
    }
    
    /** Get the top element. */
    public int top() {
    	if(empty()) return -1;
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
    	
}
