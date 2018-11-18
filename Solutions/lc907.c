#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// start 17:20
// end 18:59
typedef struct{
    int val;
    int count;
} Pair;

int sumSubarrayMins(int* A, int ASize) {
    int modval = 1000000007;
    int ans = 0;
    int dot = 0;
    Pair* stack = (Pair*)malloc(ASize * sizeof(Pair));
    int top = -1;
    for (int j = 0; j < ASize; ++j)
    {
        int count = 1;
        while(top != -1 && A[j] <= stack[top].val){
            //pop
            Pair tmp = stack[top--];
            //update
            count += tmp.count;
            dot -= tmp.val * tmp.count;
        }
        //push
        Pair newp;
        newp.val = A[j];
        newp.count = count;
        stack[++top] = newp;
        //sum by updating the dot of every turn
        dot += A[j] * count;
        ans += dot;
        ans %= modval;
    }
    free(stack);
    return ans;
}

int main(){

    
    int a[] = {3,1,2};

    printf("%d\n", sumSubarrayMins(a, 3));
	

	return 0;
}