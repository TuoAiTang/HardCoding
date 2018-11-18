package tree;
import java.util.*;
public class lc559 {
//	public int maxDepth(Node root) {
//        if(root == null)
//        	return 0;
//        int max = 0;
//        for (Node node : root.children)
//			max = Math.max(max, maxDepth(node));
//        return max + 1;
//    }
	public int maxDepth(Node root) {
        if(root == null)
        	return 0;
        int max = 0;
        Queue<Node> que = new LinkedList<>();
        que.offer(root);
        while(!que.isEmpty()) {
        	int size = que.size();
        	for (int i = 0; i < size; i++) {
				Node cur = que.poll();
				for (Node node : cur.children) {
					que.offer(node);
				}
			}
        	max++;
        }
        return max;
	}
}
