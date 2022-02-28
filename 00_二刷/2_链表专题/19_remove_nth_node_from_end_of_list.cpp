/* T19:删除链表的倒数第 N 个结点 https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=8ed685f1-9aa8-4278-b7b1-3a442a34ed76&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=5&
 * 方法：快慢指针O(n)
 * */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* quick = head;
    ListNode* spre = head;

    // 确定快指针的起始位置
    for (int i = 1; i <= n; i++)
        quick = quick->next;

    while (quick != nullptr) {
        spre = slow;
        quick = quick->next;
        slow = slow->next;
    }

    if (slow == head) {// 待删除节点为头结点
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }else {
        spre->next = slow->next;
        delete slow;
    }

    return head;
}