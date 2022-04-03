/* leetcode T203:移除链表元素
 * 原题链接：https://leetcode-cn.com/problems/remove-linked-list-elements/
 * */

/* 方法一：遍历
 *
 * 关键点：
 * 1 设置和不设置虚拟头结点时对头结点的不同处理方式
 * 2 只使用pre指针和同时使用pre、work指针
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 * */

struce ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 方法一：单独处理头结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (nullptr == head)
            return nullptr;
        // 单独处理头结点
        while (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 处理其他节点
        if (nullptr == head)
            return head;
        ListNode* pre = head;
        ListNode* work = head->next;
        while (work != nullptr) {
            if (work->val == val) {
                ListNode* tmp = work;
                pre->next = work->next;
                work = work->next;
                delete tmp;
            } else {
                pre = work;
                work = work->next;
            }
        }
        return head;
    }
};

// 方法二：设置虚拟头结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (nullptr == head)
            return nullptr;
        ListNode* pseudoHead = new ListNode();
        pseudoHead->next = head;

        ListNode* pre = pseudoHead;
        ListNode* work = pseudoHead->next;
        while (work != nullptr) {
            if (work->val == val) {
                ListNode* tmp = work;
                pre->next = work->next;
                work = work->next;
                delete tmp;
            } else {
                pre = work;
                work = work->next;
            }
        }
        return pseudoHead->next;
    }
};

// 只使用pre指针
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (nullptr == head)
            return nullptr;
        // 设置虚拟头结点
        ListNode* pseudoHead = new ListNode();
        pseudoHead->next = head;
        // 只使用pre指针进行遍历
        ListNode* pre = pseudoHead;
        while (pre->next != nullptr) {
            if (pre->next->val == val) {
                ListNode* tmp = pre->next;
                pre->next = pre->next->next;
                delete tmp;
            } else {
                pre = pre->next;
            }
        }
        head = pseudoHead->next;
        delete pseudoHead;
        return head;
    }
};