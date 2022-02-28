/* T141:环形链表 https://leetcode-cn.com/problems/linked-list-cycle/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=8ed685f1-9aa8-4278-b7b1-3a442a34ed76&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=5&
 * 方法：快慢指针O(n)
 * */

bool hasCycle(ListNode *head) {
    if (head == NULL)
        return false;
    // 定义快慢指针的起始位置
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;// fast指针仍然保持原来步长--比slow快一步
    }
    return true;
}