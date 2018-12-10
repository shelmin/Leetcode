/*
**一个简单的题目但是折射出很多问题，这里提供两个解法，第一个解法是普通的解法，直接通过循环得到。第二个是递归解法，但是不能全部通过，会遇到递归层数
**过深的堆栈溢出报错，但是逻辑没错。这里重点讲第二种解法，在码的过程中会发现怎么释放申请的指针变量的问题，free和delete的区别，以及在释放之后要将
**指针变量赋为NULL.不然只是指针所指的内存区域被释放，指针变量本身依旧指在原内存区域。
*/
//解法1
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

ListNode* rotateRight(ListNode* head, int k) {
	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		return head;
	}
	int count = 0;	
	ListNode * p = head;
	while (p!= NULL) {
		p = p->next;
		count++;
	}
	count = k % count;
	p = head;
	while(count != 0) {
		count--; 
		while (p->next->next != NULL) {
			p = p->next;
		}
		p->next->next = head;
		head = p->next;
		p->next = NULL;
		p = head;
	}
	return head;
	

}

int main() {
	ListNode * A1 = new ListNode(1);
	ListNode * A2 = new ListNode(2);
	ListNode * A3 = new ListNode(3);

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

	rotateRight(A1, 20000000000);
	cout << A1->next->val;
	system("pause");
	return 0;
}

//解法2
ListNode* rotateRight(ListNode* head, int k) {
if (head == NULL) {
	return NULL;
}
if (head->next == NULL) {
	return head;
}
ListNode * p = head;
if (k != 0) {
	k--;
	while (p->next->next != NULL) {
		p = p->next;
	}
	p->next->next = head;
	head = p->next;
	p->next = NULL;
	p = NULL;

	return rotateRight(head, k);
}
else return head;
}
