struct ListNode{
	int val;
	struct ListNode* next;
};

/*recur: top->down*/
// struct ListNode* merge(struct ListNode* left, struct ListNode* right){
// 	struct ListNode dummy = {-1, NULL};
// 	struct ListNode* tail = &dummy;
// 	while(left && right){
// 		//insert the smaller val 
// 		if(left->val > right->val){
// 			//insert at tail
// 			tail->next = right;
// 			right = right->next;
// 			tail = tail->next;
// 		}
// 		else{
// 			tail->next = left;
// 			left = left->next;
// 			tail = tail->next;
// 		}		
// 	}
// 	tail->next = left ? left : right;
// 	return dummy.next;
// }

// struct ListNode* sortList(struct ListNode* head) {
//     if(!head || !head->next) return head;
//     struct ListNode* slow = head, *fast = head->next;
//     struct ListNode* mid = NULL;
//     while(fast && fast->next){
//     	slow = slow->next;
//     	fast = fast->next->next;
//     }
//     mid = slow->next; /*the right part head*/
//     slow->next = NULL; /*cut*/
//     return merge(sortList(head), sortList(mid));
// }

/*iterative: bottom->up*/
typedef struct{
	struct ListNode* head;
	struct ListNode* tail;
}Pair;

struct ListNode* split(struct ListNode* head, int n){
	while(--n && head)
		head =  head->next;
	struct ListNode* rest = head ? head->next : NULL;
	if(head) 
		head->next = NULL;
	return rest;
}

Pair merge(struct ListNode* left, struct ListNode* right){
	struct ListNode dummy = {-1, NULL};
	struct ListNode* tail = &dummy;
	while(left && right){
		if(left->val > right->val){
			tail->next = right;
			right = right->next;
			tail = tail->next;
		}
		else{
			tail->next = left;
			left = left->next;
			tail = tail->next;
		}
	}
	tail->next = left ? left : right;
	while(tail->next) tail = tail->next;
	Pair pair = {dummy.next, tail};
	return pair;
}

struct ListNode* sortList(struct ListNode* head) {
	if(!head || !head->next) return head;

	int len = 1;
	struct ListNode* cur =  head;
	while(cur = cur->next)
		len++;

	struct ListNode dummy = {-1, head};
	struct ListNode* l, *r, *tail;
	for (int n = 1; n < len; n <<= 1){
		cur =  dummy.next;
		tail = &dummy;
		while(cur){
			l = cur;
			r = split(l, n);
			cur = split(r, n);
			Pair merged = merge(l, r);
			tail->next = merged.head;
			tail = merged.tail;
		}  	
	}
	return dummy.next;
}