/* NC50 链表中的节点每k个一组翻转
 * 原题链接：https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=117&tqId=37746&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3Dk%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=k
 * */

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* pseudoHead = new ListNode(-1);// 伪head
        pseudoHead->next = head;
        ListNode* work = head;

        // 统计节点总数
        int cnt = 0;
        while (work != nullptr) {
            cnt++;
            work = work->next;
        }

        int times = cnt / k;
        ListNode* pre = pseudoHead;// 翻转子链表的前驱指针pre(翻转过程中该pre指针一直不动)
        ListNode* cur = pre->next;// 翻转过程中该cur指针一直不动

        // 开始翻转
        for (int i = 0; i < times; i++) {
            for (int j = 1; j <= k - 1; j++) {// 1次操作翻转2个节点 故只需要k-1次操作
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = cur;// cur为翻转子链表的最后一个节点
            cur = pre->next;
        }

        return pseudoHead->next;
    }
};