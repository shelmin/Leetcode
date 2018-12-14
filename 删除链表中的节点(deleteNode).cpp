//很简单，指针基本操作
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

void deleteNode(ListNode* node) {
	ListNode * p = node;
	while (p ->next!=NULL) {
		if (p->next->next != NULL) {
			p->val = p->next->val;
			p = p->next;
		}
		else {
			p->val = p->next->val;
			p->next = NULL;
		}
	}

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
	ListNode * AAA;
	int *p = new int(1);
	int a;
	A1->next = NULL;
	A2 = A1;

	deleteNode(A1);
	system("pause");
	return 0;
}

