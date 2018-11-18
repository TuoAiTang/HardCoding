#include <stdio.h>
#include <stdlib.h>
/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedInteger *NestedIntegerInit();	//初始化
bool NestedIntegerIsInteger(struct NestedInteger *);	//是否为SingleInteger
int NestedIntegerGetInteger(struct NestedInteger *);	//返回SingleInteger的值
void NestedIntegerSetInteger(struct NestedInteger *ni, int value);	//设置一个Integre
void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);	//添加一个NestedInteger对象
struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);	//获取NestedInteger列表
int NestedIntegerGetListSize(struct NestedInteger *);	//获取NestedInteger列表长度

struct NestedInteger* deserialize(char* s) {
    struct NestedInteger** stack = (struct NestedInteger**)malloc(1000 * sizeof(struct NestedInteger*));
    int top = -1;
    while(*s != '\0'){
    	if(*s - '0' >= 0 && *s - '0' <= 9 || *s == '-'){
    		int val = 0;
    		
			else if(*s - '0' >= 0 && *s - '0' <= 9){
    			while(*s - '0' >= 0 && *s - '0' <= 9)			
    				val = 10 * val + (*s++) - '0';

    		}
    		
    		struct NestedInteger* newNi = NestedIntegerInit();
    		NestedIntegerSetInteger(newNi, val);
    		if(top == -1){
    			top++;
    			*(stack+top) = newNi; 
                break;
    		}
            NestedIntegerAdd(*(stack+top), newNi);
    	}//*s == ','/']'/'['
    	else{
    		if(*s == '['){
    			top ++;
    			*(stack+top) = NestedIntegerInit();
    		}else if(*s == ']'){
    			struct NestedInteger* tmp = *(stack+top);
    			top--;
    			if(top == -1){
    				free(stack);
    				return tmp;
    			}
    			NestedIntegerAdd(*(stack+top), tmp);
    		}
    		s++;
    	}
    }

    if(top != -1)
    	return *(stack+top);
    free(stack);
    return NULL;
}
int main(){

	char s[] = "[123,[456,[789]]]";

	deserialize(s);

	return 0;
}

