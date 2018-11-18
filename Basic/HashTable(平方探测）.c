#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



//struct definition
typedef char* ElementType;
enum KindOfEntry{Legitimate, Empty, Deleted};
typedef unsigned int Index;
typedef Index Position;

struct HashEntry {
    ElementType elem;
    int count; //for those who cares count
    enum KindOfEntry info;
};

typedef struct HashEntry Cell;

struct HashTbl{
	int tableSize;
	Cell* theCells;
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

Index hash(ElementType key, int tableSize){
	Index hashVal = 0;
	char* s = key;
	while(*s != '\0')
		hashVal = (hashVal << 5) + *s++;
	return hashVal % tableSize;
}


//useful functions
HashTable initHashTable(int tableSize){
	HashTable H = (HashTable)malloc(sizeof(struct HashTbl));

	H->tableSize = nextPrime(tableSize);

	H->theCells = (Cell*)malloc(H->tableSize * sizeof(Cell));

	//init the head pointer
	for (int i = 0; i < H->tableSize; ++i)
		H->theCells[i].info = Empty;

	return H;
}

Position find(ElementType key, HashTable H){
	Position currentPos = hash(key, H->tableSize);
	int collisionNum = 0;

	while(H->theCells[currentPos].info != Empty && strcmp(H->theCells[currentPos].elem, key) != 0){
		currentPos += 2 * (++collisionNum)  - 1;
		if(currentPos >= H->tableSize)
			currentPos -= H->tableSize;
	}
	return currentPos;
}

void insert(ElementType key, HashTable H){
	Position pos;
	pos = find(key, H);
	if(H->theCells[pos].info != Legitimate){
		H->theCells[pos].info = Legitimate;
		H->theCells[pos].count = 1;
		H->theCells[pos].elem = key;
		// int len = strlen(key);
		// char* copy = (char*)malloc(len * sizeof(char));
		// strcmp(copy, key);
		// H->theCells[pos] = copy;
	}
	else{
		H->theCells[pos].count++;
	}
}

void destroyHashtable(HashTable ht){
	ht->tableSize = 0;
	free(ht->theCells);
	free(ht);
	printf("destroyHashtable Success!\n");
}

HashTable rehash(HashTable ht){
	int oldSize = ht->tableSize;
	Cell* oldCells = ht->theCells;

	ht = initHashTable(2 * oldSize);

	for(int i = 0; i < oldSize; i++){
		if(oldCells[i].info == Legitimate){			
			insert(oldCells[i].elem, ht);
			//don't forget to update the count
			Position pos = find(oldCells[i].elem, ht);
			ht->theCells[pos].count = oldCells[i].count;
		}			
	}

	free(oldCells);
	printf("rehash success!\n");
	return ht;
}


int main(){
	HashTable ht = initHashTable(26);

	insert("tuoaitang", ht);
	insert("tuoaitang", ht);
	insert("tuoaitang", ht);
	
	insert("tc", ht); 
	insert("tc", ht); 


	int cnt = ht->theCells[find("tuoaitang", ht)].count;
	printf("tuoaitang: %d\n", cnt);
	
	cnt = ht->theCells[find("tc", ht)].count;
	printf("tc: %d\n", cnt);
	
//	destroyHashtable(ht); 
	
	ht = rehash(ht);
	
	cnt = ht->theCells[find("tc", ht)].count;
	printf("tc: %d\n", cnt);
	
	cnt = ht->theCells[find("tuoaitang", ht)].count;
	printf("tuoaitang: %d\n", cnt);
	
	return 0;
}
