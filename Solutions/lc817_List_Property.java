//6ms beats 97% 
import java.util.*;
class lc817_List_Property {
    public int numComponents(ListNode head, int[] G) {
        int [] set = new int[10000];
        for(int val : G)
        	set[val] = 1;
        while(head){
            if(set[head.val] == 1 && (head.next == null || set[head.next.val] == 0))
                ans++;
            head = head.next;
        }
        return ans;
    }
}