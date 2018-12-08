/*
**最关键是处理两个值的比较方法和循环到A的最后一个值的插入问题
*/
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) {//处理空指针
		return l2;
	}
	if (l2 == NULL) {//处理空指针
		return l1;
	}
	ListNode *rel;
	if (l1->val > l2->val) {//选取l1作为开头（head值更小），即返回的指针
		rel = l2;
		l2 = l1;
		l1 = rel;
	}
	ListNode *A = l1;
	ListNode *B = l2;
	while (A!= NULL && B!= NULL) {
		if (A->next == NULL && B->val >= A->val) {//如果A到了最后一个值，则直接插入
			l2 = B->next;
			B->next = A->next;
			A->next = B;
			B = l2;
		}
		else if (/*A->val <= B->val &&*/ B->val <= A->next->val && A->next!=NULL ) {//A循环到中间，将B的值插入，然后让B指向B的next
			l2 = B->next;
			B->next = A->next;
			A->next = B;
			B = l2;
		}
		else {//A的next的值还大于B
			A = A->next;
		}
	}
	return l1;
}


int main() {
	ListNode *A;
	ListNode *B;
	mergeTwoLists(A,B);
	system("pause");
	return 0;
}
