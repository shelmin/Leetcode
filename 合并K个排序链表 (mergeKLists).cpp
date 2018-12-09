/*
**对链表有初始化的操作，以及vector的erase操作，算法思想用到了分治法。
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
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	ListNode *rel;
	if (l1->val > l2->val) {
		rel = l2;
		l2 = l1;
		l1 = rel;
	}
	ListNode *A = l1;
	ListNode *B = l2;
	while (A != NULL && B != NULL) {
		if (A->next == NULL && B->val >= A->val) {
			l2 = B->next;
			B->next = A->next;
			A->next = B;
			B = l2;
		}
		else if (/*A->val <= B->val &&*/ B->val <= A->next->val && A->next != NULL) {
			l2 = B->next;
			B->next = A->next;
			A->next = B;
			B = l2;
		}
		else {
			A = A->next;
		}
	}
	return l1;
}



ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) {
		return NULL;
	}
	if (lists.size() == 1 && lists[0] == NULL) {
		return NULL;
	}
	if (lists.size() == 1 && lists[0] != NULL) {
		return lists[0];
	}
	if (/*lists.size() == 2 &&*/ lists[0] == NULL && lists[1] == NULL) {
		return lists[0];
	}
	if (lists.size() == 2 && lists[0] == NULL && lists[1] != NULL) {
		return lists[1];
	}
	if (lists.size() == 2 && lists[1] == NULL && lists[0] != NULL) {
		return lists[0];
	}
	vector<ListNode*>::iterator it = lists.begin();
	for (int i = 0; i < lists.size(); i++) {
		if (lists[i] == NULL) {
			lists.erase(it + i);
		}
	}
	int n;
	int left = 0;
	n = lists.size();
  
	while (n > 1) {//每两个进行使用mergeTwoLists进行合并，然后循环直到合并完成
		if (n % 2 == 1) {
			ListNode *m = new ListNode(-9999);
			lists.insert(lists.begin() + n, m);
			left++;
		}
		int k = (n + 1) / 2;
		for (int i = 0; i < k; i++) {
			lists[i] = mergeTwoLists(lists[i], lists[i + k]);
		}
		n = k;
	}
  
	ListNode* A = lists[0];
	while (left != 0) {
		A = A->next;
		left--;
	}
	return A;
}



int main() {
	ListNode * A1 = new ListNode(1);
	ListNode * A2 = new ListNode(4);
	ListNode * A3 = new ListNode(5);

	ListNode * B1 = new ListNode(1);
	ListNode * B2 = new ListNode(3);
	ListNode * B3 = new ListNode(4);

	ListNode * C1 = new ListNode(2);
	ListNode * C2 = new ListNode(6);

	A1->next = A2;
	A2->next = A3;

	B1->next = B2;
	B2->next = B3;

	C1->next = C2;
	vector<ListNode*> lists;
	lists.push_back(A1);
	lists.push_back(B1);
	lists.push_back(C1);
	cout<< mergeKLists(lists)->val;
	system("pause");
	return 0;
}
