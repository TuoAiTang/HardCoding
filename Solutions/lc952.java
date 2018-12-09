/* Time complexity: O(Σsqrt(A[i]))
** Space : max(A[i])
** Runtinme: 210ms whth (merge by rank/size); 241ms (without merge by rank/size)
** do not have enough accepted submissions to show runtime distribution chart.
*/
import java.util.*;
class lc952 {
	class UnionSet{
		public int [] parents;
		// public int [] sizes;
		UnionSet(int n){
			parents = new int[n];
			// sizes = new int[n];
			for(int i = 0; i < n; i++){
				parents[i] = i;
				// sizes[i] = 0;
			}
		}

		boolean union(int a, int b){
			// int pa = find(a);
			// int pb = find(b);
			// if(pa == pb) return false;
			// if(sizes[pa] > sizes[pb]){
			// 	parents[pb] = pa;
			// 	sizes[pa] += sizes[pb];
			// }
			// else{
			// 	parents[pa] = pb;
			// 	sizes[pb] += sizes[pa];
			// }
			parents[find(a)] = parents[find(b)];
			return true;
		}

		int find(int a){
			if(parents[a] != a)
				parents[a] = find(parents[a]);
			return parents[a];
		}

	}
    public int largestComponentSize(int[] A) {
    	if(A.length == 0) return 0;
        int m = getMax(A);
        UnionSet u = new UnionSet(m + 1);
        for(int n : A){
        	int s = (int) Math.sqrt(n);
        	for(int i = 2; i <= s; i++){
        		if(n % i == 0){
        			u.union(n, i);
        			u.union(n, n / i);
        		}
        	}
        }

        Map<Integer, Integer> count = new HashMap<>();
        int ans = 1;
        for(int a : A){
        	int p = u.find(a);
        	count.put(p, count.getOrDefault(p, 0) + 1);
        	ans = Math.max(ans, count.get(p));
        }
        return ans;
    }

    private int getMax(int [] a){
    	int m = a[0];
    	for(int i = 1; i < a.length; i++)
    		m = Math.max(m, a[i]);
    	return m;
    }


}