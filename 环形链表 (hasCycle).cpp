/*
**没什么难度，利用了set的不存在重复元素的性质
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

bool hasCycle(ListNode *head) {
	set<ListNode *> a;
	ListNode *p=head;
	while (p != NULL) {
		int v1 = a.size();
		a.insert(p);
		int v2 = a.size();
		if (v1 == v2) {
			return true;
		}
		p = p->next;
	}
	return false;
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

	cout << hasCycle(A1);
	system("pause");
	return 0;
}

