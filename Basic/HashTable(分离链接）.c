#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//struct definition
struct StrCount{
	char* str;
	int count;
};

typedef struct StrCount* ElementType;
typedef struct StrCount pair;

struct ListNode {
    ElementType elem;
    struct ListNode *next;
};

typedef struct ListNode* Position;
typedef struct ListNode* List;

struct HashTbl{
	int tableSize;
	List* theLists;
};

typedef struct HashTbl* HashTable;


//basic functions

int nextPrime(int num){
	if(num == 1)
		return 2;
	if(num == 2)
		return 3;
	int is_prime;
	if(num % 2 == 0)
		num--;
	do
	{
		is_prime = 1;
		num = num + 2;
		//ensure next num is even number
		for(int i = 2; i <= sqrt(num); i++){
			if(num % i == 0){
				is_prime = 0;
				break;
			}
		}
	}while(is_prime == 0);

	return num;
}

unsigned int hash(ElementType key, int tableSize){
	unsigned int hashVal = 0;
	char* s = key->str;
	while(*s != '\0')
		hashVal = (hashVal << 5) + *s++;
	return hashVal % tableSize;
}


//useful functions
HashTable initHashTable(int tableSize){
	HashTable H = (HashTable)malloc(sizeof(struct HashTbl));

	H->tableSize = nextPrime(tableSize);

	H->theLists = (List*)malloc(H->tableSize * sizeof(List));
	
	List* list = H->theLists; 


	//init the head pointer
	for (int i = 0; i < H->tableSize; ++i){
		H->theLists[i] = (Position)malloc(sizeof(struct ListNode));
		H->theLists[i]->next = NULL;
	}		
	return H;
}

Position find(ElementType key, HashTable H){
	int index = hash(key, H->tableSize);
	Position p;
	List l;
	l = H->theLists[index];
	p = l->next;
	//check equal
	while(p && strcmp(key->str, p->elem->str) != 0)
		p = p->next;

	return p;
}

void insert(ElementType key, HashTable H){
	Position pos, newCell;
	List l;
	pos = find(key, H);
	if(pos == NULL){
		newCell = (Position)malloc(sizeof(struct ListNode));

		l = H->theLists[hash(key, H->tableSize)];
		newCell->elem = key;
		newCell->next = l->next;
		l->next = newCell;
	}
}

void destroyHashtable(HashTable ht){
	ht->tableSize = 0;
	for (int i = 0; i < ht->tableSize; ++i){
		struct ListNode* tmp, *p = ht->theLists[i];
		while(p){
			tmp = p;
			p = p->next;
			free(tmp);
		}
	}
	free(ht->theLists);
	free(ht);
	printf("destroy hashtable success!\n");
}

int main()
{
	HashTable ht = initHashTable(26);

	pair* elem = (pair*)malloc(sizeof(pair));
	elem->str = "tuoaitang";
	elem->count = 520;
	
	pair* elem2 = (pair*)malloc(sizeof(pair));
	elem2->str = "tangaituo";
	elem2->count = 250;


	insert(elem, ht);
	insert(elem2, ht);
	
	
	Position res = find(elem, ht);
	printf("%s : %d\n", res->elem->str, res->elem->count);
	
	Position res2 = find(elem2, ht);
	printf("%s : %d\n", res2->elem->str, res2->elem->count);
	
	destroyHashtable(ht);
	
	return 0;
}
