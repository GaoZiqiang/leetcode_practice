/* leetcode T206: 反转链表
 * 原题链接：https://leetcode-cn.com/problems/reverse-linked-list/
 * */

/* 方法一：头插法
 *
 * 算法思想：
 * 关键点：
 * 设置虚头结点pseudoHead
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 *
 * 方法二：双指针法
 * 算法思想：参考https://www.programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html#%E5%8F%8C%E6%8C%87%E9%92%88%E6%B3%95
 * */

// 方法一
ListNode* reverseList(ListNode* head) {
    if (head == nullptr)
        return nullptr;
    ListNode* pseudoHead = new ListNode();
    pseudoHead->next = nullptr;
    ListNode* work = head;
    ListNode* tmp = nullptr;
    while (work != nullptr) {
        tmp = work->next;
        work->next = pseudoHead->next;
        pseudoHead->next = work;
        work = tmp;
    }
    head = pseudoHead->next;
    delete pseudoHead;
    return head;
}

// 方法二
ListNode* reverseList(ListNode* head) {
    if (head == nullptr)
        return nullptr;
    ListNode* tmp = nullptr;
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur != nullptr) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}