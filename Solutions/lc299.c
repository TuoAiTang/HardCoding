//0ms beats 100%
char* getHint(char* secret, char* guess) {
    int smap[10] = {0};
    int gmap[10] = {0};
    int n = strlen(secret);
    int A = 0;
    int B = 0;

    for(int i = 0; i < n; i++){
    	if(secret[i] == guess[i])
    		A++;
    	else{
    		smap[secret[i] - '0']++;
    		gmap[guess[i] - '0']++;
    	}
    }

    for(int i = 0; i <= 9; i++){
    	B += min(smap[i], gmap[i]);
    }

    char* res = (char*)malloc(20 * sizeof(char));
    sprintf(res, "%dA%dB", A, B);
    return res;
}