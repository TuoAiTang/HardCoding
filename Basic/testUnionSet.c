#include<stdio.h>
#include<stdlib.h>
#include "UnionSet.h"

int main(){

	UnionSet* us = createUnionSet(20);
	Union(us, 1, 2);
	Union(us, 1, 3);
	printf("Parent of %d is %d\n", 3, Find(us, 3));
	destroyUnionSet(us);
	

	return 0;
}