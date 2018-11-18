#include <stdio.h>
#include <stdlib.h>


typedef struct Entry{
	int val;
	struct Entry* next;
}Entry;

typedef struct {
    Entry** list;
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* hs = (MyHashSet*)malloc(sizeof(MyHashSet));
    hs->list = (Entry**)calloc(10007, sizeof(Entry*));
    return hs;
}

void myHashSetAdd(MyHashSet* obj, int key) {
	int hashcode = key % 10007;
    Entry** list = obj->list;
    Entry* entry = list[hashcode];
    while(entry && entry->val != key)
    	entry = entry->next;
    if(entry == NULL){
    	Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    	newEntry->val = key;
    	newEntry->next = list[hashcode];
    	list[hashcode] = newEntry;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int hashcode = key % 10007;
    Entry** list = obj->list;
    Entry* entry = list[hashcode];
    Entry* pre = NULL;
    while(entry && entry->val != key){
    	pre = entry;
    	entry = entry->next;
    }
    if(entry){
    	if(pre == NULL)
    		list[hashcode] = entry->next;
    	else
    		pre->next = entry->next;
    	free(entry);
	}
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int hashcode = key % 10007;
    Entry** list = obj->list;
    Entry* entry = list[hashcode];
    while(entry && entry->val != key)
    	entry = entry->next;
    return entry ? true : false;
}

void myHashSetFree(MyHashSet* obj) {
	Entry* tmp;
    for (int i = 0; i < 10007; ++i)
    {
    	Entry* entry = obj->list[i];
    	while(entry){
    		tmp = entry;
    		entry = entry->next;
    		free(tmp);
    	}
    }
    free(obj->list);
    free(obj);
}

int main(int argc, char const *argv[])
{
	MyHashSet* hs = myHashSetCreate();

	myHashSetAdd(hs, 1003);
	printf("%d\n", myHashSetContains(hs, 1003));
	myHashSetRemove(hs, 1003);
	printf("%d\n", myHashSetContains(hs, 1003));
	myHashSetFree(hs);
	printf("ok\n");
	return 0;
}