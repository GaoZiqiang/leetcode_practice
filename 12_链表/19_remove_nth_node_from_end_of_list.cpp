/* leetcode T19:删除链表的倒数第 N 个结点
 * 原题链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * */

/* 方法一：快慢指针法--不使用虚拟头结点
 *
 * 算法思想：
 * 设置slow和fast两个指针
 * slow初始位置为head，fast初值位置为head后面的第N个节点
 *
 * 关键点：
 * 1 N为链表长度时，待删除元素为头结点，需要单独处理
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 *
 * 方法二：快慢指针法--使用虚拟头结点
 *
 * 关键点：
 * 1 pseudoHead虚拟头结点及时删除
 *
 * 复杂度同方法一
 * */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 方法一
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* quick = head;
    ListNode* spre = head;

    for (int i = 1; i <= n; i++)
        quick = quick->next;

    while (quick != nullptr) {
        spre = slow;
        quick = quick->next;
        slow = slow->next;
    }

    // 单独处理头结点
    if (slow == head) {
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

// 方法二
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr)
        return nullptr;

    // 虚拟头结点
    ListNode* pseudoHead = new ListNode();
    pseudoHead->next = head;
    ListNode* slow = pseudoHead;
    ListNode* fast = pseudoHead;
    ListNode* pre = pseudoHead;

    // 确定fast指针的起始位置
    while (n--) {
        if (fast == nullptr)// N大于链表本身长度
            return nullptr;
        fast = fast->next;
    }

    // 遍历
    while (fast != nullptr) {
        pre = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // 删除目标节点
    pre->next = slow->next;
    delete slow;

    head = pseudoHead->next;
    delete pseudoHead;

    return head;
}

// 方法三：fast再提前走一步，因为需要让slow指向删除节点的上一个节点
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* slow = dummyHead;
    ListNode* fast = dummyHead;
    while(n-- && fast != NULL) {
        fast = fast->next;
    }
    fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummyHead->next;
}