#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* price_stack;
    int* weight_stack;
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    int* price_stack = (int*)malloc(10000 * sizeof(int));
    int* weight_stack = (int*)malloc(10000 * sizeof(int));
    StockSpanner* ssp = (StockSpanner*)malloc(sizeof(StockSpanner));
    ssp->price_stack = price_stack;
    ssp->weight_stack = weight_stack;
    ssp->top = -1;
    return ssp;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int w = 1;
    while(obj->top != -1 && obj->price_stack[obj->top] <= price)
    	w += obj->weight_stack[obj->top--];

    (obj->top)++;
    obj->price_stack[obj->top] = price;
    obj->weight_stack[obj->top] = w;
    return w;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->price_stack);
    free(obj->weight_stack);
    free(obj);
}
/**
 * Your StockSpanner struct will be instantiated and called as such:
 * struct StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 * stockSpannerFree(obj);
 */
int main(){

	StockSpanner* obj = stockSpannerCreate();
	for (int i = 1; i < 10; ++i)
	{
		//1,2,0,1,2,0,1,2,0
		printf("%d\n", stockSpannerNext(obj, i % 3));
	}

	stockSpannerFree(obj);
	return 0;
}