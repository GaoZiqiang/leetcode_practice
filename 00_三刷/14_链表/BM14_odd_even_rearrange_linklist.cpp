/* BM14 链表的奇偶重排
 * 原题链接：https://www.nowcoder.com/practice/02bf49ea45cd486daa031614f9bd6fc3?tpId=295&tqId=1073463&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
//         if (!head->next->next) return head;

        // write code here
        ListNode* pseudoHead = new ListNode(-1);
        pseudoHead->next = head;
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;

        ListNode* cur1 = oddHead;
        ListNode* cur2 = evenHead;
        ListNode* cur = head->next->next;

        int cnt = 1;

        while (cur) {
            if (cnt % 2 == 1) {// 奇数
                cur1->next = cur;
                cur1 = cur;
            } else {
                cur2->next = cur;
                cur2 = cur;
            }
            cur = cur->next;
            cnt++;
        }
        cur1->next = evenHead;
        cur2->next = nullptr;

        return pseudoHead->next;
    }
};