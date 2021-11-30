/* leetcode T147:对链表进行插入排序
 * 原题链接：https://leetcode-cn.com/problems/insertion-sort-list/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：插入排序
 *
 * 算法思想：
 * 使用插入排序法将后续节点一次插入排好序的子链表中--每次找子链表中第一个大于work->data的节点，并插入在该节点之后
 * 关键：
 * 如果待插入的节点大于子链表中所有节点，那么需要在子链表遍历结束后插入到链表尾。
 *
 * 注意：在这里头结点不是空节点，因此需要注意头结点出的处理
 * 改进一：
 * // 利用上一次新插入的结点位置
 * if (last->val <= work->val)
 *  max = last;
 * else {
 *  pre = head;
 *  max = head;
 *}
 *
 * 复杂度分析：
 * 时间复杂度：O(n^2)，最多需要遍历1+2+3+...+n次，最少需要1+1+1+...+1=n次。
 * 空间复杂度：O(1)，我们只会修改原本链表中节点的指向，而在堆栈上的堆栈帧不超过O(1)。
 * */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode* work = head->next;
    head->next = nullptr;
    ListNode* tmp = nullptr;
    ListNode* pre = head;
    ListNode* max = head;
    ListNode* last = head;

    while (work) {
        tmp = work->next;
        // 利用上一次新插入的结点位置
        if (last->val <= work->val)
            max = last;
        else {
            pre = head;
            max = head;
        }
        while (max && max->val <= work->val) {
            pre = max;
            max = max->next;
        }
        last = work;
        // 第一排序时max为头结点
        if (max == head) {
            work->next = max;
            head = work;
        } else {
            work->next = work;
            pre->next = work;
        }
        work = tmp;
    }
    return head;
}

