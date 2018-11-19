// 8ms
typedef struct {
	int* parents;
	int* ranks;
} UnionSet;

UnionSet* createUnionSet(int capacity){
	UnionSet* us = (UnionSet*)malloc(sizeof(UnionSet));
	us->parents = (int*)malloc(capacity * sizeof(int));
	us->ranks = (int*)calloc(capacity, sizeof(int));
	for(int i = 0; i < capacity; i++)
		us->parents[i] = i;
	return us;
}

int Find(UnionSet* us, int id){
	if(us->parents[id] != id)
		us->parents[id] = Find(us, us->parents[id]);	//path conpression
	return us->parents[id];
}

bool Union(UnionSet* us, int u, int v){
	int pu = Find(us, u);
	int pv = Find(us, v);
	if(pu == pv) return false;
	if(us->ranks[pu] > us->ranks[pv])
		us->parents[pv] = pu;
	else if(us->ranks[pu] < us->ranks[pv])
		us->parents[pu] = pv;
	else{
		us->parents[pu] = pv;
		us->ranks[pv] ++;
	}
	return true;
}

//O(n^2)
int findCircleNum(int** M, int MRowSize, int MColSize) {
    int n = MRowSize;
    UnionSet* us = createUnionSet(n);
    //n + (n-1) + (n-2) + ... + 2 + 1 = O(n^2)
    for (int i = 0; i < n; ++i)
    {
    	for(int j = i + 1; j < n; j++){
    		if(M[i][j] == 1)
    			Union(us, i, j);
    	}
    }

    int hashset[200] = {0};
    int ans = 0;
    //O(n)
    for (int i = 0; i < n; ++i)
    {
    	int circle = Find(us, i);
    	if(hashset[circle] == 0){
    		hashset[circle] = 1;
    		ans++;
    	}
    }
    return ans;
}

