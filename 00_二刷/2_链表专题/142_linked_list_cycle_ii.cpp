/* T142:环形链表 II https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=8ed685f1-9aa8-4278-b7b1-3a442a34ed76&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=5&
 * 方法：快慢指针O(n)
 * */

ListNode *detectCycle(ListNode *head) {
    // 起始位置
    ListNode* fast = head;
    ListNode* slow = head;
    // 判断是否有环
    do {
        if (fast == NULL || fast->next == NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    // 找环的入口节点
    fast = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}