#include<stdio.h>
#include<stdlib.h>

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
		us->parents[id] = Find(us, us->parents[id]);	//path compression
	return us->parents[id];
}

bool Union(UnionSet* us, int u, int v){
	int pu = Find(us, u);
	int pv = Find(us, v);
	if(pu == pv) return false;
	//union the smaller tree to the biger tree
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

void destroyUnionSet(UnionSet* us){
	free(us->ranks);
	free(us->parents);
	free(us);
	printf("Success: destroyUnionSet!\n");
}


