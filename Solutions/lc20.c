#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    char val;
    struct ListNode *next;
};

typedef struct ListNode Stack;

Stack* createStack(){
	Stack* head = (Stack*)malloc(sizeof(Stack));
	head->val = 0;
	head->next = NULL;
	return head;
}

void push(Stack* s, char c){
	Stack* node = (Stack*)malloc(sizeof(Stack));
	node->val = c;
	node->next = s->next;
	s->next = node;
}

char top(Stack* s){
	return s->next->val;
}

void pop(Stack* s){
	Stack* tmp = s->next;
	s->next = s->next->next;
	free(tmp);
}

int isEmpty(Stack* s){
	return s->next?0:1;
}

bool isValid(char* s) {
	Stack* head = createStack();

	while(*s != '\0'){
		if(*s == '(' || *s == '[' || *s == '{')
    		push(head, *s);
    	else if(isEmpty(head))
    		return 0;
    	else if(*s == ')'){
    		if(top(head) != '(')
    			return 0;
    		pop(head);
    	}
    	else if(*s == ']'){
    		if(top(head) != '[')
    			return 0;
    		pop(head);
    	}
    	else if(*s == '}'){
    		if(top(head) != '{')
    			return 0;
    		pop(head);
    	}
    	s ++ ;
    }
    return isEmpty(head);
}

int main(){

	char a[] = "(({}))";

	printf("%d\n", isValid(a));

	return 0;
}