/* leetcode T23:合并K个升序链表
 * 原题链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * */

/* 方法一：顺序合并
 *
 * 算法思想：
 * 依次合并每个链表
 *
 * 关键点：
 * 两链表合并时创建一个新链表记录合并后的链表
 *
 * 复杂度分析：
 * 时间复杂度：O(k^2*n)，每个链表都要与剩下k-1个链表进行比较，每次合并的时间复杂度为O(n)。
 * 空间复杂度：O(1)。
 *
 * 方法二：分治合并
 * 算法思想：
 * 基于分治，两两合并
 *
 * 复杂度分析：
 * 时间复杂度：O(kn*logk)，
 * 空间复杂度：O(logk)，递归。
 * */

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 顺序合并
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    ListNode* pseudoHead = new ListNode();// 相当于新建一个链表
    ListNode* ans = pseudoHead;
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;

    while (cur1 && cur2) {
        if (cur1->val < cur2->val) {
            ans->next = cur1;
            ans = cur1;
            cur1 = cur1->next;
        } else {
            ans->next = cur2;
            ans = cur2;
            cur2 = cur2->next;
        }
    }

    if (cur1 != nullptr)
        cur2 = cur1;
    ans->next = cur2;

    return pseudoHead->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty())
        return nullptr;
    int n = lists.size();
    ListNode* tmpHead = nullptr;
    for (int i = 0; i < n; i++) {
        tmpHead = mergeTwoLists(tmpHead, lists[i]);
    }
    return tmpHead;
}

// 分治合并
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    ListNode* pseudoHead = new ListNode();// 相当于新建一个链表
    ListNode* ans = pseudoHead;
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;

    while (cur1 && cur2) {
        if (cur1->val < cur2->val) {
            ans->next = cur1;
            ans = cur1;
            cur1 = cur1->next;
        } else {
            ans->next = cur2;
            ans = cur2;
            cur2 = cur2->next;
        }
    }

    if (cur1 != nullptr)
        cur2 = cur1;
    ans->next = cur2;

    return pseudoHead->next;
}

ListNode* merge(vector<ListNode*>& lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return nullptr;
    int mid = (l + r) >> 1;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0, lists.size() - 1);
}

// 我的分治合并
// 两两合并
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    ListNode* pseudoHead = new ListNode();
    ListNode* ans = pseudoHead;
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;

    while (cur1 && cur2) {
        if (cur1->val < cur2->val) {
            ans->next = cur1;
            ans = cur1;
            cur1 = cur1->next;
        } else {
            ans->next = cur2;
            ans = cur2;
            cur2 = cur2->next;
        }
    }

    if (cur1 != nullptr)
        cur2 = cur1;

    ans->next = cur2;

    return pseudoHead->next;// 每次都返回新合并后的表的头结点

}

// 分治法
vector<ListNode*> merge(vector<ListNode*>& lists) {
    int n = lists.size();
    int len = n % 2 == 0 ? n : n-1;
    vector<ListNode*> mergedLists;

    for (int i = 0; i < len; i += 2) {
        ListNode* res = mergeTwoLists(lists[i], lists[i+1]);// 每次合并两个
        mergedLists.push_back(res);
    }

    if (n % 2 == 1) {
        mergedLists.push_back(lists[n-1]);// 奇数那个链表
    }

    return mergedLists;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (n == 0) return nullptr;

    vector<ListNode*> mergedLists(lists);

    while (!mergedLists.empty()) {
        if (mergedLists.size() == 1) return mergedLists[0];
        vector<ListNode*> res = merge(mergedLists);
        mergedLists.clear();
        mergedLists = res;
    }

    return nullptr;
}