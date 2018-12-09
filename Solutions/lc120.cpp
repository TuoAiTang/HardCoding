class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        auto& t = triangle;
        for(int i = 0; i < n; i++)
        	for(int j = 0; j <= i; j++){
        		if(i == 0 && j == 0) continue;
        		if(j == 0) t[i][j] += t[i - 1][j];
        		else if(j == i) t[i][j] += t[i - 1][j - 1];
        		else t[i][j] += min(t[i - 1][j], t[i - 1][j - 1]);
        	}

       	int ans = INT_MAX;
       	for(int i = 0; i < n; i++)
       		ans = Math.min(ans, t[n - 1][i]);
       	return ans;
    }
};