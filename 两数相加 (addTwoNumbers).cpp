/**
 *使用了O(1)的额外空间，思路是将两个链表遍历并合并，合并过程中不断计算进位，如果计算到最后一次加法仍有进位（可能是两个链表对应位置值相加产生进位或者  *上一次的进位加本次值又产生进位），那么需要加一个值为1的新结点。这种思路的优点是空间复杂度小，缺点是实现比较复杂（跟借助一个额外的数组和链表相比）。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1,* p2=l2,*preP1 = new ListNode(0);//preP1指向P1的前一个元素  
        int addF = 0;  
        while(p1!=NULL&&p2!=NULL)  
        {  
            int addVal = p1->val + p2->val + addF;  
              
            if(addVal >= 10)  
            {  
                addVal = addVal - 10;  
                addF = 1;  
            }else  
                addF = 0;  
              
            p1->val = addVal;  
            preP1 = p1;  
            p1=p1->next;  
            p2=p2->next;  
        }  
        if(p1 != NULL || p2!=NULL)//不一样长  
        {  
            if(p2!=NULL)//l2长  
            {  
                p2->val = p2->val + addF;  
                preP1->next = p2;  
                  
                if(p2->val >= 10)  
                {  
                    p2->val -= 10;  
                    addF = 1;  
                }  
                else  
                    addF = 0;  
                preP1 = p2;  
                p2 = p2->next;  
                while(addF&&p2!=NULL)  
                {  
                    p2->val = p2->val + addF;  
                    if(p2->val >= 10)  
                        p2->val -= 10;  
                    else  
                        addF = 0;  
                    preP1 = p2;  
                    p2 = p2->next;  
                }  
            }else//l1长  
            {  
                while(addF&&p1!=NULL)  
                {  
                    p1->val = p1->val + addF;  
                    if(p1->val >= 10)  
                        p1->val -= 10;  
                    else  
                        addF = 0;  
                    preP1 = p1;  
                    p1 = p1->next;  
                }  
            }  
        }  
        if(addF == 1)  
        {  
            ListNode* addNode = new ListNode(1);  
            preP1->next = addNode;  
        }  
    return l1;  
        
        
    }
};
