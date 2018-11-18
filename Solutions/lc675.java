import java.util.*;
class lc675 {
	private class Tree implements Comparable<Tree>{
		int height, x, y;
		public Tree(int h, int x_row, int y_col) {this.height = h; this.x = x_row; this.y = y_col;}

		@Override
		public int compareTo(Tree tr) {return this.height - tr.height;}
	}

	private class Node{
		int x, y;
		public Node(int x_row, int y_col){x = x_row; y = y_col;}
	}

    public int cutOffTree(List<List<Integer>> forest) {

        List<Tree> trees = new ArrayList<>();
        for(int i = 0; i < forest.size(); i++)
        	for(int j = 0; j < forest.get(0).size(); j++)
        		if(forest.get(i).get(j) > 1)
        			trees.add(new Tree(forest.get(i).get(j), i, j));
		Collections.sort(trees);

		int ans = 0;
		int sx = 0, sy = 0;
		for(int i = 0; i < trees.size(); i++){
			int tx = trees.get(i).x;
			int ty = trees.get(i).y;

			int steps = bfs(forest, sx, sy, tx, ty);
			if(steps == -1) return -1;
			ans += steps;

			sx = tx;
			sy = ty;
		}

		return ans;
    }

    private int bfs(List<List<Integer>> forest, int sx, int sy, int tx, int ty){

    	int [][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 

    	int rows = forest.size();
    	int cols = forest.get(0).size();

    	//auto fill 0, so not nesssary to init
    	int [][] visited = new int[rows][cols];

    	int steps = 0;

    	Queue<Node> q = new LinkedList<>();
    	q.offer(new Node(sx, sy));

    	while(!q.isEmpty()){
    		Node node = q.remove();

    		if(node.x == sx && node.y == sy)
    			return steps;

    		for(int i = 0; i < 4; i++){

    			int x = node.x + dirs[i][0];
    			int y = node.y + dirs[i][1];

    			//out of bounds, visited, or can't pass through
    			if(x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y] == 1 || forest.get(x).get(y) == 0)
    				continue;	

    			visited[x][y] = 1;
    			q.offer(new Node(x, y));
    		}

    		steps++;
    	}

    	return -1; //means no path to (tx, ty)
    }
}