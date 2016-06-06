/****************************************************************
两个链表有公共节点，表示从该结点开始之后的两个链表的结点都是相等的
所以从结尾开始到第一个相等的节点是重合的，故计算两个链表的长度，让长的
链表先走到与短链表相等的长度，然后再依次比较找到第一个相等的节点
*****************************************************************/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2)
    {
        if(pHead1 == NULL && pHead2 == NULL)
            return pHead1;
        int length1 = GetListlength(pHead1);
        int length2 = GetListlength(pHead2);
        int diff = (length1>length2)?length1-length2:length2-length1;
        if(length1>length2)
        {
            for(int i = 0; i < diff;++i)
                pHead1=pHead1->next;
        }
        else
        {
             for(int i = 0; i < diff;++i)
                pHead2=pHead2->next;
        }
        while(pHead1&&pHead2)
        {
            if(pHead1->val == pHead2->val)
                {
                return pHead1;
            }
                
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
        
    }
private:
    int GetListlength(ListNode *pHead)
    {
        int length = 0;
        while(pHead)
        {
            length++;
            pHead = pHead->next;
        }
		return length;
    }
};
