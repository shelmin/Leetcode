/*
**c语言中对于链表的操作也很重要，包括如何初始化一个链表等，以及NULL代表的含义，该题比较基础
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

ListNode* reverseList(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	ListNode *p = head;
	vector<int> a;
	while (p->next != NULL) {
		a.push_back(p->val);
		p = p->next;
	}
	a.push_back(p->val);
	p = head;
	for (int i = a.size() - 1; i != -1; i--) {
		p->val = a[i];
		p = p->next;
	}
	return head;
}


int main() {
	ListNode *A;
	reverseList(A);
	system("pause");
	return 0;
}
