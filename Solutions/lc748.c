#include<stdio.h>
#include<string.h>

int hash(char c){
	if(c >= 'a')
		return c - 'a';
	return c - 'A';
}

int match(const int* map, char* word){
	int index;
	int copy[25];
	for (int i = 0; i < 25; ++i)
		copy[i] = map[i];
	for (int i = 0; i < strlen(word); ++i)
	{
		index = hash(word[i]);
		if(copy[index] > 0)
			copy[index]--;
	}
	for (int i = 0; i < 25; ++i)
	{
		if(copy[i] > 0)
			return 0;
	}
	return 1;
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int map[25] = {0};
    char* ans = NULL;
    char* word = NULL;
    for (int i = 0; i < strlen(licensePlate); ++i){
    	char c  = licensePlate[i];
    	if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
	    	map[hash(c)]++;
    }
	for (int i = 0; i < wordsSize; ++i)
	{
		word = words[i];
		printf("%s\tmatched:\t", word);
		printf("%d\n", match(map, word));
		if(ans == NULL && match(map, word))
			ans = word;
		else if(ans && strlen(word) < strlen(ans) && match(map, word))
			ans = word;
	}
	return ans;
}



int main(){
	char* words[10] = {"suggest","letter","of","husband","easy","education","drug","prevent","writer","old"};
	char plate[8] = "Ah71752";
	char* ans = shortestCompletingWord(plate, words, 10);
	printf("%s\n", ans);
	printf("%c\t%c\n", hash('A') + 'A', hash('h') + 'A');

	
}
