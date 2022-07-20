/* BM2 链表内指定区间反转
 * 原题链接：https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=295&tqId=654&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pseudoHead = new ListNode(-1);
        pseudoHead->next = head;
        ListNode* cur = head;
        ListNode* pre = pseudoHead;

        int cnt = 1;
        while (cur != nullptr) {
            // cnt != m
            if (cnt != m) {
                cnt++;
                pre = cur;
                cur = cur->next;
                continue;
            }

            // cnt == m
            for (int i = m; i < n; i++) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }

            return pseudoHead->next;
        }

        return pseudoHead->next;
    }
};