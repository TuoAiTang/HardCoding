#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* afterBackspace(char* S){
	char stack[200];
	int top = -1;
	while(*S != '\0'){
		if(*S == '#'){
			if(top != -1)
				top--; 
		}
		else
			stack[++top] = *S;
		S ++;
	}	
	int size = top + 1;	
	// char* ret = (char*)calloc(size + 1, sizeof(char));	
	printf("size:%d\n", size);
	char* ret = (char*)calloc(size, sizeof(char));	
	for (int i = 0; i < size; ++i)
		ret[i] = stack[i];		
	// ret[size] = '\0';
	printf("size of ret:%d\n", strlen(ret));	
	return ret;
}

int backspaceCompare(char* S, char* T) {
    char *s = afterBackspace(S);
    char *t = afterBackspace(T);
    if(strcmp(s, t) == 0)
    	return 1;   	
    return 0;
}



int main()
{
	
	//"ldfpgjkh##mmg####waq##obcjcb##eypcwo#######yl##ocwxomq##lat###breud####in#zniqo####wrsm#####yccsqwlbyhou###rx##gklok#rjdhr######jhcllmwt#yklspk####hml"
//"q#ldfpgjkh##mmg####waw#q##obcjcb##eyh#g#pcwo#p#######ylw###ocwxomq##v#lf#at###bs#reud####in#zniqo####wq#rsm#####r#ycow##f#csqwlbyhos#u#k###ru#xr###gklok#rjdhr######jhclt#lmwt#ys#klsa#pk##j#sj####hz#ml"
	char s[] = "ldfpgjkh##mmg####waq##obcjcb##eypcwo#######yl##ocwxomq##lat###breud####in#zniqo####wrsm#####yccsqwlbyhou###rx##gklok#rjdhr######jhcllmwt#yklspk####hml";
	//int size;
	char t[] = "q#ldfpgjkh##mmg####waw#q##obcjcb##eyh#g#pcwo#p#######ylw###ocwxomq##v#lf#at###bs#reud####in#zniqo####wq#rsm#####r#ycow##f#csqwlbyhos#u#k###ru#xr###gklok#rjdhr######jhclt#lmwt#ys#klsa#pk##j#sj####hz#ml";
	
	printf("%d\n", backspaceCompare(s, t));
	char* ret1 = afterBackspace(s);
	char* ret2 = afterBackspace(t); 
	printf("%s\n", ret1); 
	printf("%s\n", ret2); 

	return 0;
}
