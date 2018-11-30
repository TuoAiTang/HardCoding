import java.util.*;
class lc934 {
	class Pos{
		int x, y;
		Pos(int x_, int y_) {x = x_; y = y_;}
	}
    public int shortestBridge(int[][] A) {
    	Queue<Pos> q = new LinkedList<>();

    	//use tag tp quit outer loop
    	outer:
        for(int i = 0; i < A.length; i++){
        	for(int j = 0; j < A[0].length; j++){
        		if(A[i][j] == 1){
        			dfs(i, j, A, q);
        			break outer;
        		}
        	}
        }
        //bfs
        int steps = 0;
        int [] dirs = {-1, 0, 1, 0, -1};
        while(!q.isEmpty()){
        	int size = q.size();
        	while(size-- > 0){
        		Pos p = q.remove();
        		for(int i = 0; i < 4; i++){
        			int nx = p.x + dirs[i];
        			int ny = p.y + dirs[i + 1];
        			if(nx < 0 || ny < 0 || nx >= A.length || ny >= A.length || A[nx][ny] == 2)
        				continue;
        			if(A[nx][ny] == 1) return steps;
        			A[nx][ny] = 2;
        			q.offer(new Pos(nx, ny));
        		}
        	}
        	steps++;
        }
        return steps;
    }

    private void dfs(int x, int y, int [][] A, Queue<Pos> q){
    	if(x < 0 || y < 0 || x >= A.length || y >= A.length || A[x][y] != 1)
    		return;
    	A[x][y] = 2;
    	q.offer(new Pos(x, y));
    	dfs(x + 1, y, A, q);
    	dfs(x - 1, y, A, q);
    	dfs(x, y + 1, A, q);
    	dfs(x, y - 1, A, q);
    }
}