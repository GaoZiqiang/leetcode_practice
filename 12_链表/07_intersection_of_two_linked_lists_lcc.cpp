/* leetcode T07:链表相交
 * 原题链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
 * */

/* 方法一：使用hashmap统计每个节点的出现次数
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
 * 方法二：计算两个链表的长度差
 * 然后让长的链表先走diff步，然后两链表同步前进，依次比较两节点是否相同。
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

#include <unordered_map>
using namespace std;

// 方法一：使用hashmap
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    unordered_map<ListNode*, int> hash;
    ListNode* work = headA;

    while (work != nullptr) {
        hash[work]++;
        work = work->next;
    }

    work = headB;

    while (work != nullptr) {
        if (hash[work] > 0)
            return work;
        hash[work]++;
        work = work->next;
    }

    return nullptr;
}

// 方法二：计算两个链表的长度差
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* work = headA;
    int lenA = 0, lenB = 0;

    // 计算两个链表的长度
    while (work != nullptr) {
        lenA++;
        work = work->next;
    }
    work = headB;
    while (work != nullptr) {
        lenB++;
        work = work->next;
    }

    // 计算长度差
    int diff = lenA - lenB;
    ListNode* workA = headA;
    ListNode* workB = headB;

    if (diff >= 0) {
        while (diff--) {
            workA = workA->next;
        }
    } else {// lenB > lenA
        diff = -diff;
        while (diff--) {
            workB = workB->next;
        }
    }

    // 遍历得到交点
    while (workA != nullptr) {
        if (workA == workB)
            return workA;
        workA = workA->next;
        workB = workB->next;
    }

    return nullptr;
}