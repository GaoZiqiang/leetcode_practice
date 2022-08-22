/* BM10 两个链表的第一个公共结点
 * 原题链接：https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=295&tqId=23257&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * */

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) return nullptr;

        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;

        while (cur1 != cur2) {
            cur1 = cur1 ? cur1->next : pHead2;
            cur2 = cur2 ? cur2->next : pHead1;
        }

        return cur1;
    }
};