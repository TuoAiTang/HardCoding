//O(m*n*2^keys) = 30*30*64
//19ms beats 98.26%
import java.util.*;
class lc864_BFS_BIT {
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length;
        if(m == 0) return 0;
        int n = grid[0].length();
        int ALL_KEYS = 0;

        //32bit integer to represent the unique state 
        //000xxxxx|000yyyyy|00kkkkkk
        //x <= 30, y <= 30, k <= 6
        Queue<Integer> q = new LinkedList<>();

        int [][][] visited = new int[m][n][64];

        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		char c = grid[i].charAt(j);
        		if(c == '@')
        			q.offer((i << 16) | (j << 8));
        		if(c >= 'a' && c <= 'f')
        			ALL_KEYS |= (1 << (c - 'a'));
        	}
        }

        int [] dirs = {-1, 0, 1, 0, -1};
        int steps = 0;
        while(!q.isEmpty()){
        	int size = q.size();
        	while(size-- > 0){
        		int state = q.remove();
        		int x = state >> 16;
        		int y = (state >> 8) & 0xFF;
        		int keys = state & 0xFF;
        		if(visited[x][y][keys] == 1) continue;
        		visited[x][y][keys] = 1;
        		if(keys == ALL_KEYS) return steps;
        		for(int i = 0; i < 4; i++){
        			int nkeys = keys;
        			int nx = x + dirs[i];
        			int ny = y + dirs[i + 1];
        			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        			char c = grid[nx].charAt(ny);
        			//wall
        			if(c == '#') continue;
        			//no keys to the locked door
        			if(c >= 'A' && c <= 'F' && ((nkeys & (1 << (c - 'a'))) == 0))
        				continue;
        			//update the keys you own
        			if(c >= 'a' && c <= 'f') nkeys |= (1 << (c - 'a'));
        			q.offer((nx << 16) | (ny << 8) | nkeys);
        		}
        	}
        	steps++;
        }
        return -1;
    }
}