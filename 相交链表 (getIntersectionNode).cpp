//该题较简单，还是利用了set内不能存在相同元素的特点进行判断，但是时间和空间复杂度不够好，需要进一步优化
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	set<ListNode *> S;
	int count1 = 0;
	int count2 = 0;
	ListNode *p = headA;
	ListNode *q = headB;
	while (p != NULL) {
		S.insert(p);
		p = p->next;
		count1++;
	}
	p = q;
	count2 = count1;
	while (S.size()==count2 && q!=NULL) {
		S.insert(q);
		count2++;
		p = q;
		q = q->next;
	}
	if (S.size() == count2) {
		return NULL;
	}
	else return p;
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

	cout << getIntersectionNode(A1, A2)->val << endl;;
	system("pause");
	return 0;
}

