#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void randCharFill(char* s, int s_size){
	for (int i = 0; i < s_size; ++i)
		s[i] = 65 + rand() % 40;
}

int main(){

	// char a[10] = "not full";
	// printf("%s\n", a);"ldfpgjkh##mmg####waq##obcjcb##eypcwo#######yl##ocwxomq##lat###breud####in#zniqo####wrsm#####yccsqwlbyhou###rx##gklok#rjdhr######jhcllmwt#yklspk####hml"
//"q#ldfpgjkh##mmg####waw#q##obcjcb##eyh#g#pcwo#p#######ylw###ocwxomq##v#lf#at###bs#reud####in#zniqo####wq#rsm#####r#ycow##f#csqwlbyhos#u#k###ru#xr###gklok#rjdhr######jhclt#lmwt#ys#klsa#pk##j#sj####hz#ml"


	
	// randCharFill(p, size);
	// p[size] = '\0';
	// printf("%s\n", p);
	// printf("len of p:%d\n", strlen(p));	
	// printf("p[size]:%c\n", p[size]);

	char a[] = "ldfpgjkh##mmg####waq##obcjcb##eypcwo#######yl##ocwxomq##lat###breud####in#zniqo####wrsm#####yccsqwlbyhou###rx##gklok#rjdhr######jhcllmwt#yklspk####hml";
	printf("len of a:%d\n", strlen(a));

	int size = 40;
	char* p = (char*)malloc(size * sizeof(char));
	randCharFill(p, size);
	printf("%s\n", p);
	printf("len of p:%d\n", strlen(p));


	return 0;
}