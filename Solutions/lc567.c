#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool equal(int* a, int* b){
	for (int i = 0; i < 26; ++i)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}
bool checkInclusion(char* s1, char* s2) {
    int ht1[26] = {0};
    int ht2[26] = {0};
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len1; ++i)
    {
    	ht1[s1[i] - 'a']++;
    }
    for (int i = 0; i < len2; ++i)
    {
    	if(i >= len1)
    		--ht2[s2[i - len1] - 'a'];
    	ht2[s2[i] - 'a']++;
    	if(equal(ht1, ht2))
    		return true;
    }
    return false;
}

