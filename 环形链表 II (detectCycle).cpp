/**
 *本题是上题的延续，思路类似，还未做进阶。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
	set<ListNode *> a;
	ListNode *p = head;
	while (p != NULL) {
		int v1 = a.size();
		a.insert(p);
		int v2 = a.size();
		if (v1 == v2) {
			return p;
		}
		p = p->next;
	}
	return NULL;
    }
};
