/* leetcode T707:设计链表
 * 原题链接：https://leetcode-cn.com/problems/design-linked-list/
 * */

/* 方法一：遍历
 * 关键点：
 * 1 虚拟头结点
 * 2 尾指针?
 *   使用尾指针，需要管理尾指针的更新，也比较麻烦
 * */

class MyLinkedList {
private:
    ListNode* pseudoHead;
    int m_size;
public:
    MyLinkedList() {
        pseudoHead = new ListNode();
        pseudoHead->next = nullptr;
        m_size = 0;
    }

    // 获取链表中第 index 个节点的值
    int get(int index) {
        if (index >= m_size || index < 0)
            return -1;
        ListNode* pre = pseudoHead;
        while (index--) {
            pre = pre->next;
        }
        return pre->next->val;
    }

    // 在链表的第一个元素之前添加一个值为 val 的节点
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);
        tmp->next = pseudoHead->next;
        pseudoHead->next = tmp;
        m_size++;
        return;
    }

    // 将值为 val 的节点追加到链表的最后一个元素
    void addAtTail(int val) {
        ListNode* tmp = new ListNode(val);
        ListNode* pre = pseudoHead;
        while (pre->next != nullptr) {
            pre = pre->next;
        }
        pre->next = tmp;
        tmp->next = nullptr;
        m_size++;
        return;
    }

    // 在链表中的第 index 个节点之前添加值为 val  的节点
    void addAtIndex(int index, int val) {
        if (index > m_size || index < 0)
            return;
        ListNode* tmp = new ListNode(val);
        ListNode* pre = pseudoHead;
        while (index--) {
            pre = pre->next;
        }
        tmp->next = pre->next;
        pre->next = tmp;
        m_size++;
        return;
    }

    // 删除链表中的第 index 个节点
    void deleteAtIndex(int index) {
        if (index >= m_size || index < 0)
            return;
        ListNode* pre = pseudoHead;
        while (index--) {
            pre = pre->next;
        }
        ListNode* tmp = pre->next;// 待删除节点
        pre->next = pre->next->next;
        delete tmp;
        m_size--;
        return;
    }
};