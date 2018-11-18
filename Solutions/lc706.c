#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define size 10007
struct ListNodeN{
	int key, val;
	struct ListNodeN* next;
};

typedef struct ListNodeN* Cell;


typedef struct {
    Cell* list;
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap* hm = (MyHashMap*)malloc(sizeof(MyHashMap));
    //size = 10007
    hm->list = (Cell*)calloc(size, sizeof(Cell));
    //with out dummyhead , no need to malloc
    return hm;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int hashcode = key % size;
    Cell c = obj->list[hashcode];
    //first put
    if(c == NULL){
    	Cell nc = (Cell)malloc(sizeof(struct ListNodeN));
    	nc->key = key;
    	nc->val = value;
    	nc->next = NULL;
    	obj->list[hashcode] = nc;
    	return;
    }
    while(c && c->key != key)
    	c = c->next;
    //doesn't exsist
    if(c == NULL){
    	Cell nc = (Cell)malloc(sizeof(struct ListNodeN));
    	nc->key = key;
    	nc->val = value;
    	nc->next = obj->list[hashcode];
    	obj->list[hashcode] = nc;
    }
    //already exsists
    else{
    	c->val = value;
    }
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    int hashcode = key % size;
    Cell c = obj->list[hashcode];
    while(c && c->key != key)
    	c = c->next;
    return c ? c->val : -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    int hashcode = key % size;
    Cell c = obj->list[hashcode];
    Cell pre = NULL;
    while(c && c->key != key){
    	pre = c;
    	c = c->next;
    }
    if(c){
    	if(pre == NULL)
    		obj->list[hashcode] = c->next;
    	else
    		pre->next = c->next;
    	free(c);
    }
}

void myHashMapFree(MyHashMap* obj) {
	Cell tmp;
    for (int i = 0; i < size; ++i)
    {
    	Cell c = obj->list[i];
    	while(c){
    		tmp = c;
    		c = c->next;
    		free(tmp);
    	}
    }
    free(obj->list);
    free(obj);
}

int main(){

	MyHashMap* hm = myHashMapCreate();
	myHashMapPut(hm, 1002, 3);
	myHashMapPut(hm, 1002, 20);
	myHashMapPut(hm, 1002, 23);
	int val1 = myHashMapGet(hm, 1002);
	
	myHashMapRemove(hm,1002);
	// myHashMapRemove(hm,1002);
	int val2 = myHashMapGet(hm, 1002);

	printf("%d\t%d\n", val1, val2);
	myHashMapFree(hm);
	printf("ok\n");
}
