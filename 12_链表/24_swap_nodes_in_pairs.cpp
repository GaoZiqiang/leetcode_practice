/* leetcode T24:两两交换链表中的节点
 * 原题链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * */

/* 方法一：双指针法
 *
 * 算法思想：
 * 设置pre和cur两个指针
 * 创建pseudoHead虚拟头结点，重新连接调整顺序后的pre和cur节点
 *
 * 关键点：
 * 1 pseudoHead虚拟头结点及时删除
 * 2 最后一个节点的尾指针要置空!!!
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 * */

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;
    ListNode* pseudoHead = new ListNode();
    ListNode* work = pseudoHead;
    ListNode* pre = head;
    ListNode* cur = pre->next;
    ListNode* tmp = nullptr;

    while (pre || cur) {
        tmp = cur->next;

        // 调整pre和cur的位置
        work->next = cur;
        work->next->next = pre;
        work = pre;

        // 更新pre和cur指针
        if (tmp == nullptr)// 偶数个节点
            break;
        pre = tmp;

        if (tmp->next == nullptr) {// 奇数个节点
            work->next = tmp;
            work = tmp;
            break;
        }
        cur = tmp->next;
    }
    // 重点：最后一个节点尾指针一定要置空!
    work->next = nullptr;

    head = pseudoHead->next;
    delete pseudoHead;

    return head;
}